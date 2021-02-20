//Developed By Tushar S Agrawal, Devarsh RiteshKumar Shah AND Rishav Raj

//Last Updated: 01:13   14-05-2020 by tushar



/*how to Save in Complete_Student.txt file-
      Registration Number
      Student's Name
      Student's Gender
      Student's BirthDate(DD/MM/YYYY)
      Student's Age
      Student's City
      Studet's State
      Student's PhoneNumber
      Student's E-Mail
      Student's School
      student's Field
      Block
      Room Number
      Father's Name
      Father's Phone Number
 */


//including header files


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
void new_data();
void menu();
void view_block();
void give_percent();
void delete_acc();
void closer();
void check_details();
int room_allotment(int a);
int checkdate(int date,int month, int year);
void arrow(int rlptn, int arptn);
int emailcheck(char c[]);
int naive(char reg[], char match[]);
int main_exit;
int Approxdist(char x[30], char y[30]);
void update_data();
int minimum(int num[]);


//defining structures
struct student_details {
        char regno[9];
        char name[30];
        int age;
        char gender[10];
        int date,month,year;
        char phone[11];
        char mail_id[30];
        char city[20];
        char state[20];
        char block;
        char school[10];
        char branch[4];
        int room;
        char fname[30];
        char fphone[11];
} naya,upd,check,rem,sort;
//defining Global Variable For Arrow Menu
int position=0,choice=0;

//Main Function
int main()
{
        menu();
        return 0;
}

//Arrow
void arrow(int rlptn, int arptn)
{
        if(rlptn==arptn)
                printf("\t\t\t       ----->>  ");
        else
                printf("\t\t\t           ");
}

//Programme to Display Menu
void menu()
{
        choice=0,position=1;
        while(choice != 13) {
                system("cls");
                printf("\n\n\t\t\t      HOSTEL MANAGEMENT SYSTEM");
                printf("\n\n\n\t\t\t    WELCOME TO THE MAIN MENU\n\n");
                printf("\n\n\t\t\tSelect an Option:\n\n\n");
                arrow(1,position); printf("Enter new Student's data \n\n");
                arrow(2,position); printf("Update information of existing account \n\n");
                arrow(3,position); printf("Check the details of existing account \n\n");
                arrow(4,position); printf("View all Students of a particlar Hostel \n\n");
                arrow(5,position); printf("Removing existing account \n\n");
                arrow(6,position); printf("Check For Percentage \n\n");
                //  arrow(6,position); printf("View all students list \n\n");
                arrow(7,position); printf("Exit \n\n");
                        //        arrow(8,position); printf("Checker \n\n");
                //  printf("\n\n\n\n\n\t\t Enter your choice:");
                choice=getch();
                if ((choice==80) && (position!=7))
                        position++;
                else if ((choice ==72)&&(position!=1))
                        position--;
        }

        switch(position)
        {

        case 1: new_data();
                //      printf("\nSelected First\n");
                break;
        case 2:
              //  printf("\nSelected 2nd\n");
                update_data();
                break;
        case 3: check_details();
                //printf("\nSelected 3rd\n");
                break;
        case 4: view_block();
                //  printf("\nSelected 4th\n");
                break;
        case 5: delete_acc();
                break;
            case 6:
                   give_percent();
                   break;
        case 7: closer();
                break;
        // case 8:
        //       printf("%d",room_allotment(1));
        //       break;

        default:
                menu();
        }
}

void new_data()
{         system("cls");
        int choice;
        FILE *recfile, *block;

        recfile=fopen("Hostel_Management.dat","a+");


        printf("\t\t\t    ADD STUDENT'S DATA \n\n");
        check_reg:
        printf("\n Enter Student's Registration Number :");
        scanf("%s",check.regno);
        if (strlen(check.regno)!=8)
        {printf(" Invalid Registration Number!!!\nTry Again\n\n\n");
         goto check_reg;}


           if (naive("BME",check.regno)==0)
           {
             strcpy(check.school,"SMEC");
             strcpy(check.branch,"BME");
           }
            else if(naive("BCE",check.regno)==0)
               {
                 strcpy(check.school,"SCOPE");
               strcpy(check.branch,"BCE"); }

               else if(naive("BIT",check.regno)==0){

               strcpy(check.school,"SCOPE");
               strcpy(check.branch,"BIT");
               }
              else if(naive("BDS",check.regno)==0)
               {
                 strcpy(check.school,"SCOPE");
               strcpy(check.branch,"BDS"); }

            else if (naive("BEE",check.regno)==0)
           {
             strcpy(check.school,"SELECT");
           strcpy(check.branch,"BEE");  }
           else
           {
             printf("Entered Branch Does NOT Exists!!! \n\nTry Again\n\n");
             goto check_reg;
           }

        while(fscanf(recfile,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",naya.regno, naya.name, naya.gender, &naya.date, &naya.month, &naya.year, &naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, &naya.block, &naya.room, naya.fname, naya.fphone)!=EOF)
        {
                if (naive(check.regno,naya.regno)==0)
                { fseek(recfile,0,SEEK_SET);
                  printf("Student Already Exists\nOR \nIncorrect Registration Number Entered\n");
                  goto check_reg;}
        }
        strcpy(naya.regno,check.regno);
        printf("\n Enter the Name :");
        scanf(" %[^\n]",naya.name);
        printf("\n Enter Student's Gender :");
        scanf("%s",naya.gender);
check_date:
        printf("\n Enter student's Date of Birth(DD/MM/YYYY) :");
        scanf("%d/%d/%d",&naya.date,&naya.month,&naya.year);
        if (checkdate(naya.date,naya.month,naya.year)==0)
        {
                printf("Invalid Date of Birth Entered\n\nTry Again!!\n\n");
                goto check_date;
        }
        printf("\n Enter the Age :");
        scanf("%d",&naya.age);
        printf("\n Enter the City :");
        scanf(" %[^\n]",naya.city);
        printf("\n Enter the State :");
        scanf(" %[^\n]",naya.state);
naya_phone:
        printf("\n Enter Student's Phone Number :");
        scanf("%s",naya.phone);
        if(strlen(naya.phone)!=10)
        {
                printf("\nInvalid phone number!!!\nTry Again\n\n\n ");
                goto naya_phone;
        }
naya_mail:
        printf("\n Enter Student's E-Mail ID :");
        scanf("%s",naya.mail_id);
        if(emailcheck(naya.mail_id)!=1)
          {printf("Invalid Email!! Please Try Again\n\n\n");
        goto naya_mail;}
        printf("\n Enter Student's Father's Name :");
        scanf(" %[^\n]",naya.fname);
naya_fphone:
        printf("\n Enter Student's Father's Phone Number :");
        scanf("%s",naya.fphone);
        if(strlen(naya.fphone)!=10)
        {
                printf("\nInvalid phone number!!!\nTry Again\n\n\n ");
                goto naya_fphone;
        }

        if((strcmp(naya.gender,"Female")==0)||(strcmp(naya.gender,"female")==0))
        { strcpy(naya.gender,"Female");
          printf("\n Student Will be Allotted GIRLS Hostel-A\n");
         naya.block='A';
         block=fopen("A-Block.dat","a+");
         naya.room=room_allotment(4);
         if (naya.room==0)
            {printf("Rooms Full\n\n");
            menu();}
         fprintf(block,"%s\n%s\n%d\n", naya.regno, naya.name, naya.room);
         fclose(block);  }
        else
        {    naya_block:
            strcpy(naya.gender,"Male");
                choice=0,position=1;
                while(choice != 13) {
                        system("cls");
                        printf("\n\n\t\t\tChoose the BOYS Hostel to be allotted :\n\n");
                        arrow(1,position); printf("M-Block \n\n");
                        arrow(2,position); printf("N-Block \n\n");
                        arrow(3,position); printf("P-Block \n\n");
                        choice=getch();
                        if ((choice==80) && (position!=3))
                                position++;
                        else if ((choice ==72)&&(position!=1))
                                position--;
                }
                switch(position)
                {
                case 1:
                        naya.block='M';
                        block=fopen("M-Block.dat","a+");
                        naya.room=room_allotment(1);
                        if (naya.room==0)
                           {printf("Rooms Full\n\n");
                                    goto naya_block;}
                        fprintf(block,"%s\n%s\n%d\n", naya.regno, naya.name, naya.room);
                        break;
                case 2:
                        naya.block='N';
                        block=fopen("N-Block.dat","a+");
                        naya.room=room_allotment(2);
                        if (naya.room==0)
                           {printf("Rooms Full\n\n");
                         goto naya_block;}
                        fprintf(block,"%s\n%s\n%d\n", naya.regno, naya.name, naya.room);
                        break;
                case 3:
                        naya.block='P';
                        block=fopen("P-Block.dat","a+");
                        naya.room=room_allotment(3);
                        if (naya.room==0)
                           {printf("Rooms Full\n\n");goto naya_block;}
                        fprintf(block,"%s\n%s\n%d\n", naya.regno, naya.name, naya.room);
                        break;
                }
                fclose(block);
        }
        strcpy(naya.branch,check.branch);
        strcpy(naya.school,check.school);
        fprintf(recfile,"%s\n%s\n%s\n%d/%d/%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%c\n%d\n%s\n%s\n",naya.regno, naya.name, naya.gender, naya.date, naya.month, naya.year, naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, naya.block, naya.room, naya.fname, naya.fphone);
        fclose(recfile);
        printf("\n\t\t Student Added successfully!!\n\n");
sort_list_invalid:
        printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        main_exit=getch();
        if (main_exit==49)
                menu();
        else if(main_exit==48)
                closer();
        else
        {    printf("\nInvalid!\a");
             goto sort_list_invalid;}


}

void check_details()
{
        //Check Based on Registration Number
        FILE *recfile;
        int flag=0;
        char reg[9];
        char name[30];
        recfile=fopen("Hostel_Management.dat","r");
        choice=0,position=1;
        while(choice != 13) {
                system("cls");
                printf("\n\n\t\t\tDo you want to Check By :\n\n");
                arrow(1,position); printf("Registration Number \n\n");
                arrow(2,position); printf("Name \n\n");
                choice=getch();
                if ((choice==80) && (position!=2))
                        position++;
                else if ((choice ==72)&&(position!=1))
                        position--;
        }        switch(position) {
        case 1:
check_dreg:
                printf("\n Enter the Registration Number :");
                scanf("%s",reg);
                if (strlen(reg)!=8)
                {printf(" Invalid Registration Number!! Try Again!!");
                 goto check_dreg;}
                while(fscanf(recfile,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",check.regno, check.name, check.gender, &check.date, &check.month, &check.year, &check.age, check.city, check.state, check.phone, check.mail_id, check.school, check.branch, &check.block, &check.room, check.fname, check.fphone)!=EOF)
                {if (naive(reg,check.regno)==0)
                 {   printf("\n\tRegistration No.\tNAME\tBlock\tROOM NO.\n");
                     printf("\n\t%s\t%s\t%c\t %d", check.regno, check.name, check.block, check.room);
                     flag=1;
                     break;}}
                break;
        case 2:

                printf("\n Enter the Name Of the Student :");
                scanf(" %[^\n]",name);
                int count=0;
                while(fscanf(recfile,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",check.regno, check.name, check.gender, &check.date, &check.month, &check.year, &check.age, check.city, check.state, check.phone, check.mail_id, check.school, check.branch, &check.block, &check.room, check.fname, check.fphone)!=EOF)
                {if (Approxdist(name,check.name)<5)
                 { flag=1;
                   if(count==0)
                   { printf("\t\tFollowing is the list of Students:");
                     printf("\n\tRegistration No.\t\tNAME\t\tBlock\t\tRoom No.\n");}
                   printf("\n\t%s\t\t%s\t\t %c\t\t %d", check.regno, check.name, check.block, check.room);
                   count++;}}
                fclose(recfile);
                break;
        }
        if (flag==0)
        {
                printf("\n No Student Found");
        }
        printf("\n Enter 0 to Try Again,1 to Return to Main Menu and 2 to Exit:");
            do {
              main_exit=getch();
            }while (main_exit<=47||main_exit>50);
            if (main_exit==49)
    			menu();
            else if (main_exit==50)
                closer();
             else if(main_exit==48)
             check_details();

}
/////////////////////////PAste After this
void view_block()
{
        choice=0; position=1;
        while(choice!=13) {
                system("CLS");
                printf("\t\t\tEnter year choice:\n\n\n");
                arrow(1,position); printf(" M-Block\n\n");
                arrow(2,position); printf(" N-Block\n\n");
                arrow(3,position); printf(" P-Block\n\n");
                arrow(4,position); printf(" A-Block\n\n");
                choice=getch();
                if ((choice==80) && (position!=4))
                        position++;
                else if ((choice ==72)&&(position!=1))
                        position--;
        }
        FILE *block;
        int test=0;
        switch(position)
        {
        case 1: block=fopen("M-Block.dat","a+"); break;
        case 2: block=fopen("N-Block.dat","a+"); break;
        case 3: block=fopen("P-Block.dat","a+"); break;
        case 4: block=fopen("A-Block.dat","a+"); break;
        default: view_block();
        }

        while(fscanf(block,"%s\n%[^\n]\n%d\n",sort.regno, sort.name, &sort.room)!=EOF)
        {       if(test==0)
                {
                        printf("\t\tFollowing is the list of requested students:");
                        printf("\n\tROLL NO.\t\t\tNAME\t\t\tROOM NO.\n");
                }
                printf("\n\t%s\t %15s\t\t\t %d", sort.regno, sort.name, sort.room);
                test++;        }
        fclose(block);
        if (test==0)
                printf("\nNO RECORDS!!\n");
                printf("\nEnter 0 to Try Again,1 to Return to Main Menu and 2 to Exit:");
                    do {
                      main_exit=getch();
                    }while (main_exit<=47||main_exit>50);
                    if (main_exit==49)
            			menu();
                    else if (main_exit==50)
                        closer();
                     else if(main_exit==48)
                     view_block();
}

int checkdate(int date,int month, int year)
{
        if(date > 31|| date < 1)
        {
                printf("Checking 31\n");
                return 0;
        }
        int is_leap=0;

        if (year >= 1800 && year <= 2020)
        {       if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                        is_leap = 1;
                if(month >= 1 && month <= 12)
                {      // printf("Month Checkedn\n");
                        if (month == 2)
                        {      // printf("Checking Feb\n");
                                if ((is_leap==1 && date == 29)||date<=28)
                                        return 1;
                                else if (date > 28)
                                        return 0; }
                        // check for dates in April, June, September and November
                        else if (month == 4 || month == 6 || month == 9 || month == 11)
                        {      // printf("Checking 4,6,9,11\n");
                                if (date > 30)
                                        return 0;

                                else
                                        return 1; }
                        // For January, March, May, July, August, October and December
                        else
                                return 1; }
                else
                        return 0; }
}

int room_allotment(int a)
{int bed=0,rom=0;
  FILE *block;
  switch(a)
  {
    case 1:
    block=fopen("M-Block.dat","a+");
    rom=30;
    bed=4;
    break;
    case 2:
    rom=20;
    bed=2;
    block=fopen("N-Block.dat","a+");
    break;
    case 3:
    rom=22;
    bed=6;
    block=fopen("P-Block.dat","a+");
    break;
    case 4:
    rom=25;
    bed=4;
    block=fopen("A-Block.dat","a+");
    break;
  }
  char room[rom][bed][9];
  int i=0,j=0;
  while(fscanf(block,"%s\n%[^\n]\n%d\n",sort.regno, sort.name, &sort.room)!=EOF&&i!=rom)
  {
    strcpy(room[i][j],sort.regno);
    // printf("%s",room[i][j]);
    j++;
    if (j==bed)
      {i++;
        j=0;}
  }
  if (i==rom)
  return 0;
    printf("You Have been alloted Room Number %d",i+1);
  if (j==0)
  {
   printf(" without any Current Roommate\n\n\n");
  }
  else
  {printf(" with Following Roommate(s)-\n");
  int k=0;
  for (k=0;k<j;k++)
    printf("%s\n \n",room[i][k]);
}

  fclose(block);
    return i+1;

  }





//function to remove a account
void delete_acc()
{
        system("CLS");
        FILE *recfile,*newrec;
        int test=0;
        recfile=fopen("Hostel_Management.dat","r");
        newrec=fopen("new.dat","w");
        printf("\nEnter the registration no. of student whose data you want to delete: ");
        scanf("%s",rem.regno);
        while(fscanf(recfile,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",naya.regno, naya.name, naya.gender, &naya.date, &naya.month, &naya.year, &naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, &naya.block, &naya.room, naya.fname, naya.fphone)!=EOF)
        {
                if(naive(naya.regno,rem.regno)!=0)
                        fprintf(newrec,"%s\n%s\n%s\n%d/%d/%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%c\n%d\n%s\n%s\n",naya.regno, naya.name, naya.gender, naya.date, naya.month, naya.year, naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, naya.block, naya.room, naya.fname, naya.fphone);

                else
                {       char b;
                        test++;
                        FILE *block,*blocknew;
                        switch(naya.block)
                        {
                        case 'A':
                                block=fopen("A-Block.dat","r");
                                break;
                        //strcpy(b,"A-Block.dat");
                        case 'M':
                                block=fopen("M-Block.dat","r");
                                break;
                        //strcpy(b,"M-Block.dat");
                        case 'N':
                                block=fopen("N-Block.dat","r");
                                break;
                        //    strcpy(b,"N-Block.dat");
                        case 'P':
                                block=fopen("P-Block.dat","r");
                                break;
                                //      strcpy(b,"P-Block.dat");
                        } blocknew=fopen("blocknew.dat","w");
                        while(fscanf(block,"%s\n%[^\n]\n%d\n",sort.regno, sort.name, &sort.room)!=EOF)
                        {
                                if (naive(sort.regno,rem.regno)!=0)
                                {
                                        fprintf(blocknew,"%s\n%s\n%d\n", sort.regno, sort.name, sort.room);
                                }

                        }


                        fclose(block);
                        fclose(blocknew);
                        switch(naya.block)
                        {
                        case 'A':

                                remove("A-Block.dat");
                                rename("blocknew.dat","A-Block.dat");
                                break;
                        //strcpy(b,"A-Block.dat");
                        case 'M':
                        printf("IN switch\n");
                                remove("M-Block.dat");
                                rename("blocknew.dat","M-Block.dat");
                                break;
                        //strcpy(b,"M-Block.dat");
                        case 'N':
                                remove("N-Block.dat");
                                rename("blocknew.dat","N-Block.dat");
                                break;
                        //    strcpy(b,"N-Block.dat");
                        case 'P':
                                remove("P-Block.dat");
                                rename("blocknew.dat","P-Block.dat");
                                break;
                                //      strcpy(b,"P-Block.dat");
                        }
                        //   remove(b);
                        //   rename("blocknew.dat",b);
                        printf("\nRecord deleted successfully!\n");
                }
        }
        fclose(recfile);
        fclose(newrec);
    //      if (remove("Hostel_Management.dat") == 0)
    //   printf("Deleted successfully");
   	// else
    //   printf("Unable to delete the file");
         remove("Hostel_Management.dat");
    //     if (!rename("new.dat","Hostel_Management.dat") )
    //  				 printf("Renamed successfully\n");
   	// else
    //   printf("Error\n");
       rename("new.dat","Hostel_Management.dat");
        if(test==0)
                printf("\nRecord not found!!\a\a\a");
                printf("\nEnter 0 to Try Again,1 to Return to Main Menu and 2 to Exit:");
                    do {
                      main_exit=getch();
                    }while (main_exit<=47||main_exit>50);
                    if (main_exit==49)
            			menu();
                    else if (main_exit==50)
                        closer();
                     else if(main_exit==48)
                       delete_acc();
                    }




int naive(char reg[], char match[])
{   //printf("Using naive Algorithm\n");
    int M = strlen(reg);
    int N = strlen(match);
	int i=0;
    for (i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (match[i + j] != reg[j])
                break;
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            return 0;
    }
    return 1;
}


//Levenstein Distance Calculator
int Approxdist(char x[30], char y[30])
{
        int c=(int)strlen(x);
        int r=(int)strlen(y);
        int scost=0;
        int dist = 0;
        int **distance=NULL;
        int **action=NULL;
        int d,i,j;

        distance=(int **)malloc((r+1)*sizeof(int *));
        action=(int **)malloc((r+1)*sizeof(int *));

        for( i=0; i <= r; i++)
        {       distance[i]=(int *)malloc((c+1)*sizeof(int));
                action[i]=(int *)malloc((c+1)*sizeof(int));
        }
        for( i=0; i<= r; i++)
            for(j=0; j <=c; j++)
                     distance[i][j]=0;

        for(i=0; i <=c; i++)
                distance[0][i]=i;
        for( j=0; j <=r; j++)
                distance[j][0]=j;
        for(j=1; j <= r; j++)
        {    for( i=1; i <= c; i++)
             {       if(x[i-1]==y[j-1])
                             scost = 0;
                     else
                             scost = 1;

                     int op;
                     distance[j][i];
                     if(distance[j-1][i]+1 < distance[j][i-1]+1)
                     {    if(distance[j-1][i-1]+scost < distance[j-1][i]+1) {
                                  distance[j][i] = distance[j-1][i-1]+scost;
                                  op=2;                          }
                          else{ distance[j][i] = distance[j-1][i]+1;
                                op=0; }}
                     else
                     {        if(distance[j-1][i-1]+scost < distance[j][i-1]+1) {
                                      distance[j][i] = distance[j-1][i-1]+scost;
                                      op=2;
                              }
                              else{
                                      distance[j][i] = distance[j][i-1]+1;
                                      op=1;
                              }        }

                     if(op==2 && scost==0)
                             op=3;
                     action[j][i]=op;             }}
        d=distance[r][c];
         j=r;
         i=c;
        do{
                if(action[j][i]==0) {
                        j--;
                        dist++;
                }
                else if(action[j][i]==1) {
                        i--;
                        dist++;
                }
                else if(action[j][i]==2) {
                        i--;
                        j--;
                        dist+=2;
                }
                else if(action[j][i]==3) {
                        i--;
                        j--;
                }
        }while(!(j==0 && i==0));
        for( i=0; i <= r; i++)
                free(distance[i]);
        free(distance);
        for( i=0; i <= r; i++)
                free(action[i]);
        free(action);
        return dist;
}








//preogram to check email
int emailcheck(char c[])
{int j,i,flag=0;
for(i=0;i<strlen(c);i++)
{if ((c[i]>='A' && c[i]<='Z')||(c[i]>='a' && c[i]<='z')||(c[i]>='0' && c[i]<='9'))
    continue;
  else if (c[i]=='@' && flag==0)
    {j=i;
  flag=1;
  break;}}
for(i=j;i<strlen(c);i++)
{if ((c[i]>='A' && c[i]<='Z')||(c[i]>='a' && c[i]<='z')||(c[i]>='0' && c[i]<='9'))
    continue;
  else if (c[i]=='.' && flag==1 && c[i+1]!='\0')
    return 1;}
return 0;
}






void update_data()
{

        FILE *recfile,*newrec;
        int choice,test=0;
         recfile=fopen("Hostel_Management.dat","r");
        newrec=fopen("new.dat","w");
        system("CLS");
updete_reg:
        printf("\nEnter the registration no. of student whose data you want to update: ");
        scanf("%s",rem.regno);
        if (strlen(rem.regno)!=8)
        {printf("Invalid Registration Number Entered!!! \n\n Try Again\n\n\n");
        goto updete_reg;}
        while(fscanf(recfile,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",naya.regno, naya.name, naya.gender, &naya.date, &naya.month, &naya.year, &naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, &naya.block, &naya.room, naya.fname, naya.fphone)!=EOF)
        {
        	if(strcmp(naya.regno,rem.regno)==0)
        	{





            choice=0; position=1;
            while(choice!=13) {
                    system("CLS");
                    printf(" Registration Number Choosen: %s\n",rem.regno);
                    printf(" Name of The Student: %s\n\n\n",naya.name);
                  //  printf("\t\t\tEnter year choice:\n\n\n");
                  //  arrow(1,position); printf(" Name\n\n");
                    arrow(1,position); printf(" Email\n\n");
                    arrow(2,position); printf(" Student's Phone Number\n\n");
                    arrow(3,position); printf(" Father's Phone Number\n\n");
                    choice=getch();
                    if ((choice==80) && (position!=3))
                            position++;
                    else if ((choice ==72)&&(position!=1))
                            position--;
            }

        		test=1;

             // if(position==1)
             //    {printf("Enter the new name:");
             //    scanf(" %[^\n]",rem.name);
             //    fprintf(newrec,"%s\n%s\n%s\n%d/%d/%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%c\n%d\n%s\n%s\n",naya.regno, rem.name, naya.gender, naya.date, naya.month, naya.year, naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, naya.block, naya.room, naya.fname, naya.fphone);
             //    printf("Changes saved!");
             //    }

            if(position==1)
			    {

update_mail:
            printf(" Enter the new Email");
            scanf("%s",rem.mail_id);
            if(emailcheck(naya.mail_id)!=1)
              {printf(" Invalid Email!! Please Try Again\n\n\n");
            goto update_mail;}
			    	fprintf(newrec,"%s\n%s\n%s\n%d/%d/%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%c\n%d\n%s\n%s\n",naya.regno, naya.name, naya.gender, naya.date, naya.month, naya.year, naya.age, naya.city, naya.state, naya.phone, rem.mail_id, naya.school, naya.branch, naya.block, naya.room, naya.fname, naya.fphone);
			    	printf(" Changes saved!");

				}
        else if(position==2)
     {update_phone:
       printf(" Enter student's new number:");
       scanf("%s",rem.phone);
       if(strlen(rem.phone)!=10)
       {
               printf("\n Invalid phone number!!!\nTry Again\n\n\n ");
               goto update_phone;
       }

       printf("\n\n%s\n",rem.phone);
       fprintf(newrec,"%s\n%s\n%s\n%d/%d/%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%c\n%d\n%s\n%s\n",naya.regno, naya.name, naya.gender, naya.date, naya.month, naya.year, naya.age, naya.city, naya.state, rem.phone, naya.mail_id, naya.school, naya.branch, naya.block, naya.room, naya.fname, naya.fphone);
       printf(" Changes saved!");

   }     else if(position==3)
   {
     // printf("Enter student's new number:");
     // scanf("%d",rem.phone);
     update_fphone:
     printf(" Enter Father's new number:");
     scanf("%s",rem.fphone);
     if(strlen(rem.fphone)!=10)
     {
             printf("\n Invalid phone number!!!\nTry Again\n\n\n ");
             goto update_fphone;
     }
     fprintf(newrec,"%s\n%s\n%s\n%d/%d/%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%c\n%d\n%s\n%s\n",naya.regno, naya.name, naya.gender, naya.date, naya.month, naya.year, naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, naya.block, naya.room, naya.fname, rem.fphone);
     printf(" Changes saved!");

 }
			}
			else
			fprintf(newrec,"%s\n%s\n%s\n%d/%d/%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%c\n%d\n%s\n%s\n",naya.regno, naya.name, naya.gender, naya.date, naya.month, naya.year, naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, naya.block, naya.room, naya.fname, naya.fphone);

		}
		fclose(recfile);
    fclose(newrec);
    remove("Hostel_Management.dat");
    rename("new.dat","Hostel_Management.dat");

    if(test!=1)
        printf("\n Record not found!!\a\a\a");

		printf("\n Enter 0 to Try Again,1 to Return to Main Menu and 2 to Exit:");
        do {
          main_exit=getch();
        }while (main_exit<=47||main_exit>50);
        if (main_exit==49)
			menu();
        else if (main_exit==50)
            closer();
         else if(main_exit==48)
         update_data();
        }



void give_percent()
{            system("CLS");
  int flag=0, percent=23,temp;
  FILE *recfile;
  char list[5][9];
  char list2[5][50];
  int per[]={0,0,0,0,0};


  recfile=fopen("Hostel_Management.dat","r");
  printf("\nEnter Student's Registration Number :");
  scanf("%s",check.regno);

  while(fscanf(recfile,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",naya.regno, naya.name, naya.gender, &naya.date, &naya.month, &naya.year, &naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, &naya.block, &naya.room, naya.fname, naya.fphone)!=EOF)
  {
          if (naive(check.regno,naya.regno)==0)
          {strcpy(check.city,naya.city);
            strcpy(check.state,naya.state);
            strcpy(check.gender,naya.gender);
            strcpy(check.branch,naya.branch);
            strcpy(check.school,naya.school);
            int i;
            for(i=0;i<5;i++)
            { strcpy(list[i],check.regno);
              strcpy(list2[i],check.name);
            }
            fseek(recfile,0,SEEK_SET);
            flag=1;
            break;
          }
  }if (flag==0)
    printf("Entered Student Does not Exists\n\n");

    else
    {flag=0;
      while(fscanf(recfile,"%s\n%[^\n]\n%s\n%d/%d/%d\n%d\n%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%c\n%d\n%[^\n]\n%s\n",naya.regno, naya.name, naya.gender, &naya.date, &naya.month, &naya.year, &naya.age, naya.city, naya.state, naya.phone, naya.mail_id, naya.school, naya.branch, &naya.block, &naya.room, naya.fname, naya.fphone)!=EOF)
      {flag=1;
        percent=23;
          if (naive(check.regno,naya.regno)==0)
          continue;
          else if (strcmp(check.gender,naya.gender)!=0)
          continue;
          else
          { printf("%s\n\n",naya.regno);
            if(Approxdist(check.city,naya.city)==3)
            percent+=28;
            else if(Approxdist(check.state,naya.state)==3)
            percent+=12;
            if (naive(check.branch,naya.branch)==0)
                percent+=21;
            else if(strcmp(check.school,naya.school)==0)
              percent+=13;

//Finding the Top Matches;
            temp=minimum(per);
            printf("%d",temp);
            strcpy(list[temp],naya.regno);
            strcpy(list2[temp],naya.name);
            per[temp]=percent;


      }}
    if(flag==1)
    { int i;
      printf("Reg No.\t\t\t\tName\t\t\tPercentage\n\n");
      for (i=0;i<5;i++)
      {   if(strcmp(list[i],check.regno)!=0)
              printf("%s\t\t\t%s\t\t\t%d\n\n",list[i],list2[i],per[i]);
      }

    }
    }
    fclose(recfile);



printf("\nEnter 0 to Try Again,1 to Return to Main Menu and 2 to Exit:");
        do {
          main_exit=getch();
        }while (main_exit<=47||main_exit>50);
        if (main_exit==49)
      menu();
        else if (main_exit==50)
            closer();
         else if(main_exit==48)
           give_percent();

}


int minimum(int num[])
{int i=0,a,loc=0;
  a=num[i];
  for(i=1;i<5;i++)
  { if(num[i]<a)
    {
    a=num[i];
    loc=i;}
  }
return loc;
}













void closer()
{
        system("CLS");
        printf("\n\n\n\n\n\n\n\t\t\t\t\tMade by Devarsh ,Tushar and Rishav\n\n\n");
}
