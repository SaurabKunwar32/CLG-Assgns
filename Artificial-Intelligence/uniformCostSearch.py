import heapq

def uniform_cost_search(graph, start, goal):
    # Priority queue stores (cost, node, path)
    queue = [(0, start, [start])]
    visited = set()
    
    while queue:
        cost, node, path = heapq.heappop(queue)
        
        if node in visited:
            continue
        
        visited.add(node)
        
        if node == goal:
            return cost, path
        
        for neighbor, edge_cost in graph.get(node, []):
            if neighbor not in visited:
                heapq.heappush(queue, (cost + edge_cost, neighbor, path + [neighbor]))
    
    return float('inf'), []

# Updated graph with new nodes and edge costs
graph = {
    'S': [('A', 2), ('B', 1)],
    'A': [('C', 5), ('D', 10)],
    'B': [('D', 3), ('E', 7)],
    'C': [('G', 2)],
    'D': [('G', 1)],
    'E': [('G', 3)],
    'G': []
}

cost, path = uniform_cost_search(graph, "S", "G")
print(f'Path: {" -> ".join(path)} with Total Cost: {cost}')