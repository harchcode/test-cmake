#include <iostream>

using namespace std;

constexpr int MAX_INT_VALUE = 0b11111111111111111111111111111111;
constexpr int MIN_INT_VALUE = MAX_INT_VALUE * -1 - 1;

constexpr int MAX_INT_VALUE_OVER_10 = MAX_INT_VALUE / 10;
constexpr int MAX_INT_VALUE_LAST_DIGIT = MAX_INT_VALUE % 10;

int reverse(int x) {
    int r = 0;
    int n = x;

    while (n > 0) {
        if (r > MAX_INT_VALUE_OVER_10)
            return 0;

        int d = n % 10;

        if (r == MAX_INT_VALUE_OVER_10 && d > MAX_INT_VALUE_LAST_DIGIT)
            return 0;

        r = (r * 10) + d;
        n = n / 10;
    }

    return r;
}
