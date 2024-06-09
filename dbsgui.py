from flask import Flask, request, render_template
import configparser
import os

app = Flask(__name__, static_url_path='/', static_folder='/var/www/dbsgui/static')

CONFIG_FILE = "/data/etc/dbus-serialbattery/config.ini"

def read_config():
    config = configparser.ConfigParser()
    config.read(CONFIG_FILE)
    return config

@app.route('/')
def index():
    config = read_config()
    max_charge_current = config['DEFAULT'].get('MAX_BATTERY_CHARGE_CURRENT', '')
    max_discharge_current = config['DEFAULT'].get('MAX_BATTERY_DISCHARGE_CURRENT', '')
    logging_level = config['DEFAULT'].get('LOGGING', '')
    return render_template('index.html', max_charge_current=max_charge_current, max_discharge_current=max_discharge_current, logging_level=logging_level)

@app.route('/update', methods=['POST'])
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
