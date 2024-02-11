class Solution{
    public:
    ListNode* reverse(ListNode* head){
        listNode* prev = NULL;
        listNode* curr = head;
        listNode* next = NULL;
    

    while(curr){
        next=curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }return prev;
}
    ListNode* reorder(ListNode* head){
        ListNode* fast_pointer = head->next;
        ListNode* slow_pointer = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //reversing the second half and splitting it into two
            ListNode* second = reverse(slow->next); //slow here represents the 
            //last node of the first linkedlist.

            slow->next = NULL;
            ListNode* first = head;

            //merging the two ll
            while(second){
                ListNode* temp1= first->next;
                ListNode* temp2 = second->next;
                  first->next = second;
                  second->next = temp1;
                  first=temp1; //repeating the same with the latest nodes.
                  second=temp2;
            }
    }
};