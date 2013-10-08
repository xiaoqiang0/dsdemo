#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tree.h"
#define Max_depth    20
static int max_depth = 7;
static struct node_c stack[Max_depth];
int top = -1;
static int width = 800;
static int height = 400;

/*Create Bitree from preOrder and InOrder Sequences */
BiTree CTree(char *pre, int pl, int pu, char *in, int il, int iu)
{
    BiTree p;
    int i;

    p = (BiTree) malloc(sizeof(struct TreeNode));
    p->data = *(pre + pl);
    p->left = NULL;
    p->right = NULL;
    p->parent = NULL;

    if (pl == pu)
	return p;

    for (i = il; i <= iu && *(in + i) != *(pre + pl); i++);

    if (i != il)
	p->left = CTree(pre, pl + 1, pl + i - il, in, il, i - 1);
    if (i != iu)
	p->right = CTree(pre, pl + i - il + 1, pu, in, i + 1, iu);

    assign_parent(p, 0);
    return p;
}

BiTree createBiTree()
{
    //A(B(,C),D(E(F,G),H))

    BiTree T = NULL;
    BiTree stack[20];
    int top = -1;
    BiTree p = T;
    char c;
    int flag = -1;

    printf("Input Data:\n\t");
    while ((c = getchar()) != EOF && c != '\n') {
	putchar(c);
	switch (c) {
	case '(':
	    flag = 1;
	    stack[++top] = p;
	    break;
	case ')':
	    flag = 0;
	    top--;
	    break;
	case ',':
	    flag = 2;
	    break;
	default:
	    {
		p = (BiTree) malloc(sizeof(struct TreeNode));
		p->data = c;
		p->left = NULL;
		p->right = NULL;
		p->parent = NULL;
		if (T == NULL)
		    T = p;
		else {
		    if (flag == 1)
			stack[top]->left = p;
		    else if (flag == 2)
			stack[top]->right = p;
		}
	    }
	}
    }
    printf("\n");
    assign_parent(T, 0);
    return T;
}

BiTree CreateBiTreeFromArray(const char *s, int i)
{    
    BiTree p;
    if (strlen(s) <= i || s[i] == ' ') return NULL;

    p = (BiTree) malloc(sizeof(struct TreeNode));
    p->data = s[i];
    p->left = CreateBiTreeFromArray(s, (i+1) * 2 - 1);
    p->right = CreateBiTreeFromArray(s, (i+1) * 2);
    
    assign_parent(p, 0);
    return p;


}
void assign_parent(BiTree T, BiTree p)
{
    if (!T)
	return;
    if (!p)
	T->parent = T;
    else
	T->parent = p;
    assign_parent(T->left, T);
    assign_parent(T->right, T);
}

int get_pos_x(BiTree T)
{
    if (T->parent == T)
	return width * pow(0.5, T->depth);

    if (T->parent->left == T)
	return get_pos_x(T->parent) - width * pow(0.5, T->depth);
    else
	return get_pos_x(T->parent) + width * pow(0.5, T->depth);
}

int get_pos_y(BiTree T)
{
    return T->depth * height / (max_depth + 1);
}


void re_org_tree(BiTree T)
{
    if (!T)
	return;

    if (T->parent == T)
	T->depth = 1;
    else
	T->depth = T->parent->depth + 1;
    T->x = get_pos_x(T);
    T->y = get_pos_y(T);
    re_org_tree(T->left);
    re_org_tree(T->right);
}

void PreOrderTraverse(BiTree T, void (*visit)(void*))
{
    if (!T)
	return;
    if (visit)
        visit((void *)T);
    else
        printf("%c", T->data);
    PreOrderTraverse(T->left, visit);
    //printf("%c",',');
    PreOrderTraverse(T->right, visit);
    //printf("%c",')');
}

void generic_Traverse(BiTree T, int flag)
{
    struct node_c p;
    p.treenode = T;
    p.flag = 0;
    stack[++top] = p;
    while (top >= 0) {
	p = stack[top--];
	switch (p.flag) {
	case 0:
	    p.flag++;
	    stack[++top] = p;
	    if (flag == 0)
		printf("%c", p.treenode->data);
	    if (p.treenode->left) {
		p.treenode = p.treenode->left;
		p.flag = 0;
		stack[++top] = p;
	    }
	    break;
	case 1:
	    p.flag++;
	    stack[++top] = p;
	    if (flag == 1)
		printf("%c", p.treenode->data);
	    if (p.treenode->right) {
		p.treenode = p.treenode->right;
		p.flag = 0;
		stack[++top] = p;
	    }
	    break;
	case 2:
	    if (flag == 2)
		printf("%c", p.treenode->data);
	    break;
	}
    }
}

void generic_Traverse1(BiTree T, int f)
{
    BiTree stack1[100];
    int stack2[100];
    int top = -1;
    int flag;
    BiTree p = T;

    if (T) {
	do {
	    while (p) {
		stack1[++top] = p;
		stack2[top] = 0;
		//printf("%c",p->data);
		p = p->left;
	    }
	    p = stack1[top];
	    flag = stack2[top--];
	    if (flag == 0) {
		stack1[++top] = p;
		stack2[top] = 1;
		//printf("%c",p->data);
		p = p->right;	/*右子树的入栈操作由上面的while完成 */
	    } else {
		printf("%c", p->data);
		p = NULL;
	    }

	} while (p != NULL || top != -1);


    }

}

void InOrderTraverse(BiTree T)
{
    BiTree stack[100];
    int top = -1;
    BiTree p = T;
    if (T) {
	do {
	    while (p) {
		stack[++top] = p;
		//printf("%c",p->data);
		p = p->left;
	    }
	    p = stack[top--];
	    printf("%c", p->data);
	    p = p->right;
	} while (p != NULL || top != -1);
    }
}


void LevelOrderTraverse(BiTree T)
{
    BiTree Q[200];
    BiTree h;
    int front = 0, end = 0;

    if (!T)
	return;

    Q[front++] = T;
    while (front != end) {
	h = Q[end++];
	printf("%c", h->data);
	if (h->left)
	    Q[front++] = h->left;
	if (h->right)
	    Q[front++] = h->right;
    }

}

void DepthOrderTraverse(BiTree T)
{
    if (!T)
	return;

    printf("%c", T->data);

    DepthOrderTraverse(T->left);
    DepthOrderTraverse(T->right);

    return;
}

void PrintTree(BiTree T, int indent)
{
    int n = indent;
    if (!T)
	return;

    PrintTree(T->right, indent + 1);

    while (n--)
	printf("   ");
    printf("%c(%d, %d)\n", T->data, T->x, T->y);

    PrintTree(T->left, indent + 1);

    return;
}

int getDepth(BiTree T)
{
    int ldepth, rdepth;;
    if (T) {
	ldepth = getDepth(T->left);
	rdepth = getDepth(T->right);
	return 1 + (ldepth > rdepth ? ldepth : rdepth);
    }
    return 0;
}

int GetLeafCount(BiTree T)
{
    int lc, rc;
    if (T) {
	if (T->left == 0 && T->right == 0)
	    return 1;
	lc = GetLeafCount(T->left);
	rc = GetLeafCount(T->right);
	return lc + rc;
    }
    return 0;
}

int GetNodeCount(BiTree T)
{
    int lc, rc;
    if (T) {
	lc = GetNodeCount(T->left);
	rc = GetNodeCount(T->right);
	return 1 + lc + rc;
    }
    return 0;
}

void freeBiTree(BiTree T)
{
    if (T) {
	freeBiTree(T->left);
	freeBiTree(T->right);
	free(T);
    }
    return;
}
