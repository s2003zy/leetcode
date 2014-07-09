class Solution {
public:
    
    bool wordBreak(string s, unordered_set<string> &dict) {
        int sLen = s.size();
        if(s=="")return true;
        if(dict.empty())return false;
        vector<vector<bool>> dp(sLen,vector<bool>(sLen,false));
        
        for (int i = 0; i < sLen ; i++ ) {
            for (int len = 0; len < sLen - i; len++ ) {
                string sub = s.substr(i,len+1);
                if( dict.find(sub)!=dict.end())
                {
                    dp[i][i+len] =true;
                    if( i > 0 && dp[0][i-1]) dp[0][ i + len ] =true;
                }
            }
        }
        return dp[0][sLen-1];
            }
};
