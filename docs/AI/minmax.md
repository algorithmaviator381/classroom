---
layout: default
title: Min Max
parent: AI
---


```python
class Node:
    def __init__(self, value=None):
        self.value = value
        self.children = []

def minmax(node, depth, is_maximizing_player):
    if depth == 0 or not node.children:
        return node.value

    if is_maximizing_player:
        best_value = float('-inf')
        for child in node.children:
            value = minmax(child, depth - 1, False)
            best_value = max(best_value, value)
        return best_value
    else:
        best_value = float('inf')
        for child in node.children:
            value = minmax(child, depth - 1, True)
            best_value = min(best_value, value)
        return best_value

# Example usage:
# Creating a sample game tree
root = Node()
child1 = Node()
child2 = Node()
child3 = Node()

child1.children = [Node(3), Node(5), Node(2)]
child2.children = [Node(9), Node(12), Node(5)]
child3.children = [Node(23), Node(23), Node(21)]

root.children = [child1, child2, child3]

# Running minmax algorithm
result = minmax(root, 3, True)
print("The optimal value is:", result)
```