#include <stdio.h>

struct Buffer {
    int data;
    int capacity;
    int *Semaphore;
};

struct Buffer *createBUFFER(int x) {
    struct Buffer *S = malloc(sizeof(struct Buffer));
    if(!S) {
        return NULL;
    }
    S->capacity = x;
    S->data = -1;
    S->Semaphore = malloc(S->capacity*sizeof(int));
    if(!S->Semaphore) {
        return NULL;
    }
    return S;
};

int CHECK(struct Buffer *S) {
    if(Is_Empty(S)) {
        printf("Buffer is empty\n");
        return 1;
    }
    return 0;
}

int Is_Empty(struct Buffer *S) {
    return (S->data == -1); // TRUE = 1, FALSE = 0
}

int Size(struct Buffer *S) {
    return (S->data + 1);
}

int Is_Full(struct Buffer *S) {
    return (S->data == S->capacity - 1);
}

void Double_Stack(struct Buffer *S) {
    S->capacity *= 2;
    S->Semaphore = realloc(S->Semaphore,S->capacity*sizeof(int));
}

void PUSH(struct Buffer *S, int data) {
    if(Is_Full(S)) {
        Double_Stack(S);
    }
    S->Semaphore[++S->data] = data;
}

int POP(struct Buffer *S) {
    if(!CHECK(S)) {
        return (S->Semaphore[S->data--]);
    }
}

int PEEK(struct Buffer *S) {
    if(!CHECK(S)) {
        return (S->Semaphore[S->data]);
    }
}

void Delete_Stack(struct Buffer *S) {
    if(S) {
        if(S->Semaphore) {
            free(S->Semaphore);
            free(S);
        }
    }
}

void DISPLAY(struct Buffer *S) {
    if(!CHECK) {
        for(int i = S->data; i >= 0; i--) {
            printf("%d \n",S->Semaphore[i]);
        }
    }
}    