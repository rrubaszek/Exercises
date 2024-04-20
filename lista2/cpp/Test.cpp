#include "DHSetup.h"
#include "DHSetup.cpp"
#include "GaloisField.h"
#include "User.h"
#include "User.cpp"
#include <iostream>
#include <vector>


int main()
{
    DHSetup<GaloisField> setup;

    User<GaloisField> user1(setup);
    User<GaloisField> user2(setup);

    GaloisField message1(50);
    GaloisField message2(100);

    user1.setKey(user2.getPublicKey());
    user2.setKey(user1.getPublicKey());

    GaloisField encrypted1 = user1.encrypt(message1);
    GaloisField encrypted2 = user2.encrypt(message2);
    std::cout << message1 << "\n";
    std::cout << message2 << "\n";

    GaloisField decrypted1 = user2.decrypt(encrypted1);
    GaloisField decrypted2 = user1.decrypt(encrypted2);
    std::cout << decrypted1 << "\n";
    std::cout << decrypted2 << "\n";

    return 0;
}