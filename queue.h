#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

typedef struct queue_s {
    int size;
    int index;
    int first;
    int last;
    char * buf;
} queue_t;


void q_create(queue_t *q, int size);
void q_delete(queue_t *q);
void q_b_write(const char *data);
void q_b_read(char *data);

bool q_nb_write(const char *data);
bool q_nb_read(char *data);

bool q_is_full(void);
bool q_is_empty(void);

int q_size(void);

#endif
