#include <iostream>
#include <vector>

using namespace std;

int removeDuplicated(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;

    int c = 0;
    int k = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            c++;

            if (c < 2) {
                nums[k] = nums[i];
                k++;
            }
        } else {
            c = 0;
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

void test() {
    vector<int> nums = {1,
                        1,
                        1,
                        2,
                        2,
                        3};

    int k = removeDuplicated(nums);

    cout << "K: " << k << ", nums: [";

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        cout << nums[i];

        if (i < n - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}