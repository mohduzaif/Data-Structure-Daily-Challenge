int length(ListNode* head) {
    int len = 0;
    while(head) {
        head = head->next;
        ++len;
    }
    return len;
}
ListNode* deleteMiddle(ListNode* head) {
    int n = length(head);
    
    if(n == 1) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    int middle = n / 2;
    
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(middle and curr) {
        prev = curr;
        curr = curr->next;
        --middle;
    }
    
    prev->next = curr->next;
    delete curr;
    
    return head;        
}