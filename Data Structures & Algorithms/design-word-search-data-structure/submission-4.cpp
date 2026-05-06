class TrieNode{
public:
    bool endOfWord;
    unordered_map<char, TrieNode*> children;
};

class WordDictionary {
private:
    TrieNode* root;
    bool dfs(TrieNode* root, string word, int idx){
        if(idx == word.size()){
            return root->endOfWord;
        }
        char c = word[idx];

        if(c == '.'){
            for(auto& [ch, child] : root->children){
                if(dfs(child, word, idx+1)){
                    return true;
                }
            }
            return false;
        }

        if(root->children.find(c) == root->children.end()){
            return false;
        }

        return dfs(root->children[c], word, idx+1);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(curr->children.find(c) == curr->children.end()){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};
