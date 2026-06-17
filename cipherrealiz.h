

#ifndef ASSIGNMENT_3_CS560_CIPHERREALIZ_H
#define ASSIGNMENT_3_CS560_CIPHERREALIZ_H

#include "Cipher.h"
#include <string>

class CaesarCipher : public Cipher {
    int key;
public:
    CaesarCipher(int key);
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
};

class VigenereCipher : public Cipher {
    std::string key;
public:
    VigenereCipher(const std::string& key);
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
};

class BaconianCipher : public Cipher {
public:
    BaconianCipher(); // Ключ не нужен, алгоритм фиксированный
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
};

#endif //ASSIGNMENT_3_CS560_CIPHERREALIZ_H
