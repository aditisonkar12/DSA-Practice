class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int i = 0, j = n - 1;
        int maxScore = 0;
        int score = 0;
        
        //greedy approach
        while (i <= j) {
            if (power >= tokens[i]) { //use power to gain score using tokens in the beginning
                power -= tokens[i];
                score++;
                maxScore = max(maxScore, score);
                i++;
            } else if (score >= 1) { //use score to gain power from end (max values in the end)
                power += tokens[j];
                score--;
                j--;
            }else{
                return maxScore;
            }
        }
        return maxScore;
    }
};