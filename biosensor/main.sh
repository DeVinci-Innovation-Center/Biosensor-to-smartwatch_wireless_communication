/usr/bin/python3 -m get_ecflex_data &
/usr/bin/python3 -m server &
/usr/bin/python3 -m database_manager &

tail -f /dev/null
