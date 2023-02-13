class Solution{
  public:
  
  void inorder(Node *root,vector<int> &in){
      if(root == NULL){
          return;
      }
      inorder(root->left,in);
      in.push_back(root->data);
      inorder(root->right,in);
  }
  void fillPostOrder(Node*root,vector<int> &in,int &index)
  {
      if(root == NULL){
          return;
      }
     
      fillPostOrder(root->left,in,index);
      fillPostOrder(root->right,in,index);
      root->data = in[++index];
       
  }
    void convertToMaxHeapUtil(Node* root)
    {
        
        vector<int> in;
        inorder(root,in);
        //reverse(in.begin(),in.end());
        int i = -1;
        fillPostOrder(root,in,i);
    }    
};