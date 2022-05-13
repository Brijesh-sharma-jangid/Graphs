#include <iostream>
#include <vector>

using std::vector;

struct node{
   int u,v,w;
   node(int first,int second,int weight){
	   u = first,v = second,w = weight;
   }	
};

int negative_cycle(vector<node>edges, int n) {
   
   vector<int>dist(n+1,1e9);
   dist[0] = 0;
   for(int i = 0; i < n-1 ;i++){
	   for(auto it : edges){
		   if(dist[it.u]+it.w < dist[it.v]){
			  dist[it.v] = dist[it.u]+it.w;
		  }
	  }
  }
  
  for(auto it : edges){
		   if(dist[it.u]+it.w < dist[it.v]){
			   return 1;
			  dist[it.v] = dist[it.u]+it.w;
		  }
  }
  
   
  
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
   vector<node>edges;
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    edges.push_back(node(x-1,y-1,w));
  }
  std::cout << negative_cycle(edges, n);
}
