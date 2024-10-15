/*
312324247 - Liron Cohen - liron02319@gmail.com
*/

#ifndef ALGORITHMS_HPP_
#define ALGORITHMS_HPP_

#include <iostream>
#include <stdexcept>
#include <limits>
#include "Graph.hpp"

namespace ariel {

class Algorithms {


public:

/*
Function : bellmanFord
bellmanFord algorithem
https://www.youtube.com/watch?v=FaOF5BVGIEc
 This function compute the shortest paths from the start vertex to all other vertices in  graph (using the Bellman-Ford algorithm)
*/



    static void bellmanFord(Graph graph, size_t start, std::vector<int>& distanceFromVertex, std::vector<int>& parents);


/*
Function : isConnected
 This function check if the graph is connected
*/

    static bool isConnected(const Graph graph);



/*
Function : shortestPath
this function return the shortestpath from start vertex to other vertex
*/
    static std::string shortestPath(const Graph graph, size_t startVetrex, size_t endVertex);



/*
Function : isContainsCycle
that function return and check if the graph contain cycle 
*/
    static std::string isContainsCycle(const Graph graph);


/*
Function : isBipartite
 isBipartite(g) - The algorithm accepts a graph and returns the partition of the graph into a bipartite graph. If the graph cannot be partitioned, 
 the algorithm will return 0.*/
    static std::string isBipartite(const Graph graph);


/*
Function : negativeCycle
the algorithm accepts a graph and finds a negative cycle
 (that is, a cycle whose sum of the weights of the sides is negative). 
 If no such circle exists, the algorithm will print that there is no negative circle.

*/
    static std::string negativeCycle(const Graph graph);

/*
Function : DFSvisit
help function for the other functions
*/
    static size_t DFSvisit(Graph graph, size_t u, std::vector<size_t>& parents, std::vector<int>& colors);
/*
Function : DFSvisitColors
help functuion for the other functions
*/

    static bool DFSvisitColors(Graph graph, size_t u, std::vector<int>& colors);





};

} 




#endif 