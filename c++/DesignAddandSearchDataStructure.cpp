class WordDictionary {
public:

    typedef struct TrieNode{
        char val;
        bool isEnd;
        TrieNode* neighbours [26];
    } TrieNode;

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* trav = root;
        for(auto &chr : word)
            {
                if(trav -> neighbours[chr - 'a']) //node alr exists
                    trav = trav -> neighbours[chr - 'a'];
                else{ //make new node if not found
                    TrieNode* newNode = new TrieNode();
                    newNode -> val = chr;
                    newNode -> isEnd = false;
                    trav -> neighbours[chr - 'a'] = newNode;
                    trav = newNode; 
                }
            }
        trav -> isEnd = true; //set as the end of a current word
    }
     bool dfs(int i,TrieNode* currNode,string word){

        if(i == word.size())
            return currNode -> isEnd;
        if(!currNode)
            return false;
        bool ans = false;
        if(word[i] == '.')
        {
            for(int x =0;x < 26;++x) 
                    {if(currNode -> neighbours[x])
                        ans |= dfs(i + 1,currNode ->  neighbours[x],word);
                    if(ans)
                        return true;
                    }
            return false;
        }
        else if(!currNode -> neighbours[word[i] - 'a'])
            return false;
        else
            ans |= dfs(i + 1, currNode -> neighbours[word[i] - 'a'],word);
        return ans;
    };
    bool search(string word) {
        TrieNode* trav = root;
        return dfs(0,trav,word);
        };
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
