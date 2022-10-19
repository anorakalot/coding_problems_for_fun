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
		return new_head;
	}
	ListNode *removeNode(ListNode *ptr, int val)
	{
		// if (ptr->val == 0){
		if (ptr->next == nullptr)
		{
			printf("ptr->val = %i\n", ptr->val);
			printf("meaning at base case \n");
			return ptr;
		}

		// else{
		ListNode *return_node;
		return_node = removeNode(ptr->next, val);
		printf("return_node->val = %i\n", return_node->val);
		printf("ptr->val = %i\n", ptr->val);
		if (ptr->next->val == val)
		{
			// if (return_node->val == val){
			printf("inside ptr->next->val == val\n ");
			// printf("inside return_node->val == val \n");
			printf("ptr->next->val = %i\n", ptr->next->val);
			// return ptr->next;
			ptr->next = ptr->next->next;
			return ptr;
			// return return_node->
		}
		else
		{
			printf("inside else statement\n");

			// return ptr->next;//with this it was 2345
			return ptr;
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