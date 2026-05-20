#include <iostream>
#include <bits/stdc++.h>

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
/*Can be solved using level order traversal where queue has root and coordinates*/
/*I will put it in ordered map and then take it out of map and put it in vector*/
/*Map is col row and value type and each row can have multiple values which can be same or different that is why multiset*/
/*Same code as BFS is used 
S1-> push first node then until q is empty loop
S2-> Inside loop -> save node row and col then pop and if left and right exist push into queue and insert in hash map
S3-> */
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;     // first is columns which will be sorted cause it is ordered map then another map with first being row and second being multiset ie value as it can be same or different
        q.push({root,{0,0}});

        while (!q.empty())
        {
                TreeNode* node = q.front().first;
                int r = q.front().second.first;
                int c = q.front().second.second;
                q.pop();
                if(node->left != NULL) q.push({node->left,{r+1,c-1}});
                if(node->right != NULL) q.push({node->right,{r+1,c+1}});
                
                mp[c][r].insert(node->val);     //It is not a 2d array type it is simply col then row then value type mp[c] is give me internal map and mp[c][r] is give me value of c indexed internal map at index r 
        }
        for (auto col: mp) {
            vector<int>temp;
            for (auto mp_internal_map: col.second)
            {
                for(auto val : mp_internal_map.second) {
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


using namespace std;


int main() {
    
    return 0;
}