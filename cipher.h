//
// Created by Hanna Lychak on 17.06.2026.
//

#ifndef ASSIGNMENT_3_CS560_CIPHER_H
#define ASSIGNMENT_3_CS560_CIPHER_H

#include <string>

class Cipher {
public:
    virtual std::string encrypt(const std::string& text) = 0;
    virtual std::string decrypt(const std::string& text) = 0;
    virtual ~Cipher() = default;
};

#endif //ASSIGNMENT_3_CS560_CIPHER_H
