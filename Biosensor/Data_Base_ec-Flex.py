import sqlite3
import os
import Bluetooth_Connection

conn = sqlite3.connect('database.db')   # Establish a connection to the Database and create a connection object. database.db is the database file
 
def check_db(database):
    return os.path.exists(database)     # Check if the file already exists in the system


c = conn.cursor()    # Create a cursor to the Database

db_file = '/home/vivien/Documents/HP_project/database.db'
schema_file = '/home/vivien/Documents/HP_project/schema.sql'
 
if check_db(db_file):
    print('Database already exists. Exiting...')
#    exit(0)
 
with open(schema_file, 'r') as rf:
    schema = rf.read()                           # Read the schema from the file
 
with sqlite3.connect(db_file) as conn:
    print('Created the connection!') 
    conn.executescript(schema)                   # Execute the SQL query to create the table
    print('Created the Table! Now inserting')
    conn.executescript(Bluetooth_Connection.read_callback())
    print('Inserted values into the table!')
print('Closed the connection!')


