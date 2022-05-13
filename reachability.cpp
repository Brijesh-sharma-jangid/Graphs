#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int>>&adj,vector<int>&vis,int i,vector<int>&con,int cc){
      vis[i] = 1;
      con[i] = cc;
      for(auto it : adj[i]){
		  if(vis[it] != 1){
			  dfs(adj,vis,it,con,cc);
		  }
	  }
}

int reach(vector<vector<int> > &adj, int x, int y) {
    
    int maxe = adj.size();
   vector<int>vi(maxe+1,0);
   vector<int>con(maxe+1,0);
     int cc = 1;
    
        
   for(int i = 0; i < maxe; i++){
	   if(!vi[i]){
		   dfs(adj,vi,i,con,cc);
		   cc++;
	   }
   }
   
   if(con[x] == con[y] && con[x] != 0){
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
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
