class Solution {
public:
    int solve(int start, int i, int j, string &haystack, string &needle) {
        if (j == needle.size())
            return start;

        if (i == haystack.size())
            return -1;

        if (haystack[i] == needle[j])
            return solve(start, i + 1, j + 1, haystack, needle);

        return -1;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;

        if (needle.size() > haystack.size())
            return -1;

        for (int i = 0; i <=haystack.size() - needle.size(); i++) {
            int ans = solve(i, i, 0, haystack, needle);
            if (ans != -1)
                return ans;
        }

        return -1;
    }
};