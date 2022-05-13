#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int>>&adj,vector<int>&vis,int i,vector<int>&top){
   vis[i] = 1;
   for(auto it : adj[i]){
	   if(!vis[it]){
		   dfs(adj,vis,it,top);
	   }
   }
   top.push_back(i);
}
void dfs(vector<vector<int>>&adj,vector<int>&vis,int i){
   vis[i] = 1;
   for(auto it : adj[i]){
	   if(!vis[it]){
		   dfs(adj,vis,it);
	   }
   }
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  int n = adj.size();
  vector<int>vis(n+1,0);
  vector<int>top;
  for(int i = 0; i < n; i++){
	  if(!vis[i]){
		  dfs(adj,vis,i,top);
	  }
  }
  vector<vector<int>> rev(n,vector<int>());
  for(int i = 0; i < n; i++){
	   for(int j = 0; j < adj[i].size();j++){
		   rev[adj[i][j]].push_back(i);
	   }
   }
  vector<int>viss(n+1,0);
  for(int i = top.size()-1;i >= 0; i--){
	  if(!viss[top[i]]){
		  dfs(rev,viss,top[i]);
		  result++;
	  }
  }
  
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
