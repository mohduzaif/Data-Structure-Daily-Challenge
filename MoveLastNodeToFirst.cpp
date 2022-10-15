ListNode *moveToFront(ListNode *head){
        
    if(!head || !head->next)   return head; 
    
    ListNode* lastNode = head;
    ListNode* currNode = head;
    
    while(currNode && currNode->next) {
        if(!currNode->next->next) {
            lastNode = currNode->next;
            currNode->next = NULL;
            break;
        }
        currNode = currNode->next;
    }
    lastNode->next = head;
    
    return lastNode;
    
}