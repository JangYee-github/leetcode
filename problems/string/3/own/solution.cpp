class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int i, j, max_count = 0;
        unordered_set<char> set;
        for (i = 0; i < len; i++) {
            set.clear();
            for (j = i; j < len; j++) {
                if (set.find(s[j]) != set.end())
                    break;
                set.insert(s[j]);
            }
            max_count = max(j-i, max_count);
        }
        return max_count;
    }
};
