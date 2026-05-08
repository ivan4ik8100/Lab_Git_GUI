import unittest
from selenium import webdriver
from selenium.webdriver.common.by import By

class GoogleTestCase(unittest.TestCase):

    def setUp(self):
        self.driver = webdriver.Firefox()
        self.addCleanup(self.driver.quit)

    def test_registration_form(self):
        driver = self.driver
        driver.get('http://ivan4ik810.temp.swtest.ru/Regist.html')

        self.assertIn('PlayBaza1', driver.title)

        driver.find_element(By.ID, "registr_login_input").send_keys("ИванИванИванИванИванИванИ")
        driver.find_element(By.ID, "registr_email_input").send_keys("12312312312312312312312312312@123.2")
        driver.find_element(By.ID, "registr_password_input").send_keys("1234567890123456789012345")
        driver.find_element(By.ID, "registr_password2_input").send_keys("1234567890123456789012345")

        gender_male = driver.find_element(By.ID, "Female_Muzik")
        gender_male.click()

        register_button = driver.find_element(By.ID, "registr_knopka_zareg")
        register_button.click()

if __name__ == '__main__':
    unittest.main(verbosity=2)
