#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// int trap(vector<int> &height) {
//     int n = height.size();

//     int max1 = height[0];
//     int max2 = -1;
//     int current = 0;
//     int r = 0;

//     // for (int i = 1; i < n; i++) {
//     //     if (height[i] >= last_max) {
//     //         r += current;

//     //         last_max = height[i];

//     //         current = 0;
//     //     } else {
//     //         current += last_max - height[i];
//     //     }
//     // }

//     for (int i = 1; i < n; i++) {
//         if (height[i] >= max1) {
//             max1 = height[i];
//             max2 = 0;

//             r += current;
//             current = 0;
//         } else {
//             current += max1 - height[i];
//             max2 = max(max2, height[i]);
//         }
//     }

//     return r;
// }

// int trap(vector<int> &height) {
//     int n = height.size();

//     stack<int> walls_index;
//     int r = 0;

//     for (int i = 1; i < n; i++) {
//         if (height[i] < height[i - 1]) {
//             walls_index.push(i - 1);
//         }

//         if (height[i] <= height[i - 1])
//             continue;

//         int last_min = height[i - 1];

//         while (!walls_index.empty()) {
//             int wall_index = walls_index.top();
//             int wall_height = height[wall_index];

//             if (wall_height > height[i]) {
//                 r += (height[i] - last_min) * (i - wall_index - 1);

//                 break;
//             } else if (wall_height < height[i]) {
//                 r += (wall_height - last_min) * (i - wall_index - 1);
//                 last_min = wall_height;

//                 walls_index.pop();
//             } else {
//                 r += (height[i] - last_min) * (i - wall_index - 1);

//                 walls_index.pop();

//                 break;
//             }
//         }
//     }

//     return r;
// }

int trap(vector<int> &height) {
    int left_index = 0;
    int right_index = height.size() - 1;
    int left_max = height[left_index];
    int right_max = height[right_index];

    int r = 0;

    while (left_index < right_index) {
        if (left_max < right_max) {
            left_index++;
            left_max = max(left_max, height[left_index]);
            r += left_max - height[left_index];
        } else {
            right_index--;
            right_max = max(right_max, height[right_index]);
            r += right_max - height[right_index];
        }
    }

    return r;
}

void test() {
    // vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // 6
    vector<int> nums = {4, 2, 0, 3, 2, 5}; // 9

    cout << trap(nums) << endl;
}