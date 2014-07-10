class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root==nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> temp;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if( node == nullptr )
            {
                res.push_back(temp);
                temp.clear();
                if(!q.empty()) q.push(nullptr);
            }
            else
            {
                temp.push_back(node->val);
                if( node -> left != nullptr)
                    q.push( node -> left );
                if( node -> right != nullptr)
                    q.push( node -> right);
            }
            
        }
        for (int i = 0 ; i < res.size(); i++) {
            if( i%2 == 1)
            {
                std::reverse(res[i].begin(), res[i].end());
            }
        }
        return res;
    }
};