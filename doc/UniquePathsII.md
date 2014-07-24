# Unique Paths II
[Unique Paths II On LeetCode](https://oj.leetcode.com/problems/unique-paths-ii/)

### c++

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if ( m == 0 ) return 0;
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        vector<int> dp(n,0);
        dp[0]=1;
        for (int i = 0; i < m; i++ ) {
            for (int j = 0 ; j < n; j++ ) {
                if(obstacleGrid[i][j]==1)
                {
                    dp[j]=0;
                    continue;
                }
                dp[j]=dp[j]+(j>0?dp[j-1]:0);
            }
        }
        return dp[n-1];
    }
};
```

```python
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
      
```