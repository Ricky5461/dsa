#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    struct node {
        char c;
        int ends;
        node* child[26];
        string word;
    };

    node* getNode(char c) {
        node* newNode = new node;
        newNode->c = c;
        newNode->ends = 0;
        for (int i = 0; i < 26; i++) {
            newNode->child[i] = nullptr;
        }
        newNode->word = "";
        return newNode;
    }

    node* root = getNode('/');

    void insert(const string& s) { // Use const reference for efficiency
        node* curr = root;
        for (char ch : s) {
            int index = ch - 'a';
            if (curr->child[index] == nullptr) {
                curr->child[index] = getNode(ch);
            }
            curr = curr->child[index];
        }
        curr->ends += 1;
        curr->word = s;
    }

    void solve(vector<vector<char>>& board, int i, int j, int m, int n, vector<string>& ans, node* curr) {
        char letter = board[i][j];
        int index = letter - 'a';

        // Boundary check and Trie path check
        if (letter == '$' || curr->child[index] == nullptr) {
            return;
        }

        curr = curr->child[index];
        if (curr->ends > 0) {
            ans.push_back(curr->word);
            curr->ends = 0; // Optimization: set to 0 to avoid duplicate entries in 'ans'
        }

        // Mark as visited
        board[i][j] = '$';

        // 4-Directional exploration
        if (i < m - 1) solve(board, i + 1, j, m, n, ans, curr);
        if (i > 0)     solve(board, i - 1, j, m, n, ans, curr);
        if (j < n - 1) solve(board, i, j + 1, m, n, ans, curr);
        if (j > 0)     solve(board, i, j - 1, m, n, ans, curr);

        // Backtrack: Restore the character
        board[i][j] = letter;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const string& s : words) {
            insert(s);
        }

        vector<string> ans;
        int m = board.size();
        if (m == 0) return ans;
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                solve(board, i, j, m, n, ans, root);
            }
        }
        return ans;
    }
};

// --- MAIN FUNCTION WITH EXAMPLE ---
int main() {
    Solution sol;

    // Example 1: A standard board
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    // Example 2: Words to find
    // "oath" exists (top left)
    // "pea" does not exist
    // "eat" exists (top right)
    // "rain" exists (right side)
    vector<string> words = {"oath", "pea", "eat", "rain"};

    cout << "Searching for words: oath, pea, eat, rain..." << endl;
    
    vector<string> result = sol.findWords(board, words);

    cout << "Words found: ";
    if (result.empty()) {
        cout << "None";
    } else {
        for (const string& s : result) {
            cout << s << " ";
        }
    }
    cout << endl;

    return 0;
}