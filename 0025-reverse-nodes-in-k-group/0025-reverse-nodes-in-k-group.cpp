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
 ListNode* reverse(ListNode* head) {

    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* nextNode = curr->next; // Store next node
        curr->next = prev;               // Reverse link
        prev = curr;                     // Move prev forward
        curr = nextNode;                 // Move curr forward
    }

    return prev; // New head
}

 ListNode* knod(ListNode* temp,int k){
    k-=1;
    while(temp!=nullptr && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
 }
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* nextnode=nullptr;
        ListNode* prevnode=nullptr;
        ListNode* temp=head;
        while(temp!=nullptr){
            ListNode* knode=knod(temp,k);
            if(knode==nullptr){
                if(prevnode){
                    prevnode->next=temp;
                }
                break;
            }
            nextnode=knode->next;
            knode->next=nullptr;
            reverse(temp);
            if(temp==head){
                head=knode;
            }
            else{
                prevnode->next=knode;
            }
            prevnode=temp;
            temp=nextnode;
        }
        return head;
    }
};