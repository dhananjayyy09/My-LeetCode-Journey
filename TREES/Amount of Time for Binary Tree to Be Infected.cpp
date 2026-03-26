class Solution {
public:
    vector<vector<int>> adj;
    void makeGraph(TreeNode* root){
        if(!root) return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }

        makeGraph(root->left);
        makeGraph(root->right);
    }

    int amountOfTime(TreeNode* root, int start) {
        adj.resize(100001);
        makeGraph(root);

        queue<int> q;
        unordered_set<int> vis;
        q.push(start);
        vis.insert(start);
        int time = -1;

        while(!q.empty()){
            int size = q.size();
            time++;

            while(size--){
                int node = q.front();
                q.pop();
                
                for(int adjNode : adj[node]){
                    if(!vis.count(adjNode)){
                        q.push(adjNode);
                        vis.insert(adjNode);
                    }
                }
            }
        }
        return time;
    }
};
