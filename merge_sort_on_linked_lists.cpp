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


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head, *new_node;
    if(!list1) return list2;
    if(!list2) return list1;
    if(list1->val<=list2->val)
    {
        head = list1;
        list1=list1->next;
    }
    else
    {
        head = list2;
        list2 = list2->next;
    }
    new_node=head;
    while(list1!=nullptr && list2!=nullptr)
    {
        if(list1->val<=list2->val)
        {
            new_node->next=list1;
            new_node = new_node->next;
            list1=list1->next;
        }
        else
        {
            new_node->next=list2;
            new_node = new_node->next;
            list2=list2->next;
        }
    }
    if(list1) new_node->next = list1;
    else new_node->next = list2;
    return head;
}
ListNode* divide(ListNode* head, int size)
{
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* temp=head;
    int i=0;
    for(i=0;i<size/2-1;i++)
    {   
        temp=temp->next;
    }
    ListNode* head2 = temp->next;
    temp->next=nullptr;
    ListNode* left = divide(head, ++i);
    ListNode* right = divide(head2, size-i);
    return mergeTwoLists(left,right);
}
ListNode* sortList(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* temp = head;
    int n=1;
    while(temp->next != nullptr) 
    {
        temp=temp->next;
        n++;
    }
    return divide(head, n);
}


int main()
{
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head = sortList(head);
    while(head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    return 0;
}