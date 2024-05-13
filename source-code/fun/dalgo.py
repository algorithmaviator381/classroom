def dijkstra(graph, start):
    distances = {node: float('infinity') for node in graph}
    distances[start] = 0
    predecessors = {node: None for node in graph}

    unvisited = set(graph)

    while unvisited:
        current_node = min(unvisited, key=lambda node: distances[node])

        for neighbor, weight in graph[current_node].items():
            distance = distances[current_node] + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                predecessors[neighbor] = current_node

        unvisited.remove(current_node)

    return distances, predecessors


# Example usage:
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

start_node = 'A'
distances, predecessors = dijkstra(graph, start_node)

print("Shortest distances from", start_node, ":")
for node, distance in distances.items():
    print(f"To {node}: {distance}")

print("\nPredecessors:")
for node, predecessor in predecessors.items():
    print(f"{node}: {predecessor}")
