// Liam McLean #40342966
#include "DirectedGraph.h"
using namespace std;
int main() {
   Vertex arr[5]={{400,1},{200,5},{233,6},{323,7},{500,-1}};
   Vertex A(650,3),B(900,8),L(650,10),P(648,48);
   DirectedGraph G,o;
   Edges r(A,B,1,5),t(arr[0],arr[3],3,8),y(arr[2],arr[1],6,9),
   I(L,P,64,5);
   G.addEdge(r);
   G.addEdge(y);
   G.addEdge(t);
   cout<<G<<endl;
   o.addEdge(I);
   DirectedGraph usef=o+G;
   if (usef>G) {
      cout<<usef;
   }
   ++usef;
   if (usef==usef) {
      cout<<usef;
   }


return 0;
}