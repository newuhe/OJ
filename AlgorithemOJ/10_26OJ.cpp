#include <iostream>
using namespace std;

struct treenode
{
	treenode *lch;
	treenode *rch;
	char data;
};

class Bitree
{
private:
	treenode * root;
	int size;
public:

	Bitree(char * a,int i);
	void visit(treenode* node);
	bool IsEmpty();
	void LevelOrder(treenode* node);
};

Bitree::Bitree(char *a, int i)
{
	
}

void Bitree::visit(treenode * node)
{
	
}

void Bitree::LevelOrder(treenode * node)
{
	while ()
	if (!=NULL) 
	if (!=NULL)
}

bool Bitree::IsEmpty(treenode * node)
{

}

bool judge()
{

}

int main()
{
	int size;
	char tree[100];
	while (cin >> tree)
	{
		do
		{
			size++;
		} while (tree[size] != '\0');
		Bitree tree1(tree,size);

	}
	if (judge()) cout << "true";
	else cout << "false";
	system("pause");
	return 0;
}