#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string base64Decode(const string& input) {
    // Base64 character table to index mapping
    const string base64Chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";
    unordered_map<char, int> base64Index;
    for (int i = 0; i < base64Chars.size(); ++i) {
        base64Index[base64Chars[i]] = i;
    }

    string decoded;
    unsigned int buffer = 0; // Buffer to store 24 bits
    int bitsCollected = 0;   // Tracks how many bits are currently in the buffer

    for (char c : input) {
        if (c == '=') {
            // Ignore padding characters
            break;
        }

        // Add the 6-bit value of the current character to the buffer
        buffer = (buffer << 6) | base64Index[c];
        bitsCollected += 6;

        // Extract bytes when buffer contains at least 8 bits
        while (bitsCollected >= 8) {
            bitsCollected -= 8;
            decoded += static_cast<char>((buffer >> bitsCollected) & 0xFF);
        }
    }

    return decoded;
}

int main() {
    string base64Text;

    getline(cin, base64Text);

    string decodedText = base64Decode(base64Text);

    cout << decodedText << '\n';

    return 0;
}
