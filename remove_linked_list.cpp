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
		ListNode *new_head;
		new_head = removeNode(head, val);
		return new_head;
	}
	ListNode *removeNode(ListNode *ptr, int val)
	{
		if (ptr->next == nullptr)
		{
			printf("ptr->val = %i\n", ptr->val);
			return ptr;
		}
		// else{

		return removeNode(ptr->next, val);

		//}
	}
};