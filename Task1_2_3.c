// standard input/output library, Needed for printf() 
#include<stdio.h>
//standard library Needed fpr Srand() and rand()
#include <stdlib.h>
// this is time related function ,Needed for time(), clock()
#include <omp.h>
//include omp for parallelization
#include<time.h>
#define MAX_SIZE 2000//define maximum array 

// function for initialized the matrix 
void initializedArray(double A[MAX_SIZE][MAX_SIZE],int N){
   srand(time(0));// Srand that start the sequence of random number generator,witout srand everytime you run your program thr rand() generate the same sequence of number.
   //srand help you to change the sequence every rime you run your program 
   //time(0) gives the current time in a special way.
   //Instead of showing the time like 03 March 2025, 12:34 PM,
   //it gives the time as a single number (a count of seconds).
   //The count starts from a fixed date:
   //January 1, 1970.
   //time(0) changes every second.

   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         A[i][j]=rand()%100;//It generates a random number between 1 and 100, % 100	Takes the remainder when divided by 100 — so result is between 0 and 99
      }
    }
}
//loop interchange (Row major)
void RowMajor(double A[MAX_SIZE][MAX_SIZE],int N){
    
long long sum=0;
double start=omp_get_wtime(); // return current time in seconds , used in openMP programs
 #pragma openmp parallel for schedule(static) reduction(+:sum)
       for(int i=0; i<N; i++)
    {
           for(int j=0; j<N; j++){
               sum += A[i][j];
           }
    }
    double end= omp_get_wtime();
    printf("Execution Time:%.6f",(start-end));
}
//loop Interchange(coulmn Major)
void ColumnMajor(double A[MAX_SIZE][MAX_SIZE],int N){
    
    long long sum=0;//declare sum is long long beacuse result can be very large, size of the byte is 8 bytes, long long can store 9 quintillion values 
    double start=omp_get_wtime(); // return current time in seconds , used in openMP programs
    #pragma openmp parallel for schedule(static) reduction(+:sum)
        for(int j=0; j<N; j++)
        {
               for(int i=0; i<N; i++){
                   sum += A[i][j];
               }
        }
        double end= omp_get_wtime();
        printf("Execution Time:%.6f",(start-end));
    }


int main(){
int sizes[]={512,1024,2000};//Test different matrix sizes
int threads[]={1,4,8};// Test different thread sizes

 static double A[MAX_SIZE][MAX_SIZE];    //static move A to static memory which hold much large data
 //useful for large array that not fit on stack memory


    return 0;
}