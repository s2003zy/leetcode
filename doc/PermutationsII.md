# Permutations II

[Permutations II On LeetCode](https://oj.leetcode.com/problems/permutations-ii/)

### c++

```cpp
class Solution {
public:
    vector< vector<int> > res;
    
    void gen(vector<int> &num,vector<bool> &used,int usedNum,vector<int> tmp)
    {
        if(usedNum>=num.size())
        {
            res.push_back(tmp);
            return;
        }
        int numSize = num.size();
        for (int i = 0 ; i < numSize; i++ ) {
            if( !used[i] )
            {
                if( i>0 && num[i] == num[i-1] && !used[i-1] )
                    continue;
                used[i] = true;
                tmp.push_back(num[i]);
                gen(num, used, usedNum+1, tmp);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }
    
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<bool> mark(num.size(),false);
        vector<int> tmp;
        sort(num.begin(),num.end());
        gen(num, mark,0,tmp );
        return res;
    }
};

```