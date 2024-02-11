class Solution{
public:
    ListNode* delete(ListNode* node){
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};