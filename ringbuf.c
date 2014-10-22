#include "ring_buf.h"
#include "stdlib.h"
#include "stdio.h"

void rb_delete(Ringbuf *rb_t){
	if(rb_t != NULL){
		free(rb_t->buf);
		free(rb_t);
	}
	return;
}

void rb_create(Ringbuf *rb_t, int size){
	rb_t->buf = (char *)calloc(size, sizeof(char));
	
	rb_t->head = 0;
	rb_t->tail = 0;
	rb_t->count = 0;
	rb_t->length = size;
}

int rb_is_full(Ringbuf *rb_t){
	return (rb_t->count == rb_t->length) ? 1 : 0;
}

int rb_is_empty(Ringbuf *rb_t){
	return rb_t->count ? 0 : 1;
}

int rb_readable(Ringbuf *rb_t){
	return rb_t->count;
}

int rb_space(Ringbuf *rb_t){
	return rb_t->length-rb_t->count;
}

int rb_write(Ringbuf *rb_t, int data){
	if(rb_t->buf == NULL)
		return 0;

	if(rb_t->count < rb_t->length)
		rb_t->count++;
	else	//if buffer is full, need to bump up the tail too
		rb_t->tail = (rb_t->tail +1) % rb_t->length;
	
	rb_t->buf[rb_t->head] = data;
	rb_t->head = (rb_t->head +1) % rb_t->length;

	return 1;
}

int rb_read(Ringbuf *rb_t){
	char data;

	if(rb_t->buf == NULL)
		return -1;
	
	if(rb_t->count != 0) {	//make sure its not empty 
		rb_t->count--;
		data = rb_t->buf[rb_t->tail];
		rb_t->buf[rb_t->tail] = 0;
		rb_t->tail = (rb_t->tail + 1) % rb_t->length;
		return data;
	}
	else
		return 0;	//empty ring buffer
}

void rb_print_buf(Ringbuf *rb_t, int ordered) {
	int i;
	if(ordered){
		for(i=0;i<rb_t->length;i++){
			printf("%d\t", rb_t->buf[i]);
		}
	}
	else {
		for(i=0;i<rb_t->length;i++){
			printf("%d\t", rb_t->buf[i]);
		}
	}
	printf("\n");
}
