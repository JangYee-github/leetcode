class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = -1, gi, si, gsize = g.size(), ssize = s.size(), cur_g;
        for ( int gi = 0, si = 0; gi < gsize && si < ssize; gi++) {
            while (si < ssize) {
                cur_g = s[si];
                si++;
                if (cur_g >= g[gi]) {
                    res = gi;
                    break;
                }
            }
        }
        return res + 1;
    }
};
