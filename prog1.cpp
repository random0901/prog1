#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main() {
	int m, n;
	printf("Enter the size of square matrix : ");
	scanf_s("%d", &n);
	printf("Enter the size of vector : ");
	scanf_s("%d", &m);
	if (m != n) {
		printf("Multiplication is not possible.\n");
		exit(0);
	}
	int i = 0, j = 0;
	int arr[100][100], vec[100],res[100];
	omp_set_num_threads(n);
#pragma omp parallel
	{
#pragma omp for
		for (i = 0; i < n; i++) {
			srand(i);
			vec[i] = rand() % 100;
			for (j = 0; j < n; j++) {
				arr[i][j] = rand() % 100;
			}
			printf("\n");
		}
	}
#pragma omp parallel
	{
#pragma omp for
		for (i = 0; i < n; i++) {
			res[i] = 0;
			for (j = 0; j < n; j++)
				res[i] += arr[i][j] * vec[j];
		}
	}
	printf("Matrix * Vector = Resultant Matrix\n");

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%3d ", arr[i][j]);
		if (i == n / 2)
			printf("  *  %3d  = %6d\n", vec[i], res[i]);
		else
			printf("     %3d    %6d\n", vec[i], res[i]);
	}
}