class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for c in s:
            if c == '(' or c == '{' or c == '[':
                stack.append(c)
                continue
            elif c == ')' and (not stack or stack[-1] != '('):
                return False
            elif c == '}' and (not stack or stack[-1] != '{'):
                return False
            elif c == ']' and (not stack or stack[-1] != '['):
                return False
            stack.pop()
        return not stack
        