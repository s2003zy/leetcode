# Convert Sorted List to Binary Search Tree

[Convert Sorted List to Binary Search Tree On LeetCode](https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

### c++
```cpp
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
```

### python
```python
class Solution:
    # @param head, a list node
    # @return a tree node
    def sortedListToBST(self, head):
        if head == None: return None
        fast = head
        low = head
        pre = low
        while fast!=None and fast.next!=None :
            fast = fast.next.next
            pre = low
            low = low.next
        pre.next = None
        node = TreeNode(low.val)
        if head != low:
            node.left = self.sortedListToBST(head)
        pre = low.next
        low.next =None
        node.right = self.sortedListToBST(pre)
        return node
        
```