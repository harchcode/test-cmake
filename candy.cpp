#include <iostream>
#include <vector>

using namespace std;

// int candy(vector<int> &ratings) {
//     int n = ratings.size();
//     int x = 0;
//     int r = 1;
//     int prev = 1;

//     for (int i = 1; i < n; i++) {
//         if (ratings[i] < ratings[i - 1]) {
//             if (prev == 1) {
//                 r += (i - x) + 1;
//             } else {
//                 r += 1;
//                 x = i;
//             }

//             prev = 1;
//         } else if (ratings[i] > ratings[i - 1]) {
//             prev += 1;
//             r += prev;

//             x = i;
//         } else {
//             prev = 1;
//             r += 1;

//             x = i;
//         }
//     }

//     return r;
// }

// int candy(vector<int> &ratings) {
//     int n = ratings.size();
//     int r = 1;
//     int current = 1;
//     int last_max_index = 0;

//     for (int i = 1; i < n; i++) {
//         if (ratings[i] > ratings[i - 1]) {
//             current += 1;
//             r += current;
//             last_max_index = i;
//         } else if (ratings[i] < ratings[i - 1]) {
//             current -= 1;

//             if (current < 1) {
//                 current = 1;
//                 r += (i - last_max_index) + 1;
//             } else {
//                 r += current;
//             }
//         } else {
//             current = 1;
//             last_max_index = i;
//             r += current;
//         }
//     }

//     return r;
// }

// int candy(vector<int> &ratings) {
//     int n = ratings.size();
//     int r = 1;
//     int current = 1;
//     int last_max_index = 0;
//     int last_min_index = 0;

//     for (int i = 1; i < n; i++) {
//         if (ratings[i] > ratings[i - 1]) {
//             current += 1;
//             last_max_index = i;

//             r += (1 - ratings[last_min_index]) * (last_min_index - last_max_index + 1);
//         } else if (ratings[i] < ratings[i - 1]) {
//             current -= 1;
//             last_min_index = i;

//             r +=
//         } else {
//             current = 1;
//             last_max_index = i;
//             last_min_index = i;
//             r += current;
//         }
//     }

//     return r;
// }

int candy(vector<int> &ratings) {
    int n = ratings.size();
    int r = 1;
    int current = 1;
    int last_max_index = 0;
    int last_max = 0;

    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            current += 1;
            r += current;
            last_max_index = i;
            last_max = current;
        } else if (ratings[i] < ratings[i - 1]) {
            current = 1;

            int inc = i - last_max_index;

            r += inc;

            if (inc >= last_max) {
                r++;
            }
        } else {
            current = 1;
            last_max_index = i;
            last_max = 1;
            r += current;
        }
    }

    return r;
}

void test() {
    // vector<int> nums = {1, 6, 10, 8, 7, 3, 2}; // expect 18
    // vector<int> nums = {1, 3, 2, 2, 1}; // expect 7
    vector<int> nums = {1, 3, 4, 5, 2}; // expect 11

    cout << candy(nums) << endl;
}