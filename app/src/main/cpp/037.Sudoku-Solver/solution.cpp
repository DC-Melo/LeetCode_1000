#include <vector>
using namespace std;
class Solution 
{
public:
    bool isValid(vector<vector<char> > &board, int a, int b) 
    {
        for (int i = 0; i < 9; ++i) 
        {
            if (i != a && board[i][b] == board[a][b])
                return false;
        }
        for (int j = 0; j < 9; ++j) 
        {
            if (j != b && board[a][j] == board[a][b])
                return false;
        }
        int x = a / 3 * 3, y = b / 3 * 3;
        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 3; ++j) 
            {
                if (x + i != a && y + j != b 
                    && board[x + i][y + j] == board[a][b])
                    return false;
            }
        }
        return true;
    }
    
    bool solveHelper(vector<vector<char> > &board) 
    {
        for (int i = 0; i < 9; ++i) 
        {
            for (int j = 0; j < 9; ++j) 
            {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; ++k) 
                    {
                        board[i][j] = '0' + k;
                        if (isValid(board, i, j) && solveHelper(board)) 
                        {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char> > &board) 
    {
        solveHelper(board);
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
    /* bool ret1=sln.isValid(sudoku1); */
    /* bool ret2=sln.isValid(sudoku2); */
    /* bool ret3=sln.isValid(sudoku3); */
    /* sln.solveSudoku(sudoku1); */
    /* sln.solveSudoku(sudoku2); */
    /* sln.solveSudoku(sudoku3); */
    bool ret1=sln.solveHelper(sudoku1);
    bool ret2=sln.solveHelper(sudoku2);
    bool ret3=sln.solveHelper(sudoku3);
    
    return 0;
}
