  #include<iostream>
  #include <bits/stdc++.h> 
  #include<vector>
  #include<map>
  #include<unordered_map>
  #include<algorithm>
  #include<set>
  #include<cmath>
  #include <cstdlib>
  #include <math.h>
  #include<string>

  #define boost ios::sync_with_stdio(false); cin.tie(0)
  typedef long long ll; 
  using namespace std;


int main(){

    int n,m,s;
    cin >> n >> m >> s;

    vector<vector<int>> nums(m,vector<int>(3));

    vector<int> visited(n+1,0);
    for(int i = 0;i<m;i++){
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
    }

    vector<vector<pair<int,int>>>adj(n+1);

    for(int i = 0;i<m;i++){
        //u->{v,weight(u,v)}
        adj[nums[i][0]].push_back({nums[i][1],nums[i][2]});
        adj[nums[i][1]].push_back({nums[i][0],nums[i][2]});
    }

    vector<int> d(n+1,INT_MAX);

    d[s] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;   //min_heap

    pq.push({0,s});
    int u = s;
    while (!pq.empty())
    {
        pair<int,int> p = pq.top();
        int dis = p.first;
        u = p.second;
        if(visited[u]) continue;
        visited[u] = 1;
        for(auto itr : adj[u]){
            //relaxation
            if(d[itr.first]>(dis + itr.second)){
                d[itr.first] = dis + itr.second;
                pq.push({d[itr.first],itr.first});
            }
        }
        pq.pop();
    }

    for(int k : d)cout << k << " ";
    


}


