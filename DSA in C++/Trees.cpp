#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    struct Node* right;
    struct Node* left;


    Node(int data1){
        data = data1;
        right = left = nullptr;
    }
};


//Explain by chat gpt and tell time complexity

//Preorder me root left right hota hai lekin stack se banane ke liye ulta karna karna padega isliye root right left hai
vector <int> PreorderTreeTraversalIterative(Node* root) {
    vector <int> preorder;
    if (root == NULL) return preorder;
    
    stack <Node*> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right != NULL) st.push(root->right);   //Right is done before because it stack and we left to pop first so we will push it later
        if(root->left != NULL) st.push(root->left);
    }
    return preorder;
}

vector <int> InorderTreeTraversalIterative(Node* root) {
    stack <Node*> st;
    Node* node = root;
    vector <int> inorder;
    while (node != NULL || !st.empty())
    {
        if(node != NULL) {
            st.push(node);
            node = node->left;
        }
        else {
        if(st.empty()) break;
        node = st.top();
        st.pop();
        inorder.push_back(node->data);
        node = node->right;
    }
}
    return inorder;
}

//Postorder me left right root hota hai lekin stack se banane ke liye ulta karna karna padega isliye left right root hai
vector<int> PostorderTreeTraversalIterative(Node* root) {
    vector<int> postorder;
    if (root == NULL) return postorder;
    
    stack<Node*> st1, st2;
    st1.push(root);
    
    while (!st1.empty()) {
        Node* node = st1.top();
        st1.pop();
        st2.push(node);
        
        if (node->left != NULL)
        st1.push(node->left);
        
        if (node->right != NULL)
        st1.push(node->right);
    }
    
    while (!st2.empty()) {
        postorder.push_back(st2.top()->data);
            st2.pop();
        }
        return postorder;
    }
    
    
    void PreorderTreeTraversalRecursive/*Root Left Right*/ (Node* root) {
        if(root == NULL) return;
        cout << root->data << " ";
        PreorderTreeTraversalRecursive(root->left);
        PreorderTreeTraversalRecursive(root->right);
    }

    void InorderTreeTraversalRecursive(Node* root)/*Left Root Right*/ {
        if(root == NULL) return;
        InorderTreeTraversalRecursive(root->left);
        cout << root->data << " ";
        InorderTreeTraversalRecursive(root->right);
    }

    void PostorderTreeTraversalRecursive/*Left Right Root*/ (Node* root) {
        if(root == NULL) return ;
        PostorderTreeTraversalRecursive(root->left);
        PostorderTreeTraversalRecursive(root->right);
        cout << root->data << " ";
    }
/* IMPORTANT
    void inorder(struct TreeNode* root, vector<int> &v) {
    if (root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}*/


    vector<int> PostOrderTraversal2Stack(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<Node*> st1, st2;
        st1.push(root);

        while(!st1.empty()) {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left != NULL) st1.push(root->left);        //instead of ans we push it in st2
            if(root->right != NULL) st1.push(root->right);
        }
        while(!st2.empty()) {
            root = st2.top();
            st2.pop();
            ans.push_back(root->data);
        }
        return ans;
    }

    vector<int> PostOrderTraversal1Stack(Node *root) {
         vector<int> ans;
         if(root == NULL) return ans;
         stack<Node*> st;
         Node* curr = root;
         
         while (!st.empty())
         {
             if(curr != NULL) {
                 st.push(curr);
                 curr = curr->left;
                } else {
                    Node* temp = st.top()->right;
                    if(temp == NULL) {
                        temp = st.top()->right;
                        st.pop();
                        ans.push_back(temp->data);
                        while (!st.empty() && temp == st.top()->right)
                        {
                            temp = st.top();
                            st.pop();
                            ans.push_back(temp->data);
                        }   
                    }
                    else curr = temp;
                }
            }
            return ans;
        }
        
        
        
        vector<int> Pre_Post_In_Order_in_1_Traversal(Node *root) {
            if(root == NULL) return;

            vector<int> preorder;
            vector<int> postorder;
            vector<int> inorder;
            
            stack<pair<Node*,int>> st;
            st.push({root,1});

            while (!st.empty())
            {
                auto it = st.top();
                st.pop();

                //for preorder
                if(it.second == 1) {
                    preorder.push_back(it.first->data);
                    it.second++;
                    st.push(it);

                    if(it.first->left != NULL) st.push({it.first->left,1});
                }
                
                //for inorder
                else if(it.second == 2) {
                    inorder.push_back(it.first->data);
                    it.second++;
                    st.push(it);
                    
                    if(it.first->right != NULL) st.push({it.first->right,1});
                }

                //for postorder
                else {
                    postorder.push_back(it.first->data);
                }
            }
        }














Node* SearchinBST(Node* root,int val){
    while (root != NULL && root->data != val ) //while (root->data != val && root != NULL) is wrong because you are dereferencing root before checking if it is NULL. That is undefined behavior and will crash.
    {
        if(root->data < val) root = root->right;
        else root = root->left;
    }
    return root;
}

int floorinBST (Node *root, int key) {
    int floor = -1;
    if (root->data == key)
    {
        floor = root->data;
        return floor;
    }

    if (root->data < key)
    {
        floor = root->data;
        root = root->right;
    }
    else
    {
        root = root->left;
    }
    return floor;
}


bool GetPathHelper (Node* root, vector<int> &arr, int key) {
    if(!root) NULL;

    arr.push_back(root->data);

   if(GetPathHelper(root->left,arr,key) || GetPathHelper(root->right,arr,key)) return true;

   arr.pop_back();
   return false;
}

vector<int> GetPath (Node *root, int key) {
    vector<int> arr;
    if(!root) return arr;

    GetPathHelper(root,arr,key);
    return arr;
}




int main() {

    /*
            4
           / \
          2   6
         / \ / \
        1  3 5  7
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout << "Recursive Preorder: ";
    PreorderTreeTraversalRecursive(root);
    cout << "\n";

    cout << "Recursive Inorder: ";
    InorderTreeTraversalRecursive(root);
    cout << "\n";

    cout << "Recursive Postorder: ";
    PostorderTreeTraversalRecursive(root);
    cout << "\n\n";

    auto pre = PreorderTreeTraversalIterative(root);
    auto in  = InorderTreeTraversalIterative(root);
    auto post = PostorderTreeTraversalIterative(root);

    cout << "Iterative Preorder: ";
    for (int x : pre) cout << x << " ";
    cout << "\n";

    cout << "Iterative Inorder: ";
    for (int x : in) cout << x << " ";
    cout << "\n";

    cout << "Iterative Postorder: ";
    for (int x : post) cout << x << " ";
    cout << "\n\n";

    int key = 5;
    Node* found = SearchinBST(root, key);
    if (found)
        cout << "BST Search: Found " << found->data << "\n";
    else
        cout << "BST Search: Not found\n";
    
    return 0;
}