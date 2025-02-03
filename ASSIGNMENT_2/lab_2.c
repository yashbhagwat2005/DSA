#include <stdio.h>
#include <stdlib.h>
struct number{
    int *n_1;
    int *n_2;
}; // the structure hold two integer pointers 
void array_multiplication(int *n_2,int n){
    for (int i = 0;i<n;i++){
        if(i%2!=0 && i!=(n-1)){
            *(n_2 + i) = (*(n_2 + i + 1)) * (*(n_2 + i - 1));
        }
    }
};// replace  the  odd  positioned elements by the  product of its adjacent elements.
int main(){
    int n;
    printf("Enter the number of numbers you want to enter in the array: ");
    scanf("%d",&n); // input from the user to enter the number of numbers in the array
    int array[n];// initializing the array and 2nd array with n elements
    int copy_array[n];
    for (int i =0;i<n;i++){
        printf("Enter a number: ");
        scanf("%d",&array[i]);
        copy_array[i] = array[i];// copy the elements of the array to another array
    }
    struct number pointer;
    pointer.n_1 = array; // assigning address of the array and copied array to the pointer 
    pointer.n_2 = copy_array;
    array_multiplication( pointer.n_2,n);// calling the function 
    printf("The copied array's updated list \n");
    for (int i = 0;i<n;i++){
        printf(" %d ",*(pointer.n_2+i));
    }   
}

