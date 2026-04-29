// Liam McLean #40342966
#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(): maxVertices(20),maxEdges(20),numVertices(0),numEdges(0){
    vertices=new Vertex[maxVertices];
    edges=new Edges[maxEdges];
}

DirectedGraph::DirectedGraph(const DirectedGraph &g):maxVertices(20),maxEdges(20),numVertices(g.numVertices),numEdges(g.numEdges) {
    vertices=new Vertex[maxVertices];
    edges=new Edges[maxEdges];
    for (int i=0;i<g.numVertices;i++) {
        vertices[i]=g.vertices[i];

    }
    for (int i=0;i<g.numEdges;i++) {
        edges[i]=g.edges[i];
    }

}

DirectedGraph::~DirectedGraph() {
    delete[] vertices;
    delete[] edges;
}
bool DirectedGraph::addVertex(Vertex& v) {
    if (numVertices == maxVertices-1) {
        std::cout<<"max capacity of vertices."<<std::endl;
        return false;
    }else
        for (int i=0;i<numVertices;i++) {
            if (vertices[i].getid()==v.getid()) {
                std::cout<<"Vertex already exists."<<std::endl;
                return false;
            }
        }
    vertices[numVertices]=v;
    numVertices++;
    std::cout<<"Vertex added."<<std::endl;
    return true;
}
//made it so that if you want to add an array of vertices, use vertex of id value -1 is the end point.
bool DirectedGraph::addVertices(Vertex *vArray) {
    if (vArray==nullptr) {
        std::cout<<"null vertex array.";
        return false;
    }
    if (numVertices == maxVertices-1) {
        std::cout<<"max capacity of vertices.";
        return false;
    }
    int i=0;
    while (vArray[i].getid()!=-1) {
        addVertex(vArray[i]);
        i++;
    }
    std::cout<<"vertices added"<<std::endl;
    return true;
    }


bool DirectedGraph::removeVertex(Vertex& v) {
    if (numVertices==0) {
        std::cout<<"no vertices exists."<<std::endl;
        return false;
    }
    for (int i=numEdges-1;i>=0;i--) {
        if (edges[i].getStart()->getid()==v.getid()||edges[i].getEnd()->getid()==v.getid()) {
            edges[i]=edges[numEdges-1];
            numEdges--;
        }
    }
    for (int i=numVertices;i>=0;i--) {
        if (vertices[i].getid()==v.getid()) {
            vertices[i]=vertices[numVertices-1];
            numVertices--;
            std::cout<<"vertex removed"<<std::endl;
            return true;
        }
    }
    std::cout<<"vertex not found"<<std::endl;
    return false;
}

bool DirectedGraph::addEdge(Edges &e) {
    if (e.getStart()->getid()<=-1||e.getEnd()->getid()<=-1) {
        std::cout<<"invalid vertex"<<std::endl;
        return false;
    }
    if (numEdges==maxEdges) {
        std::cout<<"max capacity of edges.";
        return false;
    }
    for (int i=0;i<numEdges;i++) {
        if (edges[i].getStart()->getid()==e.getStart()->getid()&&edges[i].getEnd()->getid()==e.getEnd()->getid()) {
            std::cout<<"edge already exists."<<std::endl;
            return false;
        }
    }
    if (!searchVertex(*(e.getStart()))) {
            addVertex(*(e.getStart()));
        }
    if (!searchVertex(*(e.getEnd()))) {
        addVertex(*(e.getEnd()));
    }

    edges[numEdges]=e;
    numEdges++;
    std::cout<<"edge added"<<std::endl;
    return true;
}

bool DirectedGraph::remove(Edges &e) {
    for (int i=numEdges-1;i>=0;i--) {
        if (edges[i].getStart()->getid()==e.getStart()->getid()&&edges[i].getEnd()->getid()==e.getEnd()->getid()) {
            edges[i]=edges[numEdges-1];
            numEdges--;
            std::cout<<"edge removed"<<std::endl;
            return true;
        }
    }
    std::cout<<"edge not found"<<std::endl;
    return false;
}

bool DirectedGraph::searchVertex(const Vertex &v) {
    for (int i=0;i<numVertices;i++) {
        if (vertices[i].getid()==v.getid()) {
            std::cout<<"vertex found."<<std::endl;
            return true;
        }
    }
    std::cout<<"vertex not found"<<std::endl;
    return false;
}

bool DirectedGraph::searchEdge(const Edges &e) {
    for (int i=0;i<numEdges;i++) {
        if(edges[i].getStart()->getid()==e.getStart()->getid()&&edges[i].getEnd()->getid()==e.getStart()->getid()) {
            std::cout<<"edge found."<<std::endl;
            return true;
        }
    }
    std::cout<<"edge not found"<<std::endl;
    return false;
}
std::string DirectedGraph::toString() const {
    if (numEdges==0) {
        return "no edges exist";
    }
    //Ensuring no accidental null pointer access.
    std::ostringstream out;
    for (int i=0;i<numEdges;i++) {
        if (edges[i].getStart()!=nullptr&&edges[i].getEnd()!=nullptr) {
            out <<"Edge "<<edges[i].getId()<<":("
            <<edges[i].getStart()->getid()<<"->"<<edges[i].getEnd()->getid()<<")"<<"weight:("<<edges[i].getWeight()<<");\n";
        }
        else {
            out<< edges[i].getId()<< " has an invalid vertex\n";
        }
    }
    return out.str();
}

void DirectedGraph::display() const {
    std::cout<<"Display:"<<std::endl;
    std::cout<< toString();
}

bool DirectedGraph::clean() {
    delete[] vertices;
    delete[] edges;
    numVertices=0;
    numEdges=0;
    vertices= new Vertex[maxVertices];
    edges= new Edges[maxEdges];
    return true;
}

int DirectedGraph::getNumVerts() const {return numVertices;}
int DirectedGraph::getNumEdges() const {return numEdges;}

bool DirectedGraph::operator==(const DirectedGraph &g) const {
    if (numVertices!=g.numVertices||numEdges!=g.numEdges) {
        return false;
    }else

    for (int i=0;i<this->numVertices;i++) {
        bool found=false;
        for (int j=0;j<g.numVertices;j++) {
            if (vertices[i].getid()==g.vertices[j].getid()) {
            found=true;
                break;
            }
        }
        if (!found){return false;}
    }
    for (int i=0;i<this->numEdges;i++) {
        bool found=false;
        for (int j=0;j<g.numEdges;j++) {
            if (edges[i].getStart()->getid()==g.edges[j].getStart()->getid()) {
                found=true;
            }
        }
        if (!found){return false;}
    }
    return true;
}

DirectedGraph& DirectedGraph::operator=(const DirectedGraph &g) {
    if (*this==g) {
        return *this;
    }
    this->clean();
    for (int i=0;i<g.numVertices;i++) {
        this->vertices[i]=g.vertices[i];
        this->numVertices++;
    }
    for (int i=0;i<g.numEdges;i++) {
        this->edges[i]=g.edges[i];
        this->numEdges++;
    }
    return *this;
}

DirectedGraph &DirectedGraph::operator++() {
    for (int i=0;i<numEdges;i++) {
        edges[i].setWeight(edges[i].getWeight()+1);
    }
    return *this;
}
DirectedGraph DirectedGraph::operator++(int) {
    DirectedGraph temp=*this;
    ++*this;
    return temp;
}

DirectedGraph DirectedGraph::operator+(const DirectedGraph &g) {
    DirectedGraph result;
    for (int i=0;i<numEdges;i++) {
        result.addEdge(edges[i]);
    }
    for (int i=0;i<numVertices;i++) {
        result.addVertex(vertices[i]);
    }
    for (int i=0;i<g.numEdges;i++) {
        result.addEdge(g.edges[i]);
    }
    for (int i=0;i<g.numVertices;i++) {
        result.addVertex(g.vertices[i]);
    }
    return result;
}
bool DirectedGraph::operator>(const DirectedGraph &g)const {
    int sum1=0,sum2=0;
    for (int i=0;i<numEdges;i++) {
        sum1+=edges[i].getWeight();
    }
    for (int i=0;i<g.numEdges;i++) {
        sum2+=edges[i].getWeight();
    }
    return sum1>sum2;
}
bool DirectedGraph::operator<(const DirectedGraph &g)const {
    int sum1=0,sum2=0;
    for (int i=0;i<numEdges;i++) {
        sum1+=edges[i].getWeight();
    }
    for (int i=0;i<g.numEdges;i++) {
        sum2+=edges[i].getWeight();
    }
    return sum1<sum2;
}
std::ostream& operator<<(std::ostream& out,const DirectedGraph& g) {
    out << g.toString();
    return out;
}
