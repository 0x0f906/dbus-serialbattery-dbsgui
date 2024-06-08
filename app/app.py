from flask import Flask, request, render_template_string
import configparser
import os

app = Flask(__name__, static_url_path='/dbsgui/static', static_folder='/var/www/venus/dbsgui/static')

CONFIG_FILE = "/data/etc/dbus-serialbattery/config.ini"

def read_config():
    config = configparser.ConfigParser()
    config.read(CONFIG_FILE)
    return config

@app.route('/dbsgui/')
def index():
    config = read_config()
    max_charge_current = config['DEFAULT'].get('MAX_BATTERY_CHARGE_CURRENT', '')
    max_discharge_current = config['DEFAULT'].get('MAX_BATTERY_DISCHARGE_CURRENT', '')
    logging_level = config['DEFAULT'].get('LOGGING', '')
    return render_template_string("""
        <!doctype html>
        <html>
        <head><title>Config Editor</title></head>
        <body>
            <h1>Config Editor</h1>
            <form action="/dbsgui/update" method="post">
                <label for="max_charge_current">Max Charge Current:</label>
                <input type="text" name="max_charge_current" value="{{ max_charge_current }}"><br><br>

                <label for="max_discharge_current">Max Discharge Current:</label>
                <input type="text" name="max_discharge_current" value="{{ max_discharge_current }}"><br><br>

                <label for="logging_level">Logging Level:</label>
                <select name="logging_level">
                    <option value="ERROR" {% if logging_level == 'ERROR' %} selected {% endif %}>ERROR</option>
                    <option value="WARNING" {% if logging_level == 'WARNING' %} selected {% endif %}>WARNING</option>
                    <option value="INFO" {% if logging_level == 'INFO' %} selected {% endif %}>INFO</option>
                    <option value="DEBUG" {% if logging_level == 'DEBUG' %} selected {% endif %}>DEBUG</option>
                </select><br><br>

                <input type="submit" value="Update">
            </form>
        </body>
        </html>
    """, max_charge_current=max_charge_current, max_discharge_current=max_discharge_current, logging_level=logging_level)

@app.route('/dbsgui/update', methods=['POST'])
def update_config():
    config = configparser.ConfigParser()
    config.read(CONFIG_FILE)
    
    config['DEFAULT']['MAX_BATTERY_CHARGE_CURRENT'] = request.form['max_charge_current']
    config['DEFAULT']['MAX_BATTERY_DISCHARGE_CURRENT'] = request.form['max_discharge_current']
    config['DEFAULT']['LOGGING'] = request.form['logging_level']
    
    with open(CONFIG_FILE, 'w') as configfile:
        config.write(configfile)
    
    return "Configuration updated successfully!"

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
