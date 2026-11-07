
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        // Find length and last node
        ListNode* temp = head;
        int len = 1;

        while (temp->next != NULL) {
            temp = temp->next;
            len++;
        }

        // Reduce unnecessary rotations
        k = k % len;

        if (k == 0) {
            return head;
        }

        // Make the list circular
        temp->next = head;

        // Find new last node
        int steps = len - k;
        ListNode* newLast = head;

        for (int i = 1; i < steps; i++) {
            newLast = newLast->next;
        }

        // Set new head and break the circle
        ListNode* newHead = newLast->next;
        newLast->next = NULL;

        return newHead;
    }
};
