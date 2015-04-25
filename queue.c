#include "queue.h"

void q_delete(queue_t *q){
    if(q != NULL){
	free(q->buf);
        free(q);
    }
}

void q_create(queue_t *q, int size){
    q->buf = (char *) calloc(size, sizeof(char));
    q->size = size;
    q->index = 0;
    q->first = 0;
    q->last = 0;
}

void q_b_write(queue_t *q, char data){
    if(q->count < q->size){
        
    }
}

char q_b_read(queue_t *q){

}

bool q_is_full(queue_t *q){

}

bool q_is_empty(queue_t *q){

}

int q_size(queue_t *q){

}

