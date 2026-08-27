class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.length();
        for (int i = 0; i < n; i++) {
            if (i == 0 || title[i - 1] == ' ') {
                int j = i;
                while (j < n && title[j] != ' ') {
                    j++;
                }

                int len = j - i;
                if (len <= 2) {
                    for (int k = i; k < j; k++) {
                        title[k] = tolower(title[k]);
                    }
                } else {
                    title[i] = toupper(title[i]);
                    for (int k = i + 1; k < j; k++) {
                        title[k] = tolower(title[k]);
                    }
                }
            }
        }
        return title;
    }
};