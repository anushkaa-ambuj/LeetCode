class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        // Calculate lengths
        int len1 = 0, len2 = 0;
        while (t1 != NULL) { len1++; t1 = t1->next; }
        while (t2 != NULL) { len2++; t2 = t2->next; }

        // Reset pointers
        t1 = headA;
        t2 = headB;

        // Align both lists
        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i++) t1 = t1->next;
        } 
        else {
            for (int i = 0; i < len2 - len1; i++) t2 = t2->next;
        }

        // Traverse together until intersection
        while (t1 != NULL && t2 != NULL) {
            if (t1 == t2) return t1;
            t1 = t1->next;
            t2 = t2->next;
        }

        return NULL;
    }
};