#include "stdio.h"
#include "stdlib.h"
#include "ring_buf.h"

#define BUF_SIZE 10

int main(){

	Ringbuf *rb;
	int val;

	rb = (Ringbuf *)malloc(sizeof(Ringbuf));

	rb_create(rb, BUF_SIZE);

	for(val = 0; val< BUF_SIZE * 2; val++) {
		rb_write(rb, val);	
		rb_print_buf(rb,0);
	}

	printf("Reading %d, Count = %d, H=%d, T=%d\n", rb_read(rb), rb->count, rb->head, rb->tail);
	rb_print_buf(rb,0);
	printf("Reading %d, Count = %d, H=%d, T=%d\n", rb_read(rb), rb->count, rb->head, rb->tail);
	rb_print_buf(rb,0);
	printf("Reading %d, Count = %d, H=%d, T=%d\n", rb_read(rb), rb->count, rb->head, rb->tail);
	rb_print_buf(rb,0);
	printf("Reading %d, Count = %d, H=%d, T=%d\n", rb_read(rb), rb->count, rb->head, rb->tail);
	rb_print_buf(rb,0);
	printf("Writing 99 %d, Count = %d, H=%d, T=%d\n", rb_write(rb, 99), rb->count, rb->head, rb->tail);
	rb_print_buf(rb,0);
	printf("Writing 10 %d, Count = %d, H=%d, T=%d\n", rb_write(rb, 10), rb->count, rb->head, rb->tail);
	rb_print_buf(rb,0);
	printf("Reading %d, Count = %d, H=%d, T=%d\n", rb_read(rb), rb->count, rb->head, rb->tail);
	rb_print_buf(rb,0);
	printf("Writing 28 %d, Count = %d, H=%d, T=%d\n", rb_write(rb, 28), rb->count, rb->head, rb->tail);
	rb_print_buf(rb,0);

	while(!rb_is_empty(rb)){
		printf("%d\n", rb_read(rb));
	}

	rb_delete(rb);
	return 0;
}
