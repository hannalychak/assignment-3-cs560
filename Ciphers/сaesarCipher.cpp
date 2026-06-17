#include "CaesarCipher.h"
#include <cctype>

CaesarCipher::CaesarCipher(int key) {
    this->key = key;
}

std::string CaesarCipher::encrypt(const std::string& text) {
    std::string result = "";

    int shift = (key % 26 + 26) % 26;

    for (char symbol : text) {
        if (std::isalpha(symbol)) {
            char base = std::islower(symbol) ? 'a' : 'A';
            char encryptedSymbol = (symbol - base + shift) % 26 + base;
            result += encryptedSymbol;
        } else {
            result += symbol;
        }
    }
    return result;
}

std::string CaesarCipher::decrypt(const std::string& text) {
    CaesarCipher reverseCipher(-key);
    return reverseCipher.encrypt(text);
}