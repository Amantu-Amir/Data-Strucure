
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        int cnt = 0;
        ListNode *currNode = head, *start = NULL, *end = NULL, *L;
        while (currNode->next != NULL) {
            cnt++;
            if (cnt == left) {
                ListNode *prev = currNode, *temp;
                L = currNode;
                currNode = currNode->next;
                cnt++;
                while (cnt != right) {
                    temp = currNode;
                    currNode = currNode->next;
                    temp->next = prev;
                    prev = temp;
                    cnt++;
                }
                end = currNode->next;
                currNode->next = prev;
                break;
            }
            start = currNode;
            currNode = currNode->next;
        }
        if (start == NULL) {
            head = currNode;
        }
        else {
            start->next = currNode;
        }
        L->next = end;
        return head;
    }
};



