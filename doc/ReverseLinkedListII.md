# Reverse Linked List II

[Reverse Linked List II On LeetCode](https://oj.leetcode.com/problems/reverse-linked-list-ii/)

### c++

```cpp
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int counter = 0;
        int reverseLength = n - m + 1;
        ListNode *  pre = head;
        while(counter < m -2 )
        {
            pre = pre->next;
            counter++;
        }
        if(m==1)
        {
            pre = new ListNode(0);
            pre->next = head;
        }
        ListNode * p = pre->next;
        ListNode * first = pre->next;
        ListNode * last = pre->next;
        ListNode * pp = pre->next;
        counter = 0;
        while(p!=nullptr&&counter<reverseLength)
        {
            last = p->next;
            p->next = pp;
            pp = p;
            p = last;
            counter++;
        }
        pre->next = pp;
        first->next = p;
        if(m==1)return pre->next;
        return head;
    }
};
```