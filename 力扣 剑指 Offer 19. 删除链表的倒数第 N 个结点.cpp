#include <stdio.h>
#include <iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

ListNode *removeNthFromEnd(ListNode* head, int n)
{
    ListNode *fast = new ListNode(0, head);
    ListNode *slow = new ListNode(0, head);
    while (n-- > 0)         fast = fast->next;
    if (fast->next == NULL) head = head->next;
    while (fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}

int main(void)
{

    return 0;
}