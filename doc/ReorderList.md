#Reorder List
[Reorder List On
LeetCode](https://oj.leetcode.com/problems/reorder-list/)

###c++

```cpp
class Solution {
public:
    ListNode* reverse(ListNode* list)
    {
        ListNode * pre = nullptr;
        ListNode * cur = list;
        ListNode * next = nullptr;
        
        while (cur!=nullptr) {
            next = cur->next;            
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    
    ListNode* merge(ListNode* a,ListNode* b)
    {
        ListNode * res = nullptr;
        ListNode * t = nullptr;
        while (a!=nullptr&&b!=nullptr) {
            if( res == nullptr)
            {
                res = a;
                a = a->next;
                res->next = b;
                t = b;
                b = b->next;
                continue;
            }
            t->next = a;
            a=a->next;
            t = t->next;
            t->next = b;
            b=b->next;
            t=t->next;
        }
        while(a!=nullptr)
        {
            t->next = a;
            a=a->next;
            t= t->next;
        }
        while(b!=nullptr)
        {
            t->next = b;
            b = b->next;
            t= t->next;
        }
        return res;
    }
    
    void splite(ListNode* head,ListNode* &one,ListNode* &two)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        one = head;
        two = slow->next;
        slow->next = nullptr;
    }
    void reorderList(ListNode *head) {
        if(head==nullptr||head->next==nullptr) return;
        if(head->next->next==nullptr) return;
        ListNode* one = nullptr;
        ListNode* two = nullptr;
        splite(head, one, two);
        two = reverse(two);
        head = merge(one, two);
    }
};

```
