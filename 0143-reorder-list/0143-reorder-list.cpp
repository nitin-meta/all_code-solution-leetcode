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
    ListNode* curr;
    void reO(ListNode* head){
        if(head==nullptr) return;
        reO(head->next);
        if(curr==head){
            head->next=nullptr;
            return;
        }
        else if(curr->next==nullptr) return;
        ListNode* temp=curr->next;
        curr->next=head;
        head->next=(temp==head)?nullptr:temp;
        curr=temp;
    }
    void reorderList(ListNode* head) {
        if(!head) return;
        curr=head;
        reO(head);
    }
};