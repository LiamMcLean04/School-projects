// Liam McLean #40342966
#include "Vertex.h"
int Vertex::verteicies_created=0;
Vertex::Vertex():value(0),id(0) {
    verteicies_created++;
}

Vertex::Vertex(const int Value,const int Id):value(Value),id(Id) {
    verteicies_created++;
}

Vertex::Vertex(const Vertex &vertex):value(vertex.value),id(vertex.id) {
    verteicies_created++;
}





int Vertex::getvalue()const {return value;}
int Vertex::getid()const {return id;}

void Vertex::setId(const int Id) {id=Id;}
void Vertex::setvalue(const int Value) {value=Value;}