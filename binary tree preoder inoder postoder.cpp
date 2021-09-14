#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *ln = NULL;
	node *rn = NULL;
	
};
node *root = NULL;

node* createNode(int item)
{
	node *newnode = new node;
    if(root == NULL)
    {
	root->data = item;
	// root->ln = NULL;
	// root->rn = NULL;
    return root;   
    }
	newnode->data = item;
	// newnode->ln = NULL;
	// newnode->rn = NULL;

	return newnode;
}

void addleftright(node *pn, node *lc, node *rc)
{
	pn->ln = lc;
	pn->rn = rc;
}

void preOder(node *node)
{
    cout<<node->data<<" ";

	if(node->ln != NULL)
		preOder(node->ln);

	if(node->rn != NULL)
		preOder(node->rn);
}
 
// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(node* root)
{
    // Base Case
    if (root == NULL)
        return;
    stack<node*> nodeStack;
    nodeStack.push(root);
    while (nodeStack.empty() == false) {
        // Pop the top item from stack and print it
        node* node = nodeStack.top();
        cout<<node->data;
        nodeStack.pop();
        if (node->rn!=NULL)
            nodeStack.push(node->rn);
        if (node->ln!=NULL)
            nodeStack.push(node->ln);
    }
}

void inOder(node *node)
{
	if(node->ln != NULL)
		preOder(node->ln);

	cout<<node->data<<" ";

	if(node->rn != NULL)
		preOder(node->rn);
}

void postOder(node *node)
{
	if(node->ln != NULL)
		preOder(node->ln);

	if(node->rn != NULL)
		preOder(node->rn);
    cout<<node->data<<" "; 
}

int main()
{
	//node *root;
    int rd,pd,ld,rd;
    node *ipn,*ilc,*irc;
    cout<<"input parent node, left child, right child";
    cin>>pd,ld,rd;

    ipn = createNode(pd);
    ilc = createNode(ld);
    irc = createNode(rd);

    addleftright(ipn,ilc,irc);

	//cout<<root->data<<endl;
	preOder(root);
	return 0;
}
