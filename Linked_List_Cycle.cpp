#include <iostream>
#include <map>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool> map1;
        ListNode* temp = head;
        while(temp!=NULL && map1[temp]!=true){
            map1[temp] = true;
            temp = temp->next;
        }
        if(temp==NULL){return false;}
        return true;
    }
};
//Solution number two
bool hasCycle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}