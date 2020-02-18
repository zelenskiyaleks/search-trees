#include <stack>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
using std::cout;
using std::endl;

struct TreeNode {
	explicit TreeNode(int _value) : value(_value) {}
	int value = 0;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
};

class Tree {
public:
	~Tree();

	void Add(int value);

	void Print() const;

private:
	TreeNode* root = nullptr;

	void delete_subtree(TreeNode* node);
};

Tree::~Tree() {
	delete_subtree(root);
}

void Tree::delete_subtree(TreeNode* node) {
	if (!node) return;
	stack<TreeNode*> ochered;
	stack<TreeNode*> qq;
	ochered.push(node);
	while (ochered.empty() == false) {
		TreeNode* current = ochered.top();
		qq.push(current);
		ochered.pop();
		if (current->left != nullptr) {
			ochered.push(current->left);
		}
		if (current->right != nullptr) {
			ochered.push(current->right);
		}

	}
	while (qq.empty() == false) {
		TreeNode* x = qq.top();
		qq.pop();
		delete x;
	}
}

void Tree::Add(int X) {
	if (!root) {
		root = new TreeNode(X);
	}
	else {
		TreeNode* current = root;
		while (true) {
			if (current->value > X) {
				if (current->left == nullptr) {
					current->left = new TreeNode(X);
					break;
				}
				current = current->left;
			}
			else {
				if (current->right == nullptr) {
					current->right = new TreeNode(X);
					break;
				} current = current->right;
			}
		}
	}
}

void Tree::Print() const {
	if (!root) return;
	stack<TreeNode*> ochered;
	stack<TreeNode*> qq;
	ochered.push(root);
	while (ochered.empty() == false) {
		TreeNode* current = ochered.top();
		qq.push(current);
		ochered.pop();
		if (current->left != nullptr) {
			ochered.push(current->left);
		}
		if (current->right != nullptr) {
			ochered.push(current->right);
		}

	}
	while (qq.empty() == false) {
		cout << qq.top()->value << " ";
		qq.pop();
	}
}


int main()
{
	Tree tree;
	int n = 0;
	int j = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> j;
		tree.Add(j);
	}
	tree.Print();
	cout << endl;
	return 0;
}

