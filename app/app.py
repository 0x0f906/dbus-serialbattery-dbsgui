from flask import Flask, render_template, request
import configparser

app = Flask(__name__)

# Load the configuration file
config = configparser.ConfigParser()
config.read('config.ini')

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/update_config', methods=['POST'])
def update_config():
    # Get data from the POST request
    new_value = request.form.get('new_value')

    # Update the configuration file
    config['section']['key'] = new_value
    with open('config.ini', 'w') as configfile:
        config.write(configfile)

    return 'Config updated successfully'

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)