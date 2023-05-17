#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

typedef struct BST* Tree;
typedef struct BST{
	int value;
	struct BST* left;
	struct BST* right;
}BST;

Tree insertNode(Tree root, int key);
Tree deleteNode(Tree root, int key);
int findNode(Tree root, int key);
void printInorder(Tree root);
void deleteTree(Tree root);

int main(int argc, char* argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	char cv;
	int key;

	Tree root = NULL;

	while(!feof(fin)){
		fscanf(fin, "%c", &cv);
		switch(cv){
			case 'i':
				fscanf(fin, "%d", &key);
				fprintf(fout, "insert %d\n", key);
				root = insertNode(root, key);
				break;
			case 'f':
				fscanf(fin,"%d",&key);
				if(findNode(root, key))
					fprintf(fout, "%d is in the tree\n", key);
				else
					fprintf(fout, "finding error: %d is not in the tree\n", key);
				break;
			case 'd':
				fscanf(fin, "%d", &key);
				if(findNode(root, key)){
					root = deleteNode(root, key);
					fprintf(fout, "delete %d\n", key);
				}
				else{
					fprintf(fout, "deletion error: %d is not in the tree\n", key);
				}
				break;
			case 'p':
				fscanf(fin, "%c", &cv);
				if(cv == 'i'){
					if(root == NULL)
						fprintf(fout, "tree is empty");
					else
						printInorder(root);
				}
				fprintf(fout, "\n");
				break;
		}
	}
	deleteTree(root);

	return 0;
}

Tree insertNode(Tree root, int key) {
    if(root == NULL) { // tree is empty, create a new node
        Tree newNode = (Tree) malloc(sizeof(BST));
        newNode->value = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if(key == root->value) { // key already exists in the tree
        fprintf(fout, "Error: Key %d already exists in the tree\n", key);
        return root;
    }

    if(key < root->value) // insert into the left subtree
        root->left = insertNode(root->left, key);

    if(key > root->value) // insert into the right subtree
        root->right = insertNode(root->right, key);

    return root;
}

Tree deleteNode(Tree root, int key) {
    if(root == NULL) { // tree is empty or key not found
        fprintf(fout, "Error: Key %d not found in the tree\n", key);
        return NULL;
    }

    if(key < root->value) // search in the left subtree
        root->left = deleteNode(root->left, key);

    else if(key > root->value) // search in the right subtree
        root->right = deleteNode(root->right, key);

    else { // found the key to be deleted

        // 1. Node has no children
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // 2. Node has one child
        else if(root->left == NULL) {
            Tree temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL) {
            Tree temp = root;
            root = root->left;
            free(temp);
        }

        // 3. Node has two children
        else {
            Tree temp = root->right;
            while(temp->left != NULL) // find the smallest node in the right subtree
                temp = temp->left;

            root->value = temp->value; // copy the smallest node's value into the current node
            root->right = deleteNode(root->right, temp->value); // delete the smallest node
        }
    }

    return root;
}

int findNode(Tree root, int key) {
    if(root == NULL) // tree is empty or key not found
        return 0;

    if(key < root->value) // search in the left subtree
        return findNode(root->left, key);

    if(key > root->value) // search in the right subtree
        return findNode(root->right, key);

	return 1; // key == root->value
}

void printInorder(Tree root) {
	if(root == NULL) return;

	printInorder(root->left);
	fprintf(fout, "%d ", root->value);
	printInorder(root->right);
}

void deleteTree(Tree root){
	if(root == NULL) return;

	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}