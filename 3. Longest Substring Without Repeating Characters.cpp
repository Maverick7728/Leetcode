// Given a string s, find the length of the longest substring without duplicate characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.



class Solution {
public:
    int lengthOfLongestSubstring(string input) {
        unordered_map<char, int> index;
        int left = 0, right = 0, length = 0;
        int size = input.length();

        while (right < size) {
            char c = input[right];

            if (index.find(c) != index.end()) {
                left = max(left, index[c] + 1);
            }

            int win = right - left + 1;
            length = max(length, win);

            index[c] = right;
            right++;
        }

        return length;
    }
};