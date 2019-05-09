void swap(int* first, int* second);
void selectionsort(int* rawarr, int size) {
	int minIndex;
	for (int i = 0; i < size; ++i) {
		minIndex = i;
		for (int j = i; j < size; ++j) {
			if (rawarr[j] < rawarr[minIndex]) {
				minIndex = j;
			}
		}
		swap((rawarr + minIndex), (rawarr + i));
	}
}