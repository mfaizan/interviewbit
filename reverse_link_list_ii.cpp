/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *tn = new ListNode{ 0 };
	tn->next = A;
	A = tn;

	ListNode *m = tn;
	ListNode *prev_m = nullptr;
	int i = 0;

	while (i < B)
	{
		++i;
		prev_m = m;
		m = m->next;
	}

	ListNode *n = m;
	ListNode *next_n = n->next;
	while (i < C)
	{
		++i;
		n = n->next;
		next_n = next_n->next;
	}

	if (prev_m)
	{
		prev_m->next = n;
	}

	ListNode *x = m;
	ListNode *next_x = m->next;

	m->next = n->next;

	while (x != n)
	{
		ListNode *temp = next_x->next;

		next_x->next = x;

		x = next_x;
		next_x = temp;
	}

	return tn->next;
}

