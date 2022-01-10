class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if ( len % 2 != 0)
            return false;
        unordered_map <char, char> pairs = {
            {')' , '('},
            {']' , '['},
            {'}' , '{'}
        };
        stack<char> stk;
        for (char ch : s) {
            if (pairs.find(ch) == pairs.end()) {
                stk.push(ch);
                continue;
            }
            if (stk.empty())
                return false;
            if (stk.top() != pairs[ch])
                return false;
            stk.pop();
        }
        return stk.empty();
    }
};
