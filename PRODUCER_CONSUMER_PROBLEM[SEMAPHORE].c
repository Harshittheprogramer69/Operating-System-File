#include <stdio.h>
#include <stdlib.h>
#define N 100
#define TRUE 1
int buffer[N];
int in = 0;
int out = 0;
int mutex = 1;
int empty = N;
int full = 0;
int produced_count = 0;
int consumed_count = 0;
int LIMIT = 10;
void down(int *s) {
    while(*s <= 0);
    (*s)--;
}
void up(int *s) {
    (*s)++;
}
int produce_item() {
    static int item = 1;
    printf("Producing %d\n", item);
    return item++;
}
void consume_item(int item) {
    printf("Consuming %d\n", item);
}
void insert_item(int item) {
    buffer[in] = item;
    printf("Inserted %d at %d\n", item, in);
    in = (in + 1) % N;
}
int remove_item() {
    int item = buffer[out];
    printf("Removed %d from %d\n", item, out);
    out = (out + 1) % N;
    return item;
}
void producer() {
    int item;
    while(TRUE) {
        if(produced_count >= LIMIT)
            break;
        item = produce_item();
        down(&empty);
        down(&mutex);
        insert_item(item);
        produced_count++;
        up(&mutex);
        up(&full);
    }
}

void consumer() {
    int item;
    while(TRUE) {
        if(consumed_count >= LIMIT)
            break;
        down(&full);
        down(&mutex);
        item = remove_item();
        consumed_count++;
        up(&mutex);
        up(&empty);
        consume_item(item);
    }
}

int main() {
    printf("---- PRODUCER ----\n");
    producer();
    printf("\n---- CONSUMER ----\n");
    consumer();
    return 0;
}