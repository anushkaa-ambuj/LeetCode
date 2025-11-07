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

        ListNode* fast = head;
        ListNode* slow = head;

        // Traverse the fast pointer
        for (int i=0;i<n;i++){
            fast = fast->next;
        }

        // if target node is head
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Identify the prev node of the target node
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        // Delete target node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};