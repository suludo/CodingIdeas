/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/
//pay attn, check function signature of isValid, and how the k is handled for the grid duplicate detection
class Solution {
public:
    bool isValid(char ch, int r, int c, vector< vector<char> >&board){
        int ulr = 3*(r/3);
        int ulc = 3*(c/3);
        for(int k=0; k<9; k++){
            if(board[r][k]==ch)
                return false;
            if(board[k][c]==ch)
                return false;
            if(board[ulr+k/3][ulc+k%3]==ch)
                return false;
        }
        return true;
    }
    bool helper(int r, int c, vector< vector<char> >&board){
        if(r>=9) return true;
        if(c>=9) return helper(r+1, 0, board);
        if(board[r][c] != '.') return helper(r, c+1, board);
        for(char ch = '1'; ch<='9'; ch++){
            if(isValid(ch, r, c, board)){
                board[r][c] = ch;
                if(helper(r,c+1, board)) return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        if(board.empty() || board.size()!=9 || board[0].size()!=9) return;
        helper(0,0, board);
    }
};