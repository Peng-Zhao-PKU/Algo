/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        int cnt = 0;
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);
        ListNode *prev1 = dummy1;
        ListNode *prev2 = dummy2;
        
        while (head) {
            if (cnt % 2 == 0) {
                prev1->next = head;
                prev1 = prev1->next;
            } else {
                prev2->next = head;
                prev2 = prev2->next;
            }
            cnt++;
            head = head->next;
        }
        prev2->next = nullptr;
        prev1->next = dummy2->next;
        return dummy1->next;
    }
};