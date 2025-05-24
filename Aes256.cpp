#include "Aes256.h"
#include <openssl/aes.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream> 

using namespace std;

bool Aes256::encryptFile(const string& in, const string& pass) {
    ifstream fin(in, ios::binary);
    if (!fin || pass.empty()) return false;

    string data((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();

    for (size_t i = 0; i < data.size(); ++i)
        data[i] ^= pass[i % pass.size()];

    ofstream fout(in, ios::binary | ios::trunc);
    if (!fout) return false;
    fout.write(data.data(), data.size());
    fout.close();

    return true;
}

bool Aes256::decryptFile(const string& in, const string& pass) {
    return true;
}