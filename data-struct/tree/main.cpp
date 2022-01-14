#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct _Tree {
	int val;
	struct _Tree *left;
	struct _Tree *right;
} Tree;

typedef struct _List {
	Tree *tree;
	struct _List *next;
} TList;


Tree* initTree(vector<string> &nums, Tree **node) {
	static int index = -1;
	index++;
	if (index >= nums.size() || nums[index][0] == '#') {
		*node = NULL;
		return NULL;
	}
	*node = new Tree;
	(*node)->val = stoi(nums[index]);
	initTree(nums, &((*node)->left));
	initTree(nums, &((*node)->right));
	return *node;
}


void firstShowTree(Tree *node) {
	if (node == NULL)
		return ;
	cout << node->val << endl;
	firstShowTree(node->left);
	firstShowTree(node->right);
}

void middleShowTree(Tree *node) {
	if (node == NULL)
		return ;
	middleShowTree(node->left);
	cout << node->val << endl;
	middleShowTree(node->right);
}

void tailShowTree(Tree *node) {
	if (node == NULL)
		return ;
	tailShowTree(node->left);
	tailShowTree(node->right);
	cout << node->val << endl;
}

void deepShowTree(Tree *node) {
	firstShowTree(node);
}

void _crossShowTree(TList *p_tlist) {
	if (!p_tlist)
		return ;
	TList *tlist = new TList, *ptl = tlist, *tmp;
	while (p_tlist != NULL) {
		cout << p_tlist->tree->val << endl;
		if (p_tlist->tree->left) {
			ptl->next = new TList;
			ptl = ptl->next;
			ptl->tree = p_tlist->tree->left;
		}
		if (p_tlist->tree->right) {
			ptl->next = new TList;
			ptl = ptl->next;
			ptl->tree = p_tlist->tree->right;
		}
		tmp = p_tlist->next;
		delete p_tlist;
		p_tlist = tmp;
	}
	ptl->next = NULL;
	tmp = tlist->next;
	delete tlist;
	tlist = tmp;
	_crossShowTree(tlist);
}

void crossShowTree(Tree *node) {
	if (node == NULL)
		return ;
	TList *tlist = new TList;
	tlist->tree = node;
	tlist->next = NULL;
	_crossShowTree(tlist);
	delete tlist;
}


void allShowTree(Tree *node) {
	cout << "first show" << endl;
	cout << "---------------------------------" << endl;
	firstShowTree(node);
	cout << "---------------------------------" << endl;
	cout << "middle show" << endl;
	cout << "---------------------------------" << endl;
	middleShowTree(node);
	cout << "---------------------------------" << endl;
	cout << "tail show" << endl;
	cout << "---------------------------------" << endl;
	tailShowTree(node);
	cout << "---------------------------------" << endl;
	cout << "cross show" << endl;
	cout << "---------------------------------" << endl;
	crossShowTree(node);
	cout << "---------------------------------" << endl;
}

int main() {
	vector<string> nums = {"1", "2", "4", "#", "#", "5", "#", "#", "3", "6", "#", "#", "7", "#", "#"};
	Tree *tree;
	initTree(nums, &tree);
	allShowTree(tree);
	return 0;

}
