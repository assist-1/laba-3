void bubbleSort(float arr1[], int n1, float arr2[], int n2) {
	int i, j;
    float temp1, temp2;
	for (i = 0; i < n1 - 1; i++)
		for (j = 0; j < n1 - i - 1; j++)
			if (arr1[j] > arr1[j + 1]) {
                temp1 = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp1;

                temp2 = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp2;
            }

}