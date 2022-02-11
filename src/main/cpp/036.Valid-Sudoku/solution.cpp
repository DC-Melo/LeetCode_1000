/* Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules: */
/* Each row must contain the digits 1-9 without repetition. */
/* Each column must contain the digits 1-9 without repetition. */
/* Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition. */
/* Note: */
/* A Sudoku board (partially filled) could be valid but is not necessarily solvable. */
/* Only the filled cells need to be validated according to the mentioned rules. */
/* A Sudoku board (partially filled) could be valid but is not necessarily solvable. */
/* Only the filled cells need to be validated according to the mentioned rules. */
/* 单引号是字符型 */
/* 双引号是字符串型 */
/* 单引号引起的一个字符实际上代表一个整数。 */
/* 双引号引起的字符串，代表的却是一个指向无名数组起始字符的指针。该数组会被双引号之间的字符以及一个额外的二进制为零的字符 '\0' 初始化。 */
#include <vector>
using namespace std;
class Solution 
{
public:
    bool isValidSudoku(vector<vector<char> > &board) 
    {
        vector<vector<bool> > rows(9, vector<bool>(9,false));
        vector<vector<bool> > cols(9, vector<bool>(9,false));
        vector<vector<bool> > blocks(9, vector<bool>(9,false));

        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')continue;
                int num = board[i][j] - '1';
                if(rows[i][num] || cols[j][num] || blocks[i - i%3 + j/3][num])
                    return false;
                rows[i][num] = cols[j][num] = blocks[i - i%3 + j/3][num] = true;
            }
        return true;
    }
};
int main(){
    Solution sln;
    vector<vector<char>> sudoku1 =
    {{'5','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};
    vector<vector<char>> sudoku2 =
    {{'8','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};
    vector<vector<char>> sudoku3 =
  {{'.', '8', '7', '6', '5', '4', '3', '2', '1'},
   {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'9', '.', '.', '.', '.', '.', '.', '.', '.'}};
    bool ret1=sln.isValidSudoku(sudoku1);
    bool ret2=sln.isValidSudoku(sudoku2);
    bool ret3=sln.isValidSudoku(sudoku3);
    
}
