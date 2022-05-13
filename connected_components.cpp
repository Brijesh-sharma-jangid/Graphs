#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int>>&adj,vector<int>&vis,int i){
    vis[i] = 1;
    for(auto it : adj[i]){
		if(!vis[it]){
			dfs(adj,vis,it);
		}
	}	
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  int n = adj.size();
  vector<int>vis(n+1,0);
  for(int i = 0; i < n; i++){
	  if(!vis[i]){
		  dfs(adj,vis,i);
		  res++;
	  }
  }
  
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
