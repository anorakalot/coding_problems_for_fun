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
class Solution
{
public:
	ListNode *removeElements(ListNode *head, int val)
	{
		if (head == NULL)
		{
			return 0;
		}
		ListNode *new_head;
		new_head = removeNode(head, val);
		if (new_head->val == val)
		{ // is here for test cases like [7,7,7,7]//copy of previous if below
			// that's commented out
			printf("inside new_head->val == val\n");
			printf("new_head->val == %i", new_head->val);
			new_head = new_head->next;
			// head = new_head->next;
		}
		if (head->val == val)
		{
			printf("inside head->val == val\n");
			printf("head->val == %i ", head->val);
			head = new_head;
		}

		else
		{
			// nothing stays the same
		}

		// if (new_head->val == val){//is here for test cases like [7,7,7,7]
		//     printf("inside new_head->val == val\n");
		//     printf("new_head->val == %i",new_head->val);
		//     new_head = new_head->next;
		// }
		// //if (new_head->val != head->val && head->val != val){
		// else if (new_head->val != head->val){//to handle edge case unvalid val is right next to head
		//     //problem is doesn't actually go into this for [1,2] testcase and I would assume all
		//     //other test cases with head right next to val that needs to be removed
		//     printf("inside new_head->val != head->val");
		//     new_head = head;
		// }

		// return new_head;
		return head;
	}
	ListNode *removeNode(ListNode *ptr, int val)
	{
		// if (ptr->val == 0){
		if (ptr->next == nullptr)
		{
			printf("ptr->val = %i\n", ptr->val);
			printf("meaning at base case \n");
			return ptr;
			// return ptr->next;
		}

		// else{
		ListNode *return_node;
		return_node = removeNode(ptr->next, val);
		if (return_node != nullptr)
		{
			printf("return_node->val = %i\n", return_node->val);
		}
		else
		{
			printf("return_node is null ptr\n");
		}

		printf("ptr->val = %i\n", ptr->val);
		// if (ptr->val == val){
		if (ptr->next->val == val)
		{
			// if (return_node->val == val){
			printf("inside ptr->next->val == val\n ");
			// printf("inside return_node->val == val \n");
			printf("ptr->next->val = %i\n", ptr->next->val);
			// return ptr->next;
			// ptr->next = ptr->next->next;
			ptr->next = return_node->next;
			// return ptr;
			return return_node; // that way keep using return_node if needed
								// not good if  only one other thing
								// return return_node->
		}
		else
		{
			printf("inside else statement\n");

			// return ptr->next;//with this it was 2345
			return ptr; // this gives the valid
						// return ptr is used to be used as next valid return_node point
		}
		//         //return removeNode(ptr->next,val);
		//         if (ptr->val == val){
		//           return removeNode(ptr,val) ;
		//         }
		//         //}
		//         else{

		//         }
	}
};