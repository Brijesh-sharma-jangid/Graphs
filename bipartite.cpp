#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bfs(int src,vector<vector<int>>&adj,vector<int>&mark){
	queue<int>q;
	q.push(src);
	mark[src] = 1;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto it : adj[node]){
			if(mark[it] == -1){
				mark[it] = 1 - mark[node];
				q.push(it);
			}
			else if(mark[it] == mark[node]){
				return 0;
			}
		}
	}
	return 1;
}

int bipartite(vector<vector<int> > &adj) {
	int n = adj.size();
	vector<int>mark(n,-1);
	for(int i = 0; i < n; i++){
		if(mark[i] == -1){
			if(!bfs(i,adj,mark)) return 0;
		}
	}
				
  return 1;
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
  std::cout << bipartite(adj);
}
