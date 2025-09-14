typedef struct TrieNode {
    bool has_child;
    unordered_map<char, TrieNode*> children;
    bool word_end;
} trie;

class Solution {
public:
    void add(trie *root, string s) {
        if(s.size() == 0) {
            root->word_end = true;
            return;
        }
        root->has_child = true;
        if(!(root->children).contains(s[0])) {
            root->children[s[0]] = new trie();
        }
        add(root->children[s[0]], s.substr(1, s.size()));
    }

    string longestCommonPrefix(vector<string>& strs) {
        trie *root = new trie();
        for(string s: strs) {
            add(root, s);
        }

        int res = 0;
        while((root->children).size() == 1 && root->has_child && !root->word_end) {
            root = root->children[strs[0][res]];
            res += 1;
        }
        return strs[0].substr(0, res);
    }
};
