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
        cout <<"\n\n\n"<< "top of addtwonumbers function" << endl;
        //add_two_numbers_node->val = malloc(4*sizeof(int));
        //add_two_numbers_node 

        cout <<"l1->val: " << l1->val << "\n";
        cout <<"l2->val: " << l2->val << "\n";
        add_two_numbers_node->val = l1->val + l2->val;
        cout << "add_two_numbers_node->val: " << add_two_numbers_node->val << "\n";
        
        if (add_two_numbers_node->val >= 10){
            cout << "add_two_numbers_node->val >= 10" << endl;
            add_two_numbers_node->val -= 10;
            // if (add_two_numbers_node->val == 0){
            //     remainder = 0;
            // }
            //else{
            remainder = 1;    
            //}
            cout << "new add_two_numbers_node->val after -= 10: " << add_two_numbers_node->val << endl;
        }
        if (l1->next != nullptr || l2->next != nullptr){
           cout << "There is another node in l1->next || l2->next!" << endl;
//            if(remainder != -1){
//                cout << "there is a remainder value" << endl;
//                cout << "remainder: " << remainder  << endl;
               
//                cout << "l1 next->val: " << l1->next->val << endl;
               
//                l1->next->val += remainder;
//                cout <<"\n"<< "l1 next->val( after adding remainder ): " << l1->next->val << endl;
//            }
            
            if (l1->next == nullptr){
                cout << "l1->next == nullptr" << endl;
                ListNode * fake_node = new ListNode;
                if(remainder != -1){
                   cout << "there is a remainder value" << endl;
                   cout << "remainder: " << remainder  << endl;

                   cout << "l2 next->val: " << l2->next->val << endl;

                   l2->next->val += remainder;
                   cout << "l2 next->val( after adding remainder ): " << l2->next->val << endl;
               }
                add_two_numbers_node->next = addTwoNumbers(fake_node,l2->next);    

                //l1->val = 0;
            }// end of if l1->next == nullptr
            else if (l2->next == nullptr){
                cout << "l2->next == nullptr" << endl;
                ListNode * fake_node = new ListNode;
                if(remainder != -1){
                   cout << "there is a remainder value" << endl;
                   cout << "remainder: " << remainder  << endl;

                   cout << "l1 next->val: " << l1->next->val << endl;

                   l1->next->val += remainder;
                   cout << "l1 val->next( after adding remainder ): " << l1->next->val << endl;
               }
                add_two_numbers_node->next = addTwoNumbers(l1->next,fake_node);    


            }//end of if l2->next == nullptr

            else{ // this is if both are not nullptr so there's next for both
            cout << "both l1 and l2->next are valid" << endl;
            if(remainder != -1){
                   cout << "there is a remainder value" << endl;
                   cout << "remainder: " << remainder  << endl;

                   cout << "l1 next->val: " << l1->next->val << endl;

                   l1->next->val += remainder;
                   cout << "l1 next->val( after adding remainder ): " << l1->next->val << endl;
              }


            add_two_numbers_node->next = addTwoNumbers(l1->next,l2->next);    

            }// end of else 
        
        }// end of l1->next || l2-> next == 1 // any input parameters still have next value
        
        //if there's still a remainder value make one last fake node recursion adding remainder to last value
        else if(remainder !=-1){
            cout << "check for last remainder value after l1->next and l2->next both neg goes off" << endl;
            ListNode * fake_node_1 = new ListNode;
            ListNode * fake_node_2 = new ListNode;
            
            fake_node_1->val = remainder;
            cout <<"setting fake node_1_val to remainder value: " << fake_node_1->val << endl;
            add_two_numbers_node->next = addTwoNumbers(fake_node_1, fake_node_2);
            
        }// end of last remainder check 
        
        //else{ //if (l1->next == NULL){
        cout << "add_two_numbers_node val before return " << add_two_numbers_node->val<< endl;
        return add_two_numbers_node;
    }
};