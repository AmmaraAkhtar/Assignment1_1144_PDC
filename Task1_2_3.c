// standard input/output library, Needed for printf() 
#include<stdio.h>
//standard library Needed fpr Srand() and rand()
#include <stdlib.h>
// this is time related function ,Needed for time(), clock()
#include <omp.h>
//include omp for parallelization
#include<time.h>
#define MAX_SIZE 2000//define maximum array 


int main(){
int sizes[]={512,1024,2000};//Test different array sizes
int threads[]={1,4,8};// Test different thread sizes

 static double A[MAX_SIZE][MAX_SIZE];    //static move A to static memory which hold much large data
 //useful for large array that not fit on stack memory


    return 0;
}