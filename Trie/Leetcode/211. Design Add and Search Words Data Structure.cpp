class WordDictionary {
public:
    class trie {
        public:
        trie *next[30];
        bool endmark;
        trie() {
            for (int i = 1; i <= 26; i++) {
                next[i] = NULL;
            }
            endmark = false;
        }
    };

    trie *root = new trie();

    WordDictionary() {
        
    }
    
    void addWord(string word) {
        int n = word.size();
        trie *curr = root;
        for (int i = 0; i < n; i++) {
            int id = word[i] - 'a' + 1;
            if (curr->next[id] == NULL) {
                curr->next[id] = new trie();
            }
            curr = curr->next[id];
        }
        curr->endmark = true;
    }

    bool solve(int idx, int n, string &s, trie *curr) {
        if (curr == NULL) return false;
        if (idx >= n) {
            return curr->endmark;
        }
        bool ok = false;
        if (s[idx] == '.') {
            for (int i = 1; i <= 26; i++) {
                ok |= solve(idx + 1, n, s, curr->next[i]);
            }
        }
        else {
            int id = s[idx] - 'a' + 1;
            ok |= solve(idx + 1, n, s, curr->next[id]);
        }
        return ok;
    }
    
    bool search(string word) {
        return solve(0, word.size(), word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
