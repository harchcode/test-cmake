#include <bitset>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();

    bitset<256> chars;

    int start = 0;
    int end = 0;
    int r = 0;

    while (start < n && end < n) {
        if (chars.test(s[end])) {
            while (s[start] != s[end]) {
                chars.reset(s[start]);
                start++;
            }
            start++;
            end++;
        } else {
            chars.set(s[end]);
            r = max(r, end - start + 1);
            end++;
        }
    }

    return r;
}

void test() {
    // cout << lengthOfLongestSubstring("abcabcbb") << endl; // 3
    // cout << lengthOfLongestSubstring("pwwkew") << endl;  // 3
    cout << lengthOfLongestSubstring("tmmzuxt") << endl; // 5
}