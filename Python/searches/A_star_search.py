import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Import the world
rawworld = np.genfromtxt('world.csv', delimiter=',')

# Transfer world into a new array with walls all around to avoid edge cases
world = np.ones((np.size(rawworld,1)+2,np.size(rawworld,1)+2))
world[1:-1,1:-1] = rawworld

# Starting and ending points
start = [1,1]
end = [20,20]

# Queue row data: current node x and y, heuristic cost, cost from origin, total score, parent node
queue = [[start, 0, 0, 0, start]]
# Closed list, prevents nodes from being opened more than once
closed = []

# Find children in the queue (4-connected)
while queue:
    
    # Remove node from queue, add to closed nodes
    node = queue.pop(0)
    closed.append(node)
    
    # End when at goal
    if node[0] == end:
        queue = []
        
    for x in [-1,1]:
    
        # Open children if they are not in closed and are not a wall
        if not any([node[0][0]+x,node[0][1]] == closed[i][0] for i in range(len(closed))) and world[node[0][0]+x][node[0][1]] != 1:
            
            # Find current heuristic and path cost
            oCost = node[2] + 1
            hDist = np.sqrt((end[0] - node[0][0]+x)**2 + (end[1] - node[0][1])**2)
            
            if not any([node[0][0]+x,node[0][1]] == queue[i][0] for i in range(len(queue))):
                # Append node child to queue if it is not yet in it
                queue.append([[node[0][0]+x,node[0][1]], hDist, oCost, hDist+oCost, node[0]])
            
            elif any([i for i in range(len(queue)) if queue[i][0] == [node[0][0]+x,node[0][1]] and queue[i][3] > hDist+oCost]):    
                # If the node exists in the queue, and the new score is lower, update the node
                index = [i for i in range(len(queue)) if queue[i][0] == [node[0][0]+x,node[0][1]] and queue[i][3] > hDist+oCost][0]
                queue[index] = [[node[0][0]+x,node[0][1]], hDist, oCost, hDist+oCost, node[0]]
                
        if not any([node[0][0],node[0][1]+x] == closed[i][0] for i in range(len(closed))) and world[node[0][0]][node[0][1]+x] != 1:
            # Evaluate left and right of current node
            # Find current heuristic and path cost
            oCost = node[2] + 1
            hDist = np.sqrt((end[0] - node[0][0])**2 + (end[1] - node[0][1]+x)**2)
            
            if not any([node[0][0],node[0][1]+x] == queue[i][0] for i in range(len(queue))):
                # Append node child to queue if it is not yet in it
                queue.append([[node[0][0],node[0][1]+x], hDist, oCost, hDist+oCost, node[0]])
            
            elif any([i for i in range(len(queue)) if queue[i][0] == [node[0][0],node[0][1]+x] and queue[i][3] > hDist+oCost]):
                # If the node exists in the queue, and the new score is lower, update the node
                index = [i for i in range(len(queue)) if queue[i][0] == [node[0][0],node[0][1]+x] and queue[i][3] > hDist+oCost][0]
                queue[index] = [[node[0][0],node[0][1]+x], hDist, oCost, hDist+oCost, node[0]]
            
    queue.sort(key=lambda x: x[3])

plt.imshow(world, cmap='binary')

# Trace ideal path back to beginning
parent = [end]
while parent[0] != start:
    plt.plot(parent[0][1],parent[0][0], marker='o', color='red')
    parent = [closed[x][4] for x in range(len(closed)) if closed[x][0] == parent[0]]
    
plt.plot(parent[0][1],parent[0][0], marker='o', color='red')
plt.show()