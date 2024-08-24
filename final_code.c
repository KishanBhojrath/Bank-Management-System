#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void accountcreated(void);  //declaring functions beforehand
void account(void);
void userdetails(void);
void display(char*);
void depositcheck(void);
void deposit();
void balancecheck(void);
void check(char*);
void menu(void){              //function of main menu interface
    system("cls");
    int option;
    printf("Welcome to Bank Management System");
    printf("\n""Select an option");
     printf("\n""1---Create an account");
     printf("\n""2---Show details of user");
     printf("\n""3---Deposit money");
     printf("\n""4---Check balance");
     printf("\n""Enter your selection:");
     
     scanf("%d",&option);

     switch(option){        // switch case for selecting the option
     case 1:
     account();
     case 2:
     userdetails();
     case 3:
     deposit();
     case 4:
     balancecheck();
     
     }
}
struct details{        //structure to store personal details of user
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
struct money{        //structure for money records
char username[25];
int money;

};


void account(void){      //function to create a new account and store info in file
char password[25];
char pass;
FILE *user;
struct details p1;       //assignment operator p1
user=fopen("database.txt","ab");
 printf("\n""Create your account");
  printf("\n""Enter your Details");
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
    printf("\n Enter your login username:");
    scanf("%s",&p1.username);
    printf("\n Enter you password:");
    for(int i=0;i<25;i++){     // code to get passsword and show "*" on screen
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



    fwrite(&p1,sizeof(p1),1,user);   //writing to binary file
    fclose(user);                    //closing the file 

    accountcreated();        
    

}


void accountcreated(void){    //confirming the account creation
    printf("\n Account created!!,Thank you for joining us!\n" );
    printf("\n \n Press enter to return to menu");
    getch();
    menu();
    
    
}

void userdetails(void){  // function to display user details from file
    system("cls");
    char username[15];
    FILE *user;
    struct details p1;
    user=fopen("database.txt","rb");
    printf(" \n Enter username to get details:");
    scanf("%s",&username);
    while (fread(&p1, sizeof(p1),1, user)) 
    {
		if (strcmp(username,p1.username)== 0)   //checking if username is present
        {

			display(username);        // calling display if  username found
		}
        
	}

    printf("\n Username not found in records");    
    
    fclose(user);
    printf(" \n \t \tPress Enter to return to menu");
            getch();
            menu();

}
void display(char user_name[])    //function to display details 
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
	    printf("**User details:**\n Name:%s %s",p1.firstname, p1.lastname);   //printing info on the screen
            printf("\n Date of birth:%d-%d-%d",p1.date,p1.month,p1.year);
            printf("\n Father's Name:%s",p1.father_name);
            printf("\n Mother's Name:%s",p1.mother_name);
            printf("\n Linked Aadhar number:%s",p1.Aadhar);
            printf("\n Contact number:%s",p1.phno);
            
        }
        
    }
    fclose(user);
    printf("\n Press Enter to return to menu");
    getch();
    menu();

    

}
void deposit(void)       //function to deposit amount
{
	
	FILE *user, *mn;
	struct details p1;
	struct money m1;
	char usernamet[20];
	char usernamep[20];
	system("cls");
        int flag=0; // initializing flag with 0

	user = fopen("database.txt", "rb");
	mn = fopen("mon.txt", "ab");

	
	printf("**Money Deposit** \n Enter the username for deposit \n USERNAME:");
	scanf("%s", &usernamep);

	
	while (fread(&p1, sizeof(p1),1, user))
	{
		if (strcmp(usernamep,p1.username)== 0) 
        {
		    strcpy(m1.username,p1.username);
            flag++;                                     // incrementing flag if username found
		}
        
	}
    if(flag==0){                                    //not found flag=0
        printf("\n Username not found in records");
        printf("\n Press Enter to return to menu");
        getch();
        menu();
    }
    else{                                      //found

	
	printf("Enter the amount to be deposited:");
	scanf("%d", &m1.money);               //taking input directly to strucutre

	fwrite(&m1, sizeof(m1),1, mn);       //writing to file

	printf("\n Amount Deposited Successfully!!!");
	
	fclose(user);
	fclose(mn);
    }

    printf("\n Press enter to return to menu....");
    getch();
	menu();
}




void balancecheck(void){      //function to show balance
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
        if(strcmp(usern,p1.username)==0)     //checking if username present in file
            {
                check(usern);
            }
            
    }
    fclose(user); 
}
void check(char name[])   //function to display the deposit history and total balance
{
	
	FILE* fm;
	struct money m1;
	int amount = 0;     // initialising amount with 0

	
	fm = fopen("mon.txt", "rb");

	printf("\n Deposit History:");
	while (fread(&m1, sizeof(m1),1, fm)) {
		if (strcmp(name,m1.username)== 0) {
            
			printf("\n%d",m1.money);     //printing past deposits
			
			amount = amount + m1.money;   // adding all deposits in amount
		}
	}
	printf("\n Currert Balance:");
	printf("%d", amount);     //priting final added amount
	fclose(fm);
	printf("\n Press enter to return to menu....");
    getch();
    menu();

}


int main(){
    menu();
    
    return 0;
}
