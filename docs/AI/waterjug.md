---
layout: default
title: Water Jug Problem
parent: AI
---

# Problem statement

> You are given with 2 Jugs, 4 liter and a 3 liter one. Neither of the jugs has any Measuring marks on it. There is a pump that can be used to fill the jugs with water. How can we get exactly 2 Gallons of water in 4 liter Jug?

```python
def WaterJugProblem(jug1Capacity, jug2Capacity, target):
    visited = set()
    queue = [(0, 0)]
    visited.add((0, 0))
    parent = {}

    while queue:
        jug1, jug2 = queue.pop(0)

        if jug1 == target or jug2 == target:
            path = []
            while (jug1, jug2) in parent:
                path.append((jug1, jug2))
                jug1, jug2 = parent[(jug1, jug2)]
            path.append((jug1, jug2))
            return list(reversed(path))

        next_states = [
            (jug1Capacity, jug2), (jug1, jug2Capacity), (0, jug2), (jug1, 0),
            (jug1 + min(jug2, jug1Capacity - jug1), jug2 - min(jug2, jug1Capacity - jug1)),
            (jug1 - min(jug1, jug2Capacity - jug2), jug2 + min(jug1, jug2Capacity - jug2))
        ]

        for state in next_states:
            if state not in visited:
                queue.append(state)
                visited.add(state)
                parent[state] = (jug1, jug2)

    return None
```

## Flow Chart

```mermaid
graph TD
    A[Start] --> B[Initialize visited set and queue]
    B --> C[Add 0,0 to visited and queue]
    C --> D{Is queue empty?}
    D -->|No| E[Pop the first state from queue]
    E --> F{Is target achieved?}
    F -->|Yes| G[Construct and return path]
    F -->|No| H[Generate next possible states]
    H --> I{Is state already visited?}
    I -->|No| J[Add state to queue and visited]
    J --> K[Add current state as parent]
    K --> D
    I -->|Yes| D
    D -->|Yes| L[Return None]
```

### Tests
```python
print(WaterJugProblem(4, 4, 2))
```
None
```python
print(WaterJugProblem(4, 3, 2))
```
[(0, 0), (0, 3), (3, 0), (3, 3), (4, 2)]
```python
print(WaterJugProblem(3, 4, 2))
```
[(0, 0), (3, 0), (0, 3), (3, 3), (2, 4)]


## Tree for water jug problem

```mermaid
graph TD
    A((0,0)) --> B((4,0))
    A --> C((0,3))
    B --> D((4,3))
    B --> E((0,0))
    B --> F((1,3))
    C --> G((4,3))
    C --> H((0,0))
    C --> I((3,0))
    F --> J((4,3))
    F --> K((0,3))
    F --> L((1,0))
    F --> M((4,0))
    F --> N((0,1))
    N --> O((4,1))
    N --> P((0,3))
    N --> Q((0,0))
    N --> R((1,0))
    M --> S((4,3))
    M --> T((0,1))
    M --> U((4,0))
    M --> V((2,3))
    V --> W((4,3))
    V --> X((0,3))
    V --> Y((2,0))
    V --> Z((4,1))
```