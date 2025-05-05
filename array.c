#include <stdio.h>
#include <stdlib.h>

typedef struct IntArray {
	int *array;
	int size;
	int capacity;
} IntArray;

int error = 0;

void init_array(IntArray *arr, int capacity) {
	arr->array = (int *)malloc(sizeof(int) * capacity);
	if (arr->array == NULL) {
		printf ("Not enough space");
		//выход с ошибкой?	
	}
	arr->capacity = capacity;
	arr->size = 0;
}

void print_array (IntArray *arr) {
	for (int i = 0; i < arr->size; i++) {
		printf("%d", arr->array[i]);
		if (i < arr->size -1) {
			printf(" ");
		}
	}
	printf("\n");
}

int get_size(IntArray *arr) {
	return arr->size;
}

int get_capacity(IntArray *arr) {
	return arr->capacity;
}

void push_back(IntArray *arr, int value) {
	arr->array[arr->size] = value;
	arr->size ++;
}

void pop_back(IntArray *arr) {
	if(arr->size > 0) {
		arr->size --;
	} else {
		printf("Array is empty. Nothing to delete./n");
	}
}

void pop_first(IntArray *arr) {
	if(arr->size > 0) {
		for (int i = 0; i < arr->size - 1; i ++) {
			arr->array[i] = arr->array[i + 1];
		}
		arr->size --;
	} else {
		printf("Array is empty. Nothing to delete./n");
	}
}

void reverse_array (IntArray *arr) {
	for (int i = 0; i < arr->size / 2; i ++) {
		int temp = arr->array[i];
		arr->array[i] = arr->array[arr->size - 1 - i];
		arr->array[arr->size - 1 - i] = temp;
	}
}

void sort_array (IntArray *arr) {
		for (int  i = 0 ; i < arr->size - 1; i ++ ) {
			if (arr->array[i] > arr-> array[i + 1]) {
			int temp = arr->array[i];
			arr->array[i] = arr-> array[i + 1];
			arr-> array[i + 1] = temp;
		}
		} 
	}

int main() {
	IntArray a = {NULL, 0, 0};
	init_array(&a, 10);
	push_back(&a, 5);
	push_back(&a, 2);
	push_back(&a, 8);
	push_back(&a, 1);
	print_array(&a);
	reverse_array(&a);
	print_array(&a);
	sort_array(&a);
	print_array(&a);
	pop_back(&a);
    print_array(&a);
	pop_first(&a);
    print_array(&a);
	reverse_array(&a);
	print_array(&a);
	printf("Size: %d\n", get_size(&a)); 
	printf("Capacity: %d\n", get_capacity(&a));
	return 0;
}