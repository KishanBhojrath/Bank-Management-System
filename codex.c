#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void accountcreated(void);
void account(void);
void userdetails(void);
void display(char*);
void depositcheck(void);
void deposit();
void balancecheck(void);
void check(char*);
void withdraw(void);
void menu(void){
    system("cls");
    int option;
    printf("Welcome to Bank Management System");
    printf("\n""Select an option");
     printf("\n""1---Create an account");
     printf("\n""2---Show details of user");
     printf("\n""3---Deposit money");
     printf("\n""4---Withdraw money");
     printf("\n""5---Check balance");
     printf("\n""Enter your selection:");
    
     
     scanf("%d",&option);

     switch(option){
     case 1:
     account();
     case 2:
     userdetails();
     case 3:
     deposit();
     case 4:
     withdraw();
     case 5:
     balancecheck();
     
     }
}
struct details{
    char firstname[25];
    char lastname[25];
    int date;
    int month;
    int year;
    char father_name[25];
    char mother_name[25];
    char Aadhar[25];
    char address[50];
    char phno[15];
    char username[15];
    
};
struct money{
char username[25];
signed int money;

};


void account(void){
system("cls");
char password[25];
char username[15];
char pass;
FILE *user;
struct details p1;
user=fopen("database.txt","ab+");
 printf("\n""Create your account");
  printf("\n""Enter your Details");
   printf("\n Enter your login username:");
    scanf("%s",&username);
     while (fread(&p1, sizeof(p1),1, user)) 
    {
        
		if (strcmp(username,p1.username)== 0) 
        {
			printf("\n Sorry! This username already exists!!");
            printf("Try another username!!");
            printf("\n Press enter to try again!!");
            getch();
            account();

		}
        
	}
     printf("\n **Confirm the username again**");
      printf("\n **Remember you username**");
       printf("\n Enter Username:");
    scanf("%s",&p1.username);
    printf("\n Enter you password:");
    for(int i=0;i<25;i++){
        pass=getch();
        if(pass!=13){
            password[i]=pass;
            pass='*';
            printf("%c",pass);
        }
        else{
            break;
        }
    }
   printf("\n""First Name:");
   scanf("%s",&p1.firstname);
    printf("\n""Last name:");
    scanf("%s",&p1.lastname);
    printf("\n""Enter your Date of Birth \n Date:");
    scanf("%d",&p1.date);
    printf("\n""Month:");
    scanf("%d",&p1.month);
    printf("\n Year:");
    scanf("%d",&p1.year);
    printf("\n Father's name:");
    scanf("%s",&p1.father_name);
    printf("\n Mother's name:");
    scanf("%s",&p1.mother_name);
    printf("\n Enter Aadhar card no:");
    scanf("%s",&p1.Aadhar);
    printf("\n Enter you Residential Address:");
    scanf("%s",&p1.address);
    printf("\n Enter your phone number:");
    scanf("%s",&p1.phno);
    


    fwrite(&p1,sizeof(p1),1,user);
    fclose(user);

    accountcreated();
    

}


void accountcreated(void){
    printf("\n Account created!!,Thank you for joining us!\n" );
    printf("\n \n Press enter to return to menu");
    getch();
    menu();
    
    
}

void userdetails(void){  
    system("cls");
    char username[15];
    FILE *user;
    struct details p1;
    user=fopen("database.txt","rb");
    printf(" \n Enter username to get details:");
    scanf("%s",&username);
    while (fread(&p1, sizeof(p1),1, user)) 
    {
		if (strcmp(username,p1.username)== 0) 
        {
			display(username);
		}
        
	}

    printf("\n Username not found in records");    
    
    fclose(user);
    printf(" \n \t \tPress Enter to return to menu");
            getch();
            menu();

}
void display(char user_name[])
{
	system("cls");
	FILE* user;
    
	user = fopen("database.txt", "rb");
	struct details p1;
    
	if (user == NULL) {
		printf("Cant access database");
	}

	while (fread(&p1, sizeof(p1),1,user)) 
    {
		if (strcmp(user_name,p1.username)== 0) 
        {
			printf("**User details:**\n Name:%s %s",p1.firstname, p1.lastname);
            printf("\n Date of birth:%d-%d-%d",p1.date,p1.month,p1.year);
            printf("\n Father's Name:%s",p1.father_name);
            printf("\n Mother's Name:%s",p1.mother_name);
            printf("\n Linked Aadhar number:%s",p1.Aadhar);
            printf("\n Contact number:%s",p1.phno);
            printf("\n");
            
        }
        
    }
    fclose(user);
    printf("\n Press Enter to return to menu");
    getch();
    menu();

    

}
void deposit(void)
{
	
	FILE *user, *mn;
	struct details p1;
	struct money m1;
	char usernamet[20];
	char usernamep[20];
	system("cls");
    int flag=0;

	user = fopen("database.txt", "rb");
	mn = fopen("mon.txt", "ab");

	
	printf("**Money Deposit** \n Enter the username for deposit \n USERNAME:");
	scanf("%s", &usernamep);

	
	while (fread(&p1, sizeof(p1),1, user))
	{
		if (strcmp(usernamep,p1.username)== 0) 
        {
		    strcpy(m1.username,p1.username);
            flag++;
		}
        
	}
    if(flag==0){
        printf("\n Username not found in records");
        printf("\n Press Enter to return to menu");
        getch();
        menu();
    }
    else{

	
	printf("Enter the amount to be deposited:");
	scanf("%d", &m1.money);

	fwrite(&m1, sizeof(m1),1, mn);

	printf("\n Amount Deposited Successfully!!!");
	
	fclose(user);
	fclose(mn);
    }

    printf("\n Press enter to return to menu....");
    getch();
	menu();
}




void balancecheck(void){
    FILE *user;
    struct details p1;
    char usern[25];
    user=fopen("database.txt","rb");
    system("cls");
    printf("\n *****Balance Check*****");
    printf(" \n Enter username to Check Balance");
    printf("\n USERNAME:");
    scanf("%s",&usern);
    while(fread(&p1,sizeof(p1),1,user))
    {
        if(strcmp(usern,p1.username)==0)
            {
                check(usern);
            }
            
    }
    fclose(user); 
}
void check(char name[])
{
	
	FILE* fm;
	struct money m1;
	int amount = 0;

	
	fm = fopen("mon.txt", "rb");

	printf("\n Deposit History:");
	while (fread(&m1, sizeof(m1),1, fm)) {
		if (strcmp(name,m1.username)== 0) {
			
			
            
            printf("\n%d",m1.money);
			
			amount = amount + m1.money;
		}
	}
	printf("\n Currert Balance:");
	printf("%d", amount);
	fclose(fm);
	printf("\n Press enter to return to menu....");
    getch();
    menu();

}
void withdraw(void)
{
	
	FILE *user, *mn;
	struct details p1;
	struct money m1;
	char usernamet[20];
	char usernamep[20];
	system("cls");
    int flag=0;
    int temp;
    int temp2;

	user = fopen("database.txt", "rb");
	mn = fopen("mon.txt", "ab");

	
	printf("**Money Withdraw** \n Enter the username for Withdraw \n USERNAME:");
	scanf("%s", &usernamep);

	
	while (fread(&p1, sizeof(p1),1, user))
	{
		if (strcmp(usernamep,p1.username)== 0) 
        {
            strcpy(m1.username,p1.username);
            flag++;
		}
        
	}
    if(flag==0){
        printf("\n Username not found in records");
        printf("\n Press Enter to return to menu");
        getch();
        menu();
    }
    else{

	m1.money=0;
    
	printf("Enter the amount to withdraw:");
	scanf("%d", &temp);
    m1.money=-abs(temp);
	fwrite(&m1, sizeof(m1),1, mn);

	printf("\n Amount withdraw Successfully!!!");
    printf("\n Amount of %d has been withdrawn for account with username **%s**",temp,m1.username);
	
	fclose(user);
	fclose(mn);
    }

    printf("\n Press enter to return to menu....");
    getch();
	menu();
}






int main(){
    menu();
    
    return 0;
}