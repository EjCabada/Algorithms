#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

int stack[MaxSize];
int stackTop = -1;

typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node {
  int data;
  Node *next;
};

struct LinkedList {
  Node *head;
};

// linked list
void append(LinkedList *list, int data) {
  struct Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  if (list->head == NULL) {
    list->head = newNode;
    return;
  } else {
    Node *iterator = list->head;
    while (iterator->next != NULL) {
      iterator = iterator->next;
    }
    iterator->next = newNode;
  }
}

void prepend(LinkedList *list, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = list->head;

  list->head = newNode;
}

void printList(LinkedList *list) {
  Node *iterator = list->head;
  while (iterator != NULL) {
    printf("%d ", iterator->data);
    iterator = iterator->next;
  }
  printf("\n");
}

// stack
void push(int item) {
  if (stackTop >= MaxSize - 1) {
    printf("Stack Overflow!!!\n");
    return;
  }
  stack[++stackTop] = item;
}

int pop() {
  if (stackTop < 0) {
    printf("Stack Underflow\n");
    return -1;
  }
  return stack[stackTop--];
}

int peek() {
  if (stackTop < 0) {
    printf("Stack is empty\n");
    return -1;
  }
  return stack[stackTop];
}

int isEmpty() {
  return stackTop > 0 ? 1 : 0;
}

void printStack() {
  if (stackTop == 0) {
    printf("Stack is empty\n");
  } else {
    for (int i = stackTop; i > 0; i--) {
      printf("%d ", stack[i]);
    }
    printf("\n");
  }
}

int main() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  list->head = NULL;
  append(list, 1);
  append(list, 2);
  append(list, 3);
  append(list, 4);
  prepend(list, 5);
  printf("printing list \n");
  printList(list);
  printf("\n");
  printf("printing stack\n");

  push(10);
  push(20);
  push(30);
  push(40);
  push(50);

  printf("%d popped from stack\n", pop());
  printf("Top element is %d\n", peek());

  printStack();

  return 0;
}