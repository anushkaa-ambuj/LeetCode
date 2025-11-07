/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;

        // Step 1: Find length
        ListNode* temp = head;
        int len = 0;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        // Step 2: If deleting the head node
        if (n == len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Step 3: Move to node before the one to delete
        int stop = len - n - 1;
        temp = head;
        for (int i = 0; i < stop; i++) {
            temp = temp->next;
        }

        // Step 4: Delete target node
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};
