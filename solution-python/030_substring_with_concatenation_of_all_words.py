"""
	030. Substring with Concatenation of All Words
	@name: li jin
	@date: Apr 21, 2016
	@link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
	@time: 96 ms
"""

class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        def my_hash(st):
            return hash(st) + hash(st[-1])
        res = []
        len_word, num_word = len(words[0]), len(words)
        total_value = sum(my_hash(w) for w in words)
        hash_values = [my_hash(s[i:i+len_word]) for i in range(len(s))] + [0]
        check_values = [sum(hash_values[i:i+num_word*len_word:len_word]) for i in range(len_word)]
        for i in range(len(s)-num_word*len_word + 1):
            if check_values[i%len_word] == total_value:
                res.append(i)
            check_values[i%len_word] += hash_values[i+num_word*len_word] - hash_values[i]
        return res
