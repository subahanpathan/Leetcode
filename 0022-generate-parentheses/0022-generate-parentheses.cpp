class Solution {
public:
    vector<string> ans;

    void backtrack(string current, int open, int close, int n) {

        // We used all parentheses
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // We can add an opening bracket
        if (open < n) {
            backtrack(current + "(", open + 1, close, n);
        }

        // We can add a closing bracket only if
        // there is an unmatched opening bracket
        if (close < open) {
            backtrack(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return ans;
    }
};