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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode merge(0);

        ListNode* curM = &merge; 

        ListNode* cur1 = list1; 
        ListNode* cur2 = list2; 

        while (cur1 && cur2) {
            if (cur1->val > cur2->val) {
                curM->next = cur2; 
                cur2 = cur2->next;
            } else {
                curM->next = cur1; 
                cur1 = cur1->next;
            }

            curM = curM->next;
        }

        while (cur1) {
            curM->next = cur1; 
            cur1 = cur1->next;
            curM = curM->next;
        }

        while (cur2) {
            curM->next = cur2; 
            cur2 = cur2->next;
            curM = curM->next;
        }

        return merge.next; 
    }
};
