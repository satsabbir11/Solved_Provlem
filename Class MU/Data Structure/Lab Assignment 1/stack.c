#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int cnt=0;

struct Stack{
    int array[MAX];
    int top;
};

struct Stack* createNewStack(){
    struct Stack *st = malloc(sizeof(struct Stack));
    st->top = -1;
}

int isFull(struct Stack* st){
    if(st->top == MAX-1) return 1;
    else return 0;
}

int isEmpty(struct Stack* st){
    if(st->top == -1) return 1;
    else return 0;
}

void push(struct Stack* st, int val){
    if(isFull(st)) printf("Stack is Full\n");
    else{
      st->array[++st->top]= val;
      cnt++;
    }
}

void pop(struct Stack* st){
    if(isFull(st)) printf("Stack is Empty\n");
    else{
      st->top--;
      cnt--;
    }
}

void printStack(struct Stack* st){
    for(int i=0;i<cnt;i++){
        printf("%d ", st->array[i]);
    }
     printf("\n");
}

int main(){
    struct Stack* st = createNewStack();
    push(st, 1);
    push(st, 2);
    push(st, 3);
    printStack(st);

    pop(st);

    printStack(st);
}
