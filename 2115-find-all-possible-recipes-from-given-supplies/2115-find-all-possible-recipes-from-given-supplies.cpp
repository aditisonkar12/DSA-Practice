class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        int n = recipes.size();
        vector<string> ans;
        unordered_set<string> st(begin(supplies), end(supplies));

        int cnt = n;
        vector<bool> made(n, false); // items cooked or not yet
        while (cnt--) {
            for (int i = 0; i < n; i++) {
                if (made[i])
                    continue; // if already made skip

                bool canMake = true;
                for (int j = 0; j < ingredients[i].size(); j++) {
                    if (!st.count(ingredients[i][j])) {
                        canMake = false;
                        break;
                    }
                }
                if (canMake) {
                    st.insert(recipes[i]);
                    ans.push_back(recipes[i]);
                    made[i] = true;
                }
            }
        }
        return ans;
    }
};