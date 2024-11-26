#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define Max_Heap_Size 100

typedef struct MinHeap {
  int *arr;
  int capacity;
  int size;
} MinHeap;

MinHeap *createMinHeap(int capacity) {
  MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
  heap->capacity = capacity;
  heap->size = 0;
  heap->arr = (int *)malloc(capacity * sizeof(int));
  return heap;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int parent(int i) {
  return (i - 1) / 2;
}

int leftC(int i) {
  return ((2 * i) + 1);
}

int rightC(int i) {
  return ((2 * i) + 2);
}

void minHeapify(MinHeap *heap, int i) {
  int smallest = i;
  int left = leftC(i);
  int right = rightC(i);

  if (left < heap->size && heap->arr[left] < heap->arr[smallest]) {
    smallest = left;
  }
  if (right < heap->size && heap->arr[right] < heap->arr[smallest]) {
    smallest = right;
  }
  if (smallest != i) {
    swap(&heap->arr[i], &heap->arr[smallest]);
    minHeapify(heap, smallest);
  }
}

void insertKey(MinHeap *heap, int key) {
  if (heap->size == heap->capacity) {
    printf("Heap overflow: could not insert key \n");
    return;
  }
  heap->size++;
  int i = heap->size - 1;
  heap->arr[i] = key;

  while (i != 0 && heap->arr[parent(i)] > heap->arr[i]) {
    swap(&heap->arr[i], &heap->arr[parent(i)]);
    i = parent(i);
  }
}

int extractMin(MinHeap *heap) {
  if (heap->size <= 0) {
    return INT_MAX;
  }
  if (heap->size == 1) {
    heap->size--;
    return heap->arr[0];
  }

  int root = heap->arr[0];
  heap->arr[0] = heap->arr[heap->size - 1];
  heap->size--;
  minHeapify(heap, 0);

  return root;
}

void printHeap(MinHeap *heap) {
  for (int i = 0; i < heap->size; i++) {
    printf("%d ", heap->arr[i]);
  }
  printf("\n");
}

void freeMinHeap(MinHeap *heap) {
  free(heap->arr);
  free(heap);
}

int main() {
  MinHeap *heap = createMinHeap(Max_Heap_Size);

  insertKey(heap, 10);
  insertKey(heap, 20);
  insertKey(heap, 5);
  insertKey(heap, 6);
  insertKey(heap, 1);

  printf("Printing the heap \n");
  printHeap(heap);

  freeMinHeap(heap);

  return 0;
}