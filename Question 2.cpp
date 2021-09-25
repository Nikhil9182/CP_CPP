#include <stdio.h>

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubble_sortI(int a[], int n) 
{
    int i = 0, j = 0, tmp;
    for (i = 0; i < n; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (a[j] > a[j + 1]) {  // swop if order is broken
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void bubble_sortD(int a[], int n) 
{
    int i = 0, j = 0, tmp;
    for (i = 0; i < n; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (a[j] < a[j + 1]) {  // swop if order is broken
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

int main() 
{
  int a[1000], n, i, d, swap,ch,size;
  int N = 10;
  
  printf("Enter the first 10 digits to the array\n");
  for(i= 0;i<N;i++)
  {
  	scanf("%d", &a[i]);
  }
  size = N;
  printArray(a,size);
  
  do{
  	printf("Menu\n 1.Add Elements\n 2.BubbleSort Increasing Order\n 3.BubbleSort Decreasing Order\n 4.Exit\n");
  	scanf("%d",&ch);
  	switch(ch)
  	{
  		case 1:
  			{
  				printf("Enter number of elements you want to add in the array: ");
  				scanf("%d", &n); 
  				if(size+n > 1000)
  				{
  					printf("Bad Input!!!! Try Again");
  					break;
				}
				printf("Enter %d integers\n", n);
  				size = size+n;
  				for (i = N; i < size ; i++)
  				{
  					scanf("%d", &a[i]);
				}
				printf("Printing the unsorted array:\n");
				printArray(a,size);
				break;
			}
		case 2:
			{
				bubble_sortI(a, size);
				printf("Printing the sorted array in Increasing Order:\n");
				printArray(a,size);
				break;
			}
		case 3:
			{
				bubble_sortD(a, size);
				printf("Printing the sorted array in Decreasing Order:\n");
				printArray(a,size);
				break;
			}
		case 4:
			{
				printf("Goodbye!!!");
			}
	}
  }while(ch !=4);

  return 0;
}
