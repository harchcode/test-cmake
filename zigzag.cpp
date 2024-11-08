#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int num_rows) {
    int n = s.size();
    int num_mid = max(num_rows - 2, 0);
    int num_skip = num_rows + num_mid;
    int num_cols = (n + num_skip - 1) / num_skip;
    // int nn = n - num_mid * (num_cols - 1);

    string r;

    for (int i = 0; i < num_rows * num_cols; i++) {
        int row = i / num_cols;
        int col = i % num_cols;

        int index1 = col * num_skip + row;

        if (index1 >= n)
            continue;

        r.push_back(s[index1]);

        if (row == 0 || row == num_rows - 1)
            continue;

        int index2 = index1 + ((num_skip) - (row * 2));

        if (index2 >= n)
            continue;

        r.push_back(s[index2]);
    }

    return r;
}

void test() {
    // cout << convert("PAYPALISHIRING", 3) << endl; // "PAHNAPLSIIGYIR"
    cout << convert("ABCD", 3) << endl; // "ABDC"
}