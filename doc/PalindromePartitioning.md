# Palindrome Partitioning

[Palindrome Partitioning On LeetCode](https://oj.leetcode.com/problems/palindrome-partitioning/)

###c++

```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        part(s,path,res,0);
        return res;
    }
    void part(string &s ,vector<string> &path ,vector<vector<string>> &res,int start) {
        if(s.size()==start)
        {
            res.push_back(path);
            return ;
        }
        int sLen =s.size();
        string substr ="";
        for (int i = start; i < sLen; i++ ) {
            substr += s[i];
            if(isOk(substr))
            {
                path.push_back(substr);
                part(s,path, res, i+1);
                path.pop_back();
            }
        }
    }
    bool isOk(string& s)
    {
        int end = s.size() - 1;
        int start = 0;
        while( start < end && s[start] == s[end] )
        {
            start++;
            end--;
        }
        return start>=end;
    }
    
};
```

