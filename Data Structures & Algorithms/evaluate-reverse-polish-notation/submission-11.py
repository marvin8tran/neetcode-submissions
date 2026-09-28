class Solution:
    def evalRPN(self, tokens: List[str]) -> int:

        stack = []

        for val in tokens:
            if val == "+":
                tmp = stack[-2] + stack[-1]
                stack.pop()
                stack.pop()
                stack.append(tmp)
            elif val == "*":
                tmp = stack[-2] * stack[-1]
                stack.pop()
                stack.pop()
                stack.append(tmp)
            elif val == "-":
                tmp = stack[-2] - stack[-1]
                stack.pop()
                stack.pop()
                stack.append(tmp)
            elif val == "/":
                tmp = int(stack[-2] / stack[-1])
                stack.pop()
                stack.pop()
                stack.append(tmp)
            else:
                stack.append(int(val))
        return stack[-1]

        