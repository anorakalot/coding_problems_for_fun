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
	ListNode *swapPairs(ListNode *head)
	{
		int when_to_swap_val = 1;
		ListNode *return_val;
		if (head == NULL)
		{				 // if no val in head
			return head; // works for empty linked list in test case 2
		}
		// don't actually need head != NULL in below if
		// statement since I believe it already checks it above
		if (head != NULL && head->next == nullptr)
		{				 // if head is the only val in the linked list
			return head; // works for only one val linked list in test case 3
		}
		return_val = swapPairs_recur(head, when_to_swap_val);
		return return_val;
	}
	ListNode *swapPairs_recur(ListNode *head, int when_to_swap_val)
	{
		ListNode *swap_node;
		if (head->next == nullptr)
		{
			printf("head->val == %i\n", head->val);
			printf("returning from head->next == nullptr\n\n");
			return head;
		}
		ListNode *return_val_recur;
		when_to_swap_val += 1;
		return_val_recur = swapPairs_recur(head->next, when_to_swap_val);
		printf("when_to_swap_val == %i\n", when_to_swap_val);
		printf("head->val == %i\n", head->val);
		printf("return_val_recur->val == %i\n", return_val_recur->val);
		if (when_to_swap_val % 2 == 0)
		{ // meaning it's even
			printf("doing swap!!!!\n");
			swap_node = return_val_recur->next;
			return_val_recur->next = head;
			head->next = swap_node;
		}
		printf("\n");

		// return return_val_recur;
		return head;
	}
};