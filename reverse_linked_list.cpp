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
    ListNode* prev_head;
    ListNode* reverseList(ListNode* head) {
        if (head== NULL){
            return head;
        }
        if (head->next == nullptr){
            return head;
        }

        prev_head = reverseList(head->next);
        prev_head->next = head;
        printf("prev_head->val == %i prev_head->next->val == %i\n",prev_head->val,prev_head->next->val);

        //return prev_head;
        return head;//just a placeholder to make sure recursive calls work
    }
};