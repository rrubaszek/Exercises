import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public abstract class Field {
    public abstract void setValue(int value);
    public abstract int getValue();
    public abstract int getCharacteristic();
    public abstract Field add(final Field obj);
    public abstract Field sub(final Field obj);
    public abstract Field mult(final Field obj);
    public abstract Field div(final Field obj);
    public abstract void assign(final Field obj);
    public abstract void multAndAssign(final Field obj);
    public abstract void divAndAssign(final Field obj);
    public abstract void addAndAssign(final Field obj);
    public abstract void subAndAssign(final Field obj);
    public abstract boolean ifNotEqual(final Field b);
    public abstract boolean ifEqual(final Field b);
    public abstract boolean ifLessEqual(final Field b);
    public abstract boolean ifGreaterEqual(final Field b);
    public abstract boolean ifLess(final Field b);
    public abstract boolean ifGreater(final Field b);
}
