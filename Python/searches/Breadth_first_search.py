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


def BFS(start, end, world):
    queue = [start]
    closed = []
    path = [[start, start]]

    while queue:
        node = queue.pop(0)
        closed.append(node)

        # Check if an unknown cell has been reached
        if node == end:
            queue = []

        for x in [-1, 1]:
            # Open children to the left and right
            child_X = [node[0]+x, node[1]]

            if child_X not in closed and child_X not in queue and world[child_X[0], child_X[1]] != 1:
                queue.append(child_X)
                path.append([child_X, node])

            # Open children above and below
            child_Y = [node[0], node[1]+x]

            if child_Y not in closed and child_Y not in queue and world[child_Y[0], child_Y[1]] != 1:
                queue.append(child_Y)
                path.append([child_Y, node])

    # Retrace the path
    parent = end
    while parent != start:

        # Finds the index value of the current node's parent
        index = [i for i in range(len(path)) if path[i][0] == parent][0]

        plt.plot(parent[1], parent[0], marker='o', color='red')

        # Update the parent
        parent = path[index][1]

    # Plot the final node
    plt.plot(parent[1], parent[0], marker='o', color='red')


if __name__ == '__main__':
    # Load and plot the world
    world = load_world('world.csv')
    plt.imshow(world, cmap='binary')

    # Starting and ending points
    start = [1, 1]
    end = [20, 20]

    BFS(start, end, world)
