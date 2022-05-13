#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
using std::vector;
using std::pair;
using std::priority_queue;

struct edge{
	int u,v;
	double w;
	edge(int f,int s,double we){
		u = f, v = s,w = we;
	}
};

double weight(int x1,int x2,int y1,int y2){
   return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));	
}

int findPar(int u,vector<int>&parent){
   if(parent[u] == u){
	   return u;
   }
   return parent[u] = findPar(parent[u],parent);	
}
void Union(int u,int v,vector<int>&rank,vector<int>&parent){
   u = findPar(u,parent);
   v = findPar(v,parent);
   if(rank[u] < rank[v]){
	   parent[u] = v;
   }
   else if(rank[u] > rank[v]){
	   parent[v] = u;
   }
   else{
	   parent[u] = v;
	   rank[v]++;
   }	
}

double minimum_distance(vector<pair<int,int>> coords) {
  double result = 0.;
  int n = coords.size();
  vector<edge>edges;
  vector<pair<int,double>>adj[n];
  for(int i = 0; i < n; i++){
	  for(int j = i+1; j < n; j++){
		  edges.push_back(edge(i,j,weight(coords[i].first,coords[j].first,coords[i].second,coords[j].second)));
	  }
  }
  sort(edges.begin(),edges.end(),[](edge a,edge b){return a.w < b.w;});
  
    vector<int> parent(n);
	for(int i = 0;i<n;i++) 
	    parent[i] = i; 
	vector<int> rank(n, 0); 
  
   for(auto it : edges){
	   if(findPar(it.u,parent) != findPar(it.v,parent)){
		   result += it.w;
		   Union(it.u,it.v,rank,parent);
	   }
   }
   
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<pair<int,int>> coords;
  for (size_t i = 0; i < n; i++) {
    int x,y;
    std::cin >> x >> y;
    coords.push_back({x,y});
  }
  std::cout << std::setprecision(10) << minimum_distance(coords) << std::endl;
}
