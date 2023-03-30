
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <ostream>
using namespace std;
using namespace std::chrono;
//Return the location of the pivot
int partition(int* array,int start,int end){
    int pivot=array[end];
    int i=start-1;
    int j=start;
    int temp;
    while(j<=end-1){
        if (array[j]<pivot){
            i++;
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
        j++;
    }
    i++;
    int temp1=array[i];
    array[i]=array[end];
    array[end]=temp1;
    return i;
}

void quickSortIterative(int* array, int start, int end)
{
    int stack[end - start + 1];
    int top = -1;
    stack[++top] = start;
    stack[++top] = end;
    while (top >= 0) {
        end = stack[top--];
        start = stack[top--];
        int pivot = partition(array, start, end);
        if (pivot + 1 < end) {
            stack[++top] = pivot + 1;
            stack[++top] = end;
        }
        if (pivot - 1 > start) {
            stack[++top] = start;
            stack[++top] = pivot - 1;
        }
    }
}
  



int main()
{
	auto start = high_resolution_clock::now();
    int n;
    cout<<"Total elements in the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=rand()%50;
    quickSortIterative(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "time taken is "
       << (duration.count())*0.000001<< " seconds" << endl;
    return 0;
	
	return 0;
}
