import unittest
import arithmatics as cal


class TestArithmeticOperations(unittest.TestCase):
    def test_addition(self):
        self.assertEqual(cal.add(12, 12), 24)

    def test_subtraction(self):
        self.assertEqual(cal.subtract(20, 8), 12)

    def test_multiplication(self):
        self.assertEqual(cal.prod(5, 4), 20)

    def test_division(self):
        self.assertEqual(cal.divide(20, 5), 4)

    def test_division_by_zero(self):
        with self.assertRaises(ValueError):
            cal.divide(10, 0)


if __name__ == "__main__":
    unittest.main()
