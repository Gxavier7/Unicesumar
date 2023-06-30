#include <stdio.h>
#include <stdlib.h>

//  Node
typedef struct No {
  char data;
  struct No* next;
} No;

typedef struct stackNo {
  char data;
  struct stackNo* next;
} stackNo;

//  Queue

typedef struct Queue {
  No* start;
  No* end;
} Queue;

//  Stack

typedef struct Stack {
  stackNo* top;
} Stack;

// Create Queue
Queue* createQueue() {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->start = NULL;
  queue->end = NULL;
  return queue;
}

//  Verify if queue is empty
int verifyIfEmpty(Queue* queue) {
  return (queue->start == NULL);
}

// Insert on queue
void queueInsert(Queue* queue, char data) {
  No* newNo = (No*)malloc(sizeof(No));
  newNo->data = data;
  newNo->next = NULL;

  if (verifyIfEmpty(queue)) {
    queue->start = newNo;
    queue->end = newNo;
  } else {
    queue->end->next = newNo;
    queue->end = newNo;
  }
}

// Withdraw queue
char dequeue(Queue* queue) {
  if (verifyIfEmpty(queue)) {
    printf("A fila está vazia.\n");
    return '\0';
  } else {
    No* startNo = queue->start;
    char nucleotide = startNo->data;
    queue->start = queue->start->next;
    // free(startNo);
    return nucleotide;
  }
}

// Função para imprimir a fila
void printQueue(Queue* queue) {
  if (verifyIfEmpty(queue)) {
    printf("A fila esta vazia.\n");
  } else {
    No* currentNode = queue->start;
    printf("Fila de DNA: ");
    while (currentNode != NULL) {
      printf("%c ", currentNode->data);
      currentNode = currentNode->next;
    }
    printf("\n");
  }
}

// Create empty Stack
Stack* createStack() {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

// Verify if Stack is empty
int verifyStackEmpty(Stack* stack) {
  return (stack->top == NULL);
}

// Stack up
void push(Stack* stack, char data) {
  stackNo* newNo = (stackNo*)malloc(sizeof(stackNo));
  newNo->data = data;
  newNo->next = stack->top;
  stack->top = newNo;
}

// Print Stack
void printStack(Stack* stack) {
  if (verifyStackEmpty(stack)) {
    printf("A pilha esta vazia.\n");
  } else {
    stackNo* currentNode = stack->top;
    printf("Pilha de DNA convertido: ");
    while (currentNode != NULL) {
      printf("%c ", currentNode->data);
      currentNode = currentNode->next;
    }
    printf("\n");
  }
}

// Convert to double helix
void convertSequence(Queue* queue, Stack* stack) {
    while (!verifyIfEmpty(queue)) {
        char nucleotide = dequeue(queue);
        switch (nucleotide) {
            case 'A':
                push(stack, 'T');
                break;
            case 'C':
                push(stack, 'G');
                break;
            case 'T':
                push(stack, 'A');
                break;
            case 'G':
                push(stack, 'C');
                break;
        }
    }
}

int main() {
  int count;
  char nucleotide;
  Queue* dna = createQueue();
  Stack* convertedStack = createStack();

  system("cls");
  printf("Digite a quantidade de nucleotideos que deseja inserir:\n");
  scanf("%d", &count);

  for (int i = 0; i < count; i++)
  {
    system("cls");
    printf("Digite o %d nucleotideo (A, C, G, T)\n", i+1);
    scanf(" %c", &nucleotide);
    queueInsert(dna, nucleotide);
  }
  
  system("cls");
  printf("Sequencia original de DNA:\n");
  printQueue(dna);

  convertSequence(dna, convertedStack);

  printf("Sequencia convertida de DNA:\n");
  printStack(convertedStack);

  return 0;
}