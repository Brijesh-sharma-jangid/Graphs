#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool dfs(vector<vector<int>>&adj,vector<int>&vis,int node,vector<int>&dfsvis){
   vis[node] = 1;
   dfsvis[node] = 1;
   for(auto it : adj[node]){
	   if(!vis[it]){
		   if(dfs(adj,vis,it,dfsvis))return true;
	   }
	   else{
		    if(dfsvis[it]){
				return true;
			}
		}
	}
    dfsvis[node] = 0;
   	return false;
}

int acyclic(vector<vector<int> > &adj) {
  
   int n = adj.size();
   vector<int>vis(n+1,0);
   vector<int>dfsvis(n+1,0);
   bool ans = false;
   for(int i = 0; i < n; i++){
	   if(!vis[i]){
		   ans = ans | dfs(adj,vis,i,dfsvis);
	   }
   }
   if(ans == true){
	   return 1;
   }
  
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}

