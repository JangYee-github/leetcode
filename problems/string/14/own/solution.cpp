class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0)
            return "";
        if (size == 1)
            return strs[0];
        int comn = 0;
        int i;
        int is_end = 0;
        while (1) {
            for (i = 1; i < size; i++) {
                if ( strs[i-1].length() <= comn || strs[i].length() <= comn) {
                    is_end = 1;
                    break;
                }
                if (strs[i-1][comn] != strs[i][comn])
                    break;
            }
            if (is_end || i != size)
                break;
            comn++;
        }
        return strs[0].substr(0, comn);
    }
};
