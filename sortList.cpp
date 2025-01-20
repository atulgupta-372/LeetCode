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
    ListNode* merge(ListNode* head1,ListNode* head2){
        if(head2==NULL)    return head1;
        if(head1==NULL)    return head2;

        ListNode *ptr1=head1,*ptr2=head2,*head=NULL,*ptr=NULL;

        if(ptr1->val <= ptr2->val){
            head=ptr1;
            ptr1=ptr1->next;
        }
        else{
            head=ptr2;
            ptr2=ptr2->next;
        }
        ptr=head;

        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->val <= ptr2->val){
                ptr->next=ptr1;
                ptr1=ptr1->next;
            }
            else{
                ptr->next=ptr2;
                ptr2=ptr2->next;         
            }
            ptr=ptr->next;
        }

        if(ptr1==NULL) ptr->next=ptr2;
        if(ptr2==NULL)  ptr->next=ptr1;

        return head;
    }


public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)  return head;

        ListNode *fast=head->next,*slow=head,*head2;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        head2=slow->next;
        slow->next=NULL;
        head=sortList(head);
        head2=sortList(head2);
        head=merge(head,head2);
        return head;
    }
};
