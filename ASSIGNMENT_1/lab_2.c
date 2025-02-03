#include <stdio.h>
int main(){

        int n; //number of elements in the list
        int inversion_occurence = 0;//initially inversion_occurence is zero
        printf("Enter the number of numbers you want to enter: ");
            scanf("%d", &n);//input from the user for n

        int array_1[n];//
        for (int i = 0; i < n; i++) {
            printf("Enter a number: ");
            scanf("%d", &array_1[i]); //enter the numbers for the array
        }
        for (int i = 0; i < n; i++){
            for (int j = i+1;j<n;j++){
                    if (array_1[i]>array_1[j]){ // it just checks if the element i is bigger than element j as the loop ensures the number i is bigger than number j
                        inversion_occurence+=1;
                    }
                }
                
            }

        printf("Inversion occurence: %d",inversion_occurence);

}