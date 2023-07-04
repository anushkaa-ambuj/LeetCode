// Time Complexity = O(n/2)
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
    ListNode* middleNode(ListNode* head) {
        // If there is only one node in the linked list
        if (head == NULL || head -> next == NULL) 
            return head;
        
        // Assign 2 pointers: fast & slow
        // Note: The below code returns the second value in case of even nodes. (As given in Ques)
        // To return the first mid-value in case of even nodes. Either (i)Store the first mid-node [better] or (ii)Iterate till the 2nd last node only.
        ListNode * slow = head;
        ListNode * fast = head;
        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};
