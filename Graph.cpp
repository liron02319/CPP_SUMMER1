/*
312324247 - Liron Cohen - liron02319@gmail.com
*/

#include "Graph.hpp"

 
using namespace std;
using namespace ariel;


/*
Function : getAdjMatrix
return the  the matrix represent a graph
*/


vector<vector<int>> Graph::getAdjacencyMatrix()
{
  return graphAdjacencyMatix;
}

/*
Function : loadGraph
loadGraph the graph
*/


 void Graph::loadGraph(const vector<vector<int>>adjacencyMatrix) {
        
        graphAdjacencyMatix.resize(adjacencyMatrix.size());

        for (size_t  i = 0; i < adjacencyMatrix.size(); ++i) {
            if(adjacencyMatrix[i].size() != adjacencyMatrix.size())
                {
                    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
                }

            graphAdjacencyMatix[i].resize(adjacencyMatrix[i].size());


            for (size_t  j = 0; j < adjacencyMatrix[i].size(); ++j) 
            {
                graphAdjacencyMatix[i][j] = adjacencyMatrix[i][j];
            }

        }

      
      
    }



/*
Function : printGraph
print the graph
*/

     void Graph::printGraph() const
    {
        int count = 0;
        for(size_t  i = 0; i < graphAdjacencyMatix.size(); ++i){
            for(size_t  j = 0; j < graphAdjacencyMatix[i].size(); ++j)
            {
                if(graphAdjacencyMatix[i][j] != 0)
                {
                    count++;
                  //  cout<< "graphAdjacencyMatix[i][j]" << graphAdjacencyMatix[i][j]<< "[i]"<< i<< "[j]"<<j<<endl;
                }
            }
        }
          cout << "Graph with " << graphAdjacencyMatix.size() << 
          " vertices and " << count << " edges." << endl;
    }

/*
Function : getWeight
 //Function return the weight between 2 vertex
*/
int Graph::getWeight(size_t  u, size_t  v) const{
    
            return graphAdjacencyMatix[u][v];
        }




/*
Function : numberOfVerticesInGraph
 //return the number Of Vertices In Graph 
*/
size_t  Graph::numberOfVerticesInGraph() const
        {

            return graphAdjacencyMatix.size();

        }


int Graph::getNumEdges() const
{
    int num=0;
    for(size_t i = 0; i<graphAdjacencyMatix.size(); i++)
    {
        for(size_t j = 0; j<graphAdjacencyMatix.size(); j++)
        {
            if(graphAdjacencyMatix[i][j] != 0)
            {num++;}
        }
    }
    return num;
}


//////////// Operators

/**
     * @brief Adds two graphs by adding their adjacency matrices.
     *
     * @param other The graph to add.
     * @return Graph A new graph that is the sum of this graph and the other graph.
     * @throws std::invalid_argument If the graphs have different sizes.
     */
Graph Graph::operator+(const Graph &other) const
{
   if (this->numberOfVerticesInGraph() != other.numberOfVerticesInGraph())
        {
            throw std::invalid_argument("Graphs must be of the same size for addition.");
        }


    size_t size = this->numberOfVerticesInGraph();
    std::vector<std::vector<int>> result(size, std::vector<int>(size));


        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
            result[i][j]  = this->getWeight(i,j) + other.getWeight(i, j);
            }
        }

      Graph newGraph;
      newGraph.loadGraph(result);
        return newGraph;

}




  /**
     * @brief Adds another graph to this graph using the += operator.
     *
     * @param other The graph to add.
     * @return Graph& Reference to the current graph after addition.
     * @throws std::invalid_argument If the graphs have different sizes.
     */
Graph& Graph::operator+=(const Graph &other)
{
  if (this->numberOfVerticesInGraph() != other.numberOfVerticesInGraph())
        {
            throw std::invalid_argument("Graphs must be of the same size for addition.");
        }

        size_t size=this->numberOfVerticesInGraph();
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                this->graphAdjacencyMatix[i][j] += other.graphAdjacencyMatix[i][j];
            }
        }  

  return *this;
}


  /**
     * @brief Returns a copy of the current graph using the unary + operator.
     *
     * @return Graph A copy of the current graph.
     */
    Graph Graph::operator+() const
    {
        return *this; // Unary + returns a copy of the current graph
    }



  /**
     * @brief Subtracts another graph from this graph using the - operator.
     *
     * @param other The graph to subtract.
     * @return Graph A new graph that is the difference between this graph and the other graph.
     * @throws std::invalid_argument If the graphs have different sizes.
     */
Graph Graph::operator-(const Graph &other) const
{
  if (this->numberOfVerticesInGraph() != other.numberOfVerticesInGraph())
        {
            throw std::invalid_argument("Graphs must be of the same size for addition.");
        }


    size_t size = this->numberOfVerticesInGraph();
    std::vector<std::vector<int>> result(size, std::vector<int>(size));


        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
            result[i][j]  = this->getWeight(i,j) - other.getWeight(i, j);
            }
        }

      Graph newGraph;
      newGraph.loadGraph(result);
        return newGraph;
}



  /**
     * @brief Subtracts another graph from this graph using the -= operator.
     *
     * @param other The graph to subtract.
     * @return Graph& Reference to the current graph after subtraction.
     * @throws std::invalid_argument If the graphs have different sizes.
     */
Graph &Graph::operator-=(const Graph &other)
{
  if (this->numberOfVerticesInGraph() != other.numberOfVerticesInGraph())
        {
            throw std::invalid_argument("Graphs must be of the same size for addition.");
        }

        size_t size=this->numberOfVerticesInGraph();
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                this->graphAdjacencyMatix[i][j] -= other.graphAdjacencyMatix[i][j];
            }
        }  

  return *this;
}


  /**
     * @brief Returns the negative of the current graph using the unary - operator.
     * Each element of the adjacency matrix is multiplied by -1.
     *
     * @return Graph A new graph that is the negative of the current graph.
     */
Graph Graph::operator-() const
    {
        Graph result = *this; // Copy current graph to result

        for (size_t i = 0; i < graphAdjacencyMatix.size(); ++i)
        {
            for (size_t j = 0; j <  graphAdjacencyMatix[i].size(); ++j)
            {
                result.graphAdjacencyMatix[i][j] = -graphAdjacencyMatix[i][j];
            }
        }

        return result;
    }


// Multiplies the adjacency matrix of the current graph with the adjacency matrix of another graph.
    // Returns a new graph with the resulting adjacency matrix after matrix multiplication.
Graph Graph::operator*(const Graph &other) const
{
  if(this->graphAdjacencyMatix[0].size() != other.graphAdjacencyMatix.size())
  {
    throw invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix");
  }
  
       // Prepare the resulting adjacency matrix
        size_t rows = this->graphAdjacencyMatix.size();
        size_t cols = other.graphAdjacencyMatix[0].size();
        std::vector<std::vector<int>> newMatrix(rows, std::vector<int>(cols, 0));

         // Perform matrix multiplication
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                for (size_t k = 0; k < this->graphAdjacencyMatix[0].size(); ++k) {
                    // Accumulate the result, assuming non-negative integers
                    newMatrix[i][j] += this->graphAdjacencyMatix[i][k] * other.graphAdjacencyMatix[k][j];
                }
            }
        }


        // Create a new Graph object and load the result
        Graph newGraph;
        newGraph.loadGraph(newMatrix);
        return newGraph;


 
}





Graph Graph::operator*(int num) const
{
  vector<vector<int>> newMatrix (this->graphAdjacencyMatix.size(), vector<int>(this->graphAdjacencyMatix[0].size(), 0));
  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); i++)
  {
    for (size_t j = 0; j < this->graphAdjacencyMatix[i].size(); j++)
    {
      newMatrix[i][j] = this->graphAdjacencyMatix[i][j] * num;
    }
  }

 Graph newGraph;
      newGraph.loadGraph(newMatrix);
        return newGraph;

  
}


  // Scales the adjacency matrix of the graph by multiplying each element by the given scalar.
    // Updates the graph in place and returns a reference to the updated graph.

Graph& Graph::operator*=(int scalar)
{
  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); i++)
  {
    for (size_t j = 0; j < this->graphAdjacencyMatix[0].size(); j++)
    {
      this->graphAdjacencyMatix[i][j] *= scalar;
    }
  }

  return *this;
}

// Scales the adjacency matrix of the graph by multiplying each element by the given scalar.
    // Updates the graph in place and returns a reference to the updated graph.

// Graph *= Graph
Graph& ariel::operator*=(Graph& g1, const Graph& g2){
    g1 = g1*g2;
    return g1;
}



  // Creates and returns a new graph where the adjacency matrix is divided by the given scalar.
    // Throws an exception if the scalar is zero.
Graph Graph::operator/(int num) const
{
  vector<vector<int>> newMatrix (this->graphAdjacencyMatix.size(), vector<int>(this->graphAdjacencyMatix[0].size(), 0));
  if (num == 0)
  {
    throw invalid_argument("Invalid argument: Division by zero.");
  }

  Graph result;
  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); i++)
  {
    for (size_t j = 0; j < this->graphAdjacencyMatix[i].size(); j++)
    {
      newMatrix[i][j] = this->graphAdjacencyMatix[i][j] / num;
    }
  }

   result.loadGraph(newMatrix);
    return result;
}


  // Scales down the adjacency matrix of the graph by dividing each element by the given scalar.
    // Updates the graph in place and throws an exception if the scalar is zero.
Graph& Graph::operator/=(int num)
{
    // Iterate through the adjacency matrix and divide each element by num
    for (size_t i = 0; i < graphAdjacencyMatix.size(); ++i) {
        for (size_t j = 0; j < graphAdjacencyMatix[i].size(); ++j) {
            this->graphAdjacencyMatix[i][j] /= num; // Integer division
        }
    }

    return *this; // Return the current graph
}






// Pre-increment ++n
//first n will increase and then return him
Graph& Graph::operator++()
{
  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); i++)
  {
    for (size_t j = 0; j < this->graphAdjacencyMatix[i].size(); j++)
    {
      if (this->graphAdjacencyMatix[i][j] != 0)
      {
        this->graphAdjacencyMatix[i][j]++;
      }
    }
  }
  return *this; // Return the updated graph
}


// Post-increment n++
//n return and after that increase 
Graph Graph::operator++(int)
{
   Graph temp = *this; // Save the current state
        ++(*this);          // Use pre-increment to update the current object
        return temp;        // Return the old state
}





 
// Pre-increment --n
Graph& Graph::operator--()
{
  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); i++)
  {
    for (size_t j = 0; j < this->graphAdjacencyMatix[i].size(); j++)
    {
      if (this->graphAdjacencyMatix[i][j] != 0)
      {
        this->graphAdjacencyMatix[i][j]--;
      }
    }
  }
  return *this;
}


// Post-increment n--

Graph Graph::operator--(int)
{
   Graph temp = *this; // Save the current state
        --(*this);          // Use pre-decrement to update the current object
        return temp;        // Return the old state
}


 // Overloaded stream insertion operator for printing the graph
ostream& ariel::operator<<(ostream &os, const Graph &g)
{
  for (size_t i = 0; i < g.graphAdjacencyMatix.size(); ++i)
    {
        os << "[";
        for (size_t j = 0; j < g.graphAdjacencyMatix[i].size(); ++j)
        {
            os << g.graphAdjacencyMatix[i][j];
            if (j < g.graphAdjacencyMatix[i].size() - 1) // Check if it's not the last element
            {
                os << ",";
            }
        }
        os << "]";
        os << endl;
    }

    return os;
}


// Comparison operators

  // Compares two graphs based on their submatrix relationship and the number of edges and vertices.
    // Returns true if the current graph is less than the other graph.
bool Graph::operator<(const Graph &other) const
{

   if (checkIfAdjacencyMatrixEquel(other)) // if this graph equal
        {
            return false;
        }

   if (other.containsSubmatrix(*this) ) // if this graph is sub graph of other graph or they are equels so this not > the other
        {
            return true;
        }

        if (this->getNumEdges() < other.getNumEdges())
        {
            return true;
        }
        else if (this->getNumEdges() > other.getNumEdges())
        {
            return false;
        }

        if (this->numberOfVerticesInGraph() > other.numberOfVerticesInGraph())
        {
            return false;
        }
        else if (this->numberOfVerticesInGraph() < other.numberOfVerticesInGraph())
        {
            return true;
        }
        return false;
  
}

    // Compares two graphs and returns true if the current graph is greater than or equal to the other graph.

bool Graph::operator>=(const Graph &other) const
{
  return (*this > other) || (*this == other) ;
}

bool Graph::operator>(const Graph &other) const
{
  return (other.operator<(*this));

}

bool Graph::operator<=(const Graph &other) const
{
  return (*this < other) || (*this == other) ;
}

    // Compares two graphs for equality based on their adjacency matrices and edge counts.
    // Returns true if the matrices and edge counts are equal.
bool Graph::operator==(const Graph &other) const
{

    // Check if the number of vertices is the same

     if (this->numberOfVerticesInGraph() != other.numberOfVerticesInGraph()) {
        throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }  // If not, they are not equal


   
      if (checkIfAdjacencyMatrixEquel(other) == true)
        { // check if the matrixes equel
            return true;
        }
        if (*this > other || *this < other)
        {
            return false;
        }
        return true;
 

}


bool Graph::operator!=(const Graph &other) const
{
  return !(*this == other);
}


    // Method to check if 'other' is a submatrix of 'this'

bool Graph::containsSubmatrix(const Graph &other) const {

   size_t rowsA = this->graphAdjacencyMatix.size();
  size_t colsA = this->graphAdjacencyMatix[0].size();
  size_t rowsB = other.graphAdjacencyMatix.size();
  size_t colsB = other.graphAdjacencyMatix[0].size();

  for (size_t i = 0; i <= rowsA - rowsB; ++i)
  {
    for (size_t j = 0; j <= colsA - colsB; ++j)
    {
      bool found = false;
      for (size_t k = 0; k < rowsB; ++k)
      {
        for (size_t l = 0; l < colsB; ++l)
        {
          if (this->graphAdjacencyMatix[i + k][j + l] != other.graphAdjacencyMatix[k][l])
          {
            found = true;
            break;
          }
        }
        if (found)
        {
          break;
        }
      }
      if (found)
      {
        return true;
      }
    }
  }
  return false;
}

 // Checks if the adjacency matrix of the current graph is equal to that of the other graph.
    // Returns true if they are equal in terms of vertex count and edge weights.
    bool Graph::checkIfAdjacencyMatrixEquel(const Graph &other) const
    {
        if (other.numberOfVerticesInGraph() != this->numberOfVerticesInGraph())
        {
            return false;
        }

        for (size_t i = 0; i < other.numberOfVerticesInGraph(); ++i)
        {

            for (size_t j = 0; j < other.numberOfVerticesInGraph(); ++j)
            {
                if (graphAdjacencyMatix[i][j] != other.graphAdjacencyMatix[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }