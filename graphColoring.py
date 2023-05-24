
def isSafeToColor(graph, color):
    for i in range(V):
        for j in range(i + 1, V):
            if graph[i][j] == 1 and color[i] == color[j]:
                return False
    return True

def printArr(color):
    for i in color:
        print(i, end=" ")

def graphColoring(graph, m, i, color):
    if( i == V):
        if(isSafeToColor(graph, color)):
            printArr(graph)
            return True
        return False
    for j in range(1, m + 1):
        color[i] = j
        if graphColoring(graph, m, i + 1, color):
            return True
            color[i] = 0
    return False

def printColorArray(color):
      print("Solution colors are: ")
      for i in range(len(color)):
           print(color[i], end=" ")
      print("\n")

def graphColoring(graph, m, i, color):
    if i == V:
        if isSafeToColor(graph, color):
            printColorArray(color)
            return True
        return False
    for j in range(1, m + 1):
        color[i] = j
        if graphColoring(graph, m, i + 1, color):
            return True
            color[i] = 0
    return False    

if __name__ == "__main__":
    # Define the graph as an adjacency matrix
    graph = [
        [0, 1, 1, 1, 0, 0, 0],
        [1, 0, 1, 0, 1, 0, 0],
        [1, 1, 0, 1, 1, 0, 0],
        [1, 0, 1, 0, 1, 1, 0],
        [0, 1, 1, 1, 0, 1, 1],
        [0, 0, 0, 1, 1, 0, 1],
        [0, 0, 0, 0, 1, 1, 0]
    ]
    
    # Number of vertices in the graph
    V = 7
    
    # Define the number of colors available
    m = 3
    
    # Initialize the color array
    color = [0] * V
    
    # Call the graphColoring function
    if graphColoring(graph, m, 0, color):
        pass
    else:
        print("No solution exists.")

