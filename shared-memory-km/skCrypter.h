#pragma once

#include <stddef.h>
#include <stdint.h>

// Assuming the type T is char for simplicity
typedef char T;

// A simplified version of skCrypter, specifically for char arrays
typedef struct skCrypter {
    T* storage;
    int size;
    char key1;
    char key2;
    int isEncrypted;
} skCrypter;

void crypt(skCrypter* crypter, T* data) {
    for (int i = 0; i < crypter->size; i++) {
        crypter->storage[i] = data[i] ^ (crypter->key1 + i % (1 + crypter->key2));
    }
    crypter->isEncrypted = 1;
}

T* encrypt(skCrypter* crypter) {
    if (!crypter->isEncrypted)
        crypt(crypter, crypter->storage);
    return crypter->storage;
}

T* decrypt(skCrypter* crypter) {
    if (crypter->isEncrypted)
        crypt(crypter, crypter->storage);
    crypter->isEncrypted = 0;
    return crypter->storage;
}

void init_skCrypter(skCrypter* crypter, T* data, int size, char key1, char key2) {
    crypter->storage = data;
    crypter->size = size;
    crypter->key1 = key1;
    crypter->key2 = key2;
    crypter->isEncrypted = 0;
    crypt(crypter, data);
}