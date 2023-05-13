#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* solve(ListNode* list1, ListNode* list2)
    {
        //This is the case where only one Node is there in the list1 
        if(list1->next==NULL)
        {
            list1->next = list2;
            return list1;
        }
        ListNode* temp = list2;
        ListNode* prev = list1;
        ListNode* curr = list1->next;
        while(temp!=NULL && curr!=NULL)
        {
            if( (prev->val <= temp->val) && (temp->val <= curr->val))
            {
                //Inserting the var node betweem previous and curr node
                ListNode* var = temp;
                temp = temp->next;
                prev->next = var;
                var->next = curr;
                prev = var;
            }
            else{
                //Move the pointers
                prev = curr;
                curr = curr->next;
                if(curr==NULL)
                {
                    //Just to check if node is complete or not
                    prev->next = temp;
                    return list1;
                }
            }
        }
        return list1;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = NULL;
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        if(list1->val < list2->val)
        {
            list3 = solve(list1,list2);
        }
        else{
            list3 = solve(list2,list1);
        }
        return list3;
    }      
};