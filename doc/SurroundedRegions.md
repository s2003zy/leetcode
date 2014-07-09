#Surrounded Regions
[Surrounded Regions On
LeetCode](https://oj.leetcode.com/problems/surrounded-regions/)

###c++

```cpp
class Solution {
public:
    void fill(vector<vector<char>> &board,int x,int y,char tt)
    {
        int xLength = board.size();
        int yLength = board[0].size();
        queue< pair<int, int> > q;
        q.push(make_pair(x, y));
        board[x][y] = tt;
        while(!q.empty())
        {
            pair<int , int > t = q.front();
            q.pop();
            int x = t.first;
            int y = t.second;
            if( x+1 < xLength && board[x+1][y] == 'O' )
            {
                board[x+1][y] = tt;
                q.push(make_pair(x+1, y));
            }
            if( x-1 >= 0 && board[x-1][y] == 'O' )
            {
                board[x-1][y] = tt;
                q.push(make_pair(x-1, y));}
            if( y+1 < yLength && board[x][y+1] == 'O' )
            {
                board[x][y+1] = tt;
                q.push(make_pair(x, y+1));
            }
            if( y-1 >= 0 && board[x][y-1] == 'O' )
            {
                board[x][y-1] = tt;
                q.push(make_pair(x, y-1));
            }
        }
        
    }
    
    void solve(vector<vector<char>> &board) {
        int xLength = board.size();
        if( xLength <= 0 ) return;
        int yLength = board[0].size();
        for (int i = 0; i < xLength; i++) {
            if(board[i][0] == 'O')
                fill(board, i, 0,'!');
            if(board[i][yLength-1] == 'O')
                fill(board, i, yLength-1,'!');
            
        }
        for (int i = 0; i < yLength; i++) {
            if(board[0][i] == 'O')
                fill(board, 0, i,'!');
            if (board[xLength-1][i] == 'O')
                fill(board, xLength-1, i,'!');
            
        }
        
        for (int i = 0; i < xLength ; i++) {
            for (int j = 0; j < yLength; j++) {
                if (board[i][j]=='O')board[i][j] = 'X';
                if (board[i][j]=='!')board[i][j] = 'O';
            }
        }
        
    }
};

```
