#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0)
        return false;

    long r = 0;
    int n = x;

    while (n > 0) {
        int d = n % 10;

        r = (r * 10) + d;
        n = n / 10;
    }

    return r == x;
}

int getDigitCount(int n) {
    if (n < 100000) {
        if (n < 100) {
            if (n < 10) {
                return 1;
            } else {
                return 2;
            }
        } else {
            if (n < 1000) {
                return 3;
            } else {
                if (n < 10000) {
                    return 4;
                } else {
                    return 5;
                }
            }
        }
    } else {
        if (n < 10000000) {
            if (n < 1000000) {
                return 6;
            } else {
                return 7;
            }
        } else {
            if (n < 100000000) {
                return 8;
            } else {
                if (n < 1000000000) {
                    return 9;
                } else {
                    return 10;
                }
            }
        }
    }
}

bool isPalindrome2(int x) {
    if (x < 0)
        return false;

    int digits = getDigitCount(x);
    int divider = pow(10, digits - 1);

    int n = x;

    for (int i = 0; i < digits / 2; i++) {
        int left = n / divider;
        int right = n % 10;

        if (left != right)
            return false;

        n = n % divider;
        n = n / 10;

        divider /= 100;
    }

    return true;
}