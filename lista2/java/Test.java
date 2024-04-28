import java.util.function.Supplier;

public class Main {
    public static void main(String[] args) {

        DHSetup<Field> setup = new DHSetup<>(FiniteField::new);

        User<Field> user1 = new User<>(setup);
        User<Field> user2 = new User<>(setup);

        Field message1 = new FiniteField(123457);
        //Field message2 = new FiniteField(4567899);

        //Field res = message1.mult(message2);
        //System.out.println(res.div(message2));

        user1.setKey(user2.getPublicKey());
        user2.setKey(user1.getPublicKey());

        Field encrypted1 = user1.encrypt(message1);
        //Field encrypted2 = user2.encrypt(message2);
        System.out.println(message1);
        //System.out.println(message2);

        Field decrypted1 = user2.decrypt(encrypted1);
        //Field decrypted2 = user1.decrypt(encrypted2);
        System.out.println(decrypted1);
        //System.out.println(decrypted2);
    }
}