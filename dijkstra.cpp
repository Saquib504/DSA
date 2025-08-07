#include<iostream>
#include <set>
using namespace std;

class Solution
{
	public:
	  //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Create a set ds for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node.
        // set stores the nodes in ascending order of the distances 
        set<pair<int,int>> st; 

        // Initialising dist list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> dist(V, 1e9); 
        
        st.insert({0, S}); 

        // Source initialised with dist=0
        dist[S] = 0;
        
        // Now, erase the minimum distance node first from the set
        // and traverse for all its adjacent nodes.
        while(!st.empty()) {
            auto it = *(st.begin()); 
            int node = it.second; 
            int dis = it.first; 
            st.erase(it); 
            
            // Check for all adjacent nodes of the erased
            // element whether the prev dist is larger than current or not.
            for(auto it : adj[node]) {
                int adjNode = it[0]; 
                int edgW = it[1]; 
                
                if(dis + edgW < dist[adjNode]) {
                    // erase if it was visited previously at 
                    // a greater cost.
                    if(dist[adjNode] != 1e9) 
                        st.erase({dist[adjNode], adjNode}); 
                        
                    // If current distance is smaller,
                    // push it into the queue
                    dist[adjNode] = dis + edgW; 
                    st.insert({dist[adjNode], adjNode}); 
                 }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return dist; 
    }
};

int main()
{
    // Driver code.
    int V = 5, E = 12, S = 1;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    int i = 0;
    adj[1].push_back({2,2});
    adj[1].push_back({4,1});
    adj[2].push_back({1,2});
    adj[2].push_back({3,4});
    adj[2].push_back({5,5});
    adj[3].push_back({5,1});
    adj[3].push_back({2,4});
    adj[3].push_back({4,3});
    adj[4].push_back({3,3});
    adj[4].push_back({1,1});
    adj[5].push_back({3,1});
    adj[5].push_back({2,5});

    

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 1; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}