import numpy as np

from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])  
    
    visited.add(start)
    
    while queue:
        vertex = queue.popleft()
        print(vertex, end=' ')
        
        for adjacent in graph[vertex]:
            if adjacent not in visited:
                visited.add(adjacent)
                queue.append(adjacent)
                

graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E', 'C'],
    'C': ['A', 'B', 'F', 'G'],
    'D': ['B'],
    'E': ['B'],
    'F': ['C'],
    'G': ['C']
}

start_node = 'A'
print("BFS starting from start node:", start_node)
bfs(graph, start_node);
