/*
312324247 - Liron Cohen - liron02319@gmail.com
*/
#include "doctest.h"
#include "Algorithms.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 2, 2, 0, 0},
        {2, 0, 2, 0, 0},
        {2, 2, 0, 2, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        {0, 3, 0, 0, 0, 0, 0},
        {3, 0, 0, 3, 0, 0, 0}, 
        {0, 0, 0, 3, 0, 0, 0}, 
        {0, 3, 3, 0, 0, 0, 3}, 
        {0, 0, 0, 0, 0, 0, 3}, 
        {0, 0, 0, 0, 0, 0, 3}, 
        {0, 0, 0, 3, 3, 3, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0}, 
        {0, 0, 0, 1, 0, 0, 0}, 
        {0, 1, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 1}, 
        {0, 0, 0, 1, 1, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == false);


    vector<vector<int>> graph6 = {
        {0, 0, 0, 0, 0, 0, 0},
        {-1, 0, 0, 10, 0, 0, 0}, 
        {0, 0, 0, 13, 0, 0, 0}, 
        {0, 123, 12, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 12}, 
        {0, 0, 0, 0, 0, 0, 134}, 
        {0, 0, 0, -13, -1, 11, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0-->1-->2");

    vector<vector<int>> graph2 = {
        {0, 3, 3, 0, 0},
        {3, 0, 3, 0, 0},
        {3, 3, 0, 3, 0},
        {0, 0, 3, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1 :(there is no path between 0 to 4)");

    vector<vector<int>> graph3 = {
        {0, 3, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, -2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 5}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, -1, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 6, 0, 0, 0, 0, 0, 0}, 
        {0, -1, 0, 31, 0, 0, 4, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 5) == "0-->1-->2-->5");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 3) == "1-->2-->8-->3");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 5) == "1-->2-->5");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 3) == "1-->2-->8-->3");
    CHECK(ariel::Algorithms::shortestPath(g, 8, 5) == "8-->1-->2-->5");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 7) == "-1 :(there is no path between 0 to 7)");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 5) == "-1 :(there is no path between 3 to 5)");
    CHECK(ariel::Algorithms::shortestPath(g, 6, 1) == "-1 :(there is no path between 6 to 1)");

    vector<vector<int>> graph4 = {
        {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 2, 0, 0, -5, 0, 0, 0}, 
        {0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0}, 
        {0, 0, 0, 3, 0, 0, 0, 0, 0, 0, -1}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
        {0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 6, 10) == "6-->10");
    CHECK(ariel::Algorithms::shortestPath(g, 5, 0) == "5-->9-->0");

    vector<vector<int>>graph5 = {
    {0, 1, 0, 0, 0}, 
    {1, 0, 0, -5, 0}, 
    {0, 1, 0, 0, 0}, 
    {0, -5, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    };
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 3, 1) == "There is a negative cycle");


    vector<vector<int>>graph6 = {
        {0, -5, 0, 0, 0, 0, 0, 8}, 
        {-5, 0, 7, 3, 7, 0, 0, 0}, 
        {0, 0, 0, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 7, 0, 0, 0, 0, 8, 40}, 
        {0, 0, 0, 0, 0, 0, 4, 2}, 
        {0, 0, 0, 0, 8, 4, 0, 5}, 
        {8, 0, 0, 0, 40, 2, 5, 0}, 
    };
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "There is a negative cycle");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "There is a negative cycle");
    

}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is:0-->1-->0");



    vector<vector<int>> gr = {
    {0, 0, 1, 0}, 
    {2, 0, 0, 0}, 
    {0, 3, 0, 4}, 
    {0, 0, 0, 0}, 
    };
    g.loadGraph(gr);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is:0-->2-->1-->0");

    vector<vector<int>> gr2 = {
        {0, 0, 6, 0}, 
        {2, 0, 0, 0}, 
        {0, 0, 0, 3}, 
        {0, 0, 0, 0} 
    };
    g.loadGraph(gr2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "No cycles");

    vector<vector<int>> gr3= {
        {0, 1}, 
        {1, 0} 
    };
    g.loadGraph(gr3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is:0-->1-->0");



    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is:0-->1-->0");
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "{0 2 } {1 }");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph4 =
    {
        {0, 2, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 2}, 
        {0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 2, 0}, 
        {0, 0, 0, 0, 0, 0}, 
        {0, 0, 2, 2, 0, 0} 
    };

    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "{0 4 5 } {1 2 3 }");


}









TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 3, 2, 0},
        {1, 0, 5, 0},
        {2, 1, 0, 4},
        {0, 0, 6, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));

  



}


//operators
TEST_CASE("Plus")
{
    SUBCASE("graph1 = graph2 + graph3")
    {
        ariel::Graph g1;
        ariel::Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, 2, 0}};
        g2.loadGraph(adjmat2);

        ariel::Graph g3;

        g3 = g1 + g2;

        CHECK(g3.getAdjacencyMatrix() == vector<vector<int>>{{0, 1, 0}, {3, 0, 4}, {0, 5, 0}});
    }

    SUBCASE("graph++")
    {
         ariel::Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 0, 0, 0, 0}};
        g1.loadGraph(adjmat1);
        g1++;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 2, 3, 0, 0}, {2, 0, 7, 0, 0}, {3, 7, 0, 10, 0}, {0, 0, 10, 0, 0}, {0, 0, 0, 0, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 3, 7, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {0, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat2);

        g1++;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 0, 0, 0, 0, 0}, {0, 0, 4, 8, 0, 0}, {0, 4, 0, 0, 9, 0}, {0, 8, 0, 0, -2, -1}, {0, 0, 9, -2, 0, 2}, {0, 0, 0, -1, 2, 0}});
    }

    SUBCASE("++graph")
    {
          ariel::Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 0, 0, 0, 0}};
        g1.loadGraph(adjmat1);

        ++g1;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 2, 3, 0, 0}, {2, 0, 7, 0, 0}, {3, 7, 0, 10, 0}, {0, 0, 10, 0, 0}, {0, 0, 0, 0, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 3, 7, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {0, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat2);

        ++g1;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 0, 0, 0, 0, 0}, {0, 0, 4, 8, 0, 0}, {0, 4, 0, 0, 9, 0}, {0, 8, 0, 0, -2, -1}, {0, 0, 9, -2, 0, 2}, {0, 0, 0, -1, 2, 0}});
    }

    SUBCASE("graph1 += graph2")
    {
        ariel::Graph g1;
        ariel::Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, 2, 0}};
        g2.loadGraph(adjmat2);

        g1 += g2;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 1, 0}, {3, 0, 4}, {0, 5, 0}});

        vector<vector<int>> adjmat3 = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 3, 7, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {0, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat3);

        vector<vector<int>> adjmat4 = {
            {0, -3, 0, 0, 0, 0},
            {0, 0, 1, 2, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, 4, 1},
            {1, 3, 8, -3, 0, 1},
            {2, 0, 0, -2, 1, 0}};
        g2.loadGraph(adjmat4);

        g1 += g2;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, -3, 0, 0, 0, 0}, {0, 0, 4, 9, 0, 0}, {0, 6, 0, 0, 16, 0}, {0, 14, 0, 0, 1, -1}, {1, 3, 16, -6, 0, 2}, {2, 0, 0, -4, 2, 0}});
    }
}

TEST_CASE("Minus")
{
    SUBCASE("graph1 = graph2 - graph3")
    {
        ariel::Graph g1;
        ariel::Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, 2, 0}};
        g2.loadGraph(adjmat2);

        ariel::Graph g3;

        g3 = g1 - g2;

        CHECK(g3.getAdjacencyMatrix() == vector<vector<int>>{{0, 3, 0}, {1, 0, 2}, {0, 1, 0}});
    }

    SUBCASE("graph--")
    {
        ariel::Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 0, 0, 0, 0}};
        g1.loadGraph(adjmat1);

        g1--;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 0, 1, 0, 0}, {0, 0, 5, 0, 0}, {1, 5, 0, 8, 0}, {0, 0, 8, 0, 0}, {0, 0, 0, 0, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 1, 0, 0, 1, 0},
            {0, 0, 3, 7, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {0, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat2);

        g1--;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 0, 0, 0, 0, 0}, {0, 0, 2, 6, 0, 0}, {0, 2, 0, 0, 7, 0}, {0, 6, 0, 0, -4, -3}, {0, 0, 7, -4, 0, 0}, {0, 0, 0, -3, 0, 0}});
    }

    SUBCASE("--graph")
    {
        ariel::Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 0, 0, 0, 0}};
        g1.loadGraph(adjmat1);

        --g1;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 0, 1, 0, 0}, {0, 0, 5, 0, 0}, {1, 5, 0, 8, 0}, {0, 0, 8, 0, 0}, {0, 0, 0, 0, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 3, 7, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {0, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat2);

        --g1;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 0, 0, 0, 0, 0}, {0, 0, 2, 6, 0, 0}, {0, 2, 0, 0, 7, 0}, {0, 6, 0, 0, -4, -3}, {0, 0, 7, -4, 0, 0}, {0, 0, 0, -3, 0, 0}});
    }

    SUBCASE("graph1 -= graph2")
    {
        ariel::Graph g1;
        ariel::Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, 2, 0}};
        g2.loadGraph(adjmat2);

        g1 -= g2;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 3, 0}, {1, 0, 2}, {0, 1, 0}});

        vector<vector<int>> adjmat3 = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 3, 7, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {0, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat3);

        vector<vector<int>> adjmat4 = {
            {0, -3, 0, 0, 0, 0},
            {0, 0, 1, 2, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, 4, 1},
            {1, 3, 8, -3, 0, 1},
            {2, 0, 0, -2, 1, 0}};
        g2.loadGraph(adjmat4);

        g1 -= g2;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 3, 0, 0, 0, 0}, {0, 0, 2, 5, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, -7, -3}, {-1, -3, 0, 0, 0, 0}, {-2, 0, 0, 0, 0, 0}});
    }
}

TEST_CASE("Multiplication")
{
    SUBCASE("graph1 = graph2 * graph3")
    {
        ariel::Graph g1;
        ariel::Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, 2, 0}};
        g2.loadGraph(adjmat2);

        ariel::Graph g3;
        g3 = g1 * g2;
        CHECK(g3.getAdjacencyMatrix() == vector<vector<int>>{{2, 0, 2}, {0, 4, 0}, {3, 0, 3}});

        vector<vector<int>> adjmat3 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 4, 1, 0, 5}};
        g1.loadGraph(adjmat3);

        vector<vector<int>> adjmat4 = {
            {0, 3, 8, 0, 3},
            {1, 0, 6, 2, 0},
            {2, -6, 0, 9, 0},
            {1, 0, 9, 0, 2},
            {0, 6, 0, 5, 0}};
        g2.loadGraph(adjmat4);

        g3 = g1 * g2;

        CHECK(g3.getAdjacencyMatrix() == vector<vector<int>>{{5, -12, 6, 20, 0}, {12, -33, 8, 54, 3}, {15, 6, 133, 12, 24}, {18, -54, 0, 81, 0}, {6, 24, 24, 42, 0}});
    }

    SUBCASE("graph1 *= graph2")
    {
        ariel::Graph g1;
        ariel::Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, 2, 0}};
        g2.loadGraph(adjmat2);

        g1 *= g2;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{2, 0, 2}, {0, 4, 0}, {3, 0, 3}});

        vector<vector<int>> adjmat3 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 4, 1, 0, 5}};
        g1.loadGraph(adjmat3);

        vector<vector<int>> adjmat4 = {
            {0, 3, 8, 0, 3},
            {1, 0, 6, 2, 0},
            {2, -6, 0, 9, 0},
            {1, 0, 9, 0, 2},
            {0, 6, 0, 5, 0}};
        g2.loadGraph(adjmat4);
        g1 *= g2;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{5, -12, 6, 20, 0}, {12, -33, 8, 54, 3}, {15, 6, 133, 12, 24}, {18, -54, 0, 81, 0}, {6, 24, 24, 42, 0}});
    }

    SUBCASE("graph1 = graph2 * scalar(int)")
    {
        ariel::Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        ariel::Graph g2;
        g2 = g1 * 2;

        CHECK(g2.getAdjacencyMatrix() == vector<vector<int>>{{0, 4, 0}, {4, 0, 6}, {0, 6, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 4, 1, 0, 5}};
        g1.loadGraph(adjmat2);

        g1 = g1 * 4;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 4, 8, 0, 0}, {4, 0, 24, 0, 0}, {8, 24, 0, 36, 0}, {0, 0, 36, 0, 0}, {0, 16, 4, 0, 20}});
    }

    SUBCASE("graph1 *= scalar(int)")
    {
        ariel::Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        g1 *= 2;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 4, 0}, {4, 0, 6}, {0, 6, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 4, 1, 0, 5}};
        g1.loadGraph(adjmat2);

        g1 *= 4;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 4, 8, 0, 0}, {4, 0, 24, 0, 0}, {8, 24, 0, 36, 0}, {0, 0, 36, 0, 0}, {0, 16, 4, 0, 20}});
    }
}

TEST_CASE("Division")
{
    SUBCASE("graph1 = graph2 / scalar(int)")
    {
        ariel::Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        ariel::Graph g2;
        g2 = g1 / 2;

        CHECK(g2.getAdjacencyMatrix() == vector<vector<int>>{{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 4, 1, 0, 5}};
        g1.loadGraph(adjmat2);

        g2 = g1 / 4;
        CHECK(g2.getAdjacencyMatrix() == vector<vector<int>>{{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 0, 2, 0}, {0, 0, 2, 0, 0}, {0, 1, 0, 0, 1}});
    }

    SUBCASE("graph1 /= scalar(int)")
    {
        ariel::Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        g1 /= 2;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 4, 1, 0, 5}};
        g1.loadGraph(adjmat2);

        g1 /= 4;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 0, 2, 0}, {0, 0, 2, 0, 0}, {0, 1, 0, 0, 1}});
    }
}

TEST_CASE("Compare")
{
    SUBCASE("graph1 == graph2")
    {
        ariel::Graph g1;
        ariel::Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g1 == g2);

        vector<vector<int>> adjmat3 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat3);

        vector<vector<int>> adjmat4 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g2.loadGraph(adjmat4);

        CHECK(g1 == g2);
    }

    SUBCASE("graph1 > graph2")
    {
        ariel::Graph g1;

        vector<vector<int>> adjmat1 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat1);

        ariel::Graph g2;

        vector<vector<int>> adjmat2 = {
            {0, 3, 7, 0},
            {3, 0, 0, 8},
            {7, 0, 0, -3},
            {0, 8, -3, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g1 > g2);
    }

    SUBCASE("graph1 < graph2")
    {
        ariel::Graph g1;

        vector<vector<int>> adjmat1 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat1);

        ariel::Graph g2;

        vector<vector<int>> adjmat2 = {
            {0, 3, 7, 0},
            {3, 0, 0, 8},
            {7, 0, 0, -3},
            {0, 8, -3, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g2 < g1);
    }

    SUBCASE("graph1 >= graph2")
    {
        ariel::Graph g1;

        vector<vector<int>> adjmat1 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat1);

        ariel::Graph g2;

        vector<vector<int>> adjmat2 = {
            {0, 3, 7, 0},
            {3, 0, 0, 8},
            {7, 0, 0, -3},
            {0, 8, -3, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g1 >= g2);

        ariel::Graph g3;
        vector<vector<int>> adjmat3 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g3.loadGraph(adjmat3);
        CHECK(g1 >= g3);
        CHECK(g3 >= g1);
    }

    SUBCASE("graph1 <= graph2")
    {
        ariel::Graph g1;

        vector<vector<int>> adjmat1 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat1);

        ariel::Graph g2;

        vector<vector<int>> adjmat2 = {
            {0, 3, 7, 0},
            {3, 0, 0, 8},
            {7, 0, 0, -3},
            {0, 8, -3, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g2 <= g1);

        ariel::Graph g3;
        vector<vector<int>> adjmat3 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g3.loadGraph(adjmat3);
        CHECK(g1 <= g3);
        CHECK(g3 <= g1);
    }

    SUBCASE("graph1 != graph2")
    {
        ariel::Graph g1;
        ariel::Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 1, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g1 != g2);

        vector<vector<int>> adjmat3 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, 1, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat3);

        vector<vector<int>> adjmat4 = {
             {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, 0, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g2.loadGraph(adjmat4);

        CHECK(g1 != g2);
    }
}