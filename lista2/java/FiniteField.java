import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class FiniteField extends Field {
    private int value;
    private static final int characteristic = 1234567891;
    public FiniteField() {
        this.value = 0;
    }

    public FiniteField(int value) {
        setValue(value);
    }

    public void setValue(int value) {
        while(value < 0) {
            value += characteristic;
        }

        this.value = value % characteristic;
    }

    public int getValue() {
        return this.value;
    }

    public int getCharacteristic() {
        return characteristic;
    }

    private FiniteField findInverse(int value) {
        int[] res = new int[2];
        try {
            int g = gcdExtended(value, characteristic, res);
            if (g != 1) {
                throw new Exception();
            }
            else {
                return new FiniteField(res[0]);
            }
        }
        catch(Exception e)
        {
            System.out.println("Inverse not found");
        }

        return new FiniteField();
    }

    private int gcdExtended(int a, int b, int[] res) {
        if (a == 0) {
            res[0] = 0;
            res[1] = 1;
            return b;
        }

        // To store results of recursive call
        int gcd = gcdExtended(b % a, a, res);
        int x1 = res[0];
        int y1 = res[1];

        // Update x and y using results of recursive
        // call
        int tmp = b / a;
        res[0] = y1 - tmp * x1;
        res[1] = x1;

        return gcd;
    }

    public Field add(final Field obj) {
        return new FiniteField(this.value + obj.getValue());
    }

    public Field sub(final Field obj) {
        int result = this.value - obj.getValue();
        return new FiniteField(result);
    }

    public Field mult(final Field obj) {
        int res = fastMultiplication(this.value, obj.getValue());
        return new FiniteField(res);
    }

    private int fastMultiplication(int a, int b) {
        int res = 0;

        a %= characteristic;
        while (b > 0) {

            if ((b & 1) > 0) {
                res = (res + a) % characteristic;
            }
            a = (2 * a) % characteristic;
            b >>= 1;
        }
        return res;
    }

    public Field div(final Field obj) {
        FiniteField inv = findInverse(obj.getValue());
        return mult(inv);
    }

    public void assign(final Field obj) {
        this.value = obj.getValue();
    }

    public void multAndAssign(final Field obj) {
        assign(mult(obj));
    }

    public void divAndAssign(final Field obj) {
        assign(div(obj));
    }

    public void addAndAssign(final Field obj) {
        assign(add(obj));
    }

    public void subAndAssign(final Field obj) {
        assign(sub(obj));
    }

    public boolean ifNotEqual(final Field b) {
        return this.value != b.getValue();
    }

    public boolean ifEqual(final Field b) {
        return this.value == b.getValue();
    }

    public boolean ifLessEqual(final Field b) {
        return this.value <= b.getValue();
    }

    public boolean ifGreaterEqual(final Field b) {
        return this.value >= b.getValue();
    }

    public boolean ifLess(final Field b) {
        return this.value < b.getValue();
    }

    public boolean ifGreater(final Field b) {
        return this.value > b.getValue();
    }

    public static void stdinRead(Field a)  {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            FiniteField b = new FiniteField(Integer.parseInt(br.readLine()));
            a.assign(b);
        } catch (IOException ex){
            System.out.println("IO exception");
        }
    }
    @Override
    public String toString() {
        return String.valueOf(value);
    }
}
