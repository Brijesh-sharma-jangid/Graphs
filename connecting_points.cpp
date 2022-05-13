
/// prims algo
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
using std::vector;
using std::pair;
using std::priority_queue;


double weight(int x1,int x2,int y1,int y2){
   return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));	
}

double minimum_distance(vector<pair<int,int>> coords) {
  double result = 0.;
  int n = coords.size();
  vector<pair<int,double>>adj[n];
  for(int i = 0; i < n; i++){
	  for(int j = i+1; j < n; j++){
		  adj[i].push_back({j,weight(coords[i].first,coords[j].first,coords[i].second,coords[j].second)});
		  adj[j].push_back({i,weight(coords[i].first,coords[j].first,coords[i].second,coords[j].second)});
	  }
  }
  
  vector<double>dist(n,std::numeric_limits<double>::max());
  priority_queue< pair<double,int>, vector <pair<double,int>> , std::greater<pair<double,int>> > pq;
  dist[0] = 0;
  pq.push({0,0});
  vector<bool>vis(n,false);
  while(!pq.empty()){
	  int nod = pq.top().second;
	  pq.pop();
	  vis[nod] = true;
	  for(auto it : adj[nod]){
		  double weight = it.second;
		  int j = it.first;
		  if(dist[j] > weight && !vis[j]){
			  dist[j] = weight;
			  pq.push({dist[j],j});
		  }
	  }
  }
  
  for(auto it : dist){
	  result += it;
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
