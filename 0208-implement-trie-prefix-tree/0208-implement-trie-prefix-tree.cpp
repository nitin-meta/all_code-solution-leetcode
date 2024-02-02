class Node{
public:
    char data;
    unordered_map<char,Node*>mp;
    bool isTerminal;
    Node(char d){
        data=d;
        isTerminal=false;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root=new Node('\0');
    }
    
    void insert(string word) {
        Node* temp=root;
        for(auto ch:word){
            if(temp->mp.count(ch)==0){
                Node *n= new Node(ch);
                temp->mp[ch]=n;
            }
            temp=temp->mp[ch];
        }
        temp->isTerminal=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(auto ch:word){
            if(temp->mp.count(ch)==0) return false;
            temp=temp->mp[ch];
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(auto ch:prefix){
            if(temp->mp.count(ch)==0) return false;
            temp=temp->mp[ch];
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