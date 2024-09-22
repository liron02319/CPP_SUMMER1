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


 void Graph::loadGraph(vector<vector<int>>adjacencyMatrix) {
        
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
int Graph::getWeight(size_t  u, size_t  v){
    
            return graphAdjacencyMatix[u][v];
        }




/*
Function : numberOfVerticesInGraph
 //return the number Of Vertices In Graph 
*/
size_t  Graph::numberOfVerticesInGraph()
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




Graph Graph::operator+(const Graph &other)
{
  vector<vector<int>> newMatrix(this->graphAdjacencyMatix.size(), vector<int>(this->graphAdjacencyMatix.size(), 0));
  vector<vector<int>> myadjMatrix = this->graphAdjacencyMatix;
  vector<vector<int>> otheradjMatrix = other.graphAdjacencyMatix;

  if (this->graphAdjacencyMatix.size() != otheradjMatrix.size())
  {
    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
  }

  for (size_t i = 0; i < myadjMatrix.size(); i++)
  {
    for (size_t j = 0; j < myadjMatrix[i].size(); j++)
    {
      newMatrix[i][j] = myadjMatrix[i][j] + otheradjMatrix[i][j];
    }
  }

  Graph g;
  g.loadGraph(newMatrix);
  return g;
}

Graph &Graph::operator+=(const Graph &other)
{
  vector<vector<int>> otheradjMatrix = other.graphAdjacencyMatix;

  if (this->graphAdjacencyMatix.size() != otheradjMatrix.size())
  {
    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
  }

  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); i++)
  {
    for (size_t j = 0; j < this->graphAdjacencyMatix[i].size(); j++)
    {
      this->graphAdjacencyMatix[i][j] += otheradjMatrix[i][j];
    }
  }

  return *this;
}


Graph &Graph::operator++()
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
  return *this;
}

Graph Graph::operator++(int)
{
  Graph g = *this;

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
  return g;
}

Graph Graph::operator-(const Graph &other)
{
  vector<vector<int>> newMatrix(this->graphAdjacencyMatix.size(), vector<int>(this->graphAdjacencyMatix.size(), 0));
  vector<vector<int>> otheradjMatrix = other.graphAdjacencyMatix;

  if (this->graphAdjacencyMatix.size() != otheradjMatrix.size())
  {
    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
  }

  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); i++)
  {
    for (size_t j = 0; j < this->graphAdjacencyMatix[i].size(); j++)
    {
      newMatrix[i][j] = this->graphAdjacencyMatix[i][j] - otheradjMatrix[i][j];
    }
  }

  Graph g;
  g.loadGraph(newMatrix);
  return g;
}

Graph &Graph::operator-=(const Graph &other)
{
  vector<vector<int>> otheradjMatrix = other.graphAdjacencyMatix;
/*
  if (this->graphAdjacencyMatix.size() != otheradjMatrix.size())
  {
    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
  }*/

  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); i++)
  {
    for (size_t j = 0; j < this->graphAdjacencyMatix[i].size(); j++)
    {
      this->graphAdjacencyMatix[i][j] -= otheradjMatrix[i][j];
    }
  }

  return *this;
}

Graph &Graph::operator-()
{
  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); i++)
  {
    for (size_t j = 0; j < this->graphAdjacencyMatix[i].size(); j++)
    {
      this->graphAdjacencyMatix[i][j] = -this->graphAdjacencyMatix[i][j];
    }
  }

  return *this;
}

Graph &Graph::operator--()
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

Graph Graph::operator--(int)
{
  Graph g = *this;

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
  return g;
}

Graph &Graph::operator*(int num)
{
  vector<vector<int>> newMatrix (this->graphAdjacencyMatix.size(), vector<int>(this->graphAdjacencyMatix[0].size(), 0));
  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); i++)
  {
    for (size_t j = 0; j < this->graphAdjacencyMatix[i].size(); j++)
    {
      newMatrix[i][j] = this->graphAdjacencyMatix[i][j] * num;
    }
  }

  Graph *g = new Graph();
  g->loadGraph(newMatrix);
  return *g;
}

Graph &Graph::operator*=(int num)
{
  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); i++)
  {
    for (size_t j = 0; j < this->graphAdjacencyMatix[0].size(); j++)
    {
      this->graphAdjacencyMatix[i][j] *= num;
    }
  }

  return *this;
}

// matrix multiplication
Graph &Graph::operator*(const Graph &other)
{
  if(this->graphAdjacencyMatix.size() != other.graphAdjacencyMatix.size())
  {
    throw invalid_argument("Invalid graph: The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
  }
  
  vector<vector<int>> newMatrix(this->graphAdjacencyMatix.size(), vector<int>(other.graphAdjacencyMatix[0].size(), 0));
  vector<vector<int>> otheradjMatrix = other.graphAdjacencyMatix;

  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); ++i)
  {
    for (size_t j = 0; j < otheradjMatrix[0].size(); ++j)
    {
      for (size_t k = 0; k < this->graphAdjacencyMatix[0].size(); ++k)
      {
        newMatrix[i][j] += this->graphAdjacencyMatix[i][k] * otheradjMatrix[k][j];
      }
    }
  }

  Graph *g = new Graph();
  g->loadGraph(newMatrix);
  return *g;
}

Graph &Graph::operator*=(const Graph &other)
{
  if(this->graphAdjacencyMatix.size() != other.graphAdjacencyMatix.size())
  {
    throw invalid_argument("Invalid graph: The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
  }
  
  vector<vector<int>> newMatrix(this->graphAdjacencyMatix.size(), vector<int>(other.graphAdjacencyMatix[0].size(), 0));
  vector<vector<int>> otheradjMatrix = other.graphAdjacencyMatix;

  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); ++i)
  {
    for (size_t j = 0; j < otheradjMatrix[0].size(); ++j)
    {
      for (size_t k = 0; k < this->graphAdjacencyMatix[0].size(); ++k)
      {
        newMatrix[i][j] += this->graphAdjacencyMatix[i][k] * otheradjMatrix[k][j];
      }
    }
  }

  this->loadGraph(newMatrix);
  return *this;
}

Graph &Graph::operator/(int num)
{
  vector<vector<int>> newMatrix (this->graphAdjacencyMatix.size(), vector<int>(this->graphAdjacencyMatix[0].size(), 0));
  if (num == 0)
  {
    throw invalid_argument("Invalid argument: Division by zero.");
  }

  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); i++)
  {
    for (size_t j = 0; j < this->graphAdjacencyMatix[i].size(); j++)
    {
      newMatrix[i][j] = this->graphAdjacencyMatix[i][j] / num;
    }
  }

  Graph *g = new Graph();
  g->loadGraph(newMatrix);
  return *g;
}

Graph &Graph::operator/=(int num)
{
  if (num == 0)
  {
    throw invalid_argument("Invalid argument: Division by zero.");
  }

  for (size_t i = 0; i < this->graphAdjacencyMatix.size(); i++)
  {
    for (size_t j = 0; j < this->graphAdjacencyMatix[i].size(); j++)
    {
      this->graphAdjacencyMatix[i][j] /= num;
    }
  }

  return *this;
}

bool Graph::operator==(const Graph &other)
{
  return this->graphAdjacencyMatix == other.graphAdjacencyMatix;
}

bool Graph::operator>(const Graph &other)
{
  size_t rowsA = this->graphAdjacencyMatix.size();
  size_t colsA = this->graphAdjacencyMatix[0].size();
  size_t rowsB = other.graphAdjacencyMatix.size();
  size_t colsB = other.graphAdjacencyMatix[0].size();

  for (size_t i = 0; i <= rowsA - rowsB; ++i)
  {
    for (size_t j = 0; j <= colsA - colsB; ++j)
    {
      bool found = true;
      for (size_t k = 0; k < rowsB; ++k)
      {
        for (size_t l = 0; l < colsB; ++l)
        {
          if (this->graphAdjacencyMatix[i + k][j + l] != other.graphAdjacencyMatix[k][l])
          {
            found = false;
            break;
          }
        }
        if (!found)
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

bool Graph::operator>=(const Graph &other)
{
  return *this > other || *this == other;
}

bool Graph::operator<(const Graph &other)
{
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

bool Graph::operator<=(const Graph &other)
{
  return *this < other || *this == other;
}

bool Graph::operator!=(const Graph &other)
{
  return !(*this == other);
}

ostream &ariel::operator<<(ostream &os, const Graph &g)
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

