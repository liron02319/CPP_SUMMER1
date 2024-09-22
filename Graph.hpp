/*
312324247 - Liron Cohen - liron02319@gmail.com
*/


/*
Class represent a Graph
*/

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <iostream>
#include <vector>
#include <stdexcept>
#include <ostream>

namespace ariel {


class Graph {

    private:
    std::vector<std::vector<int>> graphAdjacencyMatix; //AdjacencyMatrix of Graph
    

    public:
    void loadGraph(std::vector<std::vector<int>> adjcccccMatrix); //load the graph function
    void printGraph() const; //print the graph function

    //help functions
    size_t numberOfVerticesInGraph(); //return the number Of Vertices In Graph 
    int getWeight(size_t  u, size_t  v); //return the weight between 2 vertex
    int getNumEdges()const;

    
   
    std::vector<std::vector<int>> getAdjacencyMatrix(); //return matrix







    Graph operator+(const Graph &g);
    Graph &operator++();
    Graph operator++(int);
    Graph &operator+=(const Graph &g);

   
   

    Graph operator-(const Graph &g);
    Graph &operator-=(const Graph &g);
    Graph operator--(int);
    Graph &operator--();

  
    Graph &operator-();

    Graph &operator*(const Graph &g);
    Graph &operator*=(const Graph &g);
    Graph &operator*(int);
    Graph &operator*=(int);
    Graph &operator/(int);
    Graph &operator/=(int);

    bool operator==(const Graph &g);
    bool operator>(const Graph &g);
    bool operator<(const Graph &g);
    bool operator>=(const Graph &g);
    bool operator<=(const Graph &g);
    bool operator!=(const Graph &g);

    friend std::ostream &operator<<(std::ostream &os,const Graph &g);



};

} 

#endif 