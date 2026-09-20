class Solution {
public:

    void backtrack(vector<int>& candidates,
                   int target,
                   int start,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // Found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Candidate is too large
            if (candidates[i] > target) {
                continue;
            }

            // Choose
            current.push_back(candidates[i]);

            // Same i because we can reuse the same number
            backtrack(candidates,
                      target - candidates[i],
                      i,
                      current,
                      result);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                        int target) {

        vector<vector<int>> result;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, current, result);

        return result;
    }
};