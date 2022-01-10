class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        int i, j;
        for (i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0)
            return "";
        int i, j, k, max_count=0;
        string max_str = s.substr(0, 1);
        for (i = 0; i < len; i++) {
            for (j = len - 1; j > i; j--) {
                if ((j - i) < max_count)
                    break;
                if (isPalindrome(s, i, j)) {
                    if (max_count < (j - i)) {
                        max_count = j - i;
                        max_str = s.substr(i, max_count + 1);
                    }
                }
            }
        }
        return max_str;
    }
};
