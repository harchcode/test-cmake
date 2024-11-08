#include <iostream>
#include <vector>

using namespace std;

// string intToRoman(int num) {
//     string v1[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
//     string v10[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
//     string v100[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
//     string v1000[] = {"", "M", "MM", "MMM"}; // only up to 3000 because the constraint of num is 1 <= num <= 3999

//     string s1000 = v1000[num / 1000];

//     num %= 1000;
//     string s100 = v100[num / 100];

//     num %= 100;
//     string s10 = v10[num / 10];

//     num %= 10;
//     string s1 = v1[num];

//     return s1000 + s100 + s10 + s1;
// }

void process(string &r, int c, char v1, char v5, char v10) {
    if (c == 4) {
        r.push_back(v1);
        r.push_back(v5);
    } else if (c == 9) {
        r.push_back(v1);
        r.push_back(v10);
    } else {
        if (c >= 5) {
            r.push_back(v5);
            c -= 5;
        }

        for (int i = 0; i < c; i++) {
            r.push_back(v1);
        }
    }
}

string intToRoman(int num) {
    string r;

    int c = num / 1000;

    for (int i = 0; i < c; i++) {
        r.push_back('M');
    }

    num %= 1000;
    process(r, num / 100, 'C', 'D', 'M');

    num %= 100;
    process(r, num / 10, 'X', 'L', 'C');

    num %= 10;
    process(r, num, 'I', 'V', 'X');

    return r;
}

void test() {
    int num = 3749;

    cout << intToRoman(num) << endl;
}