class Solution {
public:
    string countAndSay(int n) {

        string result = "1";

        for (int i = 1; i < n; i++) {

            string next = "";

            for (int j = 0; j < result.length(); ) {

                int count = 1;

                // Count consecutive identical digits
                while (j + count < result.length() &&
                       result[j + count] == result[j]) {
                    count++;
                }

                // Append count + digit
                next += to_string(count);
                next += result[j];

                // Move to the next group
                j += count;
            }

            result = next;
        }

        return result;
    }
};