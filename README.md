(Do not display this in the rendered blob to see the content properly)

Write a program that reads a graph (from its input) and prints, either “This graph is not Eulerian.” or an Eulerian circuit of the graph (depending whether or not the
graph is Eulerian).

Input Format:
- The names of the letters are single (uppercase or lowercase) letters.
- The first line of the input contains the names of the vertices of the graph.
- Number the vertices in the order they appear in this line.
- Each of the subsequent input lines contains an edge as a pair of two letters.

Number every edge in the order it is read from the input.

Output Format:
If the graph is Eulerian, you should print the Eulerian circuit as a sequence of vertices that starts and ends in the vertex numbered 1. Moreover, whenever your algorithm has to choose an edge, it should choose the edge with the smallest possible index.

Example given by the following input:
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

In this case the only valid output is:
afedcbfdba

If the graph is not Eularian, the output is “GRAPH NOT EULERIAN”
