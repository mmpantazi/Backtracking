class Solution
{
public:
	vector<string> ans;
	unordered_map<unsigned char, string> digitToLetters =
	{
		{'2', "abc"},
		{'3', "def"},
		{'4', "ghi"},
		{'5', "jkl"},
		{'6', "mno"},
		{'7', "pqrs"},
		{'8', "tuv"},
		{'9', "wxyz"}
	};

	vector<string> letterCombinations(string digits, string str = "")
	{
		if (digits.size() == 0)
		{
			if (str == "") return ans;
			ans.push_back(str);
			return ans;
		}
		char currentDigit = digits[0];
		for (auto x : digitToLetters[currentDigit])
		{
			letterCombinations(digits.substr(1), str + x);
		}
		return ans;
	}
};