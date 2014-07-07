#Search in Rotated Sorted Array II

[Search in Rotated Sorted Array II On LeetCode](https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/)

###c++

```cpp
class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0 , right = n-1;
        while(left<=right)
        {
            if(A[left]==target||A[right]==target)return true;
            
            if(A[left]==A[right]) {left++,right--;continue;}
            
            int mid = (left+right)>>1;

            if( A[mid] == target )
                return true;
            if( A[left] <= A[mid])
            {
                if(target>=A[left] && target < A[mid])
                    right = mid -1;
                else
                    left = mid + 1;
            }
            else
            {
                if( target > A[mid] && target <= A[right] )
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};

```