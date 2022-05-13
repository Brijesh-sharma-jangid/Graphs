#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  int n = adj.size();
  vector<int>dist(n,1e9);
  dist[s] = 0;
  queue<int>q;
  q.push(s);
  while(!q.empty()){
	  int node = q.front();
	  q.pop();
	  for(auto it : adj[node]){
		  if(dist[it] > dist[node] + 1){
			  q.push(it);
			  dist[it] = dist[node] + 1;
		  }
	  }
  }
  if(dist[t] != 1e9){
	  return dist[t];
  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
