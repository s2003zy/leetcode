# Validate Binary Search Tree

[Validate Binary Search Tree On LeetCode](https://oj.leetcode.com/problems/validate-binary-search-tree/)

### c++

```cpp
class Solution {
public:
    bool isValid(TreeNode* root,int minNum, int maxNum)
    {
        if(root==nullptr)return true;
        
        return root->val<maxNum &&
               root->val > minNum &&
               isValid(root->left,minNum,root->val) &&
               isValid(root->right, root->val, maxNum);
    }
    bool isValidBST(TreeNode *root) {
        return isValid(root,INT_MIN,INT_MAX);
    }
};
```