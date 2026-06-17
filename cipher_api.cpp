#include "cipher_api.h"
#include "CaesarCipher.h"
#include "VigenereCipher.h"
#include "BaconianCipher.h"
#include <cstring>

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

extern "C" {

EXPORT cipher_t* cipher_create_caesar(int key) {
    return new CaesarCipher(key);
}

EXPORT cipher_t* cipher_create_vigenere(const char* key) {
    return new VigenereCipher(key ? key : "");
}

EXPORT cipher_t* cipher_create_baconian() {
    return new BaconianCipher();
}

EXPORT char* cipher_encrypt(cipher_t* cipher, const char* text) {
    if (!cipher || !text) return nullptr;
    std::string res = static_cast<Cipher*>(cipher)->encrypt(text);
    char* out = new char[res.length() + 1];
    return std::strcpy(out, res.c_str());
}

EXPORT char* cipher_decrypt(cipher_t* cipher, const char* text) {
    if (!cipher || !text) return nullptr;
    std::string res = static_cast<Cipher*>(cipher)->decrypt(text);
    char* out = new char[res.length() + 1];
    return std::strcpy(out, res.c_str());
}

EXPORT void cipher_destroy(cipher_t* cipher) {
    delete static_cast<Cipher*>(cipher);
}

EXPORT void cipher_free(char* str) {
    delete[] str;
}

}
