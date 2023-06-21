# Eulerian Circuit Project

This project presents an efficient program that reads a graph from its input and determines whether the graph is Eulerian or not. If the graph is Eulerian, the program prints an Eulerian circuit of the graph. If it is not, the program simply prints "This graph is not Eulerian."

## Description

The program, written in C++, implements the necessary logic to evaluate the input graph. The graph is represented using an adjacency list structure. The main steps of the algorithm involve:

1. Reading and constructing the graph from the input
2. Checking if the graph is Eulerian (all vertices with non-zero degrees are connected and all vertices have even degrees)
3. If the graph is Eulerian, constructing and printing the Eulerian circuit

The Eulerian circuit is printed as a sequence of vertices that starts and ends in the vertex numbered 1. When the algorithm has to choose an edge, it chooses the edge with the smallest possible index.

## Input Format

The names of the vertices are single (uppercase or lowercase) letters.

- The first line of the input contains the names of the vertices of the graph. Number the vertices in the order they appear in this line.
- Each of the subsequent input lines contains an edge as a pair of two letters. Number every edge in the order it is read from the input.

Example: 
```
acbfde 
af 
bd 
df 
ef 
ba 
de 
dc 
bf 
bc
```

## Output Format

- If the graph is Eulerian, the program prints the Eulerian circuit as a sequence of vertices that starts and ends in the vertex numbered 1. 
- If the graph is not Eulerian, the program prints "GRAPH NOT EULERIAN".

## Getting Started

You will need a C++ compiler installed on your system.

### Installing

1. Clone the repo or download the .cpp file to your local system.
2. Compile the file using your C++ compiler. 

### Usage

- Run the compiled program. The input consists of a series of lines, the first of which contains the names of the vertices, and the subsequent lines containing the edges. 
- The output will be either the Eulerian circuit or the message "GRAPH NOT EULERIAN", depending on the properties of the graph.
