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
            ListNode* list3;
            ListNode* list3_head;
            list3 = new ListNode;
            list3_head = new ListNode;
            list3_head->next = list3;
        
            // list3->val = list1->val;
            // list3->next = new ListNode;
            // printf("%i ",list3->val);
            // list3 = list3->next;        
            
             printf("%i ",list1->val);
            // list1 = list1->next;
            // printf("%i ",list1->val);
            // list1 = list1->next;
            // printf("%i ",list1->val);

            // printf("%i ",list1->val);
            // list1->next = list1->next;
            // printf("%i ",list1->val);
            // list1 = list1->next;
            // printf("%i ",list1->val);

        int val_1;
        int val_2;
        while (list1->next != nullptr || list2->next != nullptr){
//             if (list1->val != NULL){
//                 val_1 = list1->val;
                
//             }
//             if (list2->val != NULL){
//                 val_2 = list2->val;
                
//             }
                   //for (int x = 0; x < 3; x++){
        //     //if (list1->next == nullptr)
             if (list1->val > list2->val && (list1->val != NULL && list2->val != NULL) ){
                list3->val = list1->val; 
                list3->next = new ListNode;
                printf("%i ",list3->val);
                list3 = list3->next;
                 
                list1 = list1->next;//go to next list1 since using this value already
        //         list3 = 
             }
             else if (list1->val < list2->val){
                list3->val = list1->val;
                list3->next = new ListNode;
                printf("%i ",list3->val);
                list3 = list3->next;
                 
                list2 = list2->next;//go to next list2 since using this value already
             }
             else{//list1->val == list2->val
                list3->val = list1->val;
                list3->next = new ListNode;
                printf("%i ",list3->val);
                list3 = list3->next;    
                
                list1 = list1->next;
                
                list3->val = list2->val;
                list3->next = new ListNode;
                printf("%i ",list3->val); 
                list3 = list3->next;
                
                list2 = list2->next;
             }
         }
        return list3_head->next;
    }
};