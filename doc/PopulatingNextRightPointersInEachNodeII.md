#Populating Next Right Pointers in Each Node II

[Populating Next Right Pointers in Each Node II On LeetCode](https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

###c++

```cpp
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        if(root==NULL) return;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeLinkNode * p = q.front();
            q.pop();
            p->next = q.front();
            if(p->left!=NULL)
                q.push(p->left);
            if(p->right!=NULL)
                q.push(p->right);
            if(q.front()==NULL)
            {
                q.push(NULL);
                while (!q.empty()&&q.front()==NULL) {
                    q.pop();
                }

            }
        }
    }
};
    

```