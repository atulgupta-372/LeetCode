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
    ListNode* middleNode(ListNode* head) {
        ListNode * ptr=head,*fastptr=head;
        while(fastptr!=NULL && fastptr->next!=NULL){
            ptr=ptr->next;
            fastptr=fastptr->next->next;
        }
        return ptr;
    }
};