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
void initialized_Matrix(double A[MAX_SIZE][MAX_SIZE],int N){
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

void static1(double A[MAX_SIZE][MAX_SIZE], int N){


double total=0.0;
for(int w=0; w<10; w++){
long long sum=0;
double start=omp_get_wtime(); // return current time in seconds , used in openMP programs
 #pragma omp parallel for schedule(static , 100) reduction(+:sum)
    for(int i=0; i<N; i++)
    {
           for(int j=0; j<N; j++){
               sum += A[i][j];
           }
    }
    double end= omp_get_wtime();
    total=end-start;
}
    printf("Average Execution Time(static scheduing)After 10 Runs:%.6f\n",total/10);
}

void dynamic(double A[MAX_SIZE][MAX_SIZE],int N){
    
     double total=0.0;
    for(int w=0; w<10; w++){
    long long sum=0;
    double start=omp_get_wtime(); // return current time in seconds , used in openMP programs
     #pragma omp parallel for schedule(dynamic, 100) reduction(+:sum)
        for(int i=0; i<N; i++)
        {
               for(int j=0; j<N; j++){
                   sum += A[i][j];
               }
        }
        double end= omp_get_wtime();
        total=end-start;
    }
        printf("Average Execution Time(dynamic scheduling) After 10 Runs:%.6f\n",total/10);
    }
 
    

int main(){
int sizes[]={512,1024,2000};//Test different matrix sizes
int threads[]={1,4,8};// Test different thread sizes



for(int t=0; t<3; t++){
    
        omp_set_num_threads(threads[t]);
        printf("\n--- Testing with %d Threads ---\n", threads[t]);
        for(int s=0; s<3; s++){
            int N=sizes[s];
            printf("\nMatrix Size: %d X %d \n",N,N);
            static double A[MAX_SIZE][MAX_SIZE];    //static move A to static memory which hold much large data
             //useful for large array that not fit on stack memory
             initialized_Matrix(A,N);
             static1(A,N);
             dynamic(A,N);
       
    }
}
 

    return 0;
}