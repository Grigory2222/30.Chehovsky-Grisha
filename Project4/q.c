#include "stdio.h"
#include <stdlib.h>

void sort_vuborom(int a[], int n) {
	int min_index;
	for (int i = 0; i < n - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min_index] > a[j]) {
				min_index = j;
			}
		}
		if (min_index != i)
		{
			int temp = a[i];
			a[i] = a[min_index];
			a[min_index] = temp;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d \n", a[i]);
	}
}







static void vubor_vvoda_massive() {
	printf("1.Vvedu sam\n");
	printf("2.Random massive\n");
}
void random_massive(int a[], int n) {
	srand(100);
	int i;
	for (i = 0; i < n; i++) {
		a[i] = rand();
	}
}

void linpoisk(int a[], int n) {
	int i, x, flag = 0;
	printf("Vvedite x\n");
	scanf_s("%d", &x);
	for (i = 0; i < n; i++) {
		if (a[i] == x) {
			flag = i;
			break;
		}
	}
	if (flag != 0) {
		printf("chislo naydeno, index - %d", flag);
	}
	else {
		printf("chisla net v massive");
	}
}


void b_poisk(int a[], int n) {
	int x, flag = 0;
	int l = 0, r = n - 1, c;
	printf("Vvedite x\n");
	scanf_s("%d", &x);
	flag = 0;
	while (l <= r) {
		c = (l + r) / 2;
		if (a[c] > x) {
			r = c - 1;
		}
		else if (a[c] < x) {
			l = c + 1;
		}
		else {
			flag = c;
			break;
		}
	}
	if (flag != 0) {
		printf("chislo naydeno, index - %d\n", flag);
	}
	else {
		printf("chisla net v massive\n");
	}

}




void menu()
{
	printf("1. b_poisk \n");
	printf("2. linpoisk\n");
	printf("3. sort_vuborom\n");
	printf("4. Linear search\n");
	printf("5. Exit\n");
	printf("6. Exit\n");
	printf("7. Exit\n");
	printf("8. Exit\n");
}


void genmassiva_sam(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
}

void vivodmassive(int a[], int n) {

	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}



int main() {
	int c, n, g = 1;
	int a[10];
	vubor_vvoda_massive();

	scanf_s("%d", &c);
	if ((c == 1) || (c == 2)) {
		if (c == 1) {
			printf("Vvedite dliny massiva\n");
			scanf_s("%d", &n);
			genmassiva_sam(a, n);
			vivodmassive(a, n);
		}
		if (c == 2) {
			printf("Vvedite dliny massiva\n");
			scanf_s("%d", &n);
			random_massive(a, n);
			vivodmassive(a, n);

		}
		printf("\n");

		while (g != 8) {
			printf("Vuberite sortirovky\n");
			menu();
			scanf_s("%d", &g);
			switch (g)
			{
			case 1: {


				b_poisk(a, n);
				break;
			}
			case 2: {


				linpoisk(a, n);
				break;
			}
			case 3: {
				sort_vuborom(a, n);
				break;
			}

			}
		}
	}
}