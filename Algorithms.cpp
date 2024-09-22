/*
312324247 - Liron Cohen - liron02319@gmail.com
*/

#include <algorithm> 
#include "Algorithms.hpp"
#include <string>

using namespace std;
using namespace ariel;



/*
Function : bellmanFord
bellmanFord algorithem
https://www.youtube.com/watch?v=FaOF5BVGIEc
 This function compute the shortest paths from the start vertex to all other vertices in  graph (using the Bellman-Ford algorithm)
*/

void ariel::Algorithms::bellmanFord(Graph graph, size_t start, vector<int> &distanceFromVertex, vector<int> &pi)
{
    // Initialize  0.
    distanceFromVertex[start] = 0;
    
    // run over all vertices-1 times.
    for (int i = 0; i < graph.numberOfVerticesInGraph() - 1; i++)
    {
        // edges.
        for (size_t j = 0; j < graph.numberOfVerticesInGraph(); j++)
        {
            for (size_t k = 0; k < graph.numberOfVerticesInGraph(); k++)
            {

                if (graph.getWeight(j, k) != 0 && distanceFromVertex[j] != INT32_MAX && distanceFromVertex[k] > distanceFromVertex[j] + graph.getWeight(j, k))
                {
                    distanceFromVertex[k] = distanceFromVertex[j] + graph.getWeight(j, k);
                    pi[k] = j;
                }
            }
        }
    }


     // Check for negative cycles.
    for (size_t i = 0; i < graph.numberOfVerticesInGraph(); i++)
    {
        for (size_t j = 0; j < graph.numberOfVerticesInGraph(); j++)
        {
            if (graph.getWeight(i, j) != 0 && distanceFromVertex[i] != INT32_MAX && (distanceFromVertex[j] > distanceFromVertex[i] + graph.getWeight(i, j) || distanceFromVertex[i] == INT32_MIN))
            {
                distanceFromVertex[j] = INT32_MIN;
                pi[j] = i;
            }
        }
    }
}


/*
Function : isConnected
 This function check if the graph is connected
*/

bool ariel::Algorithms::isConnected(Graph graph)
{
    // run each vertex in the graph.
    for (size_t s = 0; s < graph.numberOfVerticesInGraph(); s++)
    {
        // for the Bellman-Ford algorithm.
        vector<int> d(graph.numberOfVerticesInGraph(), INT32_MAX);
        vector<int> pi(graph.numberOfVerticesInGraph(), -1);

         
        bellmanFord(graph, s, d, pi);
        
        for (size_t i = 0; i < graph.numberOfVerticesInGraph(); i++)
        {
            if (d[i] == INT32_MAX)
                return false; 
        }
    }
    
// the graph is connected.
    return true;
}


/*
Function : shortestPath
this function return the shortestpath from start vertex to other vertex
*/
string Algorithms::shortestPath(Graph graph, size_t start, size_t end)
{
  
  // for the Bellman-Ford algorithm.
    vector<int> d(graph.numberOfVerticesInGraph(), INT32_MAX);
    vector<int> pi(graph.numberOfVerticesInGraph(), -1);
    
    bellmanFord(graph, start, d, pi);

// start=end same vertices 
    if (start == end) {
        return std::to_string(start); 
    }

    if (d[end] == INT32_MIN) {
        return "There a negative cycle"; // If there is a negative cycle
    }

    if (pi[end] == -1) {
        return std::to_string(-1) + " :(there is no path between " + std::to_string(start) + " to " + std::to_string(end) + ")";
    }

    string strShortenPath = std::to_string(end); // the path from the end vertex. construct the shortest path.
    int t = end;


    while (t != start) {
        t = pi[(size_t)t]; // the parent.
        if (t == -1) break; 
        strShortenPath = std::to_string(t) + "-->" + strShortenPath; 
    }

    return strShortenPath; 



}

/*
Function : isContainsCycle
that function return and check if the graph contain cycle 
*/
string Algorithms::isContainsCycle(Graph graph)
{
    string str = "No cycles"; // no cycles found.
    
    // Initialize vectors to store colors and parens for DFS.
     // Colors: white (0), gray (1), black (2)
    vector<int> colors(graph.numberOfVerticesInGraph(), 0);
    vector<size_t> parents(graph.numberOfVerticesInGraph(), SIZE_MAX); //Parent
    
    // Perform DFS from each vertex to check for cycles.
    for (size_t i = 0; i < graph.numberOfVerticesInGraph(); i++)
    {
         // vertex has not been visited yet, perform DFS
        if (colors[i] == 0)
        { 
            size_t s = DFSvisit(graph, i, parents, colors); // DFS visit from vertex .

            // cycle is found during DFS visit, construct a string representing the cycle.
            if (s != SIZE_MAX)
            {
                str = std::to_string(s); 

                size_t parent = parents[s]; 

                while (parent != s)
                {
                    str = std::to_string(parent) + "-->" + str; 
                    parent = parents[parent]; 
                }

                str = std::to_string(s) + "-->" + str; 
                
              
                return "The cycle is:" + str;
            }
        }
    }   

    return str;
}




/*
Function : isBipartite
 isBipartite(graph) - The algorithm accepts a graph and returns the partition of the graph into a bipartite graph. If the graph cannot be partitioned, 
 the algorithm will return 0.*/
string Algorithms::isBipartite(Graph graph)
{
    // Initialize a vector to store colors of vertices during DFS (white:0, red:1, green:2).
    vector<int> colors(graph.numberOfVerticesInGraph(), 0);

    for(size_t i = 0; i < graph.numberOfVerticesInGraph(); i++)
    {
        // if the current vertex is already color
        if(colors[i] != 0)
        {
            continue;
        }
        
        for(size_t j = 0; j < graph.numberOfVerticesInGraph(); j++)
        {
            // If the adjacent vertex j is already colored and edge between i and j, determine the color of vertex i.
            if(colors[j] != 0 && (graph.getWeight(i,j) != 0 || graph.getWeight(j,i) != 0 ) && i != j)
            {
                  colors[i] = 3 - colors[j]; // write different color from the color of vertex j.
                break;
            }
        }
         
        if(colors[i] == 0)
        {
            colors[i] = 1;
        }

      // check if the graph remains bipartite after coloring vertex i.
        bool b = DFSvisitColors(graph, i, colors);
        
        if(!b){
            return std::to_string(0);
        }
    }
    string str1 = "{";
    string str2 = "{";

    // Iterate over each vertex and categorize them into s1 or s2 based on their colors.
    for(size_t i = 0; i < graph.numberOfVerticesInGraph(); i++)
    {
          if(colors[i] == 1)
        {
            str1 += std::to_string(i) + " "; 
        }
        else{
            str2 += std::to_string(i) + " "; 
        }
    }    
     str1 += "}"; 
    str2 += "}"; 

    return str1 +""+ str2;
}





/*
Function : negativeCycle
the algorithm accepts a graph and finds a negative cycle
 (that is, a cycle whose sum of the weights of the sides is negative). 
 If no such circle exists, the algorithm will print that there is no negative circle.

*/
string Algorithms::negativeCycle(Graph graph)
{
    string str = "There isn't a negative cycle"; 
    vector<size_t> points; 

    
    for (size_t s = 0; s < graph.numberOfVerticesInGraph(); s++)
    {
        vector<int> d(graph.numberOfVerticesInGraph(), INT32_MAX); 
        vector<int> pi(graph.numberOfVerticesInGraph(), -1); 

        bellmanFord(graph, s, d, pi); // bellman-Ford algorithm to find shortest paths from vertex s.

        // Check if there is a negative distance from vertex s to itself, indicating the presence of a negative cycle.
        if (d[s] < 0)
        {
            str = ""; 
            points.push_back(s); 

            for (size_t t = 0; t < points.size(); t++)
            {

                if (pi[s] == points[t])
                {

                    for (size_t k = 1; k < points.size(); k++)
                    {
                        str += std::to_string(points[k]) + ", "; 
                    }
                    str += std::to_string(points[0]); 
                    return str;
                }
                else
                {
                    points.push_back(t); // Add the parent vertex to the list of potential negative cycle vertices.
                }
            }
        }
    }

    return str; 
}

size_t Algorithms::DFSvisit(Graph graph, size_t u, vector<size_t> &pi, vector<int> &colors)
{
    colors[u] = 1; // color the current vertex as visited (gray).
    

    for (size_t j = 0; j < graph.numberOfVerticesInGraph(); j++)
    {

        if (graph.getWeight(u, j) == 0)
        {
            continue;
        }


 // If the adjacent vertex j has not been visited yet, recursively visit it.
        if (colors[j] == 0)
        {
            pi[j] = u; // Set the parent of j as u.
            

            size_t res = DFSvisit(graph, j, pi, colors);
            

            if (res != SIZE_MAX)
            {
                return res;
            }
          }

      
      
        else if (colors[j] == 1 && j != u)
        {
            pi[j] = u; 
            return j; 
            
        }
    }
     colors[u] = 2; 
    return SIZE_MAX; 
}



bool Algorithms::DFSvisitColors(Graph graph, size_t u, vector<int> &colors)
{
    // Iterate over each adjacent vertex of the current vertex u.
    for (size_t j = 0; j < graph.numberOfVerticesInGraph(); j++)
    {
        // If there is no edge between vertex u and vertex j, skip to the next adjacent vertex.
        if (graph.getWeight(u, j) == 0)
        {
            continue;
        }
         // if vertex j is not yet colored, assign it a color different from vertex u.
        if (colors[j] == 0)
        {
            colors[j] = 3 - colors[u]; 
            bool res = DFSvisitColors(graph, j, colors); 
            if (!res) 
            {
                  return res;
            }
        }

        //if vertex j has the same color as vertex u and they are not the same vertex, return false =graph not bipartite
        else if (colors[j] == colors[u] && j != u)
        {
            return false;
        }
    }
    return true;
}
