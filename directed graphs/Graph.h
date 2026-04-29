// Liam McLean #40342966

#ifndef GRAPH_H
#define GRAPH_H
#include "Edges.h"
#include <string>
class Graph {
public:
    Graph();
    virtual ~Graph();
    virtual bool addVertex(Vertex& v)=0;
    virtual bool addVertices(Vertex* vArray) = 0;
    virtual bool removeVertex(Vertex& v) = 0;
    virtual bool addEdge(Edges& e) = 0;
    virtual bool remove(Edges& e)=0;
    virtual bool searchVertex(const Vertex& v) = 0;
    virtual bool searchEdge(const Edges& e) =0;
    virtual void display() const = 0;
    virtual std::string toString () const = 0;
    virtual bool clean() = 0;
};
#endif