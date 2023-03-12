/*******************************************************
*AUTHOR-TUSHAR SINGH  DATE-12-03-2023  CHAR_CIPHER_PROG
********************************************************/

/**************************************************************************************************************
                               *******CHAR_CIPHER_PROG********

* A simple and very old method of sending secret messages is the substitution cipher.
  We all have used this cipher with our friends when we were a kid.
  Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
  For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

*  Write a program thats ask a user to enter a secret message.

* Encrypt this message using the substitution cipher and display the encrypted message.
  Then decryped the encrypted message back to the original message.

* We will be using 2 strings below for the subsitition.
  For example, to encrypt we can replace the character at position n in alphabet string
  with the character at position n in key string.

* To decrypt we can replace the character at position n in key
  with the character at position n in alphabet.

* Currently the cipher only substitutes letters - we could easily add digits, puncuation, and so forth.
  Also, currently the cipher always substitues a lowercase letter with an uppercase letter and vice-versa.

* using c++ style string and their operations and functionality.

*******************************************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string alphabet {"@ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {" @XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
   
    string secret_message {};
    cout << "Enter your secret message : ";
    getline(cin, secret_message);
    
    cout<<"\n============================================================"<<endl;
    
    string encrypted_message {};             //string to store the encrypted message
    
    cout << "\nEncrypting message..." << endl;
    
    for (char c: secret_message) {                     //using the range based for loop available in C++(14) or higher
        size_t position = alphabet.find(c);            //.find() for finding the letter
        if (position != string::npos) {
            char new_char {  key.at(position) };       //.at for locating the position
            encrypted_message += new_char;
        } else {
            encrypted_message += c;                   //print same letter if not available in string for encoding
        }
    }
    
    cout << "\nEncrypted message: " << encrypted_message << endl;
    cout<<"\n============================================================"<<endl;
    
    string decrypted_message {};                             //string to store my decrypted message
    cout << "\nDecrypting message..." << endl;
    
    for (char c: encrypted_message) {
        size_t position = key.find(c);
        if (position != string::npos) {
            char new_char { alphabet.at(position) };
            decrypted_message += new_char;
        } else {
            decrypted_message += c;
        }
    }
    
    cout << "\nDecrypted message: " << decrypted_message << endl;
    cout<<"\n============================================================"<<endl;
    
    cout << endl;
    return 0;
}
