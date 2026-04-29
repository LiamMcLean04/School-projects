// Liam McLean #40342966
#ifndef EDGES_H
#define EDGES_H
#include "Vertex.h"

class Edges {
private:
    Vertex* start;
    Vertex* end;
    int weight;
    int id;

    public:
    //constructors
    Edges();
    Edges(Vertex* Start, Vertex* End,int Id);
    Edges(Vertex* Start, Vertex* End, int ID, int Weight);
    Edges(const Edges& E);
    Edges(const Vertex& Start, const Vertex& End,int id, int Weight);
    Edges(const Vertex& Start, const Vertex& End,int Id);
    ~Edges();
    //setters
    void setStart(Vertex* Start);
    void setEnd(Vertex* End);
    void setWeight(int Weight);
    void setStart(const Vertex& Start);
    void setEnd(const Vertex& End);
    void setId(int id);
    //getters
    Vertex* getStart()const;
    Vertex* getEnd()const;
    int getWeight()const;
    int getId()const;

    Edges& operator=(const Edges& E);
};
#endif