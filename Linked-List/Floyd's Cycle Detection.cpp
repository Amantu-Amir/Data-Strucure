class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *turtoise=head;
        ListNode *hare=head;
        bool cycle=false;
        while(hare!=NULL and hare->next!=NULL){
            turtoise=turtoise->next;
            hare=hare->next->next;
            if(turtoise==hare){
                cycle=true;
                break;
            }
        }
        if(cycle==false){
            return NULL;
        }
        while(head!=NULL){
            if(head==turtoise){
                return turtoise;
            }
            head=head->next;
            turtoise=turtoise->next;
        }
        return NULL;
    }
};


