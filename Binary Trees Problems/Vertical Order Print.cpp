
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

    
    void traverse(TreeNode* root, int d,map<int,map<int,vector<int> > > &m,int level){
    if(root == NULL){
        return;
    }
        
    m[d][level].push_back(root->val);

    traverse(root->left,d-1,m,level+1);
    traverse(root->right,d+1,m,level+1);
}
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int,map<int,vector<int> > > m;
    int d = 0;
    int level = 0;
    vector<int> temp;
    vector<vector<int> > v;

    traverse(root,d,m,level);
    for(auto i  : m){
        for(auto j : i.second){
            sort(j.second.begin(),j.second.end());
            temp.insert(temp.end(),j.second.begin(),j.second.end());
        }
        v.push_back(temp);
        temp.clear();
    }
    return v;
        
    }
};
