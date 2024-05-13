import operator


def is_operator(c):
    return c in '+-*/'


def precedence(op):
    if op in '*/':
        return 2
    elif op in '+-':
        return 1
    return 0


def infix_to_postfix(infix):
    operator_stack = []
    postfix = ""

    for c in infix:
        if c.isalnum():
            postfix += c
        elif c == '(':
            operator_stack.append(c)
        elif c == ')':
            while operator_stack and operator_stack[-1] != '(':
                postfix += operator_stack.pop()
            operator_stack.pop()  # Pop the left parenthesis
        elif is_operator(c):
            while operator_stack and operator_stack[-1] != '(' and precedence(operator_stack[-1]) >= precedence(c):
                postfix += operator_stack.pop()
            operator_stack.append(c)

    while operator_stack:
        postfix += operator_stack.pop()

    return postfix


def postfix_value(postfix):
    operand = []

    for c in postfix:
        if c.isdigit():
            operand.append(int(c))
        else:
            num1 = operand.pop()
            num2 = operand.pop()
            if c == '+':
                result = num2 + num1
            elif c == '-':
                result = num2 - num1
            elif c == '*':
                result = num2 * num1
            elif c == '/':
                result = num2 / num1
            operand.append(result)

    return operand[0]


expression = "(4 * 3) / (6 - 3)"
infix = infix_to_postfix(expression)
print("Infix to postfix: ", infix)
value = postfix_value(infix)
print("Value of expression: ", value)
