from FiniteField import FiniteField
import sys

class Test:

    @staticmethod
    def main():
        num1 = FiniteField(100000)
        num2 = FiniteField(20)

        num1 += num2
        print(num1)

        gf_instance = FiniteField()
        print("Enter a value:")
        gf_instance >> sys.stdin 
        gf_instance *= gf_instance
        print(gf_instance)

if __name__ == "__main__":
    Test.main()