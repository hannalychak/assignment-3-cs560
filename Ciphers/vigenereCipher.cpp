#include "cipherrealiz.h"
#include <cctype>

VigenereCipher::VigenereCipher(const std::string& key) {
    this->key = key;
}

std::string VigenereCipher::encrypt(const std::string& text) {
    std::string result = "";
    int key_idx = 0;
    int key_len = key.length();

    if (key_len == 0) return text;

    for (char symbol : text) {
        if (std::isalpha(symbol)) {
            char base = std::islower(symbol) ? 'a' : 'A';
            char key_char = std::tolower(key[key_idx % key_len]);
            int shift = key_char - 'a';

            char encryptedSymbol = (symbol - base + shift) % 26 + base;
            result += encryptedSymbol;
            key_idx++;
        } else {
            result += symbol;
        }
    }
    return result;
}

std::string VigenereCipher::decrypt(const std::string& text) {
    if (key.length() == 0) return text;

    std::string reverse_key = "";

    for (char c : key) {
        int shift = std::tolower(c) - 'a';
        int reverse_shift = (26 - shift) % 26;
        reverse_key += (char)(reverse_shift + 'a');
    }

    VigenereCipher reverseCipher(reverse_key);
    return reverseCipher.encrypt(text);
}