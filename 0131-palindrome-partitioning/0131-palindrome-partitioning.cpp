
class Solution {
public:

    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void solve(string &s, int index, vector<string> &path,
               vector<vector<string>> &ans) {

        // Base case: entire string is partitioned
        if (index == s.length()) {
            ans.push_back(path);
            return;
        }

        // Try every possible substring
        for (int i = index; i < s.length(); i++) {

            if (isPalindrome(s, index, i)) {

                // Choose
                path.push_back(s.substr(index, i - index + 1));

                // Explore
                solve(s, i + 1, path, ans);

                // Backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;

        solve(s, 0, path, ans);

        return ans;
    }
};
