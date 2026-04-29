// Liam McLean #40342966
#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
class Vertex {
private:
static int verteicies_created;
int value;
int id;

public:
//constructors
Vertex();
Vertex(const int value, const int Id);
Vertex(const Vertex& vertex);
~Vertex()=default;
//seters
void setvalue(const int value);
void setId(const int id);
//getter
 int getvalue()const;
 int getid()const;


};
#endif