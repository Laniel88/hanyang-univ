#include<stdio.h>
#include<stdlib.h>
#define INF 1e9

FILE *fin;
FILE *fout;

typedef struct HeapStruct{
	int Capacity;
	int Size;
	int *Elements;
}Heap;

Heap* CreateHeap(int heapSize);
void Insert(Heap *heap, int value);
int Find(Heap *heap, int value);
int DeleteMax(Heap* heap);
void PrintHeap(Heap* heap);
int IsFull(Heap *heap);

int main(int argc, char* argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

	char cv;
	Heap* maxHeap;
	int heapSize, key, max_element;

	while(!feof(fin)){
		fscanf(fin, "%c", &cv);
		switch(cv){
			case 'n':
				fscanf(fin, "%d", &heapSize);
				maxHeap = CreateHeap(heapSize);
				break;
			case 'i':
				fscanf(fin, "%d", &key);
				Insert(maxHeap, key);
				break;
			case 'd':
				max_element = DeleteMax(maxHeap);
				if(max_element != -INF){
					fprintf(fout, "max element : %d deleted\n", max_element);
				}
				break;
			case 'p':
				PrintHeap(maxHeap);
				break;
			case 'f':
				fscanf(fin, "%d", &key);
				if(Find(maxHeap, key)) fprintf(fout, "%d is in the heap\n", key);
				else fprintf(fout, "finding error : %d is not in the heap\n", key);
				break;
		}
	}

	return 0;
}

/* create a new heap */
Heap* CreateHeap(int heapSize){
	// Allocate memory
    Heap* heap = (Heap*) malloc(sizeof(Heap));

	// Set the capacity and size of the heap
    heap->Capacity = heapSize;
    heap->Size = 0;

	// Allocate memory for the array to hold heap elements
    heap->Elements = (int*) malloc(heapSize * sizeof(int));

    return heap;
}

/* insert a value into the heap */
void Insert(Heap *heap, int value) {

	// Check if the heap is already full
    if (IsFull(heap)) {
        fprintf(fout, "insert error: heap is full\n");
        return;
    } else {
		fprintf(fout,"insert %d\n", value); // The heap is not full
	}

	// Increment the size of the heap (and assign to variable i)
    int i = ++(heap->Size);

	// Find the correct position for the new value in the heap
    while (i != 1 && value > heap->Elements[i / 2]) {
        heap->Elements[i] = heap->Elements[i / 2];
        i /= 2;
    }

	// Insert the value at the correct position
    heap->Elements[i] = value;
}

/* find a value in the heap */
int Find(Heap* heap, int value){
	// Iterate through the elements of the heap
    for (int i = 1; i <= heap->Size; i++) {
        if (heap->Elements[i] == value)
            return 1; // The value is found.
    }

	// The value is not found.
    return 0;
}

/* delete Max value from the heap */
int DeleteMax(Heap* heap){
	// Check if the heap is empty
    if (heap->Size == 0) {
        fprintf(fout, "delete error : heap is empty\n");
        return -INF;
    }

    int i, child;
    int max_element, last_element;

	// Store the maximum element(root) and last element of the heap
    max_element = heap->Elements[1];
    last_element = heap->Elements[heap->Size--];

	// Reconstruct the heap after removing the maximum element
    for (i = 1; i * 2 <= heap->Size; i = child) {
        child = i * 2;
        if (child != heap->Size && heap->Elements[child + 1] > heap->Elements[child])
            child++;
        if (last_element < heap->Elements[child])
            heap->Elements[i] = heap->Elements[child];
        else
            break;
    }

	// Insert the last element at the correct position
    heap->Elements[i] = last_element;

	// Return the maximum element that was deleted.
    return max_element;
}

/* print the heap */
void PrintHeap(Heap* heap){
	/// Check if the heap is empty
    if (heap->Size == 0) {
        fprintf(fout, "print error : heap is empty\n");
        return;
    }

	// Iterate through the elements of the heap and print them
    for (int i = 1; i <= heap->Size; i++)
        fprintf(fout, "%d ", heap->Elements[i]);
    fprintf(fout, "\n");
}

/* check if the heap is full */	
int IsFull(Heap* heap){
    // Check if the size of the heap is equal to its capacity
    return (heap->Size == heap->Capacity);
}