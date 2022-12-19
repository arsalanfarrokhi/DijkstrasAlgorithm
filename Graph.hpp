/*
Written by Arsalan Farrokhi, Kevin Tran, Hanz Chua, Stephen Ali
*/
//Importing the base class and standard libraries for the algorithm
#include "GraphBase.hpp"
#include <vector>
#include <map>
#include <queue>
using namespace std;

//Inhereting the Graph class from the GraphBase class and defining non-virtual functions, as well as maps to store shortest path, 
//previous node in the shortest path, and adjecency list
class Graph : public GraphBase {
  public:
    Graph(){};
    ~Graph(){};
    void addVertex(std::string label);
    void removeVertex(std::string label);
    void addEdge(std::string label1, std::string label2, unsigned long weight);
    void removeEdge(std::string label1, std::string label2);
    unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);
  private:
    map<string, unsigned long> shortest_path;
    map<string, string> prev; 
    map<string, map<string, unsigned long>> adj;
};