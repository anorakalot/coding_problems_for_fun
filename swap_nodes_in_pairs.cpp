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
		int swap_val = 1;
		ListNode *return_val;
		return_val = swapPairs_recur(head, swap_val);
		return return_val;
	}
	ListNode *swapPairs_recur(ListNode *head, int swap_val)
	{
		if (head->next == nullptr)
		{
			return head;
		}
		ListNode *return_val_recur;
		swap_val += 1;
		return_val_recur = swapPairs_recur(head->next, swap_val);
		return return_val_recur;
	}
};