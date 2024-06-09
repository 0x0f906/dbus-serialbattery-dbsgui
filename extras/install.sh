#!/bin/bash

#defines
PARENT_DIR="/var/www/dbsgui"

#create directories
mkdir -p $PARENT_DIR
chmod -R 755 $PARENT_DIR
chown -R www-data:www-data $PARENT_DIR


#install dependencies
opkg install python3-pip && pip3 install flask configparser configobj

#get dbus-serialbattery-dbsgui
WEB_URL="https://github.com/0x0f906/dbus-serialbattery-dbsgui/archive/refs/heads/main.zip"
wget $WEB_URL -O /tmp/main.zip
unzip /tmp/main.zip 
cp -r /tmp/dbus-serialbattery-dbsgui-main/* $PARENT_DIR 

#init.d
cp $PARENT_DIR/extras/dbsgui /etc/init.d/
chmod +x /etc/init.d/dbsgui
update-rc.d dbsgui defaults
/etc/init.d/dbsgui start

#cleanup
#rm /tmp/main.zip
#rm -rf /tmp/dbus-serialbattery-dbsgui-main

echo "dbus-serialbattery-dbusgui installed - RESTART YOUR SYSTEM."