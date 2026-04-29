#include "Edges.h"

Edges::Edges() {
    start=new Vertex();
    end=new Vertex();
    weight=1;
    id=0;
}

Edges::Edges(Vertex *Start, Vertex *End,int Id) {
    start=new Vertex(*Start);
    end=new Vertex(*End);
    weight=1;
    id=Id;
}

Edges::Edges(const Edges &E) {
    end=new Vertex(*E.end);
    start=new Vertex(*E.start);
    id=E.id;
    weight=E.weight;
}
Edges::Edges(const Vertex &Start, const Vertex &End,int Id, int Weight) {
    end=new Vertex(End);
    start=new Vertex(Start);
    id=Id;
    weight=Weight;

}

Edges::Edges(const Vertex &Start, const Vertex &End,int Id) {
    end=new Vertex(End);
    start=new Vertex(Start);
    weight=1;
    id=Id;
}

Edges::Edges(Vertex *Start, Vertex *End,int Id, int Weight) {
    end=new Vertex(*End);
    start=new Vertex(*Start);
    weight=Weight;
    id=Id;
}

Edges::~Edges() {
    delete start;
    delete end;
}

void Edges::setStart(const Vertex &Start) {
    delete start;
    start=new Vertex(Start);
}
void Edges::setEnd(const Vertex &End) {
    delete end;
    end=new Vertex(End);
}

void Edges::setStart(Vertex *Start) {
    delete start;
    start=new Vertex(*Start);
}
void Edges::setEnd(Vertex *End) {
    delete end;
    end=new Vertex(*End);
}
Edges& Edges::operator=(const Edges& E) {
    if (this != &E) {
        delete start;
        delete end;

        start = E.start ? new Vertex(*E.start) : nullptr;
        end   = E.end   ? new Vertex(*E.end)   : nullptr;
        weight = E.weight;
        id = E.id;
    }
    return *this;
}
void Edges::setId(int Id) {id=Id;}
void Edges::setWeight(int Weight) {weight=Weight;}

Vertex *Edges::getEnd()const {return end;}
Vertex *Edges::getStart()const {return start;}
int Edges::getWeight()const {return weight;}
int Edges::getId()const{return id;}
