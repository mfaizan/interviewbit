/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) 
{
	ListNode *a = A;
	ListNode *b = B;
	int carry = 0;

	ListNode *head = nullptr;
	ListNode *last = nullptr;

	ListNode *last_zero_parent = nullptr;

	while (a || b || carry)
	{
		int x = a ? a->val : 0;
		int y = b ? b->val : 0;

		int z = x + y + carry;
		carry = z / 10;
		z = z % 10;

		ListNode *n = new ListNode{ z };
		if (last)
		{
			last->next = n;
		}
		else
		{
			head = n;
		}

		if (!z && !last_zero_parent)
		{
			last_zero_parent = last;
		}

		if (z)
		{
			last_zero_parent = nullptr;
		}

		last = n;

		if (a)
		{
			a = a->next;
		}

		if (b)
		{
			b = b->next;
		}
	}

	if (last_zero_parent)
	{
		last_zero_parent->next = nullptr;
	}

	return head;
}

