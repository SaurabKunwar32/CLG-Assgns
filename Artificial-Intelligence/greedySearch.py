from queue import PriorityQueue

def greedy_best_first_search(graph, start, goal, heuristic):
    open_list = PriorityQueue()
    open_list.put((heuristic[start], start, [start], 0))
    visited = set()

    while not open_list.empty():
        _, current_node, path, cost = open_list.get()
        if current_node == goal:
            print(f"Goal reached! Path: {' -> '.join(path)} with Total Cost: {cost}")
            return
        visited.add(current_node)
        for neighbor in graph[current_node]:
            if neighbor not in visited:
                new_path = path + [neighbor]
                new_cost = cost + 1  # Assuming cost of 1 for each step
                open_list.put((heuristic[neighbor], neighbor, new_path, new_cost))
                visited.add(neighbor)

# Updated graph and heuristic
graph = {
    'S': ['A', 'B', 'C'],
    'A': ['D', 'E'],
    'B': ['E', 'F'],
    'C': ['F'],
    'D': ['G'],
    'E': ['G'],
    'F': ['G'],
    'G': []
}

heuristic = {
    'S': 7,
    'A': 6,
    'B': 5,
    'C': 4,
    'D': 3,
    'E': 2,
    'F': 1,
    'G': 0
}

# Running the search with the updated graph
greedy_best_first_search(graph, 'S', 'G', heuristic)