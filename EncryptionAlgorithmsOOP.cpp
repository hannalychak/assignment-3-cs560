#include <iostream>
#include <dlfcn.h>
#include <string>

typedef void* (*create_caesar_fn)(int);
typedef void* (*create_vigenere_fn)(const char*);
typedef void* (*create_baconian_fn)();
typedef char* (*cipher_op_fn)(void*, const char*);
typedef void (*destroy_fn)(void*);
typedef void (*free_fn)(char*);

int main() {
    void* handle = dlopen("./libcipher.dylib", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error: " << dlerror() << std::endl;
        return 1;
    }

    create_caesar_fn create_caesar = (create_caesar_fn)dlsym(handle, "cipher_create_caesar");
    create_vigenere_fn create_vigenere = (create_vigenere_fn)dlsym(handle, "cipher_create_vigenere");
    create_baconian_fn create_baconian = (create_baconian_fn)dlsym(handle, "cipher_create_baconian");
    cipher_op_fn encrypt = (cipher_op_fn)dlsym(handle, "cipher_encrypt");
    cipher_op_fn decrypt = (cipher_op_fn)dlsym(handle, "cipher_decrypt");
    destroy_fn destroy = (destroy_fn)dlsym(handle, "cipher_destroy");
    free_fn free_str = (free_fn)dlsym(handle, "cipher_free");

    std::string text = "Hello";

    void* c1 = create_caesar(3);
    char* e1 = encrypt(c1, text.c_str());
    char* d1 = decrypt(c1, e1);
    std::cout << "Сaesar Orig: " << text << ", Enc: " << e1 << ", Dec: " << d1 << std::endl;
    free_str(e1); free_str(d1); destroy(c1);


    void* c2 = create_vigenere("KEY");
    char* e2 = encrypt(c2, text.c_str());
    char* d2 = decrypt(c2, e2);
    std::cout << "Vigenere Orig: " << text << ", Enc: " << e2 << ", Dec: " << d2 << std::endl;
    free_str(e2); free_str(d2); destroy(c2);

    void* c3 = create_baconian();
    char* e3 = encrypt(c3, text.c_str());
    char* d3 = decrypt(c3, e3);
    std::cout << "Baconian Orig: " << text << ", Enc: " << e3 << ", Dec: " << d3 << std::endl;
    free_str(e3); free_str(d3); destroy(c3);

    dlclose(handle);
    return 0;
}