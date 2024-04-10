public class Main {
    public static void main(String[] args) {

        FiniteField a = new FiniteField(3);
        FiniteField b = new FiniteField(4);

        if(a.ifEqual(b)) {
            FiniteField res = a.add(b);
            System.out.println(res);
        } else {
            a.subAndAssign(b);
            System.out.println(a);
        }
        FiniteField c = new FiniteField();
        FiniteField.stdinRead(c);
        System.out.println(c);
    }
}