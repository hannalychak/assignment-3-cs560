//
// Created by Hanna Lychak on 17.06.2026.
//

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

class XorCipher : public Cipher {
    std::string key;
public:
    XorCipher(const std::string& key);
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
};

#endif //ASSIGNMENT_3_CS560_CIPHERREALIZ_H
