/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::subtract(ListNode* A) 
{
    ListNode *head = A;
    int len = 1;
    while(head->next)
    {
        ++len;
        head = head->next;
    }
    
    if(len == 1)
    {
        return A;
    }

    int i = 1;
    head = A->next;
    ListNode *prev = A;
    prev->next = nullptr;
    while(i < len / 2)
    {
        ListNode *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
        ++i;
    }

    ListNode *center = prev;
    ListNode *center_next = head;

    if(len % 2)
    {
        head = head->next;
    }

    do
    {
        prev->val = head->val - prev->val;
        head = head->next;
        prev = prev->next;
    } while(head);

    head = center->next;
    prev = center;
    prev->next = center_next;
    while(head)
    {
        ListNode *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }

    return prev;
}

