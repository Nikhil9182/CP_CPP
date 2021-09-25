#include <stdio.h>

void ShowElements(int arr[],int size)
{
	printf("Updated Array : ");
    for(int i = 0; i < size; i++)
    {
    	printf(" %d",arr[i]);
	}
}

void InsertElemets(int arr[],int size, int elements,int position,int numbers)
{
	int n = position + elements;
	for(int i = position; i < n; i++)
	{
		arr[i+elements] = arr[i];
	}
	printf("Enter the numbers to be Inserted\n");
    for(int i = 0; i < elements; i++)
    {
    	scanf("%d",&n);
    	arr[position + i] = n;
	}
	ShowElements(arr,numbers);
}

void DeleteElements(int arr[],int size, int elements,int position,int numbers)
{
	int n = elements - 1;
	for(int i = position; i < size; i++)
	{
		arr[i] = arr[i + n + 1];
	}
	ShowElements(arr,numbers - elements);
}

int main()
{
    int arr[20];
    int size = sizeof(arr)/sizeof(arr[0]);
    int numbers;
    
    printf("Enter number of elements in the array\n");
    scanf("%d", &numbers);
    if(numbers > 20)
        return 0;
    printf("Enter %d elements\n", numbers);
    
    for (int i = 0; i < numbers; i++) 
    {
        scanf("%d", &arr[i]);
    }
    ShowElements(arr,numbers);
    int ch;
    do
    {
    printf("\nMenu\n 1.Insertion\n 2.Deletion\n 3.ShowElements\n 4.Exit\n");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1: 
        	{   
				int position,elements;
                printf("Enter the number of elements you want to insert : ");
                scanf("%d",&elements);
                printf("Enter the position : ");
                scanf("%d",&position);
                if((numbers + elements) > size)
                {
                	printf("Number Exceded!!! Terminating");
                    break;
                }
                else
                {
                	numbers+=elements;
                	InsertElemets(arr,size,elements,position-1,numbers);
                	break;
				}
        	}
        case 2:
        	{
        		int position,elements;
                printf("Enter the number of elements you want to delete : ");
                scanf("%d",&elements);
                printf("Enter the position : ");
                scanf("%d",&position);
                if((position < 0) || (position > size) || ((position + elements) > size))
                {
                	printf("Number Exceded!!! Terminating");
                    break;
				}
				else
				{
					numbers-=elements;
					DeleteElements(arr,size,elements,position-1,numbers);
					break;
				}
			}
		case 3:
			{
				ShowElements(arr,numbers);
				break;
			}
		case 4:
			{
				printf("\nGoodbye!!!");
			}
    }
	}while(ch != 4);
    return 0;
}


