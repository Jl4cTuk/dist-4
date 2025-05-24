#include <openssl/evp.h> 
#include <openssl/err.h> 
#include <iostream> 
#include <string>
#include <cstring>

using namespace std;

class Crypt {
public:
    static Crypt& getInstance() {
        static Crypt instance;
        return instance;
    }

    void setKey(const string& key) {
        cout << "setKey(): " << key << endl;
    }

    void encrypt(const string& path) {
        cout << "encrypt(): " << path << endl;
    }

    void decrypt(const string& path) {
        cout << "decrypt(): " << path << endl;
    }
};

bool processOption(const string& option, const string& dir, const string& password) {
    Crypt& crypto = Crypt::getInstance();
    crypto.setKey(password);

    if (option == "encrypt") {
        crypto.encrypt(dir);
    } else if (option == "decrypt") {
        crypto.decrypt(dir);
    } else {
        cerr << "Unknown option: " << option << endl;
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) { 
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " [encrypt|decrypt] /path/to/your/folder/ password" << endl; 
        return 1; 
    }

    string option = argv[1];
    string targetDir = argv[2];
    string password = argv[3];

    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    bool success = processOption(option, targetDir, password);

    EVP_cleanup();
    ERR_free_strings();

    return success ? 0 : 1;
}