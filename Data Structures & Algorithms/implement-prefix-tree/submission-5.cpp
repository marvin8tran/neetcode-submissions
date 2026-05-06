class TrieNode{
public:
    bool isEnd = false;
    unordered_map<char, TrieNode*> child;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->child.count(c)){
                curr->child[c] = new TrieNode();
            }
            curr = curr->child[c];
        }
        curr->isEnd = true;
        return;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->child.count(c)){
                return false;
            }
            curr = curr->child[c];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix){
            if(!curr->child.count(c)){
                return false;
            }
            curr = curr->child[c];
        }
        return true;
    }
};
