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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int size=1;
        while(temp->next!=nullptr){
            temp=temp->next;
            size++;
        }
        if(size==1){
            return nullptr;
        }
       if(size==n){
        head=head->next;
        return head;
       }
        int k=size-n;
        ListNode* current=head;
        while(k>1){
           current=current->next;
           k--;
        }
        ListNode* agla=current->next;
        current->next=agla->next;
        agla->next=nullptr;
        return head;

    }
};