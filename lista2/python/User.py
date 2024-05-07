import random
from DHSetup import DHSetup
from FiniteField import FiniteField

class User:
    def __init__(self, setup):
        self.setup = setup

        seed = random.randint(0, 2**32 - 1)
        distribution = random.randint(1, 50)  
        self.secret = distribution 

    def get_public_key(self):
        generator = self.setup.generator
        return self.setup.power(generator, self.secret)

    def set_key(self, a):
        self.key = self.setup.power(a, self.secret)

    def decrypt(self, c):
        try:
            if self.key != 0:
                return c / self.key
            else:
                raise RuntimeError("Key has not been set up!")
        except RuntimeError as e:
            print(e)

        return 0
    
    def encrypt(self, m):
        try:
            if self.key != 0:
                return m * self.key
            else:
                raise RuntimeError("Key has not been set up!")
        except RuntimeError as e:
            print(e)

        return 0