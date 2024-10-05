class TrieNode{
    public:
    bool is_word = false;
    TrieNode *children[26];
    TrieNode() {
        for(int i=0;i<26;++i){
            children[i]=NULL;
        }
    }
};


class Trie {
public:
    TrieNode *root;
    Trie(){
       root = new TrieNode();
    }

    void insert(string word) {
       TrieNode *curr = root;
       for(int i=0;i<word.size();++i){
        int k=word[i]-'a';
        if(curr->children[k]==NULL){
            curr->children[k] = new TrieNode();
        }
        curr=curr->children[k];
       }
       curr->is_word = true;

    }
    
    bool search(string word) {
        TrieNode *curr=root;
        for(int i=0;i<word.size();++i){
            int k=word[i]-'a';
            curr=curr->children[k];
            if(curr==NULL) return false;
        }
        return curr->is_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr=root;
        for(int i=0;i<prefix.size();++i){
            int k=prefix[i]-'a';
            curr=curr->children[k];
            if(curr==NULL) return false;
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