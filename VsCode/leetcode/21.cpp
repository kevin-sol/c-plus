#include<iostream>
using namespace std;


/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * head=new ListNode;
        ListNode *p1=list1,*p2=list2,*p=head;
        while (p1!=NULL&&p2!=NULL)
        {
            if (p1->val<p2->val)
            {
                p->next=p1;
                p=p->next;
                p1=p1->next;
            }
            else
            {
                p->next=p2;
                p=p->next;
                p2=p2->next;
            }
        }
        if (p1==NULL)
        {
            while (p2!=NULL)
            {
                p->next=p2;
                p2=p2->next;
                p=p->next;
            }
        }
        else
        {
            while (p1!=NULL)
            {
                p->next=p1;
                p1=p1->next;
                p=p->next;
            }
        }
        head=head->next;
        return head;
    }
};