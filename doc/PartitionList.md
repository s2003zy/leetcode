#Partition List

[Partition List On Leetcode](https://oj.leetcode.com/problems/partition-list/)

###C++

```cpp
class Solution {
public:
    void addNode(ListNode* &head,ListNode* &back,ListNode* &theNode)
    {
        if( head == NULL )
        {
            head = theNode;
            back = theNode;
            theNode = theNode -> next;
            back->next=NULL;
            return;
        }
        back->next = theNode;
        back = back->next;
        theNode = theNode->next;
        back->next=NULL;
    }
    
    
    ListNode *partition(ListNode *head, int x) {
     
        ListNode* bigger = NULL;
        ListNode* smaller = NULL;
        
        ListNode* bigTemp = NULL;
        ListNode* smallTemp = NULL;
        
        while( head != NULL )
        {
            if( head -> val >= x)
                addNode(bigger, bigTemp, head);
            else
                addNode(smaller, smallTemp, head);
        }
        if( smallTemp != NULL )
            smallTemp -> next = bigger;
        else return bigger;
        return smaller;
    }
};
```
