# Add Two Numbers

[Add Two Numbers On LeetCode](https://leetcode.com/problems/add-two-numbers/?tab=Description)

### c++

```cpp
// This Solution is Just for Fun
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int sum = 0;
        auto addSum = [] -> int(ListNode** list, int &num) { if (*list) num += (*list) -> val, (*list) = (*list) -> next;};
        while (l1 || l2 || sum) {
            addSum(&l1, sum), addSum(&l2, sum);
            p -> next = new ListNode(sum % 10);
            sum /= 10;
            p = p -> next;
        }
        return head -> next;
    }
};
```