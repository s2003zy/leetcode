# Word Break II
[Word Break II On LeetCode](https://oj.leetcode.com/problems/word-break-ii/)

### c++

```cpp
class Solution {
public:
    
    void getResutlt(string &s,unordered_set<string> &dict, int cur,vector<vector<bool>> path, vector<string> &result,vector<string> &tempPath)
    {
        if(cur==0)
        {
            string res;
            for (int i = tempPath.size()-1; i >= 0; i--) {
                res += tempPath[i]+" ";
            }
            res.erase(res.size()-1);
            result.push_back(res);
        }
        for (int i = 0 ; i < cur; i++ ) {
            if(path[cur][i])
            {
                tempPath.push_back(s.substr(i,cur-i));
                getResutlt(s, dict, i, path, result, tempPath);
                tempPath.pop_back();
            }
        }
        
    }
    
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int sLen = s.size();
        
        vector<bool> mark(sLen,false);
        vector< vector<bool> > path(sLen+1,vector<bool>(sLen+1,false));
        
        mark[0] = true;
        for (int i = 1; i < sLen+1; i++) {
            for (int j  = i-1; j>=0 ; j--) {
                if(mark[j]==true)
                {
                    string subString = s.substr( j , i - j );
                    if(dict.find(subString)!=dict.end())
                    {
                        mark[i] = true;
                        path[i][j] = true;
                    }
                }
            }
        }
        vector<string> result;
        vector<string> tempPath;
        getResutlt(s, dict, s.size(),path, result, tempPath);
        return result;
        
    }
};
```
