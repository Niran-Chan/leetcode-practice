class Trie {
public:
    typedef struct TrieNode{
        char val;
        bool isWord;
        TrieNode* neighbours[26];
    } TrieNode;
    TrieNode* root;
    Trie() { //constructor
        this -> root = new TrieNode();
    }



    void insert(string word) {

        TrieNode* node = root;
        int i =0;
        while(i < word.size()){
           
                if(node -> neighbours[word[i] - 'a'])
                    {
                        node = node -> neighbours[word[i] - 'a'];
                        i++;
                    }
                else 
                    break;
        }
            if(i < word.size()) //incomplete 
                {
                for(;i < word.size();++i)
                    {
                    TrieNode* newNode = new TrieNode();
                    newNode ->  val = word[i];
                    newNode -> isWord = (i == word.size() -1 ? true : false);
                    node -> neighbours[word[i] - 'a'] = newNode;
                    node = newNode;
                    }
                }
            else
                node -> isWord = true;
                
        }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int i =0;i< word.size();++i){
            if(node -> neighbours[word[i] - 'a'])
                node = node -> neighbours[word[i] - 'a'];
            else return false;
        }
        return node ->isWord;

    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto &a : prefix){
            if(node && node -> neighbours[a - 'a'])
                node = node -> neighbours[a - 'a'];
            else
                return false;
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
