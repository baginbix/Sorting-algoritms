#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "sorting_algorithms.h"

#define LENGTH 10000000
int cint = 0;

extern void bubbleSort(int *list, const int length);

int main()
{
    /*LPCSTR screen[100*100];
	HANDLE console = CreateConsoleScreenBuffer(GENERIC_READ|GENERIC_WRITE,0,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);
	SetConsoleActiveScreenBuffer(console);
	DWORD bytesWritten =0;
	screen[100*100-1] = '\0';

	COORD coord;
	coord.X=0;

	e,&screen,100*100,coord,&bytesWritten);
	return 0;*/

    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("Current local time and date: %s", asctime(timeinfo));

    clock_t start, end;
    int *list = (int *)malloc(sizeof(int) * LENGTH);
    for (int i = 0; i < LENGTH; i++)
    {
        list[i] = rand();
    }

    printf("\nQuickSort\n");
    start = clock();
    int *qList = (int *)malloc(sizeof(list) * LENGTH);
    memcpy(qList, list, sizeof(int) * LENGTH);
    //quickSort(qList, 0, LENGTH - 1);
    end = clock() - start;
    printf("Sorted: %d numbers\n", LENGTH);
    printf("Time: %f", (double)(end) / CLOCKS_PER_SEC);
    free(qList);

    printf("\nMergeSort\n");
    start = clock();
    int *mList = (int *)malloc(sizeof(list) * LENGTH);
    memcpy(mList, list, sizeof(int) * LENGTH);
    mergeSort(mList, 0, LENGTH - 1);
    end = clock() - start;
    printf("Sorted: %d numbers\n", LENGTH);
    printf("Time: %f", (double)(end) / CLOCKS_PER_SEC);
    free(mList);

    printf("\nInsertionSort\n");
    start = clock();
    int *iList = (int *)malloc(sizeof(list) * LENGTH);
    memcpy(iList, list, sizeof(int) * LENGTH);
    insertionSort(iList, LENGTH);
    end = clock() - start;
    printf("Sorted: %d numbers\n", LENGTH);
    printf("Time: %f", (double)(end) / CLOCKS_PER_SEC);
    free(iList);

    printf("\nBubblesort\n");
    start = clock();
    int *bList = (int *)malloc(sizeof(list) * LENGTH);
    memcpy(bList, list, sizeof(int) * LENGTH);
    bubbleSort(bList, LENGTH);
    end = clock() - start;
    printf("Sorted: %d numbers\n", LENGTH);
    printf("Time: %f", (double)(end) / CLOCKS_PER_SEC);
    free(bList);

    free(list);
    exit(EXIT_SUCCESS);
    return 0;
}
