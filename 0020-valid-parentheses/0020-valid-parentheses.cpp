class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {

            // Opening brackets
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                // No opening bracket to match
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                // Check matching pair
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        // Valid only if nothing is left open
        return st.empty();
    }
};