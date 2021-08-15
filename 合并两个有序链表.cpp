/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        rerturn l1;
    if(l1->val<=l2->val)
    {
        l1->next=mergeTowLists(l1->next,l2);
        return l1;
    }
    l2->next=mergeTowLists(l1,l2->next);
    return l2;

}
