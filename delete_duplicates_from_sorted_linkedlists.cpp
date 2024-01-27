class solution{
    public:
    ListNode* removeDuplicates(ListNode* head){
        while(node!=nullptr && node->next != nullptr){
            if(node->val == noe->next->val){
                ListNode* temp = node->next;
                node->next = node->next->next;
                delete temp;
            }else
            {
                node = node->next;
            }
        }
        return head;s
    }
};