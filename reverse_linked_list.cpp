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
	ListNode *prev_head;
	ListNode *head_to_return;
	int total_nodes = 0;
	ListNode *reverseList(ListNode *head)
	{
		if (head == NULL)
		{
			head_to_return = head; // because this is the last head;
			return head;
		}
		if (head->next == nullptr)
		{
			head_to_return = head; // because this is the last head;
			return head;
		}
		total_nodes += 1;
		prev_head = reverseList(head->next);

		// head->next = nullptr;
		printf("test_1\n");
		prev_head->next = head;
		printf("head->val == %i\n", head->val);
		printf("total_nodes== %i\n", total_nodes);
		printf("prev_head->val == %i prev_head->next->val == %i\n", prev_head->val, prev_head->next->val);

		total_nodes -= 1;
		// return prev_head;
		printf("total_nodes right before if== %i \n", total_nodes);
		if (total_nodes == 0)
		{
			head->next = nullptr;
			return head_to_return;
		}
		else
		{
			return head; // just a placeholder to make sure recursive calls work
		}
	}
};