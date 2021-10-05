#include <stdio.h>
#include <stdlib.h>
 
void printArray(int* arr, int n)
{
    for(int i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}

void bubbleSort(int* arr, int n)
{
    int temp, isSorted=0;
    for(int i=0; i<n-1; i++)   //for no. of passes
    {
        isSorted = 1;
        for(int j=0; j<n-1-i;j++)   //for no. of comparisons
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted)
        {
            return;
        }
    }
}

int main()
{
    int *ptr;
    int n,ch;
    printf("Enter total no. of elements::");
    scanf("%d",&n);
    
    ptr = (int*)malloc(n*sizeof(int));
    
    if(ptr == NULL)
    {
        printf("Memory is not allocated.\n");
    }
    else
    {
        printf("Memory is allocated successfully.\n");
        printf("Enter the elements:");
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ptr[i]);
        }
        printf("Elements in the Array::");
        printArray(ptr,n);
    }
    
    do
    {
        printf("\nEnter your Choice::"
               "\n1. Bubble Sort"
               "\n2. Insertion Sort"
               "\n0. Quit\n");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                bubbleSort(ptr,n);
                printf("Sorted elements::");
                printArray(ptr,n);
                break;
            case 2:
                // insertionSort(ptr,n);
                // printf("Sorted elements::");
                // printArray(ptr,n);
                break;
            case 0:
                exit(1);
                break;
            default:
                printf("Please enter a valid choice!!!");
                break;
        }
    }while(ch != 0);
    
    return 0;
}
