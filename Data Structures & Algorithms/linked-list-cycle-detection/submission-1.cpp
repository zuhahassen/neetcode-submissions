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
    bool hasCycle(ListNode* head) {
        if (!head) return false; 

        ListNode* fastPointer = head;
        ListNode* slowPointer = head; 

        while (fastPointer && fastPointer->next) {
            fastPointer = fastPointer->next->next;
            slowPointer = slowPointer->next; 

            if (fastPointer == slowPointer) {
                return true; 
            }
        }

        return false; 
    }
};
