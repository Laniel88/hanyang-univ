#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

typedef struct BNode* BNodePtr;

struct BNode{
    int order;
    int size;           /* number of children */
    BNodePtr *child;    /* children pointers */
    int *key;           /* keys */
    int is_leaf;
} BNode;

BNodePtr CreateTree(int order);

void Insert(BNodePtr *root, int key);
BNodePtr Insert_sub(BNodePtr parent, BNodePtr node, int key, int pos);
BNodePtr split_node(BNodePtr parent, BNodePtr node, int pos);
BNodePtr Createnode(int order);

int Find(BNodePtr root, int key);

void PrintTree(BNodePtr root);

void DeleteTree(BNodePtr root);
void free_node(BNodePtr node);

int main(int argc, char* argv[]){
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");

    int order;
    fscanf(fin, "%d", &order);
    BNodePtr root = CreateTree(order);

    char cv;
    int key;
    while(!feof(fin)){
        fscanf(fin, "%c", &cv);
        switch(cv){
            case 'i':
                fscanf(fin, "%d", &key);
                if(Find(root, key))
                    fprintf(fout, "insert error : key %d is already in the tree!\n", key);
                else
                    Insert(&root, key);
                break;
            case 'f':
                fscanf(fin, "%d", &key);
                if(Find(root, key))
                    fprintf(fout, "key %d found\n", key);
                else
                    fprintf(fout, "finding error : key %d is not in the tree!\n", key);
                break;
            case 'p':
                if (root->size == 1)
                    fprintf(fout, "print error : tree is empty!");
                else
                    PrintTree(root);
                fprintf(fout, "\n");
                break;
        }
    }
   
    DeleteTree(root);
    fclose(fin);
    fclose(fout);

    return 0;
}

/* 새로운 트리를 생성하는 함수 */
BNodePtr CreateTree(int order){
    BNodePtr root = Createnode(order);
    root->is_leaf = 1;
    return root;
}

/* insert key */
void Insert(BNodePtr *root, int key){ // 루트를 함수 내에서 변경시키기 위해 이중 포인터로 선언
    *root = Insert_sub(*root, *root, key, 0); // 리턴값이 있는 재귀함수 활용, 처음에 root 노드는 현재 노드이자 parent이므로 같이 parent, node 똑같이 매개변수 전달
}

BNodePtr Insert_sub(BNodePtr parent, BNodePtr node, int key, int p_pos){
    int i = node->size - 1;
    if (node->is_leaf == 1) {
        while (i >= 0 && key < node->key[i]) { // Shift keys greater than the new key to the right
            node->key[i + 1] = node->key[i];
            i--;
        }
        node->key[i + 1] = key; // Insert the new key in the correct position
        node->size++;
        return node;
    } else {
        while (i >= 0 && key < node->key[i]) // Find the child node to insert the key
            i--;
        i++;
        if (node->child[i]->size == 2 * node->order - 1) { // Split the child node if it's full
            node->child[i] = split_node(node, node->child[i], i);
            if (key > node->key[i])
                i++;
        }
        return Insert_sub(node, node->child[i], key, i);
    }
}

BNodePtr split_node(BNodePtr parent, BNodePtr node, int pos){
    BNodePtr new_node = Createnode(node->order);
    new_node->is_leaf = node->is_leaf;
    new_node->size = node->order - 1;
    int i;
    for (i = 0; i < node->order - 1; i++) {
        new_node->key[i] = node->key[i + node->order]; // Copy the upper keys to the new node
    }
    if (node->is_leaf == 0) {
        for (i = 0; i < node->order; i++) {
            new_node->child[i] = node->child[i + node->order]; // Copy the upper child nodes to the new node
        }
    }
    node->size = node->order - 1;
    for (i = parent->size; i > pos; i--) {
        parent->child[i + 1] = parent->child[i]; // Shift child pointers to the right
    }
    parent->child[pos + 1] = new_node; // Insert the new node as a child of the parent
    for (i = parent->size - 1; i >= pos; i--) {
        parent->key[i + 1] = parent->key[i]; // Shift keys to the right
    }
    parent->key[pos] = node->key[node->order - 1]; // Insert the median key to the parent
    parent->size++;
    return node;
}

/* 노드 하나를 동적할당하는 함수, size, is_leaf는 노드마다 다르므로 초기화하지 않고 공통되는 부분만 초기화 */
BNodePtr Createnode(int order){
    BNodePtr new_node = (BNodePtr)malloc(sizeof(struct BNode));
    new_node->order = order;
    new_node->size = 0;
    new_node->child = (BNodePtr*)malloc(sizeof(BNodePtr) * (2 * order));
    new_node->key = (int*)malloc(sizeof(int) * (2 * order - 1));
    new_node->is_leaf = 1;
    return new_node;
}

/* find node that has key */
int Find(BNodePtr root, int key){
    int i = 0;
    while (i < root->size && key > root->key[i])
        i++;
    
    if (i < root->size && key == root->key[i])
        return 1;   // Key found
    if (root->is_leaf == 1)
        return 0;   // Key not found
    else
        return Find(root->child[i], key);   // Recursively search in the child node
}

/* print Tree, inorder traversal */
void PrintTree(BNodePtr root){
    int i;
    for (i = 0; i < root->size; i++) {
        if (root->is_leaf == 0)
            PrintTree(root->child[i]); // Recursively print child nodes
        fprintf(fout, "%d ", root->key[i]); // Print the key
    }
    if (root->is_leaf == 0)
        PrintTree(root->child[i]); // Recursively print the last child node
}

/* depth first search -> free memory */
void DeleteTree(BNodePtr root){
    if (root->is_leaf == 0) {
        for (int i = 0; i <= root->size; i++)
            DeleteTree(root->child[i]); // Recursively delete child nodes
    }
    free_node(root); // Free the memory of the current node
}

/* 노드의 메모리를 해제해주는 helper function */
void free_node(BNodePtr node){
    free(node->child);
    free(node->key);
    free(node);
}
