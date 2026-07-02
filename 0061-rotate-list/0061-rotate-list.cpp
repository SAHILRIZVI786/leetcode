class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        
        ListNode* temp = head;
        int size = 1;
        while (temp->next) {
            temp = temp->next;
            size++;
        }

        
        temp->next = head;

        k = k % size;
        int stepsToNewHead = size - k;

        // Step 4: Find new tail and break the circle
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
