#include <iostream>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board) {
    bitset<9> seen_row[9];
    bitset<9> seen_col[9];
    bitset<9> seen_block[9];

    for (int i = 0; i < 9; i++) {
        seen_row[i].reset();
        seen_col[i].reset();
        seen_block[i].reset();
    }

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.')
                continue;

            int val = board[row][col] - '1';
            int block = ((row / 3) * 3) + (col / 3);

            if (seen_col[col].test(val) || seen_row[row].test(val) || seen_block[block].test(val)) {
                return false;
            }

            seen_col[col].set(val);
            seen_row[row].set(val);
            seen_block[block].set(val);
        }
    }

    return true;
}

// bool isValidSudoku(vector<vector<char>> &board) {
//     bool seen_row[9][9];
//     bool seen_col[9][9];
//     bool seen_block[9][9];

//     for (int i = 0; i < 9; i++) {
//         for (int j = 0; j < 0; j++) {
//             seen_row[i][j] = false;
//             seen_col[i][j] = false;
//             seen_block[i][j] = false;
//         }
//     }

//     for (int row = 0; row < 9; row++) {
//         for (int col = 0; col < 9; col++) {
//             if (board[row][col] == '.')
//                 continue;

//             int val = board[row][col] - '1';
//             int block = ((row / 3) * 3) + (col / 3);

//             if (seen_col[col][val] || seen_row[row][val] || seen_block[block][val]) {
//                 return false;
//             }

//             seen_col[col][val] = true;
//             seen_row[row][val] = true;
//             seen_block[block][val] = true;
//         }
//     }

//     return true;
// }

void test() {
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << (isValidSudoku(board) ? "true" : "false") << endl;
}