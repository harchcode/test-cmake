#include <iostream>
#include <vector>

using namespace std;

int hIndex(vector<int> &citations) {
    sort(citations.begin(), citations.end());

    int h = citations.size();
    int i = 0;

    while (h > 0 && citations[i] < h) {
        h--;
        i++;
    }

    return h;
}

void test() {
    vector<int> nums = {0};

    cout << hIndex(nums) << endl;
}