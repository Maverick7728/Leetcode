// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if:

// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.
// 3. Every close bracket has a corresponding open bracket of the same type.

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

// Example 4:
// Input: s = "([])"
// Output: true

// Constraints:
// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

class Solution
{
public:
    bool isValid(string str)
    {
        stack<char> s;
        for (int i = 0; i < str.length(); i++)
        {
            char c = str[i];
            if (c == '(' || c == '{' || c == '[')
            {
                s.push(c);
            }
            else
            {
                if (s.empty())
                    return false;
                if (c == ')' && s.top() != '(')
                    return false;
                if (c == '}' && s.top() != '{')
                    return false;
                if (c == ']' && s.top() != '[')
                    return false;
                s.pop();
            }
        }
        return s.empty();
    }
};