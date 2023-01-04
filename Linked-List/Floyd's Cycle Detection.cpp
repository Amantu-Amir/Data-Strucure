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






// #include<iostream>
// using namespace std;

// class node {
// public:
//     int id;
//     node *next;
// };

// node *root = NULL, *temp, *currNode;

// void addBack(int n) {
//     if (root == NULL) {
//         root = new node();
//         root -> id = n;
//         root -> next = NULL;
//         return;
//     }
//     currNode = root;
//     while (currNode -> next != NULL) {
//         currNode = currNode -> next;
//     }
//     node *newNode = new node();
//     newNode -> id = n;
//     newNode -> next = NULL;
//     currNode -> next = newNode;
//     if (n == 5) temp = newNode;
// }

// void print() {
//     node *currNode = root;
//     while (currNode != NULL) {
//         cout << currNode -> id << " ";
//         currNode = currNode -> next;
//     }
//     cout << "\n";
// }

// bool isCycle;
// node *floydCycle() {
//     node *hare = root;
//     node *tortoise = root;
//     while (hare -> next != NULL and hare -> next -> next != NULL) {
//         hare = hare -> next -> next;
//         tortoise = tortoise -> next;
//         if (hare == tortoise) {
//             isCycle = true;
//             break;
//         }
//     }
//     if (!isCycle) return NULL;
//     node *currNode = root;
//     while (currNode != tortoise) {
//         currNode = currNode -> next;
//         tortoise = tortoise -> next;
//     }
//     return tortoise;
// }


// int main() {
    
//     addBack(2);
//     addBack(3);
//     addBack(5);
//     addBack(7);
//     addBack(10);

//     currNode -> next = temp;

//     node *res = floydCycle();
//     if (!isCycle) cout << "No cycle is found\n";
//     else {
//         cout << "Cycle has with node " << res -> id << "\n";
//     }

//     return 0;
// }



