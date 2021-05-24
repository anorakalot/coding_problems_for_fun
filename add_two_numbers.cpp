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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int prev_val;
        ListNode* add_two_numbers_node = new ListNode;
        //add_two_numbers_node->val = malloc(4*sizeof(int));
        //add_two_numbers_node 
        add_two_numbers_node->val = l1->val + l2->val;
        cout << add_two_numbers_node->val;
        
        return add_two_numbers_node;
    }
};