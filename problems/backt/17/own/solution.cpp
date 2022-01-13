class Solution {
public:
	int len;
	unordered_map<char, vector<char>> pairs  {
		{'2', {'a', 'b', 'c'}},
		{'3', {'d', 'e', 'f'}},
		{'4', {'g', 'h', 'i'}},
		{'5', {'j', 'k', 'l'}},
		{'6', {'m', 'n', 'o'}},
		{'7', {'p', 'q', 'r', 's'}},
		{'8', {'t', 'u', 'v'}},
		{'9', {'w', 'x', 'y', 'z'}},
	};
	vector<string> res;
	char *buf;
    void _letterCombinations(string &digits, int index) {
		if(index == len) {
			res.push_back(buf);
			return ;
		}
		for (auto i = pairs[digits[index]].begin(); i < pairs[digits[index]].end(); i++) {
			buf[index] = *i;
			_letterCombinations(digits, index + 1);
		}
	}

    vector<string> letterCombinations(string digits) {
		len = digits.length();
		if (len == 0)
			return res;
		buf = new char[len + 1];
		buf[len] = 0;
		_letterCombinations(digits, 0);
		return res;
    }
};
