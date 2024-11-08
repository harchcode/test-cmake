#include <iostream>
#include <vector>

using namespace std;

// vector<vector<int>> threeSum(vector<int> &nums) {
//     int n = nums.size();
//     sort(nums.begin(), nums.end());

//     vector<vector<int>> r;

//     int i = 0;
//     int j = n - 1;

//     while (i < j - 1) {
//         int k = (i + j) / 2;

//         while (k > i && k < j) {
//             int s = nums[i] + nums[k] + nums[j];

//             if (s < 0) {
//                 k = (k + j + 1) / 2;
//             } else if (s > 0) {
//                 k = (i + k) / 2;
//             } else {
//                 r.push_back({nums[i], nums[k], nums[j]});
//                 break;
//             }
//         }

//         if (nums[i] + nums[j] > 0) {
//             do
//                 j--;
//             while (j > i + 1 && nums[j] == nums[j + 1]);
//         } else {
//             do
//                 i++;
//             while (i < j - 1 && nums[i] == nums[i - 1]);
//         }
//     }

//     return r;
// }

vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> r;

    int i = 0;

    while (i < n - 2) {
        if (nums[i] > 0)
            break;

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int s = nums[i] + nums[j];

            if (s > 0)
                break;

            s += nums[k];

            if (s > 0) {
                do
                    k--;
                while (k > j && nums[k] == nums[k + 1]);
            } else if (s < 0) {
                do
                    j++;
                while (j < k && nums[j] == nums[j - 1]);
            } else {
                r.push_back({nums[i], nums[j], nums[k]});

                do
                    j++;
                while (j < k && nums[j] == nums[j - 1]);
            }
        }

        do
            i++;
        while (i < n - 2 && nums[i] == nums[i - 1]);
    }

    return r;
}

void test() {
    vector<int> nums = {1, 2, -2, 1};
    auto res = threeSum(nums);
}