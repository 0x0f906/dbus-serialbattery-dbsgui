#!/bin/bash

# Define
PARENT_DIR="/var/www/venus/dbsgui"
APP_DIR="$PARENT_DIR/app"

# Create directories
mkdir -p $PARENT_DIR

# Install dependencies
opkg install python3-pip && pip3 install flask

# Download dbus-serialbattery-dbsgui
WEB_URL="https://github.com/0x0f906/dbus-serialbattery-dbsgui/archive/refs/heads/main.zip"
wget $WEB_URL -O /tmp/main.zip
unzip -j /tmp/main.zip -d $PARENT_DIR
rm /tmp/main.zip

# Permissions
chmod -R 755 $PARENT_DIR
chown -R www-data:www-data $PARENT_DIR

# Set up systemd service
cat <<EOF > /etc/systemd/system/flask-app.service
[Unit]
Description=Flask App
After=network.target

[Service]
User=www-data
WorkingDirectory=$APP_DIR
ExecStart=/usr/bin/python3 $APP_DIR/app.py
Restart=always

[Install]
WantedBy=multi-user.target
EOF

# Reload systemd and enable the service
systemctl daemon-reload
systemctl enable flask-app
systemctl start flask-app

# Set up nginx configuration
cat <<EOF > /etc/nginx/sites-available/dbsgui
server {
    listen 80;
    server_name your_domain_or_ip;

    location /dbsgui/ {
        proxy_pass http://127.0.0.1:5000/;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto $scheme;
    }

    location / {
        # Your existing web server configuration
    }
}
EOF

# Enable the nginx site
ln -s /etc/nginx/sites-available/dbsgui /etc/nginx/sites-enabled/

# Restart nginx to apply changes
systemctl restart nginx

echo "dbus-serialbattery-dbusgui installed."