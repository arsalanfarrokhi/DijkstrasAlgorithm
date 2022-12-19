//Importing the header file with the class declaration
#include "Graph.hpp"
#include <iostream>
//Adding a vertex to the map with adjacency list
void Graph::addVertex(std::string label){
  adj[label];
};

//Removing a vertex from the adjacency list
void Graph::removeVertex(std::string label){
  adj.erase(label);
  for(auto i : adj){
    i.second.erase(label);
  }
}

//Adding an edge to the adjacency list
void Graph::addEdge(std::string label1, std::string label2, unsigned long weight){
  adj[label1][label2] = weight;
  adj[label2][label1] = weight;
  
};

//Removing an edge from the adjacency list
void Graph::removeEdge(std::string label1, std::string label2){
  adj[label1].erase(label2);
  adj[label2].erase(label1);
};

//A function to return the distance of the shortest path as well as the path itself
unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path){
  
  //Declaring a map for visited nodes and queue to perform the breadth-first search 
  map<string,int> visited;
  queue<string> unvisited;
  
  //Initializing shortest_path map with a very big number that will be bigger than any possible values for distances and setting up the starting node in the both maps
  for(auto i : adj){
    
    if(i.first ==  startLabel){
      shortest_path[i.first] = 0;
      prev[i.first] = startLabel;
      }
    else{
      shortest_path[i.first] = 123456789;
      prev[i.first] = "\0";
    }
  }
  
  //Adding the starting node to the queue
  unvisited.push(startLabel);
  
  //BFS
  while(!unvisited.empty()){
    //Extracting the first element
    string current = unvisited.front();
    //If it wasn't visited -> get its path and compare the path to the node plus from the node to its children with the shortest path of its children
    if(visited[current] != 1){
      unsigned long shortest_dist = shortest_path[current];
      for(auto edge : adj[current]){
        string child = edge.first;
        unvisited.push(child);
        unsigned long dist = edge.second;
        //If the path to the node and from the node to the child is less than the child has -> update the shortest path of the child and set the value of the previous node in the shorest path to the child is the node to track the path
        if(shortest_dist + dist < shortest_path[child]){
          prev[child] = current;
          shortest_path[child] = shortest_dist + dist;
        }
      }
    }
    //Pop the visited node from the queue
    unvisited.pop();
    //Mark it as visited
    visited[current] = 1;
  }
  
  //Tracking the path from the end-point to the starting point and adding it to path
  string cur = endLabel;
  while(cur!=startLabel){
    path.insert(path.begin(), cur);
    cur = prev[cur];
  }
  path.insert(path.begin(), startLabel);
  
  //returning the distance of the path
  return shortest_path[endLabel];
}