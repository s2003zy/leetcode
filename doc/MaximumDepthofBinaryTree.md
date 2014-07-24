# Maximum Depth of Binary Tree

[Maximum Depth of Binary Tree On LeetCode](https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/)

### c++

```cpp
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root==nullptr)
            return 0;
        return max(maxDepth(root.left),maxDepth(root.right))+1;
    }
};
```

### python

```python
class Solution:
    def maxDepth(self, root):
        if root==None:
            return 0
        return max( self.maxDepth(root.left), self.maxDepth(root.right))+1;
```