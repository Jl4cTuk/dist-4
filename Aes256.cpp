#include "Aes256.h"
#include <openssl/aes.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream> 

using namespace std;

bool Aes256::encryptFile(const string& in, const string& out, const string& pass) {
    cout << "Aes256 encryptFile: \n"; 
    return true;
}

bool Aes256::decryptFile(const string& in, const string& out, const string& pass) {
    cout << "Aes256 decryptFile: \n"; 
    return true;
}