class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *turtoise=head;
        ListNode *hare=head;
        while(hare!=NULL and hare->next!=NULL){
            turtoise=turtoise->next;
            hare=hare->next->next;
            if(turtoise==hare){
                return true;
            }
        }
        return false;
    }
};
