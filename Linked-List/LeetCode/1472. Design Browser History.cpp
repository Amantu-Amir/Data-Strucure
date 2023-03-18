//Doubly
class BrowserHistory {
public:
    class ListNode {
        public:
        ListNode *next, *prev;
        string link;
        ListNode(string str) {
            next = NULL;
            link = str;
        }
    };

    ListNode *root;
    BrowserHistory(string homepage) {
        root = new ListNode(homepage);
        root->prev = NULL;
    }
    
    void visit(string url) {
        root->next = new ListNode(url);
        root->next->prev = root;
        root = root->next;
    }
    
    string back(int steps) {
        while (steps and root->prev != NULL) {
            steps--;
            root = root->prev;
        }
        return root->link;
    }
    
    string forward(int steps) {
        while (steps and root->next != NULL) {
            steps--;
            root = root->next;
        }
        return root->link;
    }
};


//Singly
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

