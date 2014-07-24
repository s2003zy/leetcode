class Solution {
private:
    vector<ListNode*> list;
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if( head == nullptr) return nullptr;
        list.clear();
        ListNode *p = head;
        while (p) {
            list.push_back(p);
            p = p->next;
        }
        return toBTS(0, list.size()-1);
    }
    TreeNode *toBTS(int start,int end)
    {
        if(start>end)return nullptr;
        if(start==end) return new TreeNode(list[start]->val);
        int mid = (start+end)>>1;
        TreeNode* p = new TreeNode(list[mid]->val);
        p->left = toBTS(start, mid-1);
        p->right = toBTS(mid+1, end);
        return p;
        
    }
};
