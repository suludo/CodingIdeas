/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/
class Solution {
public:
    bool isValidElem(vector<vector<char>>& board, int r, int c, char ch){

        //board[r][c]='.';
        int ulr = 3*(r/3);
        int ulc = 3*(c/3);
        
        for(int i=0; i<9; i++){
            if(board[r][i]==ch) return false;
            if(board[i][c]==ch) return false;
            if(board[ulr+i/3][ulc+i%3]==ch) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j]!='.'){
                    char ch = board[i][j];
                    board[i][j] = '.';
                    if(!isValidElem(board,i,j,ch)){
                        board[i][j]=ch;
                        return false;
                    }
                    board[i][j] = ch;
                }
            }
        }
        return true;
    }
};