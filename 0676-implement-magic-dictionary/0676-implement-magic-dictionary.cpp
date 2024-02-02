class Node{
public:
    char data;
    unordered_map<char, Node*> mp;
    bool isTerminal;
    Node(char d){
        data = d;
        isTerminal = false;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node* temp = root;
        for (auto ch : word) {
            if (temp->mp.count(ch) == 0) {
                Node* n = new Node(ch);
                temp->mp[ch] = n;
            }
            temp = temp->mp[ch];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for (auto ch : word) {
            if (temp->mp.count(ch) == 0) return false;
            temp = temp->mp[ch];
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for (auto ch : prefix) {
            if (temp->mp.count(ch) == 0) return false;
            temp = temp->mp[ch];
        }
        return true;
    }
};

class MagicDictionary {
private:
    Trie trie;
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for (const auto& word : dictionary) {
            trie.insert(word);
        }
    }
    
    bool search(string searchWord) {
        for (int i = 0; i < searchWord.length(); ++i) {
            char original = searchWord[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == original) continue;
                searchWord[i] = c;
                if (trie.search(searchWord)) return true;
            }
            searchWord[i] = original;
        }
        return false;
    }
};
