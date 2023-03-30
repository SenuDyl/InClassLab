#include <bits/stdc++.h>
#include <chrono>
#include <iomanip>
using namespace std::chrono;
using namespace std;
double * InsertionSort(double *arr,int n)
    {
        
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            //Shift one element to the right is it is larger than the key
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
            //print the output such that every iteration in a new line with elements seperated by spaces
                 
        }
   return arr;
}
double median(double *arr,int n){
   if (n%2==1){
      return arr[n/2];
   }else{
      return (arr[n/2]+arr[n/2 - 1])/2;
   }
}


void printArray(double *array,int size){
   cout<<"Sorted: ";
   for (int i=0;i<size;i++){
      cout<<array[i]<<" ";
   }
   cout<<endl;    
   

}
int main(){

   int n;
   cin>>n;
   double arr[n] ;
   for(int i=0;i<n;i++)
      cin>>arr[i]; 

   for(int j=0;j<n;j++){
      double *newArray=InsertionSort(arr,j+1);
      double answer=median(newArray,j+1);
      printArray(newArray,j+1);
      cout<<"Median: ";
      printf("%.1f",answer);
      cout<<endl;
   }
   return 0;

}
    
 