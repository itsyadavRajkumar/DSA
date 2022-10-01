#ifndef NODE_H
#define NODE_H

#include <utility>
#include <vector>
#include <cfloat>
#include <string>

//This is a Node Class for our a_star algoirthm

class Node {
    public:
    //Position of the node
    unsigned short x_coord;
    unsigned short y_coord;
    
    //Node Requirements to see if they're valid
    bool visited = false;
    bool obstacle = false;

    //Global Val is the f(x), Local Val is the g(x)
    float global_val = FLT_MAX;
    float local_val = FLT_MAX;

    std::vector<Node*> neighbors;
    Node* parent = nullptr;
};



#endif