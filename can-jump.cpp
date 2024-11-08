#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums) {
    int n = nums.size();
    int target = n - 1;
    int current_pos = 0;
    int reach = 0;

    while (current_pos < n && current_pos <= reach && reach < target) {
        reach = max(current_pos + nums[current_pos], reach);
        current_pos++;
    }

    return reach >= target;
}

void test() {
    vector<int> nums = {3, 2, 1, 0, 4};

    cout << canJump(nums) << endl;
}