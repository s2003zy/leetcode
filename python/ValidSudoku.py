class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        row = [0]*9
        col = [0]*9
        cell = [0]*9
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue;
                number = 1 << int(board[i][j])
                if row[i]&number != 0:
                    return False
                if col[j]&number != 0:
                    return False
                if cell[(i/3)*3+j/3]&number !=0:
                    return False
                row[i] |= number
                col[j] |= number
                cell[(i/3)*3+j/3] |=number
        return True
        