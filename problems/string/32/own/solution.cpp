class Solution {
public:

    int longestValidParentheses(string s) {
        int len = s.length();
        if (len < 2)
            return 0;
        int i, j, k, max_count=0, counter = 0;
        for (i = 1; i < len; i++) {
            if (s[i-1] == '(' && s[i] == ')') {
                s[i-1] = '0';
                s[i] = '0';
                for (j = i - 2, k = i + 1; j >= 0 && k < len; k++) {
                    if (s[j] == '0') {
                        j--;
                        while (j >= 0 && s[j] == '0')
                            j--;
                        if (j < 0)
                            break;
                    }
                    if (s[j] == '(' && s[k] == ')') {
                        s[j] = '0';
                        s[k] = '0';
                    }
                    else
                        break;
                }
                i = k;
            }
        }
        // cout << s << endl;
        for (i = 0; i < len; i++) {
            if (s[i] == '0') {
                counter = 0;
                for (j = i; j < len; j++) {
                    if (s[j] != '0')
                        break;
                    counter++;
                }
                max_count = max(counter, max_count);
                i = j;
            }
        }
        return max_count;
    }
};
