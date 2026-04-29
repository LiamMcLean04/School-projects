// Liam McLean #40342966
#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
#include "Graph.h"
#include <sstream>
class DirectedGraph: public Graph {
    protected:
    Vertex* vertices;
    Edges* edges;
    const int maxVertices;
    const int maxEdges;
    int numVertices;
    int numEdges;
    public:
    DirectedGraph();
    DirectedGraph(const DirectedGraph& g);
    ~DirectedGraph() override;
    virtual bool addVertex(Vertex& v)override;
    virtual bool addVertices(Vertex *vArray) override;
    virtual bool removeVertex(Vertex& v)override;
    virtual bool addEdge(Edges& e)override;
    virtual bool remove(Edges &e) override;
    virtual bool searchVertex(const Vertex& v)override;
    virtual bool searchEdge(const Edges& e)override;
    virtual std::string toString () const override;
    virtual void display() const override;
    virtual bool clean() override;

    int getNumVerts() const;
    int getNumEdges() const;

    bool operator==(const DirectedGraph& g) const;
    bool operator>(const DirectedGraph& g) const;
    bool operator<(const DirectedGraph& g) const;
    DirectedGraph& operator=(const DirectedGraph& g);
    DirectedGraph& operator++();
    DirectedGraph operator++(int);
    DirectedGraph operator+(const DirectedGraph& g);
    friend std::ostream& operator<<(std::ostream& os, const DirectedGraph& g);

};
#endif