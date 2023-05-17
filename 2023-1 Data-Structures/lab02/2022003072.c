#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node {
    ElementType element;
    Position next;
};

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
void Insert(ElementType X, List L, Position P);
void PrintList(List L);
void Delete(ElementType X, List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void DeleteList(List L);

FILE *fin;
FILE *fout;

int main(int argc, char **argv) {
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    char x;
    Position header = NULL, tmp = NULL;
    header = MakeEmpty(header);
    while (fscanf(fin, "%c", &x) != EOF) {
        if (x == 'i') {
            int a, b;
            fscanf(fin, "%d%d", &a, &b);
            if (b == -1) { 
                Insert(a, header, header);  // 위치 -1 은 main에서 예외처리한다.
            }
            else {
                tmp = Find(a, header);
                if (tmp != NULL) {
                    fprintf(fout, "insertion(%d) failed : the key already exists in the list\n", a);
                    continue;
                }
                tmp = Find(b, header);
                if (tmp == NULL) {
                    fprintf(fout, "insertion(%d) failed : can not find the location to be inserted\n", a);
                    continue;
                }
                Insert(a, header, tmp);
            }
        }
        else if (x == 'd') {
            int a;
            fscanf(fin, "%d", &a);
            Delete(a, header);
        }
        else if (x == 'f') {
            int a;
            fscanf(fin, "%d", &a);
            tmp = FindPrevious(a, header);
            if (IsLast(tmp, header))
                fprintf(fout, "finding(%d) failed : element %d is not in the list\n", a, a);
            else {
                if (tmp->element > 0)
                    fprintf(fout, "key of the previous node of %d is %d\n", a, tmp->element);
                else
                    fprintf(fout, "key of the previous node of %d is head\n", a);
            }
        }
        else if (x == 'p')
            PrintList(header);
    }
    DeleteList(header);
    fclose(fin);
    fclose(fout);
    return 0;
}


List MakeEmpty(List L) {
    L = malloc(sizeof(struct Node));
    L->element = 0;
    L->next = NULL;
    return L;
}

int IsEmpty(List L) {
    return L->next == NULL;
}

int IsLast(Position P, List L) {
    return P->next == NULL;
}

void Insert(ElementType X, List L, Position P) {
    Position TmpCell = malloc(sizeof(struct Node));
    // if (TmpCell == NULL)
    //     FatalError("Out of space!!!\n");
    TmpCell->element = X;
    if(L->next == NULL && P==L) {   // 빈 리스트
        TmpCell->next = NULL;
        L->next = TmpCell;
    } else {    // 일반적인 경우
        TmpCell->next = P->next;
        P->next = TmpCell;
    }
}

void PrintList(List L) {
    // IsEmpty(List가 비어있는지) 먼저 확인 및 처리
    if (IsEmpty(L)) {
        fprintf(fout, "empty list!\n");
        return;
    }

    Position P = L->next;
    while (P != NULL) {
        fprintf(fout, "key: %d ", P->element);
        P = P->next;
    }
    fprintf(fout, "\n");
}

void Delete(ElementType X, List L) {
    Position P, TmpCell;
    
    P = FindPrevious(X, L);
    if (!IsLast(P, L)) {
        TmpCell = P->next;
        P->next = TmpCell->next;
        free(TmpCell);
    } else {
        fprintf(fout, "deletion(%d) failed : element %d is not in the list\n", X, X);   // 예외 처리
    }
}

Position Find(ElementType X, List L) {
    Position P;
    P = L->next;
    while (P != NULL && P->element != X)
        P = P->next;
    
    return P;
}

Position FindPrevious(ElementType X, List L) {
    Position P;

    P = L;
    while (P->next != NULL && P->next->element != X)
        P = P->next;

    return P;
}

void DeleteList(List L) {
    Position P, Tmp;
    P = L->next;
    L->next = NULL;
    while (P != NULL) {
        Tmp = P->next;
        free(P);
        P = Tmp;
    }
}
