#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt


def load_world(file):
    # Import the world
    raw_world = np.genfromtxt(file, delimiter=',')

    # Transfer world into a new array with walls all around to avoid edge cases
    world = np.ones((np.size(raw_world, 1)+2, np.size(raw_world, 1)+2))
    world[1:-1, 1:-1] = raw_world

    return world


def a_star(start, end, world):
    # Initialize node queue
    queue = [[start[0], start[1]]]

    # track nodes that have been evaluated
    closed = []

    # Contained in node data:
    #   heuristic cost, origin cost, total cost, parent x, parent y
    node_data = [[0, 0, 0, 0, 0]]

    # contains node x and y as well as respective node data
    closed_data = []

    # Run while the goal has not been reached
    while queue:

        # Pull best node off queue, add it to closed list
        node = queue.pop(0)
        closed_data.append([node, node_data.pop(0)])
        closed.append(node)

        # End when at goal
        if node == end:
            queue = []

        # Open children in a 4-connected region
        for x in [-1, 1]:
            # Open children to the left and right
            child_X = [node[0]+x, node[1]]

            if child_X not in closed and world[child_X[0], child_X[1]] != 1:

                # Find current heuristic and path cost
                oCost = 1
                hDist = np.sqrt((end[0]-child_X[0])**2+(end[1]-child_X[1])**2)

                # Add node if not already in the queue
                if child_X not in queue:

                    queue.append(child_X)
                    node_data.append([hDist, oCost, node[0], node[1]])

            # Open children above and below
            child_Y = [node[0], node[1]+x]

            if child_Y not in closed and world[child_Y[0], child_Y[1]] != 1:

                # Find current heuristic and path cost
                oCost = 1
                hDist = np.sqrt((end[0]-child_Y[0])**2+(end[1]-child_Y[1])**2)

                # Add node if not already in the queue
                if child_Y not in queue:

                    queue.append(child_Y)
                    node_data.append([hDist, oCost, node[0], node[1]])

    # Retrace the path
    parent = end
    while parent != start:

        # Finds the index value of the current node's parent
        index = [i for i in range(len(closed_data)) if closed_data[i][0] == parent][0]

        plt.plot(parent[1], parent[0], marker='o', color='red')

        # Update the parent
        parent = closed_data[index][1][2:4]

    # Plot the final node
    plt.plot(parent[1], parent[0], marker='o', color='red')


if __name__ == '__main__':
    # Load and plot the world
    world = load_world('world.csv')
    plt.imshow(world, cmap='binary')

    # Starting and ending points
    start = [1, 1]
    end = [20, 20]

    a_star(start, end, world)
