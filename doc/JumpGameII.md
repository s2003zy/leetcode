# Jump Game II

[Jump Game II On LeetCode](https://oj.leetcode.com/problems/jump-game-ii/)

### c++

```cpp
class Solution {
public:
    int jump(int A[], int n) {
        if(n<=1)return 0;
        queue<pair<int, int>> q;
        q.push(make_pair(0,A[0]));
        q.push(make_pair(-1,-1) );
        int counter = 1;
        while(!q.empty())
        {
            int p = q.front().first;
            int stap = q.front().second;
            q.pop();
            if(p==-1)
            {
                counter++;
                if(!q.empty())
                    q.push(make_pair(-1, -1));
                continue;
            }
            if(p+stap>=n-1)
            {
                return counter;
            }
            for (int i = p+stap ; i > p ; i--) {
                if(A[i]!=-1)
                {
                    q.push( make_pair(i,A[i]));
                    A[i]=-1;
                }
                else
                {
                    break;
                }
            }
        }
        return -1;
    }
};
```