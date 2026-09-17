class Solution {
public:
    vector<string> result;

    vector<string> letters = {
        "",     "",     "abc",  "def",
        "ghi",  "jkl",  "mno",  "pqrs",
        "tuv",  "wxyz"
    };

    void backtrack(string& digits, int index, string current) {

        // We used all digits
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string possible = letters[digits[index] - '0'];

        for (char c : possible) {
            current.push_back(c);

            backtrack(digits, index + 1, current);

            // Undo the choice
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        backtrack(digits, 0, "");

        return result;
    }
};