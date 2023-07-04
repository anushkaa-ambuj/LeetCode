// Time Complexity: O(N^2)
// Space Complexity: O(1)

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
      if (head == NULL || head -> next == NULL) return head;

      // Iterate to count the num of nodes
      int len = 0;
      ListNode * temp = head;
      while (temp != NULL) {
        len++;
        temp = temp -> next;
      }

      // Find the mid value & Iterate over mid value to obtain the node
      int mid = len / 2;
      temp = head;
      while (mid--) {
        temp = temp -> next;
      }
      return temp;
    };
