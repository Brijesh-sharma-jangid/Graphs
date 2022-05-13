#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;


long long distance(vector<pair<int,int> > adj[],int s, int t,int n) {
    vector<long long> dist(n+1,1e9);
    dist[s] = 0;
    priority_queue< pair<int,int>,vector<pair<int,int>>,std::greater<pair<int,int>>> pq;    
    pq.push({0,s});
    while(!pq.empty()){
		int val = pq.top().second;
		pq.pop();
		for(auto it : adj[val]){
			int weight = it.second;
			int node = it.first;
			if(dist[node] > dist[val] + weight){
				dist[node] = dist[val] + weight;
				pq.push({dist[node],node});
			}
		}
	}

	
  if(dist[t] == 1e9){
     return -1;
  }
  else{
	  return dist[t];
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<pair<int,int> > adj[n];
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back({y-1,w});
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t, n);
}
