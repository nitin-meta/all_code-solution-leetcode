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

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (const auto& word : words) {
            trie.insert(word);
        }
        string longest = "";
        for (const auto& word : words) {
            bool valid = true;
            string prefix = "";
            for (auto ch : word) {
                prefix += ch;
                if (!trie.search(prefix)) {
                    valid = false;
                    break;
                }
            }
            if (valid && (word.length() > longest.length() || (word.length() == longest.length() && word < longest))) {
                longest = word;
            }
        }
        return longest;
    }
};
