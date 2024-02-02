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
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for (const auto& str : strs) {
            trie.insert(str);
        }
        string prefix;
        Node* temp = trie.root;
        // temp->mp.size() == 1: This condition checks if the current node temp has exactly one child node. If it has more than one child or no child nodes, the loop will exit because we can't continue the common prefix.
        while (temp->mp.size() == 1 && !temp->isTerminal) {
            auto it = temp->mp.begin();
            prefix += it->first;//character joined through chaining
            temp = temp->mp.begin()->second;//moved to next node after adding to resultant prefix 
            //temp = it->second;//another way of writing above line
        }
        return prefix;
    }
};
