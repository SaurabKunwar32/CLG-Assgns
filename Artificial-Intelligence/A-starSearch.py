from queue import PriorityQueue

def a_star_search(graph, start, goal, heuristic):
    open_list = PriorityQueue()
    open_list.put((0 + heuristic[start], 0, start, [start]))
    came_from = {start: None}

    while not open_list.empty():
        _, current_cost, current_node, path = open_list.get()
        if current_node == goal:
            print(f"Goal reached! Path: {' -> '.join(path)} with Total Cost: {current_cost}")
            return
        for neighbor, cost in graph[current_node]:
            new_cost = current_cost + cost
            if neighbor not in came_from or new_cost < came_from[neighbor][1]:
                came_from[neighbor] = (current_node, new_cost)
                new_path = path + [neighbor]
                open_list.put((new_cost + heuristic[neighbor], new_cost, neighbor, new_path))

# Updated graph and heuristic
graph = {
    'S': [('A', 1), ('B', 4), ('C', 8)],
    'A': [('D', 5), ('E', 2)],
    'B': [('E', 3), ('F', 7)],
    'C': [('F', 2)],
    'D': [('G', 9)],
    'E': [('G', 4)],
    'F': [('G', 1)],
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
a_star_search(graph, 'S', 'G', heuristic)