import random
import math
from FiniteField import FiniteField

class DHSetup:
    def __init__(self, num):
        self.num = num
        self.primes = None
        self.generator = None

        seed = random.randint(0, 2**32 - 1)
        p = self.num.characteristic

        self.primes = self.find_primes(p - 1)  

        exponent = 0
        ctr = 0
        a = 0
        while True:
            a = random.randint(0, p - 1)

            self.num.setValue(a) 

            ctr = 0
            for i in self.primes:
                exponent = (p - 1) // i

                if self.power(self.num, exponent) != 1:
                    ctr += 1

            if ctr == len(self.primes):
                break

        self.generator = self.num 

    def find_primes(self, characteristic):
        primes = []

        if characteristic % 2 == 0:
            primes.append(2)
        for i in range(3, int(math.sqrt(characteristic)) + 1, 2):
            if characteristic % i == 0:
                primes.append(i)

        return primes

    def power(self, a, b):
        result = a / a
 
        while b > 0:
            if b % 2 == 1:
                result = (result * a) 
            a *= a  
            b //= 2
        return result
