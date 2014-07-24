class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int row[9]={0};
        int col[9]={0};
        int cell[9]={0};
        for (int i = board.size()-1; i >= 0 ; i--  )
            for (int j = board[0].size()-1; j>=0; j--) {
                if(board[i][j]=='.')continue;
                int number = 1 << (board[i][j]-'0');
                if( row[i]&number ) return false;
                if( col[j]&number ) return false;
                if( cell[ (i/3)*3 + j/3 ]&number ) return false;
                row[i] |= number;
                col[j] |= number;
                cell[(i/3)*3 + j/3 ] |= number;
        }
        return true;
    }
};