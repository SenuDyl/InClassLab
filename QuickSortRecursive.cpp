#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
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
//Sort using divide and conquer approach
int* quickSort(int* array,int start,int end){
    if(end<=start){return array;}//base case
    int pivot=partition(array,start,end);
    quickSort(array,start,pivot-1);
    quickSort(array,pivot+1,end);
    return array;
}

int main(){
    auto start = high_resolution_clock::now();
    int n;
    cout<<"Total elements in the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=rand()%50;
    int *newArray=quickSort(arr,0,n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "time taken is "
       << (duration.count())*0.000001<< " seconds" << endl;
    return 0;
}