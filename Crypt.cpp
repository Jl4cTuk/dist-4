#include "Crypt.h" 
#include "Aes256.h" 
#include <iostream> 
#include <cstdio>

using namespace std;

Crypt& Crypt::getInstance() { 
    static Crypt instance; 
    return instance; 
}

void Crypt::setPassword(const string& password) { 
    pass = password; 
    cout << "setKey: " << pass << endl;
}

void Crypt::encrypt(const string& path) { 
    cout << "encrypt: " << path << endl;
    createFile(path, true); 
}

void Crypt::decrypt(const string& path) { 
    cout << "decrypt: " << path << endl;
    createFile(path, true); 
}

void Crypt::createFile(const string& path, bool opt) { 
    bool success; 
    
    if (opt) { 
        cout << "encrypting: " << path << endl; 
        success = Aes256::encryptFile(path, path, pass); 
    } 
    else { 
        cout << "decrypting: " << path << endl; 
        success = Aes256::decryptFile(path, path, pass); 
    } 
}
