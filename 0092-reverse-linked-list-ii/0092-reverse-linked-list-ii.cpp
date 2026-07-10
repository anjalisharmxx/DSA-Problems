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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        // Dummy node to easily handle cases where left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // 1. Reach the node right before the 'left' position
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        // 'curr' will be the first node of the sublist to be reversed
        ListNode* curr = prev->next;
        
        // 2. Reverse the sublist between left and right
        // We look ahead and bring the 'next' node to the front of the sublist one by one
        for (int i = 0; i < right - left; ++i) {
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up memory
        return newHead;
    }
};