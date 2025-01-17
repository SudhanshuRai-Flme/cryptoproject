#include <iostream>
#include <string>
#include <vector>
#include "hex.cpp"
#include "base64.cpp"
#include "prime.cpp"
#include "thunder.cpp"

using namespace std;

int main() {
    string input, step1, step3, step4str, step2str;
    getline(cin, input);
    step1 = step1Encode(input);
    step2str = step2(step1);
    step3 = step3Encode(step2str);
    step4str = step4(step3);
    cout << step4str;
}
