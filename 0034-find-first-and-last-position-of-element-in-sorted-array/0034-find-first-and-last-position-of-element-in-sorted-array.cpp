class Solution {
public:
    int findFirst(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int first = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;   // Keep searching left
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return first;
    }

    int findLast(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int last = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;    // Keep searching right
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        return {
            findFirst(nums, target),
            findLast(nums, target)
        };
    }
};