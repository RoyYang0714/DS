#include <iostream>
#include<queue>
#include<string>
using namespace std;

class TreeNode {
friend class Tree;

private:
	int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode *down;
	TreeNode *up; 
};

class Tree {
public:
	void building(int x, int y, TreeNode *p);
	void LevelOrder();
	void PreOrder();
	void pre(TreeNode *p);
	void PostOrder();
	void post(TreeNode *p);

private:
	TreeNode *root;
};

int matrix[100][100];
int id[100][100];
int init;
int pf; 
int wid, hi;

int main()
{
	int num;
	int x, y;
	string command;

	cin>>num;
	cout<<num<<endl;

	while (num != 0) {
		cin>>wid>>hi;
		cin>>y>>x;

		cout<<wid<<' '<<hi<<endl;
		cout<<y<<' '<<x<<endl;

		for (int i=0; i<hi; i++) {
			for (int j=0; j<wid; j++) {
				cin>>matrix[i][j];
				id[i][j] = 0;
				if (j != wid-1) cout<<matrix[i][j]<<' ';
				else cout<<matrix[i][j]<<endl;
			}
		}

		Tree tree;
		init = 0;
		pf = 0;
		tree.building(x, y, 0);
		cin>>command;
		cout<<command<<endl;
		if (command == "Level-order-traversal") tree.LevelOrder();
		else if (command == "Pre-order-traversal") tree.PreOrder();
		else if (command == "Post-order-traversal") tree.PostOrder();
		cout<<endl;
		num--;
	}


	return 0;
}

void Tree::building(int x, int y, TreeNode *p)
{
	if (init == 0) {
		root = new TreeNode;
		root->data = matrix[x][y];
		id[x][y]=1;
		int stop = 0;
		init = 1;
		building (x, y, root);
		return;
	}
	TreeNode *tmp;

	if (y > 0 && (matrix[x][y-1] != 0) && (id[x][y-1] != 1)) {
		y--;
		tmp = new TreeNode;
		tmp->data = matrix[x][y];
		id[x][y]=1;
		//cout<<tmp->data<<endl;
		p->left = tmp;
		building (x, y, p->left);
		y++;
	} 
	if (x < hi-1 && (matrix[x+1][y] != 0) && (id[x+1][y] != 1)) {
		x++;
		tmp = new TreeNode;
		tmp->data = matrix[x][y];
		id[x][y]=1;
		//cout<<tmp->data<<endl;
		p->down = tmp;
		building (x, y, p->down);
		x--;
	}
	if (y < wid-1 && (matrix[x][y+1] != 0) && (id[x][y+1] != 1)) {
		y++;
		tmp = new TreeNode;
		tmp->data = matrix[x][y];
		id[x][y]=1;
		//cout<<tmp->data<<endl;
		p->right = tmp;
		building (x, y, p->right);
		y--;
	}
	if (x > 0 && (matrix[x-1][y] != 0) && (id[x-1][y] != 1)) {
		x--;
		tmp = new TreeNode;
		tmp->data = matrix[x][y];
		id[x][y]=1;
		//<<tmp->data<<endl;
		p->up = tmp;
		building (x, y, p->up);
		x++;
	}
	return;
}

void Tree::LevelOrder()
{
	int first = 0; 

	queue<TreeNode*> q;

	TreeNode *p = root;
	while (p) {
		if (first == 0) {
			cout<<p->data;
			first = 1;
		}
		else cout<<' '<<p->data;
		if (p->left != 0) q.push(p->left); 
		if (p->down != 0) q.push(p->down); 
		if (p->right != 0) q.push(p->right); 
		if (p->up != 0)	q.push(p->up);

		if (q.empty()) return;

		p = q.front();
		q.pop();
	}
}

void Tree::PreOrder()
{
	pre (root);
}

void Tree::pre(TreeNode *p)
{
	if (pf == 0){
		cout<<p->data;
		pf = 1;	
	} 
	else cout<<' '<<p->data;
	if (p->left != 0) pre(p->left); 
	if (p->down != 0) pre(p->down); 
	if (p->right != 0) pre(p->right); 
	if (p->up != 0)	pre(p->up);
	return; 
}

void Tree::PostOrder()
{
	post(root);
}

void Tree::post(TreeNode *p)
{
	if (p->left != 0) post(p->left); 
	if (p->down != 0) post(p->down); 
	if (p->right != 0) post(p->right); 
	if (p->up != 0)	post(p->up);
	if (pf == 0){
		cout<<p->data;
		pf = 1;	
	} 
	else cout<<' '<<p->data;

	return;
}
