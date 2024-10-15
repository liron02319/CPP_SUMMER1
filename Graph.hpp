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

   // Default constructor
    Graph() = default;

    // Copy constructor
    Graph(const Graph &other) : graphAdjacencyMatix(other.graphAdjacencyMatix) {
        // The std::vector copy constructor handles deep copying automatically.
    }

    void loadGraph(const std::vector<std::vector<int>> adjcccccMatrix); //load the graph function
    void printGraph() const; //print the graph function

    //help functions
    size_t numberOfVerticesInGraph() const; //return the number Of Vertices In Graph 
    int getWeight(size_t  u, size_t  v) const; //return the weight between 2 vertex
    int getNumEdges()const;

    bool containsSubmatrix(const Graph &other) const;
    bool checkIfAdjacencyMatrixEquel(const Graph &other) const;

    std::vector<std::vector<int>> getAdjacencyMatrix(); //return matrix


        // Adds the adjacency matrix of the current graph with another graph
        Graph operator+(const Graph &other) const;

        // Adds the adjacency matrix of current graph with the another graph and the result equal to the current graph
        Graph& operator+=(const Graph &other);

        // Unary plus operator (identity operation)
        //Graph g1; 
        //Graph g2 = +g1;
        Graph operator+() const;


        // Subtracts the adjacency matrix of the current graph with another graph
        Graph operator-(const Graph &other) const;

        // Subtracts the adjacency matrix of current graph with the another graph and the result equal to the current graph
        Graph& operator-=(const Graph &other);

        // Unary minus operator (negates all elements in the adjacency matrix)
        Graph operator-() const;


        // Multiplies the adjacency matrix of the current graph with that of another graph
        Graph operator*(const Graph &other) const;

        // multiplying the graph by each element of the adjacency matrix by a scalar
        Graph operator*(int scalar) const;

        // multiplying the graph by each element of the adjacency matrix by a scalar and the result equal to the current graph
        Graph& operator*=(int scalar);

        // multiplying the graph by each element of the adjacency matrix by a scalar and the result equal to the current graph
        friend Graph& operator*=(Graph& g1, const Graph& g2) ;



        // Creates a new graph where each element of the adjacency matrix is divided by a scalar
        Graph operator/(int scalar) const;

        // Scales down the graph in place by dividing each element of the adjacency matrix by a scalar
        Graph& operator/=(int scalar);

        

        // Overloaded increment operators
        Graph &operator++();   // Pre-increment ++n
        Graph operator++(int); // Post-increment n++


        // Overloaded decrement operators
        Graph &operator--();   // Pre-decrement ++n
        Graph operator--(int); // Post-decrement n++


        // Overloaded stream insertion operator for printing the graph
        friend std::ostream &operator<<(std::ostream &os, const Graph &graph);


        // Comparison operators
        bool operator>(const Graph &other) const;
        bool operator>=(const Graph &other) const;
        bool operator<(const Graph &other) const;
        bool operator<=(const Graph &other) const;
        bool operator==(const Graph &other) const;
        bool operator!=(const Graph &other) const;




};

} 

#endif  // GRAPH_HPP_
