import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class FiniteField {

    private int value;

    private static final int characteristic = 1234577;

    public FiniteField() {
        this.value = 0;
    }

    public FiniteField(int value) {
        setValue(value);
    }

    private void setValue(int value) {
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
        try {
            int[] res = new int[2];
            int g = gcdExtended(value, characteristic, res);

            if (g != 1) {
                throw new Exception();
            } else {
                return new FiniteField((res[0] % characteristic) % characteristic);
            }

        } catch(Exception e) {
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

        int[] res1 = new int[2];
        int gcd = gcdExtended(b % a, a, res1);

        res1[0] = res[0] - (b / a) * res[1];
        res1[1] = res[0];

        return gcd;
    }

    public FiniteField add(final FiniteField obj) {
        return new FiniteField(this.value + obj.value);
    }

    public FiniteField sub(final FiniteField obj) {
        int result = this.value - obj.value;

        return (result < 0) ? new FiniteField(characteristic + result) : new FiniteField(result);
    }

    public FiniteField mult(final FiniteField obj) {
        int temp = obj.value;

        FiniteField res = new FiniteField();
        for(int i = 0; i < temp; i++) {
            res = add(this);
        }

        return res;
    }

    public FiniteField div(final FiniteField obj) {
        FiniteField res = findInverse(obj.value);
        return mult(res);
    }

    void assign(final FiniteField obj) {
        this.value = obj.value;
    }

    void multAndAssign(final FiniteField obj) {
        assign(mult(obj));
    }

    void divAndAssign(final FiniteField obj) {
        assign(div(obj));
    }

    void addAndAssign(final FiniteField obj) {
        assign(add(obj));
    }

    void subAndAssign(final FiniteField obj) {
        assign(sub(obj));
    }

    boolean ifNotEqual(final FiniteField b) {
        return this.value != b.value;
    }

    boolean ifEqual(final FiniteField b) {
        return this.value == b.value;
    }

    boolean ifLessEqual(final FiniteField b) {
        return this.value <= b.value;
    }

    boolean ifGreaterEqual(final FiniteField b) {
        return this.value >= b.value;
    }

    boolean ifLess(final FiniteField b) {
        return this.value < b.value;
    }

    boolean ifGreater(final FiniteField b) {
        return this.value > b.value;
    }

    public static void stdinRead(FiniteField a)  {
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
