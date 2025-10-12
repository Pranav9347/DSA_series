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

    // choose head
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

    // merge remaining nodes
    // create new_node to track the last node of merged list
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

int main()
{
    ListNode* list1 = nullptr, *list2 = nullptr;
    // Creating first sorted linked list
    list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    // Creating second sorted linked list
    list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    // Merging the two sorted linked lists
    ListNode* temp = mergeTwoLists(list1, list2);
    while(temp!= nullptr)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return 0;
}
