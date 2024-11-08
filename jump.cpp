#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int> &nums) {
    int target = nums.size() - 1;
    int current_pos = 0;
    int reach = 0;
    int current_reach = 0;
    int step = 0;

    while (current_pos < target && reach < target) {
        current_reach = max(current_reach, current_pos + nums[current_pos]);

        if (current_pos == reach) {
            reach = current_reach;
            current_reach = 0;
            step++;
        }

        current_pos++;
    }

    return step;
}

void test() {
    vector<int> nums = {7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3};

    cout << jump(nums) << endl;
}