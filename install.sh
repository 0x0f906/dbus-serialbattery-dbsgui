#!/bin/bash

# Defines
PARENT_DIR="/var/www/venus/dbsgui"
LIB_DIR="$PARENT_DIR/lib"
APP_DIR="$PARENT_DIR/app"

# Create directories
mkdir -p $PARENT_DIR
mkdir -p $PARENT_DIR/lib

# Download depends
FLASK_URL="https://github.com/pallets/flask/releases/download/3.0.3/flask-3.0.3.tar.gz"
wget $FLASK_URL -P /tmp
tar -zxvf /tmp/flask*.tar.gz -C $LIB_DIR
rm /tmp/flask*.tar.gz

# Download dbus-serialbattery-dbsgui
WEB_URL="https://github.com/0x0f906/dbus-serialbattery-webgui/archive/refs/heads/main.zip"
wget $WEB_URL -O /tmp/main.zip
unzip -j /tmp/main.zip -d $PARENT_DIR
rm /tmp/main.zip

# Ensure correct permissions
chmod -R 755 $PARENT_DIR
chown -R www-data:www-data $PARENT_DIR

echo "Installation completed successfully."
