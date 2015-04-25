#ifndef RING_BUF_H
#define RING_BUF_H

typedef struct ring_buf_t {
	int head;
	int tail;
	int length;
	int count;
	char *buf;
}Ringbuf;

void rb_delete(Ringbuf *rb_t);
void rb_create(Ringbuf *rb_t, int size);

int rb_is_full(Ringbuf *rb_t);
int rb_is_empty(Ringbuf *rb_t);
int rb_readable(Ringbuf *rb_t);
int rb_space(Ringbuf *rb_t);

int rb_write(Ringbuf *rb_t, int data);
int rb_read(Ringbuf *rb_t);

void rb_print_buf(Ringbuf *rb_t, int ordered);

#endif
