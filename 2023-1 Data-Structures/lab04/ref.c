#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

#define FROMPARENT 0
#define FROMTHREAD 1

typedef struct ThreadedTree* ThreadedPtr;
typedef int ElementType;

struct ThreadedTree {
   int left_thread; // flag if ptr is thread, 1, if it is a thread or 0, if it points to a child node
   ThreadedPtr left_child;
   ElementType data;
   ThreadedPtr right_child;
   int right_thread; // flag if ptr is thread, 1, if it is a thread or 0, if it points to a child node
}ThreadedTree;

/*
Create a root of new Threaded Tree
Root data should be -1
return:
   the pointer of new Threaded Tree
*/

ThreadedPtr CreateTree(){
	ThreadedPtr tree = NULL;
	tree = (ThreadedPtr)malloc(sizeof(ThreadedTree));
	if(tree==NULL) {
		fprintf(fout, "Out of Space!\n");
		return NULL;
	}
	tree->data = -1;
	tree->left_thread = 1;
	tree->left_child = tree;
	tree->right_thread = 1;
	tree->right_child = tree;
	return tree;
}


/*
Insert the key value "data" in Threaded Tree
root : Pointer to the root node of Threaded Tree
root_idx : Index of the root node of Threaded Tree, means the first node to find the insertion position
data : data key value of the node to be newly inserted,
idx : The index of the node to be newly inserted, 0 means root index
return :
   1, the insertion succeeds
   0, the insertion fails.
*/
int Insert(ThreadedPtr root, int root_idx, ElementType data, int idx){
    ThreadedPtr parent = root; // 삽입되는 노드의 부모, 초기 부모는 root로 초기화
    int parent_idx = 0;  // 삽입되는 노드의 부모 index, 초기값은 root의 index인 0
    int tmp_idx = idx; // 삽입 위치를 찾기 위한 임시 index
    ThreadedPtr new_node = (ThreadedPtr)malloc(sizeof(ThreadedTree));
    new_node->data = data; // 삽입할 노드에 주어진 data 값을 넣어줌.

    if(root == NULL) return 0; // 트리를 형성할 root 노드가 없으면 삽입 실패
    
    
    // 삽입할 위치를 찾는 과정
    while(parent_idx < tmp_idx/2){  // 삽입되는 노드의 index는 부모 노드의 index의 2배(왼쪽 자식) 또는 2배+1(오른쪽 자식)
        while(tmp_idx > 2*parent_idx+1){ // 삽입되는 노드의 부모를 찾는 과정, 부모 노드를 하나하나씩 바로 밑의 자식으로 초기화하는 단계
            tmp_idx /= 2; // 2로 계속 나누면서 바로 위 부모 노드를 찾아내는 과정
        }
        if(tmp_idx == 2*parent_idx){  // 왼쪽 자식일 때
            parent = parent->left_child; // 부모 노드를 왼쪽 자식으로 초기화
            parent_idx = 2*parent_idx; // 부모 노드의 index를 왼쪽 자식으로 초기화
        }
        else{ // 오른쪽 자식일 때
            parent = parent->right_child; // 부모 노드를 오른쪽 자식으로 초기화
            parent_idx = 2*parent_idx+1; // 부모 노드의 index를 오른쪽 자식으로 초기화
        }
        tmp_idx = idx; // 부모를 찾기 위한 임시 index를 다시 원래 index로 초기화해주고 진짜 부모를 찾을 때까지 반복
    }

    if(tmp_idx == 2*parent_idx){  // 왼쪽 자식에 삽입
        new_node->left_thread = 1; // 삽입된 노드는 자식이 없으므로
        new_node->left_child = parent->left_child; // 왼쪽 자식이 없었던 부모의 왼쪽 thread가 가리키는 노드를 새로 생긴 왼쪽 thread가 물려받음.
        new_node->right_thread = 1; // 삽입된 노드는 자식이 없으므로
        new_node->right_child = parent; // 오른쪽 thread는 부모를 가리킴

        parent->left_thread = 0; // 자식이 생겼으므로 thread가 없어짐
        parent->left_child = new_node; // 부모의 왼쪽 자식에 새로운 노드를 삽입
    }
    else{  // 오른쪽 자식에 삽입
        new_node->left_thread = 1; // 삽입된 노드는 자식이 없으므로
        new_node->left_child = parent; // 왼쪽 thread는 부모를 가리킴
        new_node->right_thread = 1; // 삽입된 노드는 자식이 없으므로
        new_node->right_child = parent->right_child; // 오른쪽 자식이 없었던 부모의 오른쪽 thread가 가리키는 노드를 새로 생긴 오른쪽 thread가 물려받음

        parent->right_thread = 0; // 자식이 생겼으므로 thread가 없어짐
        parent->right_child = new_node; // 부모의 오른쪽 자식에 새로운 노드를 삽입
    }

    return 1; // 오류 없이 성공
}

/*
In Order Traversal
Implementing in a recursive form is prohibited.
When printing out, the interval between each key is one space
print out:
   "inorder traversal : data1 data2 data3" (When there are 3 data, except root node)

*/
void printInorder(ThreadedPtr root) {
    fprintf(fout, "inorder traversal : ");

    ThreadedPtr current_node = (ThreadedPtr)malloc(sizeof(ThreadedTree)); // 데이터를 출력할 현재 노드를 동적할당
    ThreadedPtr previous_node = (ThreadedPtr)malloc(sizeof(ThreadedTree));  // thread를 따라 순서대로 출력하기 위해 직전 노드 형성

    current_node = root->right_child; // root 밑 맨 위에 있는 노드로 current_node를 초기화
    while (current_node->left_thread == 0) { // 존재하는 왼쪽 자식으로 계속 가다가 맨 처음 current_node를 초기화
        current_node = current_node->left_child;
    }

    while (1) {
        fprintf(fout, "%d ", current_node->data); // current_node의 data를 출력
        previous_node = current_node; // 다음 data를 출력하기 위해 previous_node를 current_node로 초기화하고
        current_node = current_node->right_child; // current_node를 다음으로 가리키는 노드로 초기화

        if(previous_node->right_thread == 0) { // 이전 노드에 만약 오른쪽 자식이 있었다면
            while(current_node -> left_thread == 0) { // 왼쪽 자식이 없을 때까지 계속 밑으로 이동하다가
                current_node = current_node->left_child; // 맨 왼쪽 노드로 current_node를 초기화하고
            }
        }

        if (current_node == root) break; // 오른쪽이 root를 가리킬 때까지 반복
        
    }
}


void DeleteTree(ThreadedPtr root) {
    if(!root->left_thread)
        DeleteTree(root->left_child);
    if(!root->right_thread)
        DeleteTree(root->right_child);
    free(root);
}

int main(int argc, char *argv[]){
   fin=fopen(argv[1], "r");
   fout=fopen(argv[2], "w");

   ThreadedPtr root = CreateTree();

   int NUM_NODES;
   fscanf(fin, "%d", &NUM_NODES);

   int root_idx=0, idx=0;

   while(++idx <= NUM_NODES){
      ElementType data;
      fscanf(fin, "%d", &data);
      
      if(Insert(root, root_idx, data, idx) == 0){
         return 0;
      }
   }

   printInorder(root);
   DeleteTree(root);
   
   
   fclose(fin);
   fclose(fout);

   return 0;
}