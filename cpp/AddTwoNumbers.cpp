// This Solution is Just For Fun
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