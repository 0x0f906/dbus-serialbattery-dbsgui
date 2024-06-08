#!/bin/bash

# Define the parent directory
PARENT_DIR="/var/www/venus/dbsgui"

# Create the parent directory if it doesn't exist
mkdir -p $PARENT_DIR

# Download Flask and place it in the 'depends' subdirectory
DEPENDS_DIR="$PARENT_DIR/depends"
mkdir -p $DEPENDS_DIR
FLASK_URL="https://github.com/pallets/flask/releases/download/3.0.3/flask-3.0.3.tar.gz"
wget $FLASK_URL -O $DEPENDS_DIR/flask.tar.gz
tar -xf $DEPENDS_DIR/flask.tar.gz -C $DEPENDS_DIR
rm $DEPENDS_DIR/flask.tar.gz

# Download and unpack the Python app and web interface
WEB_DIR="$PARENT_DIR/web"
mkdir -p $WEB_DIR
APP_URL="https://github.com/0x0f906/dbus-serialbattery-webgui/archive/refs/heads/main.zip"
wget $APP_URL -O $WEB_DIR/app.zip
unzip $WEB_DIR/app.zip -d $WEB_DIR
rm $WEB_DIR/app.zip

# Set permissions
chown -R www-data:www-data $PARENT_DIR

# Restart Nginx (assuming you're using systemd)
systemctl restart nginx
