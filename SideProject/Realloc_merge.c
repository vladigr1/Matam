#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


void mergesort(int a[], int size);
void m_sort(int a[], int help[], int size);
void merge(int a[], int asize, int b[], int bsize, int help[]);

int main() {
	int i;
	int arr[10] = {0,1,2,3,4,55,6,7,8,9};
	mergesort(arr, 10);
	for (i = 0; i < 10; ++i)printf("%d ", arr[i]);
	_getch();
	return 0;
}
void merge(int a[], int asize, int b[], int bsize, int help[]) {
	int i=0,j=0,k=0;
	while (i < asize && j < bsize) {
		help[k++] = (a[i] < b[j]) ? a[i++] : b[j++];
	}
	while (i < asize) {
		help[k++] = a[i++];
	}
	while (j < bsize) {
		help[k++] = b[j++];
	}
}

void m_sort(int a[], int help[], int size) {
	int left = size / 2, right = size - left;
	if (size < 2) return;
	m_sort(a, help, left);
	m_sort(a+left, help, right);
	merge(a, left, a + left, right, help);
	memcpy(a, help, size*sizeof(int));
}

void mergesort(int a[], int size) {
	int *help = (int *)malloc(size*sizeof(int));
	if (help == NULL) exit(1);
	m_sort(a, help, size);
	free(help);
}
