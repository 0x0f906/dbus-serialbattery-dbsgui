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
        with open(CONFIG_FILE, 'r') as file:
            lines = file.readlines()

        config_dict = {key: request.form[key] for key in request.form}

        new_lines = []
        for line in lines:
            if '=' in line:
                key = line.split('=')[0].strip()
                if key in config_dict:
                    value = config_dict[key]
                    new_lines.append(f"{key} = {value}\n")
                    del config_dict[key]
                else:
                    new_lines.append(line)
            else:
                new_lines.append(line)

        for key, value in config_dict.items():
            new_lines.append(f"{key} = {value}\n")

        with open(CONFIG_FILE, 'w') as file:
            file.writelines(new_lines)

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
