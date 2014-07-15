# Palindrome Partitioning II

[Palindrome Partitioning II On LeetCode](https://oj.leetcode.com/problems/palindrome-partitioning-ii/)

### c++

```cpp
class Solution {
public:
    int minCut(string s) {
        if(s=="")return 0;
        int sLen = s.size();
        vector<int> dp(sLen,INT_MAX);
        dp[0]=0;
        vector<vector<int>> mark(sLen,vector<int>(sLen,false));
        for (int i = 1 ; i < sLen ; i++ ) {
            for (int j = i; j >=0; j--) {
                
                if(s[i]==s[j]&&( (i-j<2)||(mark[j+1][i-1]) ) )
                {
                    mark[j][i] = true;
                    if(j>0)
                        dp[i] = min(dp[i],dp[j-1]+1);
                    else
                        dp[i] = 0;
                }
            }
        }
        return dp[sLen-1];
        
    }
};
```