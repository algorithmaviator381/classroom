---
layout: default
title: Tree search
parent: AI
---

```python
class Node:
    def __init__(self, value):
        self.value = value
        self.children = []

def bfs(root):
    queue = [root]
    visited = set()
    visited.add(root)
    
    while queue:
        node = queue.pop(0)
        print(node.value, end=' ')
        
        for child in node.children:
            if child not in visited:
                visited.add(child)
                queue.append(child)

def dfs(root):
    stack = [root]
    visited = set()
    
    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            print(node.value, end=' ')
            stack.extend(reversed(node.children))

# Example usage:
# Creating a sample tree
root = Node(1)
root.children = [Node(2), Node(3), Node(4)]
root.children[0].children = [Node(5), Node(6)]
root.children[1].children = [Node(7)]
root.children[2].children = [Node(8), Node(9)]

print("BFS Traversal:")
bfs(root)
print("\nDFS Traversal:")
dfs(root)
```