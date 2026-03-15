#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct Node{
    Node *links[26] = {nullptr};

    /* Flag indicating if the node marks the end of a word */
    bool flag = false;

    /* Check if the node contains a specific key (letter) */
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    /* Insert a new node with a specific key (letter) into the Trie */   
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }

    /* Get the node with a specific key (letter) from the Trie */    
    Node* get(char ch) {
        return links[ch-'a'];
    }

    /* Set the current node as the end of a word */
    void setEnd() {
        flag = true;
    }

    /* Check if the 
    current node marks 
    the end of a word */
    bool isEnd() {
        return flag;
    }
};

class Trie {
    private: Node* root;

    public:
        Trie() {
        root = new Node();
        }

        void insert(string word) {
            Node *node = root;
            for (int i = 0; i < word.length(); i++)
            {
                if(!node->containsKey(word[i])) node->put(word[i], new Node());

                // Move to the next node
                node = node->get(word[i]);

            }
            node->setEnd();
        }

        bool search(string word) {
            Node* node = root;
            for (int i = 0; i < word.length(); i++)
            {
                if(!node->containsKey(word[i])) return false;
                node = node->get(word[i]);
            }
            return node->isEnd();
        }
        
        bool startsWith(string prefix) {
            Node *node = root;
            for (int i = 0; i < prefix.length(); i++)
            {
                if(!node->containsKey(prefix[i])) return false;
                node = node->get(prefix[i]);
            }
            return true;
        }
};


//This one is completely based on how leetcode asks questions so yeah it's useful
int main() {

    // Create a Trie object dynamically
    // Equivalent to: Trie trie; (but using heap allocation)
    Trie* trie = new Trie();

    /*
        operations vector represents the sequence of function calls
        that an online judge would make on the Trie.

        Example:
        "insert"      -> trie.insert(...)
        "search"      -> trie.search(...)
        "startsWith"  -> trie.startsWith(...)
    */
    vector<string> operations = {
        "Trie", "insert", "search", "search",
        "startsWith", "insert", "search"
    };

    /*
        arguments vector stores the arguments for each operation.
        - Empty {} means no argument (used for "Trie")
        - {"apple"} means the function gets "apple" as input

        operations[i] and arguments[i] always correspond.
    */
    vector<vector<string>> arguments = {
        {}, {"apple"}, {"apple"}, {"app"},
        {"app"}, {"app"}, {"app"}
    };

    // This vector stores outputs exactly like LeetCode expects
    vector<string> output;

    // Loop through all operations one by one
    for (int i = 0; i < operations.size(); i++) {

        // Constructor call (already executed earlier)
        if (operations[i] == "Trie") {
            output.push_back("null");
        }

        // Insert a word into the Trie
        else if (operations[i] == "insert") {
            trie->insert(arguments[i][0]);
            output.push_back("null");
        }

        // Search for a complete word in the Trie
        else if (operations[i] == "search") {
            bool result = trie->search(arguments[i][0]);

            // Convert boolean result to string for output
            output.push_back(result ? "true" : "false");
        }

        // Check if any word starts with a given prefix
        else if (operations[i] == "startsWith") {
            bool result = trie->startsWith(arguments[i][0]);

            // Convert boolean result to string for output
            output.push_back(result ? "true" : "false");
        }
    }

    // Print all results line by line
    // This matches the expected output format of online judges
    for (string res : output) {
        cout << res << endl;
    }

    // Free the memory allocated for Trie
    delete trie;

    return 0;
}
