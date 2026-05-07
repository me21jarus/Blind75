class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertEle(string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root,string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        if(word[0] == '.'){
            for(int i=0;i<26;i++){
                if(root->children[i] != NULL){
                    if(searchUtil(root->children[i], word.substr(1))){
                        return true;
                    }
                }
            }
            return false;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] == NULL){
            return false;
        }
        return searchUtil(root->children[index], word.substr(1));
    }
    bool searchEle(string& word){
        return searchUtil(root,word);
    }

};

class WordDictionary {
public:
    Trie* t;
    WordDictionary() {
        t = new Trie();
    }
    
    void addWord(string word) {
        t->insertEle(word);
    }
    
    bool search(string word) {
        return t->searchEle(word);
    }
};
