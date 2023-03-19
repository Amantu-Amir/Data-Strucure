class Trie {
public:
    class trie {
        public:
        trie *next[30];
        bool endmark;
        trie() {
            endmark = false;
            for (int i = 1; i <= 26; i++) {
                next[i] = NULL;
            }
        }
    };

    Trie() {
        
    }

    trie *root = new trie();
    
    void insert(string word) {
        trie *curr = root;
        for (auto i : word) {
            int id = i - 'a' + 1;
            if (curr->next[id] == NULL) {
                curr->next[id] = new trie();
            }
            curr = curr->next[id];
        }
        curr->endmark = true;
    }
    
    bool search(string word) {
        trie *curr = root;
        for (auto i : word) {
            int id = i - 'a' + 1;
            if (curr->next[id] == NULL) {
                return false;
            }
            curr = curr->next[id];
        }
        return curr->endmark;
    }
    
    bool startsWith(string prefix) {
         trie *curr = root;
        for (auto i : prefix) {
            int id = i - 'a' + 1;
            if (curr->next[id] == NULL) {
                return false;
            }
            curr = curr->next[id];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
