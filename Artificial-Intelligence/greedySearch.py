from queue import PriorityQueue

def greedy_best_first_search(graph, start, goal, heuristic):
    open_list = PriorityQueue()  # Priority queue to select the node with the lowest heuristic value
    open_list.put((heuristic[start], start, [start], 0))  # (heuristic value, current node, path, total cost)
    visited = set()  # To keep track of visited nodes

    while not open_list.empty():
        _, current_node, path, cost = open_list.get()  # Get the node with the lowest heuristic value
        if current_node == goal:
            print(f"Goal reached! Path: {' -> '.join(path)} with Total Cost: {cost}")
            return cost  # Return the total cost when the goal is reached
        
        visited.add(current_node)  # Mark the current node as visited
        
        # Explore the neighbors of the current node
        for neighbor, edge_cost in graph[current_node]:  # Consider actual edge costs
            if neighbor not in visited:
                new_path = path + [neighbor]  # Create a new path by adding the neighbor
                new_cost = cost + edge_cost  # Update the total cost with the edge cost
                open_list.put((heuristic[neighbor], neighbor, new_path, new_cost))  # Add the neighbor to the priority queue

    print("Goal not reachable")
    return None  # Return None if the goal is not reachable

# Example graph and heuristic with actual costs considered
graph = {
    'A': [('B', 5), ('C', 4)],
    'B': [('D', 4), ('E', 4)],
    'C': [('F', 2)],
    'D': [],
    'E': [('G', 5)],
    'F': [],
    'G': []
}

heuristic = {
    'A': 1,
    'B': 9,
    'C': 8,
    'D': 6,
    'E': 4,
    'F': 9,
    'G': 0
}

# Running the search
total_cost = greedy_best_first_search(graph, 'A', 'G', heuristic)
print(f"The total cost of the path found by Greedy Best-First Search is: {total_cost}")
