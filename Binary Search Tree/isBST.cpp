#include
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this-&gt;key = key;
       left = right  = NULL;
   }
};
 bool solve(Node * root, Node* minNode, Node * maxNode){
        
        if(root == NULL){
            return true;
        }
        
        if(minNode!=NULL &amp;&amp; root-&gt;key &lt;= minNode-&gt;key || maxNode!=NULL &amp;&amp; root-&gt;key &gt;= maxNode-&gt;key){
            return false;
        }
        
        return solve(root-&gt;left,minNode,root) &amp;&amp; solve(root-&gt;right,root,maxNode);
    }
bool isBST(Node * root){
    //complete this method
    return solve(root,NULL,NULL);

}
