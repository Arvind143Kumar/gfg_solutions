class Solution {
    private:
    int countNode(struct Node *root){
        if(root == NULL){
            return 0;
        }
        int ans = 1 + countNode(root->left) + countNode(root->right);
        return ans;
    }
    bool isCBT(struct Node *root,int i, int nodeCount){
        if(root == NULL){
            return true;
        }
        if(i >= nodeCount){
            return false;
        }
        else{
        bool left = isCBT(root->left,2*i+1,nodeCount);
        bool right = isCBT(root->right,2*i+2,nodeCount);
        return left && right;
        }
    }
    
    bool ismaxOrder(struct Node *root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        if(root->right == NULL){
            return root->data > root->left->data;
        }
        else{
            bool left = ismaxOrder(root->left);
            bool right = ismaxOrder(root->right);
            
            return(left && right && (root->data > root->left->data) && (root->data > root->right->data));
        }
    }
  public:
    bool isHeap(struct Node* tree) {
        int index = 0;
        int nodeCount = countNode(tree);
        if(isCBT(tree,index,nodeCount) && ismaxOrder(tree)){
            return true;
            
        }
        else{
            return false;
        }
    }
};