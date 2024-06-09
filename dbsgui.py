from flask import Flask, request, render_template, jsonify
import configparser
import os
import subprocess

app = Flask(__name__)

CONFIG_FILE = "/data/etc/dbus-serialbattery/config.ini"

def read_config():
    config = configparser.ConfigParser(allow_no_value=True)
    config.optionxform = str  # preserve case of keys
    config.read(CONFIG_FILE)
    return config

@app.route('/')
def index():
    try:
        config = read_config()
        config_dict = {section: dict(config.items(section)) for section in config.sections()}
        config_dict['DEFAULT'] = dict(config.items('DEFAULT'))
        return render_template('index.html', config=config_dict)
    except Exception as e:
        return f"Error reading configuration file: {str(e)}"

@app.route('/update', methods=['POST'])
def update_config():
    try:
        config = read_config()

        for key in request.form:
            # Ensure key is added to config if it doesn't exist
            config['DEFAULT'][key] = request.form[key] if request.form[key] else ""

        with open(CONFIG_FILE, 'w') as configfile:
            config.write(configfile, space_around_delimiters=False)
        
        # Restore original file permissions and attributes
        os.chmod(CONFIG_FILE, 0o777)
        os.system(f"setfattr -n user.simple-upnpd -v 127 {CONFIG_FILE}")

        return jsonify(success=True)
    except Exception as e:
        print(f"Error: {e}")
        return jsonify(success=False, error=str(e))

@app.route('/restart-driver', methods=['POST'])
def restart_driver():
    try:
        result = subprocess.run(['/data/etc/dbus-serialbattery/restart-driver.sh'], check=True)
        return jsonify(success=True)
    except subprocess.CalledProcessError as e:
        print(f"Error: {e}")
        return jsonify(success=False, error=str(e))

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)

