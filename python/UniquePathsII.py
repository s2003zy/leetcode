class Solution:
    # @param obstacleGrid, a list of lists of integers
    # @return an integer
    def uniquePathsWithObstacles(self, obstacleGrid):
        m = len(obstacleGrid)
        if m == 0 : return 0
        n = len(obstacleGrid[0])
        if n == 0 : return 0
        if obstacleGrid[0][0] == 1 : return 0
        dp = [1]+[0]*(n-1)
        
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    dp[j]=0;
                else:
                    dp[j] = dp[j]+(dp[j-1] if j>0 else 0)
        return dp[n-1]
      