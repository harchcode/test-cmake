#include <iostream>
#include <vector>

using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> r;

    int start = 0;
    int line_chars = 0;
    int i = 0;

    while (i < words.size()) {
        string word = words[i];

        if (line_chars == 0) {
            // start of line
            start = i;
            line_chars += word.size();
            i++;
            continue;
        }

        if (line_chars + word.size() + 1 <= maxWidth) {
            // still enough space for word in line
            line_chars += word.size() + 1;
            i++;

            continue;
        }

        // handle justifying and prepare for next line
        int word_count = i - start;
        int extra = maxWidth - line_chars + word_count - 1;
        int space = word_count > 1 ? extra / (word_count - 1) : 0;
        int remain = word_count > 1 ? extra % (word_count - 1) : 0;
        string tmp(maxWidth, ' ');
        int l = 0;

        for (int j = start; j < i; j++) {
            for (int k = 0; k < words[j].size(); k++) {
                tmp[l] = words[j][k];
                l++;
            }

            l += space;

            if (remain > 0) {
                l++;
                remain--;
            }
        }

        r.push_back(tmp);
        line_chars = 0;
    }

    string tmp(maxWidth, ' ');
    int l = 0;

    for (int j = start; j < words.size(); j++) {
        for (int k = 0; k < words[j].size(); k++) {
            tmp[l] = words[j][k];
            l++;
        }

        l++;
    }

    r.push_back(tmp);

    return r;
}

void test() {
    vector<string> words = {"What", "must", "be", "acknowledgment", "shall", "be"};
    vector<string> r = fullJustify(words, 16);

    /*
        [
            "This    is    an",
            "example  of text",
            "justification.  "
        ]
    */

    for (auto x : r) {
        cout << x << endl;
    }
}