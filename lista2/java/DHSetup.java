import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class DHSetup<T extends FiniteField> {

    private List<Integer> primes;

    private T generator;
    
    public DHSetup(T num) {
        int p = num.getCharacteristic();
        primes = findPrimes(p-1);

        long exponent;
        int ctr;
        Random random = new Random();
        while(true) {
            num.setValue(random.nextInt(p-1));

            ctr = 0;
            for(int i : primes) {
                exponent = (p-1)/i;

                if(power(num, exponent).ifNotEqual(new FiniteField(1))) {
                    ctr++;
                }
            }

            if(ctr == primes.size()) {
                break;
            }
        }

        generator = num;
    }

    private List<Integer> findPrimes(int num) {
        List<Integer> primes = new ArrayList<>();

        if(num % 2 == 0) {
            primes.add(2);
        }

        for(int i = 3; i < Math.sqrt(num); i += 2) {

            if(num % i == 0) {
                primes.add(i);
            }
        }

        return primes;
    }

    public T power(T a, long b) {
        T res = a;
        res.div(a);
        while(b > 0) {
            if(b % 2 == 1) {
                res.assign(res.mult(a));
            }
            a.assign(a.mult(a));
            b = b / 2;
        }
        //res.div(a);
        return res;
    }
}
