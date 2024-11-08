#include <iostream>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {
    int m = s.size();
    int n = t.size();

    unordered_map<char, int> remain;
    for (char c : t) {
        remain[c]++;
    }

    int start = 0;

    while (start <= m - n && remain.find(s[start]) == remain.end()) {
        start++;
    }

    if (start > m - n)
        return "";

    if (n == 1) {
        string ss(1, s[start]);
        return ss;
    }

    remain[s[start]]--;

    int end = start + 1;
    int match_count = 1;
    int min_start = 0;
    int min_end = 0;
    int min_len = m + 1;

    while (start <= m - n && end < m) {
        // cout << start << ", " << end << endl;

        char c = s[end];

        if (remain.find(c) == remain.end()) {
            end++;
            continue;
        }

        remain[c]--;

        if (remain[c] >= 0) {
            match_count++;

            while (match_count == n) {
                // cout << "B: " << start << ", " << end << endl;
                if (end - start + 1 < min_len) {
                    min_len = end - start + 1;
                    min_start = start;
                    min_end = end;
                }

                remain[s[start]]++;

                if (remain[s[start]] > 0) {
                    match_count--;
                }

                start++;
                while (start <= end && remain.find(s[start]) == remain.end()) {
                    start++;
                }

                // cout << "E: " << start << ", " << end << ", " << match_count << endl;

                continue;
            }

            end++;
        } else {
            end++;
        }
    }

    // cout << min_start << ", " << min_end << endl;
    if (min_len > m) {
        return "";
    }

    return s.substr(min_start, min_end - min_start + 1);
}

void test() {
    cout << minWindow("ADOBECODEBANC", "ABC") << endl; // BANC
    // cout << minWindow("babb", "baba") << endl; // ""
}