#include <iostream>

using namespace std;

int findJudge(int n, vector<vector<int>> &trust) {
    if (n == 1 && trust.size() == 0) {
        return 1;
    }

    unordered_map<int, int> trusted_count;
    unordered_map<int, int> trust_count;

    int r = -1;

    for (auto &x : trust) {
        trust_count[x[0]]++;
        trusted_count[x[1]]++;

        if (trusted_count[x[1]] == n - 1) {
            r = x[1];
        }
    }

    if (r > -1 && trust_count[r] > 0) {
        r = -1;
    }

    return r;
}