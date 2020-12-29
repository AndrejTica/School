#include <sstream>
#include <string>
using namespace std;
#include <cstdlib> // srand

class CipherStream {
private:
  int key;
  string cryptText;

public:
  CipherStream(int key) {
    this->key = key;
    srand(key); // init key
    cryptText = "";
  }
  CipherStream &operator<<(const string &s) { // ---------> encrypt
    this->encrypt(s);
    return *this;
  }
  CipherStream &operator<<(const char *p) {
    this->encrypt(string(p));
    return *this;
  }
  void encrypt(const string &s) {
    === ENTER CODE ===
  }
  CipherStream &operator>>(string &s) { // --------------> decrypt
    s = this->decrypt();
    return === ENTER CODE ===;
  }
  string decrypt() {
    === ENTER CODE ===
  }
  const string &str() const { return cryptText; } // ----> GET/SET CryptText
  const string &getCryptText() const { return str(); }
  void setCryptText(string &cryptText) {
    this->cryptText = cryptText;
    // adapt key
    srand(key);
    === ENTER CODE ===
  }

  void reset() {
    cryptText = "";
    srand(key);
  } // --------------------> reset

  friend ostream &operator<<(ostream &o, CipherStream &cs) { //---> output
    o << "[ ";
    for (unsigned int i = 0; i < cs.cryptText.size() - 1; i++) {
      o << (int)cs.cryptText[i] << ",";
    }
    o << (int)cs.cryptText[cs.cryptText.size() - 1];
    o << " ]" << endl;
    return o;
  } // output

  // ------------------------- communication
  string plain2cipher(const string &plain) {
    // NO srand(key)
    // do this only in constructor
    // encrypt
    string scipher = "";
    for (size_t i = 0; i < plain.size(); i++) {
      scipher += plain[i] ^ rand();
    }

    // return
    return scipher;
  }

  string cipher2plain(const string &scipher) {
    // NO srand(key)
    // do this only in constructor
    // decrypt
    string plain = "";
    for (size_t i = 0; i < scipher.size(); i++) {
      plain += scipher[i] ^ rand();
    }

    // return
    return plain;
  }
};
