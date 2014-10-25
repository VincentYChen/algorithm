#!/usr/bin/env python
class Solution:

    # @param s, a string

    # @return an integer

    def longestValidParentheses(self, s):
        stack = []
        maxLen = 0
        for i, c in enumerate(s):
            if c == "(":
                stack.append(i)
            elif c == ")":
                if len(stack) != 0:
                    indexOfLeft=stack.pop();
                    length = i-indexOfLeft +1
                    if length > maxLen:
                        maxLen = length

        print maxLen

        
if __name__ == '__main__':
    #s = "(()";
    #s = "())))";
    #s = "(())()))))((()()())))";  
    s = "()()"          
    solution = Solution()
    solution.longestValidParentheses(s);