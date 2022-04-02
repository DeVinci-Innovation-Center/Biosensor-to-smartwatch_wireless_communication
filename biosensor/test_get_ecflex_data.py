#####################################################################
###     A python script to test the type of the processed data    ###
#####################################################################


import get_ecflex_data
import unittest

class TestProgram(unittest.TestCase):        # Individual unit of testing.
     def testbytereceive(self):
          data_to_test = get_ecflex_data.read_callback(sender, read_value)
          id_test = data_to_test[0]
          timer_test = data_to_test[1]
          temperature_test = data_to_test[2]
          concentration_test = data_to_test[3]
          assert type(id_test) is int, "value is int"
          assert type(timer_test) is float, "value is float"
          assert type(temperature_test) is float, "value is float"
          assert type(concentration_test) is float, "value is float"

# Run pytest test_get_ecflex_data.py in the terminal
