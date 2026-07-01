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
   int length(ListNode* head){
     int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
   } 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int len=length(head);
      
       if(len==n) return head->next;

       ListNode* temp=head;
       int i=1;
       int a=len-n;
       while(i<a){
        temp=temp->next;
        i++;
       }
       temp->next=temp->next->next;
       return head;
    }
};