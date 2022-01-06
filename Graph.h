#ifndef CS236_PROJECT1_GRAPH_H
#define CS236_PROJECT1_GRAPH_H

#include "KeyValues.h"

#include <stack>
#include <algorithm>


class Graph
{
private:

//    std::vector<std::pair<int, std::vector<int>>> graph;
  //map<int,set<int>> graph;
  std::vector<KeyValues<int>> graph;
  std::vector<std::pair<std::string, bool>> nodesVisit;
  std::set<int> markedNodes;

  std::vector<int> postOrder;
  std::vector<set<int>> SCCs;



public:
    Graph(){}
    Graph(std::vector<KeyValues<int>> graph){
        this->graph = graph;

        //initializeNodesVisit();
    }

//    void initializeNodesVisit(){
//        nodesVisit.clear();
//        for(unsigned int i = 0; i< graph.size();i++){
//            nodesVisit.push_back(std::make_pair(graph[i].getKey(),false));
//        }
//    }



    void DFS(int node){
        //We mark the node as being visited
        markedNodes.insert(node);
        int index = -1;
        for(unsigned int i = 0; i < graph.size(); i++){
            if(graph[i].getKey() == node){
                index = i;
            }
        }
        std::vector<int> adjList = graph[index].getValues();
        for(unsigned int i = 0; i< adjList.size();i++ ){
            if (!markedNodes.count(adjList[i])){
                DFS(adjList[i]);
            }
        }
        postOrder.push_back(node);
    }

    void DFSPost(){

        stack<int> DFSStacky;

        unsigned int numNodes = graph.size();
        //I want to make sure I go through each node to make the forest.
        for(unsigned int i = 0; i< numNodes;i++){
            if(!markedNodes.count(graph[i].getKey())){
                DFS(graph[i].getKey());
            }
        }


    }

    void findSCCs (){//The vector of adjacency lists has to be in order.

        for(unsigned int i =0; i < graph.size();i++){
            int node = graph[i].getKey();
            if(!markedNodes.count(node)){
                DFS(node);
                //This will be the first tree / first SCC.
                //It's all in the post order so I just need to put those into a set for the SCC
                set<int> thisSCC;
                for (unsigned int j = 0;j< postOrder.size();j++){
                    thisSCC.insert(postOrder[j]);
                }
                SCCs.push_back(thisSCC);
                postOrder.clear();
            }
        }
    }

    std::vector<int> getPostOrder(){
        return postOrder;
    }

    vector<set<int>> getSCCs(){
        return SCCs;
    }

    std::string printAdjList(){

        std::stringstream out;
        for(unsigned int i =0; i < graph.size();i++){
            out<<"R" << graph[i].getKey() <<": ";
            auto vals = graph[i].getValues();
            sort(vals.begin(), vals.end());
            for(unsigned int j = 0; j<vals.size();j++){
                out <<"R" << vals[j];
                if(j < vals.size()-1){
                    out << ",";
                }
            }
            out <<"\n";
        }
        return out.str();
    }

};




#endif //CS236_PROJECT1_GRAPH_H
