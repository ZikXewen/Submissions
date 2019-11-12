#include<cstdio>
#include<>
using namespace std;
struct Node{
	int data;
	Node* left, *right;
};
Node* NewNode(int data){
	Node* node = new Node; 
    node->data = data;
    node->left = node->right = NULL; 
    return node;
}
void storeBSTNodes(Node* root, vector<Node*> &nodes) { 
    if (root==NULL) return; 
    storeBSTNodes(root->left, nodes); 
    nodes.push_back(root); 
    storeBSTNodes(root->right, nodes); 
}
Node* buildTreeUtil(vector<Node*> &nodes, int start, int end) {
    if (start > end) 
        return NULL;   
    int mid = (start + end)/2; 
    Node *root = nodes[mid]; 
    root->left  = buildTreeUtil(nodes, start, mid-1); 
    root->right = buildTreeUtil(nodes, mid+1, end); 
    return root; 
} 
Node* buildTree(Node* root) { 
    vector<Node *> nodes; 
    storeBSTNodes(root, nodes); 
    int n = nodes.size(); 
    return buildTreeUtil(nodes, 0, n-1); 
}
int main(){
	
}
