class Node {
public:
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;
    
    Node(char d) {
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
            if (temp->m.count(ch) == 0) {
                Node* n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word) {
        Node* temp = root;
        for (auto ch : word) {
            if (temp->m.count(ch) == 0) return false;
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }

    bool startsWith(string prefix) {
        Node* temp = root;
        for (auto ch : prefix) {
            if (temp->m.count(ch) == 0) return false;
            temp = temp->m[ch];
        }
        return true;
    }
};