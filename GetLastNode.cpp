int getNthFromLast(Node *head, int n) {
       // Your code here
       Node *curr=head;
       Node *save=head; 
       while(curr){
           if(n){
               curr=curr->next;
               n--;
           }else{
               save=save->next;
               curr=curr->next;
           }
       }
       if(n) return -1;
       return save->data;
}