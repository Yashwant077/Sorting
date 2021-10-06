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
    printf("\nBubble Sort is Running...");
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

void insertionSort(int* arr, int n)
{
    printf("\nInsertion Sort is Running...");
    int temp,key,j;
    for(int i=1;i<n;i++)    //for no. of passes
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void selectionSort(int* arr, int n)
{
    printf("\nSelection Sort is Running...");
    int temp,indexOfMin;
    for(int i=0;i<n-1;i++)     //for n-1 no. of passes
    {
        indexOfMin = i;
        for(int j=i+1; j<n;j++)
        {
            if(arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        //swapping
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int* A, int low, int high)
{
    int partitionIndex; // Index of pivot after partition
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);    // sort left subarray
        quickSort(A, partitionIndex + 1, high);   // sort right subarray
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
               "\n3. Selection Sort"
               "\n4. Quick Sort"
               "\n0. Quit\n");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                bubbleSort(ptr,n);
                printf("\nSorted elements::");
                printArray(ptr,n);
                break;
            case 2:
                insertionSort(ptr,n);
                printf("\nSorted elements::");
                printArray(ptr,n);
                break;
            case 3:
                selectionSort(ptr,n);
                printf("\nSorted elements::");
                printArray(ptr,n);
                break;
            case 4:
                quickSort(ptr,0,n-1);
                printf("\nSorted elements::");
                printArray(ptr,n);
                break;
            case 0:
                free(ptr);
                exit(1);
                break;
            default:
                printf("Please enter a valid choice!!!");
                break;
        }
    }while(ch != 0);
    return 0;
}
