class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if( head == nullptr )return head;
        int count = 0;
        ListNode* counter = head;
        while(counter!=nullptr)
        {
            count++;
            counter=counter->next;
        }
        k = k%count;
        if( k == 0) return head;
        ListNode * lastOne;
        ListNode * lastTwo;
        lastOne = head;
        lastTwo = head;
        while( k && lastTwo -> next != nullptr)
        {
            k--;
            lastTwo = lastTwo -> next;
        }
        while ( lastTwo -> next != nullptr) {
            lastTwo = lastTwo -> next;
            lastOne = lastOne ->next;
        }
        lastTwo->next = head;
        head = lastOne->next;
        lastOne->next = nullptr;
        return head;
    }
};
