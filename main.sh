/usr/bin/python3 biosensor/get_ecflex_data.py &
/usr/bin/python3 biosensor/server.py &
/usr/bin/python3 biosensor/database_manager.py &

arduino --upload smartwatch/wifi_client/wifi_client.ino --port /dev/ttyUSB*

tail -f /dev/null
