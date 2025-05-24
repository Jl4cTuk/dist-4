#ifndef AES256_H
#define AES256_H
#include <string>

using namespace std;

class Aes256 {
public:
    static bool encryptFile(const string& inFile, const string& outFile, const string& key);
    static bool decryptFile(const string& inFile, const string& outFile, const string& key);
};
#endif // AES256_H