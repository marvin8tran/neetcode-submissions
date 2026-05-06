class TrieNode{
    public:
        bool endOfWord = false;
        unordered_map<char, TrieNode*> children;
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
            //char doesn't exist
            if(curr->children.count(c) == 0){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(curr->children.count(c) == 0){
                return false;
            }
            curr = curr->children[c];
        }
        return curr->endOfWord;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix){
            if(curr->children.count(c) == 0){
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};
