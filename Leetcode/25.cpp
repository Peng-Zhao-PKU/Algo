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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        while (head) {
            ListNode *temp = head;
            int current = 0;
            while (head && current < k) {
                current++;
                head = head->next;
            }

            if (current >= k) {
                prev->next = reverse(temp, head);
                temp->next = head;
                prev = temp;
            } else {
                break;
            }
        }
        return dummy->next;
    }
    
    ListNode *reverse(ListNode *head, ListNode *tail) {
        if (head == tail || head->next == tail) {
            return head;
        }
        ListNode *x = head, *y = head->next, *z;
        while (true) {
            z = y->next;
            y->next = x;
            x = y;
            y = z;
            if (y == tail) {
                break;
            }
        }
        head->next = nullptr;
        return x;
    }
};