#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
   int n = adj.size();
   distance[s] = 0;
   reachable[s] = 1;
   queue<int>q;
   for(int i = 0; i < n; i++){
	   for(int j = 0; j < n; j++){
		   for(int k = 0; k < adj[j].size();k++){
			   int v = adj[j][k], u = distance[j] + cost[j][k];
			   if(distance[j] != std::numeric_limits<long long>::max() && distance[v] > u){
				   distance[v] = u;
				   reachable[v] = 1;
				   if(i == n - 1){
					   q.push(v);
				   }
			   }
		   }
	   }
   }
   
   vector<int>vis(n,0);
   while(!q.empty()){
	   int nod = q.front();
	   q.pop();
	   vis[nod] = 1;
	   shortest[nod] = 0;
	   for(auto it : adj[nod]){
		   if(!vis[it]){
			   q.push(it);
			   vis[it] = 1;
			   shortest[it] = 0;
		   }
	   }
   }
   distance[s] = 0; 
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
