//please only add the hex decrypter as a function on this code don't make changes to the main function
//Message to contributer OGhostyy

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string base64Encode(const string& input) {
    const string base64Chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    string encoded;
    vector<unsigned char> bytes(input.begin(), input.end());

    for (size_t i = 0; i < bytes.size(); i += 3) {
        unsigned int buffer = 0;
        int padding = 0;

        for (size_t j = 0; j < 3; ++j) {
            if (i + j < bytes.size()) {
                buffer |= static_cast<unsigned int>(bytes[i + j]) << (16 - j * 8);
            } else {
                padding++;
            }
        }

        for (int j = 0; j < 4 - padding; ++j) {
            encoded += base64Chars[(buffer >> (18 - j * 6)) & 0x3F];
        }
        while (padding-- > 0) {
            encoded += '=';
        }
    }

    return encoded;
}

int main() {
    string plainText;

    getline(cin, plainText);

    string encodedText = base64Encode(plainText);

    cout << encodedText << '\n';

    return 0;
}
