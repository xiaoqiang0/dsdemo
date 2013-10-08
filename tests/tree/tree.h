#ifndef	_TREE_H
#define _TREE_H
typedef char DataType;

typedef struct TreeNode {
    DataType data;
    int x, y;
    int depth;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode;

typedef struct TreeNode *BiTree;

struct node_c {
    BiTree treenode;
    int flag;
};

/*------------------------BiTree------------------------------------*/
BiTree CTree(char *pre, int pl, int pu, char *in, int il, int iu);
BiTree createBiTree();
BiTree CreateBiTreeFromArray(const char *s, int i);
void re_org_tree(BiTree T);
void assign_parent(BiTree T, BiTree p);

void PreOrderTraverse(BiTree T, void (*visit)(void*));

void generic_Traverse(BiTree T, int flag);

void generic_Traverse1(BiTree T, int f);

void InOrderTraverse(BiTree T);

void LevelOrderTraverse(BiTree T);

void DepthOrderTraverse(BiTree T);

void PrintTree(BiTree T, int indent);

int getDepth(BiTree T);

int GetLeafCount(BiTree T);

int GetNodeCount(BiTree T);

void freeBiTree(BiTree T);

/*-----------------------BSTree-------------------------------------*/
BiTree Insert(BiTree p, int t);

BiTree SearchBST(BiTree T, int t);

void InsertBST(BiTree T, int t);

int Delete(BiTree T, BiTree P);

int DeleteBST(BiTree T, BiTree P, int key);

/*-----------------------BSTree-------------------------------------*/
typedef struct BSTNode {
    char data;
    int bf;
    struct BSTNode *left, *right;
} BSTNode, *BSTree;
#endif
