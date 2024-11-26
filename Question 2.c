 struct ListNode {
   int val;
    struct ListNode *next;
  };
 
 struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* r,* q;
    r=(struct ListNode*)malloc(sizeof(struct ListNode*));
    q=(struct ListNode*)malloc(sizeof(struct ListNode*));
    r=NULL;
    q=NULL;
    while(head!=NULL){
        r=q;
        q=head;
        head=head->next;
        q->next=r;
    }
    return q;
}
bool isPalindrome(struct ListNode* head) {
   int c=0;
   if(head==NULL)
   return true;
   struct ListNode *p=head;
   while(p!=NULL){
       p=p->next;
       c++;
   } 
   if(c%2==0)
   c=c/2;
   else
   c=c/2+1;
   p=head;
   while(c!=0){
       p=p->next;
c--;
   }
   struct ListNode * q=head;
  p=reverseList(p);
  while(p!=NULL){
      if(p->val!=q->val)
      return false;
      else{
          q=q->next;
          p=p->next;
      }
  }
  return true;
}
