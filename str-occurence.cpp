#include <iostream>
#include <vector>

using namespace std;

int strStr(string haystack, string needle) {
    int m = haystack.size();
    int n = needle.size();
    int i = 0;
    int j = 0;
    int r = 0;

    while (i < m) {
        if (haystack[i] == needle[j]) {
            if (j == 0) {
                r = i;
            }

            if (j == n - 1) {
                return r;
            }

            i++;
            j++;
        } else {
            r++;
            i = r;
            j = 0;
        }
    }

    return -1;
}

void test() {
    // cout << strStr("sadbutsad", "sad") << endl; // 0
    // cout << strStr("sadbutsad", "dbuts") << endl; // 2
    // cout << strStr("a", "a") << endl; // 0
    // cout << strStr("mississippi", "issip") << endl; // 4
    cout << strStr("hello", "ll") << endl; // 2
}