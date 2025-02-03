#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct bankmanagment {
    int accnumber;
    char custname[50];
    float avlbalance;
    char acctype;
};
void withdrawl(struct bankmanagment*b1,int acc_num,int count){
    float withdrawal_amount;
    int found;
    for (int i = 0;i<count;i++){
        if (b1[i].accnumber==acc_num){
            found = 1;
            printf("\nEnter the withdrawal amount: ");
            scanf("%f",&withdrawal_amount);
            if (withdrawal_amount>b1[i].avlbalance){
                printf("Insufficent balance");
            }
            else{
                b1[i].avlbalance = b1[i].avlbalance - withdrawal_amount;
                printf("The new balance is: ",b1[i].avlbalance);
            }
            break;
        }

    }
    if (!found){
        printf("The give account number does not exist");
    }
}

void deposit(struct bankmanagment*b1,int acc_num,int count){
    float deposit;
    int found;
    for (int i = 0;i<count;i++){
        if (b1[i].accnumber==acc_num){
            found = 1;
            printf("\nEnter the deposit amount: ");
            scanf("%f",&deposit);
            b1[i].avlbalance = b1[i].avlbalance + deposit;
            printf("The updated balance is: ",b1[i].avlbalance);
            }
            break;
        }
    if (!found){
        printf("The give account number does not exist");
    }
}

void display(struct bankmanagment*b1,int acc_num,int count){
    int found;
    for (int i = 0;i<count;i++){
        if (b1[i].accnumber==acc_num){
            found = 1;
            printf("Available balance of the customer with customer id %d is %f",b1[i].accnumber,b1[i].avlbalance);
            }
            break;
        }
    if (!found){
        printf("The give account number does not exist");
    }
    
}

int main(){
    int count = 0;
    char choice;
    printf("Do you want to enter records in the bank(y/n): ");
    scanf("%c",&choice);
    struct bankmanagment *b1 = (struct bankmanagment*)malloc(sizeof(struct bankmanagment));
    if (choice =='Y' || choice =='y'){
        if (b1==NULL){
            printf("Memory is not available");
            free(b1);
        }
    }
    else if (choice =='N' || choice =='n'){
        printf("hell nah");
        return 0;
    }
    else{
        printf("Enter the corrrect option");
        return 1;
    }
    while (choice == 'Y' || choice == 'y') {
        b1 = (struct bankmanagment *)realloc(b1, (count + 1) * sizeof(struct bankmanagment));
        if (b1 == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("\nEnter the details of customer %d\n", count + 1);

        printf("Enter the account number: ");
        scanf("%d", &b1[count].accnumber);

        printf("Enter the customer name: ");
        getchar();
        fgets(b1[count].custname, sizeof(b1[count].custname), stdin);
        b1[count].custname[strcspn(b1[count].custname, "\n")] = '\0'; 
        printf("Enter the available balance: ");
        scanf("%f", &b1[count].avlbalance);
        printf("Enter the account type (S for Savings, C for Current): ");
        getchar();
        scanf("%c", &b1[count].acctype);

        count++;

        printf("Do you want to enter another record (y/n): ");
        getchar(); 
        scanf("%c", &choice);

        if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
            printf("Invalid choice. Exiting.\n");
            return 1;
        }
    }


    if (choice == 'N' || choice == 'n') {
        printf("\nExiting and saving records.\n");
    }
    int option;
    int account_number;
    printf("Enter the account number: ");
    scanf("%d",&account_number);
    printf("\nMenu option \n");
    printf("1. Withdrawal\n");
    printf("2. Deposit\n");
    printf("3. Display Balance\n");
    printf("4. Exit\n");
    printf("Choose your option number: ");
    scanf("%d",&option);
    if (option==1){
        withdrawl(b1,account_number,count);
    }
    else if (option==2){
        deposit(b1,account_number,count);
    }
    else if (option==3){
        display(b1,account_number,count);
    }
    else if (option==4){
        return 0;
    }
    else {
        printf("Enter the correct option number");
        return 1;
    }

}
