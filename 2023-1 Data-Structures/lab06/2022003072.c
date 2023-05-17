#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;
typedef int ElementType;

typedef struct AVLNode{
	ElementType element;
	AVLTree left, right;
	int height;
} AVLNode;
int Height(Position P);
int getBalance(AVLTree T);
int Max(int a, int b);
AVLTree Insert(ElementType X, AVLTree T);
AVLTree Delete(ElementType X, AVLTree T);
Position SingleRotateWithLeft(Position node);
Position SingleRotateWithRight(Position node);
Position DoubleRotateWithLeft(Position node);
Position DoubleRotateWithRight(Position node);
void PrintInorder(AVLTree T);
void DeleteTree(AVLTree T);

int main(int argc, char *argv[]) {
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	AVLTree Tree = NULL;
	char cv;
	int key;

	while(!feof(fin)) {
		fscanf(fin, "%c", &cv);
		switch(cv){
			case 'i':
				fscanf(fin, "%d\n", &key);
				Tree = Insert(key, Tree);
				break;
			case 'd':
				fscanf(fin, "%d\n", &key);
				Tree = Delete(key, Tree);
				break;
		}
		PrintInorder(Tree);
		fprintf(fout, "\n");
	}

	DeleteTree(Tree);
	fclose(fin);
	fclose(fout);

	return 0;
}

AVLTree Insert(ElementType X, AVLTree T){
    if(T == NULL){
        T = (AVLTree)malloc(sizeof(AVLNode));
        T->element = X;
        T->height = 0;
        T->left = T->right = NULL;
    } else if(X < T->element) {
        T->left = Insert(X, T->left);
        if(height(T->left) - height(T->right) == 2){
            if(X < T->left->element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    } else if(X > T->element) {
        T->right = Insert(X, T->right);
        if(height(T->right) - height(T->left) == 2){
            if(X > T->right->element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }

    T->height = Max(height(T->left), height(T->right)) + 1;
    return T;
}

AVLTree Delete(ElementType X, AVLTree T){
    if(T == NULL)
        return NULL;

    if(X < T->element)
        T->left = Delete(X, T->left);
    else if(X > T->element)
        T->right = Delete(X, T->right);
    else if(T->left && T->right) {
        AVLTree tmp = FindMin(T->right);
        T->element = tmp->element;
        T->right = Delete(T->element, T->right);
    } else {
        AVLTree tmp = T;
        if(T->left == NULL)
            T = T->right;
        else if(T->right == NULL)
            T = T->left;
        free(tmp);
    }

    if(T == NULL)
        return T;

    T->height = Max(height(T->left), height(T->right)) + 1;

    if(height(T->left) - height(T->right) == 2){
        if(height(T->left->left) - height(T->left->right) == 1)
            T = SingleRotateWithLeft(T);
        else
            T = DoubleRotateWithLeft(T);
    } else if(height(T->right) - height(T->left) == 2){
        if(height(T->right->right) - height(T->right->left) == 1)
            T = SingleRotateWithRight(T);
        else
            T = DoubleRotateWithRight(T);
    }

    return T;
}

Position SingleRotateWithLeft(Position node){
    Position k = node->left;
    node->left = k->right;
    k->right = node;

    node->height = Max(height(node->left), height(node->right)) + 1;
    k->height = Max(height(k->left), node->height) + 1;

    return k;
}

Position SingleRotateWithRight(Position node) {
    Position k = node->right;
    node->right = k->left;
    k->left = node;

    node->height = Max(height(node->left), height(node->right)) + 1;
    k->height = Max(height(k->right), node->height + 1);

	return k;
}

Position DoubleRotateWithLeft(Position node){
	node->left = SingleRotateWithRight(node->left);
	return SingleRotateWithLeft(node);
}

Position DoubleRotateWithRight(Position node){
	node->right = SingleRotateWithLeft(node->right);
	return SingleRotateWithRight(node);
}

void PrintInorder(AVLTree T){
	if(T == NULL)
		return;	
	PrintInorder(T->left);
	fprintf(fout, "%d(%d) ", T->element, T->height);
	PrintInorder(T->right);
}

void DeleteTree(AVLTree T){
	if(T == NULL)
		return;
	DeleteTree(T->left);
	DeleteTree(T->right);
	free(T);
}

int height(Position P){
	if(P == NULL)
		return -1;
	else
		return P->height;
}

int Max(int a, int b){
	return a > b ? a : b;
}

AVLTree FindMin(AVLTree T){
	if(T == NULL)
		return NULL;
	else if(T->left == NULL)
		return T;
	else
		return FindMin(T->left);
}

int Height(Position P){ //returning the height of corresponding node
	if(P == NULL){
		return -1;
	}
	return P->height;
}
int getBalance(AVLTree T){ //calculating the balance of tree in the same level
	if(T == NULL){
		return 0;
	}
	return Height(T->left) - Height(T->right);
}
int Max(int a, int b){ //returning the greater value between a and b
	return (a > b) ? a : b;
}

AVLTree Insert(ElementType X, AVLTree T){
	if(T == NULL){ //if the tree is not yet created, allocate T and set initial condition
		T = malloc(sizeof(AVLNode));
		T->element = X;
		T->height = 0;
		T->left = NULL;
		T->right = NULL;
		return T;
	}
	if(X < T->element){ //if X is smaller than the element, move to left side of tree
		T->left = Insert(X, T->left); //use recursion
		if(getBalance(T) >= 2){ //if the difference of height is greater or equal to two, rotate
			if(X < T->left->element){ //if X is smaller than the next left's element, use single rotate with left
				T = SingleRotateWithLeft(T);
			}
			else{ //if X is greater than, use double rotate with left
				T = DoubleRotateWithLeft(T);
			}
		}
	}
	else if(X > T->element){ //if X is larger than the element, move to right side of tree
		T->right = Insert(X, T->right); //use recursion
		if(Height(T->right) - Height(T->left) >= 2){ //if the difference of height is greater or equal to two, rotate
			if(X > T->right->element){ //if X is larger than the next right's element, use single rotate with right
				T = SingleRotateWithRight(T);
			}
			else{ //if X is less than, use double rotate with right
				T = DoubleRotateWithRight(T);
			}
		}
	}
	else{ //print error message if there is X in tree already
		fprintf(fout, "insertion error : %d is already in the tree!\n", X);
	}
	T->height = Max(Height(T->left), Height(T->right)) + 1; //reset the height of the node
	return T;
}

AVLTree Delete(ElementType X, AVLTree T){
	if(T == NULL){ //if T is NULL, then print error message that X is not in the tree
		fprintf(fout, "deletion error : %d is not in the tree!\n", X);
		return T;
	}
	if(T->element > X){ //if key is smaller than the value, move to left node
                T->left = Delete(X, T->left);
        }
        else if(T->element < X){ //if key is larger than the value, move to right node
                T->right = Delete(X, T->right);
        }
        else{ //when found the corresponding node same as key
                if(T->left == NULL){ //if there is no child in left side, delete the node and return right child
                        AVLTree tmp = T->right;
                        free(T);
                        return tmp;
                }
                else if(T->right == NULL){ //if there is no child in right side, delete the node and return left child
                        AVLTree tmp = T->left;
                        free(T);
                        return tmp;
                }
                else{ //if both left and right sides exist
                        int min = T->element;
                        AVLTree tmp = T->right;
                        while(tmp->left != NULL){
                                min = tmp->element; //find the minimum value in the right tree
                                tmp = tmp->left;
                        }
                        T->element = min; //insert min value to root
                        T->right = Delete(T->element, T->right); //delete the corresponding node from the right tree
                }
        }
	if(T == NULL){ //check if T is empty
		return T;
	}
	T->height = 1 + Max(Height(T->left), Height(T->right)); //updating the current node's height
	int balance = getBalance(T); //get the difference of height
	
	if(balance > 1 && getBalance(T->left) >= 0) //if the difference is larger than 1 and the left subtree has balance greater than or equal to 0, do single rotate with right
		return SingleRotateWithLeft(T);
	
	if(balance > 1 && getBalance(T->left) < 0) //if the difference is larger than 1 and left subtree has balance less than 0, do double rotate with left
		return DoubleRotateWithLeft(T);
	
	if(balance < -1 && getBalance(T->right) <= 0) //if the difference is less than -1 and right subtree has balance less than or equal to 0, do single rotate with left
		return SingleRotateWithRight(T);
	
	if(balance < -1 && getBalance(T->right) > 0) //if the difference is less than -1 and right subtree has balance greater than 0, do double rotate with right
		return DoubleRotateWithRight(T);
	
	return T;
}

void PrintPreorder(AVLTree T){ //print tree in preorder
	if(T == NULL){
		return;
	}
	fprintf(fout, "%d(%d) ", T->element, T->height); //print before moving to subtree
	PrintPreorder(T->left); //move to left subtree
	PrintPreorder(T->right); //move to right subtree
}

void DeleteTree(AVLTree T){ //deleting whole tree
	if(T == NULL){
		return;
	}
	DeleteTree(T->left); //use recursion to delete left subtree
	DeleteTree(T->right); //use recursion to delete right subtree
	free(T); //deallocate tree
}

Position SingleRotateWithLeft(Position node){ //left subtree of left child
	Position n = node->left; //making temp to store node's left subtree
	node->left = n->right; //node's left is now node->left's right
	n->right = node; //node->left's right is now node
	node->height = Max(Height(node->left), Height(node->right)) + 1; //set node's height
	n->height = Max(Height(n->left), node->height) + 1; //set temp(node->left)'s height
	return n;
}
Position SingleRotateWithRight(Position node){ //right subtree of right child
	Position n = node->right; //making temp to store node's right subtree
	node->right = n->left; //node's right is now node->right's left
	n->left = node; //node->right's left is now node
	node->height = Max(Height(node->left), Height(node->right)) + 1; //set node's height
	n->height = Max(Height(n->left), node->height) + 1; //set temp(node->right)'s height
	return n;
}
Position DoubleRotateWithLeft(Position node){ //left subtree of right child
	node->left = SingleRotateWithRight(node->left); //node's left does single rotate with right
	return SingleRotateWithLeft(node); //second rotate with left
}
Position DoubleRotateWithRight(Position node){ //right subtree of left child
	node->right = SingleRotateWithLeft(node->right); //node's right does single rotate with left
	return SingleRotateWithRight(node); //second rotate with right
}
