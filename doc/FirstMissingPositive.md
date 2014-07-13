# First Missing Positive

[First Missing Positive On LeetCode](https://oj.leetcode.com/problems/first-missing-positive/)

### c++

```cpp
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int temp = 0;
        for (int i = 0; i < n ; i++ ) {
            if( A[i] > 0 && A[i] != i+1 && A[i]<=n && A[ A[i]-1 ] != A[i] )
            {
                temp = A[ A[i]-1 ];
                A[ A[i] -1 ] = A[i];
                A[i] = temp;
                i--;
            }
        }
        for (int i = 0 ; i < n; i++) {
            if(A[i]!=i+1)return i+1;
        }
        return n+1;
    }
};
```
