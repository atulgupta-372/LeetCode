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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* preptr=NULL,*ptr=head,*temp;
        while(ptr!=NULL){
            temp=ptr->next;
            ptr->next=preptr;
            preptr=ptr;
            ptr=temp;
        }
        return preptr;
    }
};