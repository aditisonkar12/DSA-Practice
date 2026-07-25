class Solution {
public:
    vector<string> ans;
    int n;
    int m;

    struct trieNode {
        bool endWord;
        string word;
        trieNode* child[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endWord = false;
        newNode->word = "";
        for (int i = 0; i < 26; i++) {
            newNode->child[i] = NULL;
        }
        return newNode;
    }

    void insert(trieNode* root, string& word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (crawler->child[ch - 'a'] == NULL) {
                crawler->child[ch - 'a'] = getNode();
            }
            crawler = crawler->child[ch - 'a'];
        }
        crawler->endWord = true;
        crawler->word = word;
    }

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void find(vector<vector<char>>& board, int i, int j, trieNode* root) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }
        if (board[i][j] == '$' || root->child[board[i][j] - 'a'] == NULL) {
            return;
        }

        root = root->child[board[i][j] - 'a'];
        if (root->endWord == true) {
            ans.push_back(root->word);
            root->endWord = false;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for (vector<int>& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            find(board, ni, nj, root);
        }
        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        n = board.size();
        m = board[0].size();
        trieNode* root = getNode();

        for (string& word : words) {
            insert(root, word);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch = board[i][j];
                if (root->child[ch - 'a'] != NULL)
                    find(board, i, j, root);
            }
        }
        return ans;
    }
};