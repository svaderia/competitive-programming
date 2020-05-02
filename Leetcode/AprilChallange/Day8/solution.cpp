/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size = 1;
        ListNode* mid = head;
        ListNode* curr = head;
        while(curr -> next != NULL){
            curr = curr -> next;
            size++;
            if(size % 2 == 0){
                mid = mid -> next;
            }
        }
        return mid;
    }
};