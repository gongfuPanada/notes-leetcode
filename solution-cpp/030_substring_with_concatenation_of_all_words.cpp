/*
	030. Substring with Concatenation of All Words
	@name: li jin
	@date: Apr 21, 2016
	@link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
	@time: 20 ms
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len_word = words[0].size(), num_word = words.size(), len_str = s.size(), total_value = 0;
        int hash_values[len_str - len_word + 1], check_values[len_word] = {0};
        vector<int> res;
        hash<string> hash_fun;
        for (auto w : words) {
            total_value += hash_fun(w);
        }
        for (int i = 0; i <= len_str - len_word; i++) {
            hash_values[i] = hash_fun(s.substr(i, len_word));
        }
        for (int i = 0; i < len_word; i++) {
            int j = 0;
            while (j < num_word) {
                check_values[i] += hash_values[i + (j++) * len_word];
            }
            do {
                if (check_values[i] == total_value)
                    res.push_back(i + len_word * (j - num_word));
                check_values[i] += hash_values[i + j * len_word] - hash_values[i + (j - num_word) * len_word];
                j++;
            } while (i + j * len_word <= len_str);
        }
        return res;
    }
};
