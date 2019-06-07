#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>


void CountSort(int* array, int size) {
	int minValue = array[0];
	int maxValue = array[0];
	for (int i = 1; i < size; ++i) {
		if (array[i] < minValue)
			minValue = array[i];
		if (array[i] > maxValue)
			maxValue = array[i];
	}
	int range = maxValue - minValue + 1;
	int* pCount = (int*)malloc(sizeof(int)*range);
	if (pCount == NULL) {
		assert(0);
		return;
	}
	memset(pCount, 0, range*sizeof(int));
	for (int i = 0; i < size; ++i) {
		pCount[array[i] - minValue]++;
	}
	int index = 0;
	for (int i = 0; i < range; ++i) {
		while (pCount[i]) {
			array[index++] = i + minValue;
			pCount[i]--;
		}
	}
}

int main() {
	int array[] = { 3,6,7,7,6,9,4,5,5,5,3,4,6,8,6,4,8 };
	CountSort(array, sizeof(array) / sizeof(array[0]));
	return 0;
}