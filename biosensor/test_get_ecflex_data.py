import get_ecflex_data
import unittest

class TestProgram(unittest.TestCase):        # Individual unit of testing.
     def testbytereceive(self):
          data_to_test1 = get_ecflex_data.read_callback()
          assert type(data_to_test1) is int, "value is int"
