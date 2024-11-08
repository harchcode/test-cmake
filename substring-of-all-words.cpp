#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// vector<int> findSubstring(string s, vector<string> &words) {
//     int m = s.size();
//     int n = words[0].size();
//     int total_words_length = n * words.size();

//     unordered_map<string, int> word_map;
//     for (string word : words) {
//         word_map[word]++;
//     }

//     vector<int> r;
//     unordered_map<string, int> remain = word_map;
//     int start = 0;
//     int end = n - 1;

//     while (start < m - total_words_length + 1) {
//         string cur = s.substr(end - n + 1, n);

//         if (remain[cur] == 0) {
//             start++;
//             end = start + n - 1;
//             remain = word_map;
//             continue;
//         }

//         if (end - start + 1 == total_words_length) {
//             r.push_back(start);
//             start += n;
//             end = start + n - 1;
//             remain = word_map;
//         } else {
//             remain[cur]--;
//             end += n;
//         }
//     }

//     return r;
// }

vector<int> findSubstring(string s, vector<string> &words) {
    int m = s.size();
    int n = words[0].size();
    int total_words_length = n * words.size();

    unordered_map<string, int> word_map;
    for (string word : words) {
        word_map[word]++;
    }

    vector<int> r;

    for (int i = 0; i < n; i++) {
        unordered_map<string, int> remain = word_map;

        int start = i;
        int end = i;

        while (start < m - total_words_length + 1) {
            string cur = s.substr(end, n);

            if (remain[cur] == 0) {
                string tmp = s.substr(start, n);
                while (tmp != cur) {
                    remain[tmp]++;
                    start += n;
                    tmp = s.substr(start, n);
                }
                start += n;
                end += n;
                continue;
            }

            if (end - start + n == total_words_length) {
                r.push_back(start);

                remain[s.substr(start, n)]++;

                start += n;
            }

            remain[cur]--;
            end += n;
        }
    }

    return r;
}

void test() {
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar", "foo", "the"};

    auto r = findSubstring(s, words); // [6, 9, 12]
    cout << "[";
    for (int x : r) {
        cout << x << ", ";
    }
    cout << "]" << endl;
}