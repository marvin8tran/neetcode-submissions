class TrieNode{
public:
    bool endOfWord;
    vector<TrieNode*> children;
    string fullWord;

    TrieNode() : children(26, nullptr), endOfWord(false){}
};

class Solution {
private:
    TrieNode* root;

    void insert(string word){
        TrieNode* x = root;

        for(char c : word){
            int i = c - 'a';
            if(x->children[i] == nullptr){
                x->children[i] = new TrieNode();
            }
            x = x->children[i];
        }
        x->endOfWord = true;
        x->fullWord = word;
        return;
    }
    

    void dfs(vector<vector<char>>& board, TrieNode* root, vector<string>& res, int x, int y){
        
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()){
            return;
        }

        if(root == nullptr || board[x][y] == '.'){
            return;
        }

        if(root->endOfWord){
            res.push_back(root->fullWord);
            root->endOfWord = false;
        }
        char tmp = board[x][y];
        board[x][y] = '.';

        if(x + 1 < board.size()){
            dfs(board, root->children[board[x+1][y]-'a'], res, x + 1, y);
        }
        if(x - 1 >= 0){
            dfs(board, root->children[board[x-1][y]-'a'], res, x - 1, y);
        }
        if(y + 1 < board[0].size()){
            dfs(board, root->children[board[x][y+1]-'a'], res, x, y+1);
        }
        if(y - 1 >= 0){
            dfs(board, root->children[board[x][y-1]-'a'], res, x, y-1);
        }
        board[x][y] = tmp;

        return;
    
    }

    

public:
    Solution(){
        root = new TrieNode();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        for(string w : words){
            insert(w);
        }


        //search all words at once ngl
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                dfs(board, root->children[board[r][c] - 'a'], res, r, c);
            }
        }
            
    
        return res;
    }
};
