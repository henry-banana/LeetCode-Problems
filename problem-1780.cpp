#include <iostream>
#include <string>

using std::cin, std::cout, std::string;

string convertDectoTer(int n) {
    string temp = "";

    while (n != 0) {
        temp += (n % 3) + '0';
        n /= 3;
    }

    temp.shrink_to_fit();
    return temp; 
}

bool checkPowerOfThree(int n) {
    string converted = convertDectoTer(n);

    if (converted.find('2') == string::npos) {
        return true;
    }

    return false;
}

int main() {

    int n; cin >> n;

    cout << (checkPowerOfThree(n) ? "True" : "False");

    return 0;
}