/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zig;
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 1, 0);
        for(int i=1;i<zig.size();i+=2) reverse(zig[i].begin(), zig[i].end()); 
        return zig;
    }
    
private:
    void dfs(TreeNode* start, int f, int lv){
        if(start == NULL) return;
        if(lv >= zig.size()) zig.push_back(vector<int>());
        
        zig[lv].push_back(start->val);

        if (start->left != NULL) dfs(start->left, 1-f, lv+1);
        if (start->right != NULL) dfs(start->right, 1-f, lv+1);
    }
};
