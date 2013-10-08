#include <stdio.h>
#include "tree.h"

BiTree T;//Root of the tree

int testBitree()
{

	char pre[]	= "ABDCEF";
	char in[]	= "BDAEFC";
        char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char table[] = "A(B(,C),D(E(F,G),H))";
	T = createBiTree(table);

	//T = CTree(pre, 0, 5, in, 0, 5);
        //T = CreateBiTreeFromArray(s, 0);
        T->depth = 1;
        re_org_tree(T);
	printf ("Print Tree :\n");
	PrintTree(T, 0);
	printf("\n");

	printf ("Pre   Order traverse:\t");
	PreOrderTraverse(T, NULL);
	printf("\n");

	printf ("In    Order traverse:\t");
	InOrderTraverse(T);
        InOrderTraverse_recurse(T, NULL);
	printf("\n");

	printf ("Post  Order traverse:\t");
	generic_Traverse1(T, 0);
	printf("\n");

	printf ("Level Order traverse:\t");
	LevelOrderTraverse(T);
	printf("\n");

	printf ("Depth Order traverse:\t");
	DepthOrderTraverse(T);
	printf("\n\n");

	printf ("The depth of the tree:\t%d\n", getDepth(T));

	printf ("The leafs of the tree:\t%d\n", GetLeafCount(T));

	printf ("The Nodes of the tree:\t%d\n", GetNodeCount(T));
	
	freeBiTree(T);

	return 0;
}

int testBSTree()
{
	T = Insert(T,'F');
	T = Insert(T,'B');
	T = Insert(T,'E');
	T = Insert(T,'A');
	T = Insert(T,'C');
	T = Insert(T,'D');
	T = Insert(T,'G');
	

	printf ("Print Tree :\n");
	PrintTree(T, 0);
	printf("\n");


	printf ("Pre   Order traverse:\t");
	InOrderTraverse(T);
	printf("\n");
	
	printf("Delete 'F'\n");
	DeleteBST(T, NULL, 'F');

	PrintTree(T, 0);

	printf ("Pre   Order traverse:\t");
	InOrderTraverse(T);
	printf("\n");

	return 0;
}

int main()
{
	testBitree();
	//testBSTree();
	return 0;
		
}
