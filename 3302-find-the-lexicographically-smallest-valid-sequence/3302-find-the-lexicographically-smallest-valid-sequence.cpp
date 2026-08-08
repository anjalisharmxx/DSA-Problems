class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<int> last(n2, -1);
        int ptr = n1 - 1;
        for (int j = n2 - 1; j >= 0; --j) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            if (ptr < 0)
                break;
            last[j] = ptr;
            ptr--;
        }

        vector<int> ans;
        bool used_change = false;
        int i = 0;

        for (int j = 0; j < n2; ++j) {
            while (i < n1) {
                if (word1[i] == word2[j]) {
                    ans.push_back(i);
                    i++;
                    break;
                } else if (!used_change) {
                    if (j + 1 == n2 || (last[j + 1] > i)) {
                        used_change = true;
                        ans.push_back(i);
                        i++;
                        break;
                    }
                }
                i++;
            }

            if (ans.size() <= j) {
                return {};
            }
        }

        return ans;
    }
};