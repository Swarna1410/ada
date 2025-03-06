#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n,i,j;
void selectionsort(int arr[],int n)
{
for(i=0;i<n-1;i++)
{
int minIndex=i;
for(j=i+1;j<n;j++)
{
if(arr[j]<arr[minIndex])
{
minIndex=j;
}
}
if(minIndex!=i)
{
int temp=arr[i];
arr[i]=arr[minIndex];
arr[minIndex]=temp;
}
}
}
int main()
{
int n;
printf("enter the number of elements:");
scanf("%d",&n);

int arr[n];
srand(time(NULL));
for(i=0;i<n;i++)
{
arr[i]=rand()%10000;
}
clock_t start=clock();
selectionsort(arr,n);
printf("the sorted elemenrs are");
for(i=0;i<10;i++)
printf("%d\t",arr[i]);
clock_t end=clock();
double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
printf("time taken for sorting .%f seconds\n",time_taken);
return 0;
}




