class BrowserHistory {
public:
    class ListNode {
        public:
        ListNode *next;
        string link;
        ListNode() {
            next = NULL;
        }
    };

    int curr = 1;
    ListNode *root, *currNode;
    BrowserHistory(string homepage) {
        root = new ListNode();
        root->link = homepage;
        currNode = root;
    }
    
    void visit(string url) {
        currNode->next = new ListNode();
        currNode = currNode->next;
        currNode->link = url;
        curr++;
    }
    
    string back(int steps) {
        if (steps >= curr) {
            curr = 1;
            currNode = root;
            return root->link;
        }
        curr = curr - steps;
        currNode = root;
        int now = 1;
        while (now < curr) {
            now++;
            currNode = currNode->next;
        }
        return currNode->link;
    }
    
    string forward(int steps) {
        int now = 0;
        while (steps and currNode->next != NULL) {
            now++;
            currNode = currNode->next;
            steps--;
        }
        curr += now;
        return currNode->link;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
