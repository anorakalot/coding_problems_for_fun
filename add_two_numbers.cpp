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
        int remainder = -1;
        
        ListNode* add_two_numbers_node = new ListNode;
        cout << "top of addtwonumbers function" << endl;
        //add_two_numbers_node->val = malloc(4*sizeof(int));
        //add_two_numbers_node 
        if (l1->val == NULL){
            cout << "l1->val == null" << endl;
            l1->val = 0;
        }
        else if (l2->val == NULL){
            cout << "l2->val == null, ser val to 0" << endl;
            l2->val = 0;
        }
        cout <<"l1->val: " << l1->val << "\n";
        cout <<"l2->val: " << l2->val << "\n";
        add_two_numbers_node->val = l1->val + l2->val;
        cout << "add_two_numbers_node->val: " << add_two_numbers_node->val << "\n";
        
        if (add_two_numbers_node->val >= 10){
            cout << "add_two_numbers_node->val >= 10" << endl;
            add_two_numbers_node->val -= 10;
            remainder = 1;
            cout << "new add_two_numbers_node->val after -= 10: " << add_two_numbers_node->val << endl;
        }
        if (l1->next != NULL){
           cout << "There is another node in l1->next!" << endl;
           if(remainder != -1){
               cout << "there is a remainder value" << endl;
               cout << "remainder: " << remainder  << endl;
               
               cout << "l1 val->next: " << l1->next->val << endl;
               
               l1->next->val += remainder;
               cout <<"\n"<< "l1 val->next( after adding remainder ): " << l1->next->val << endl;
           }
           add_two_numbers_node->next = addTwoNumbers(l1->next,l2->next);    
        }
        //else{ //if (l1->next == NULL){
        cout << "add_two_numbers_node val before return " << add_two_numbers_node->val<< endl;
        return add_two_numbers_node;
    }
};