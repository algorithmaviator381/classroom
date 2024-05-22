---
layout: default
title: Travelling Salesman Problem
parent: AI
---

# Travelling Salesman Problem in python

Given a list of cities and the distances between them, the objective is to find the optimal tour that visits each city exactly once and returns to the starting city, minimizing the total distance traveled.

## Algorithm

```mermaid
graph TD;
    A[Cities] --> B(Start);
    B --> C{Unvisited cities exist?};
    C -- Yes --> D(Find nearest city);
    D --> E{Set visited};
    E -- Yes --> F[Add to tour];
    F --> G{All cities visited?};
    G -- No --> D;
    G -- Yes --> H[Add starting city to tour];
    H --> I(End);
    C -- No --> I;
```

---
## Here is the entire code for you to copy paste

```python
import math

def TSP(cities):
    currentCity = cities[0]
    tour = [currentCity]
    SetVisited(currentCity)
    while Check(cities):
        nearest_city = FindNearestCity(currentCity, cities)
        tour.append(nearest_city)
        SetVisited(nearest_city)
        currentCity = nearest_city
    tour.append(tour[0]) 
    return tour

def Check(cities):
    return any(city['visited'] == False for city in cities)

def FindNearestCity(currentCity, cities):
    nearest_distance = float('inf')
    nearest_city = None
    for city in cities:
        if not city['visited']:
            distance = GetDistance(currentCity, city)
            if distance < nearest_distance:
                nearest_distance = distance
                nearest_city = city
    return nearest_city

def SetVisited(city):
    city['visited'] = True

def GetDistance(city1, city2):
    return math.sqrt((city2['x'] - city1['x']) ** 2 + (city2['y'] - city1['y']) ** 2)

cities = [
    {'name': 'Pune', 'x': 0, 'y': 0, 'visited': False},
    {'name': 'Wakad', 'x': 1, 'y': 1, 'visited': False},
    {'name': 'Moshi', 'x': 2, 'y': 2, 'visited': False},
    {'name': 'Hadapsar', 'x': 1, 'y': 3, 'visited': False},
    {'name': 'PCMC', 'x': 0, 'y': 2, 'visited': False}
]

print("Cities")
for city in cities:
    print(f"{city['name']} - ({city['x']}, {city['y']})")

tour = TSP(cities)

print("\nTour:")
for i, city in enumerate(tour):
        print(f"Step {i+1}: Visit {city['name']}")
```