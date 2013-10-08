#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

BiTree Insert(BiTree p, int t)
{
	if (p == 0) {
		p = (BiTree) malloc(sizeof(struct TreeNode));
		p->data = t;
	} else if (t < p->data) {
		p->left = Insert(p->left, t);
	} else if (t > p->data) {
		p->right = Insert(p->right, t);
	} // do nothing if p->val == t
	return p;
}

BiTree SearchBST(BiTree T,int t)
{
	if (!T && T->data == t)
		return T;
	else if (T->data <= t)
		return SearchBST(T->right, t);
	else
		return SearchBST(T->left, t);
	return NULL;
}

void InsertBST(BiTree T, int t) 
{ 
	T = Insert(T, t); 
}

int Delete(BiTree T, BiTree P)
{
	BiTree q, s;
	
	if (!T->right){	//右子树是空
		if (P->right == T) 
			P->right = T->left;
		else
			P->left  = T->left;
	}else if (!T->left){//左子树是空
		if (P->right == T) 
			P->right = T->right;
		else
			P->left  = T->right;
	}else{
		q = T; s = T->left;			// turn left one step
		while(s->right){ q = s; s = s->right;}	// run to the end of right
		T->data = s->data;			// exchange data of T, s, where s is the pre-Node of T 
							// rebuild the parent node of s
		if (q != T)				
			q->right = s->left;	
		else
			q->left  = s->left;
		free(s);				//free s instead of T
			
	}
	return 1;
}

int DeleteBST(BiTree T, BiTree P, int key)
{
	if (T == NULL) return 0;
	if (T->data == key)
		return Delete(T, P);
	else if (T->data <= key)
		return DeleteBST (T->right, T, key);
	else
		return DeleteBST (T->left , T, key);
}
