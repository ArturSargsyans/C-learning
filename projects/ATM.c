#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int display_menu(void);
void check_balance(int *);
void deposit(int *, int [], int *);
void withdraw(int *, int[], int *);
void show_history(int [], int);

int main(void)
{
    int *p_to_balance;
    int balance = 1000;
    p_to_balance=&balance;
    int *p_to_counter;
    int counter = 0;
    p_to_counter = &counter;
    int history[SIZE] = {0};

    while(1)
    {
        int option = display_menu();
        switch(option){
            case 1:
                check_balance(p_to_balance);
                break;
            case 2:
                deposit(p_to_balance, history, p_to_counter);
                break;
            case 3:
                withdraw(p_to_balance, history, p_to_counter);
                break;
            case 4:
                show_history(history, counter);
                break;
            case 5:
                printf("\n EXITING THE PROGRAM...");
                exit(0);
            default:
                printf("\n please enter a valid option\n");
                break;
        }
    }
    return 0;
}

int display_menu(void)
{
    int option;
    printf("\n====== ATM SYSTEM =======\n\n1.Check Balance\n2.Deposit\n3.Withdraw\n4.Transaction history\n5.Exit\n\n Choose an option\t");
    scanf("%d", &option);
    return option;
}

void check_balance(int *p_to_balance)
{
    printf("\nChecking the balance ...");
    printf("\nThe current balance is %d$\n", *p_to_balance);
}

void deposit(int *p_to_balance, int history[], int *p_to_counter)
{
    if(*p_to_counter >= SIZE)
    {
        printf("\n!!You have reached the maximum amount of transactions for today, unable to deposit!!\n");
    }
    else
    {
        int dep;
        printf("Enter the deposit amount (a positive integer): \t");
        scanf("%d", &dep);
        if(dep>0)
        {
            *p_to_balance+=dep;
            printf("\nDeposite successful\n New balance is %d\n", *p_to_balance);
            history[*p_to_counter] = dep;
            *p_to_counter+=1;
            printf("%d allowed transactions left\n\n", SIZE-*p_to_counter);
        }
        else
            printf("\n!!Invalid input!!\n");

    }
        
}

void withdraw(int *p_to_balance, int history[], int *p_to_counter)
{
    if(*p_to_counter >= SIZE)
    {
        printf("\n!!You have reached the maximum amount of transactions for today, unable to withdraw!!\n");
    }
    else
    {
        int wdraw;
        printf("Enter the withdrawal amount (a positive integer): \t");
        scanf("%d", &wdraw);
        if(wdraw>0)
        {
            if(*p_to_balance >= wdraw)
            {
                *p_to_balance-=wdraw;
                printf("\nWithdrawal successful\n New balance is %d\n", *p_to_balance);
                history[*p_to_counter] = 0-wdraw;
                *p_to_counter+=1;
                printf("%d allowed transactions left\n\n", SIZE-*p_to_counter);
            }
            else
                printf("\nInsuficient Funds!\n");
        }
        else
            printf("\n!!Invalid input!!\n");
    }
   
 
}

void show_history(int history [], int size)
{
    if(size == 0)
    {
        printf("\nNo transactions so far\n");
    }
    else
    {
        printf("\n\nYour transaction history:\n");
        int i;
        for(i=0;i<size;i++)
        {
            if(history[i]>0)
                printf("%d. +%d$\n", i+1, history[i]);
            else 
                printf("%d. %d$\n", i+1, history[i]);
                
        }
        printf("\n");
    }
    
}