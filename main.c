#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char line[100];
int i=0,ending,temp=-1,nooflname=0,flag=0,identifier,msearch=0,printed=0;
float validifier;

typedef struct{
    int day;
    int month;
    int year;
}Birth;

typedef struct {
    char first_name[20];
    char last_name[20];
    Birth birth;
    char address[50];
    char email[50];
    int phone_number;
}Person;

void load(FILE*);
void search();
int add();
int delete_record();
void modify(FILE*);
void print_sort();
int quit();
void sort_by_DOB();
void sort_by_lastName();

Person names [100];

/***
To read the information of every contact and store each one's data in a separate array according to type of data
***/

void load(FILE *fp){
    i=0; char *token;
        fp=fopen("phonebook.txt","r");
        if(fp==NULL){
            printf("Failed to open file!");
            exit(0);
        }
        while(!feof(fp)){
        //To read the whole line which will then be tokenized
        fscanf(fp,"%[^\n]\n",line);
        //Strtok is used in tokenizing the line where the delimiter is the comma, 
        //so every piece of information seperated by a comma is stored seperately
        token=strtok(line,",");

        strcpy(names[i].last_name,token);

        token=strtok(NULL,",");

        strcpy(names[i].first_name,token);
        //The delimiter here is the hyphen as the date is seperated using it(dd-mm-yyyy)
        //atoi is used to convert the string "token" into an integer to be stored
        token=strtok(NULL,"-");

        names[i].birth.day=atoi(token);

        token=strtok(NULL,"-");

        names[i].birth.month=atoi(token);

        token=strtok(NULL,",");

        names[i].birth.year=atoi(token);

        token=strtok(NULL,",");

        strcpy(names[i].address,token);

        token=strtok(NULL,",");

        strcpy(names[i].email,token);

        token=strtok(NULL,",");

        names[i].phone_number=atoi(token);
        //Printing the line after being seperated
        printf("First name:%s\n",names[i].first_name);
        printf("Last name:%s\n",names[i].last_name);
        printf("Date of Birth:%d/%d/%d\n",names[i].birth.day,names[i].birth.month,names[i].birth.year);
        printf("Address:%s\n",names[i].address);
        printf("Email:%s\n",names[i].email);
        printf("Phone number:0%d\n\n",names[i].phone_number);
        ++i;
}
        i--;
        }

/***
To search for a specific contact either by means of last name or by a detailed search which allows user to
insert other fields to search by
***/

void search(){
        printf("Choose searching method\nEnter 1 for searching by last name or 0 for multi search\n");
        scanf("%d", &identifier);
        if(identifier==1){
        char comp[50];
        printf("Insert last name:");
        scanf("%s",comp);

        i=0;int j=0,cmp;

        while(i<=ending){
            cmp=strcasecmp(comp,names[i].last_name);
            if( cmp==0 && j!=0){
            printf("\nFirst name is:%s\n",names[i].first_name);
            printf("Address is: %s\n",names[i].address);
            printf("Email is: %s\n",names[i].email);
            printf("Phone number is: 0%d\n",names[i].phone_number);
            i++;
            continue;
        }
        else if(cmp==0 && j==0){
            j=1;
            printf("\nFirst name is: %s\n",names[i].first_name);
            printf("Address is: %s\n",names[i].address);
            printf("Email is: %s\n",names[i].email);
            printf("Phone number is: 0%d\n",names[i].phone_number);
            i++;
            continue;
        }
        else if(cmp!=0 &&j==0 && i==ending){
            printf("\nRecord doesn't exist!");
        }
        i++;
        }
}else if(identifier==0){
        char sfname[20],saddress[50],slname[20],semail[50],sphone[20],null[5]={'\0'},bluff;
        ending++;

        printf("Press enter to skip a search field\n");

        scanf("%c", &bluff);

        printf("Please enter first name\n");

        gets(sfname);

        printf("Please enter last name\n");

        gets(slname);

        printf("Please enter address\n");

        gets(saddress);

        printf("Please enter email\n");

        gets(semail);

        printf("Enter phone number\n");

        gets(sphone);
        for(i=0;i<ending;i++){msearch=0;
            if((!strcasecmp(sfname,names[i].first_name))||(!strcmp(sfname,null))){
                msearch++;}

            if((!strcasecmp(slname,names[i].last_name))||(!strcmp(slname,null))){
                msearch++;}

            if((!strcasecmp(saddress,names[i].address))||(!strcmp(saddress,null))){
                msearch++;}

            if((!strcasecmp(semail,names[i].email))||(!strcmp(semail,null))){
                msearch++;}

            if(names[i].phone_number==atoi(sphone)||(!strcmp(sphone,null))){
                msearch++;}

            if(msearch==5){
                printf("First name:%s\n",names[i].first_name);
                printf("Address:%s\n",names[i].address);
                printf("Email:%s\n",names[i].email);
                printf("Phone number:0%d\n\n",names[i].phone_number);
                printed=1;
            }}

            if(printed!=1){
            printf("There is no record that matches these entries\n");}

}else{
    printf("invalid entry\n");
    while(identifier!=0&&identifier!=1){
        scanf("%d", &identifier);
    }
}
}

/***
To add a new contact to the telephone book
***/

int add(){
                char bluff;
                int cname,finalchar;
                printf("Insert first name of new record:");
                do{
                    flag=0;
                    scanf("%s",names[ending].first_name);
                cname=0;
                //To check that name doesn't include a number by mistake
                while(names[ending].first_name[cname]!='\0'){
                    if(names[ending].first_name[cname]=='0' || names[ending].first_name[cname]=='1' ||
                       names[ending].first_name[cname]=='2' || names[ending].first_name[cname]=='3' ||
                       names[ending].first_name[cname]=='4' || names[ending].first_name[cname]=='5' ||
                       names[ending].first_name[cname]=='6' || names[ending].first_name[cname]=='7' ||
                       names[ending].first_name[cname]=='8' || names[ending].first_name[cname]=='9'){
                            flag=1;
                            printf("Invalid entry!\nPlease reenter name:");
                            break;
                    }
                    cname++;
                }
                }while(flag==1);
                printf("Insert last name:");

                 do{
                    flag=0;
                    scanf("%s",names[ending].last_name);
                cname=0;
                //To check that name doesn't include a number by mistake
                while(names[ending].last_name[cname]!='\0'){
                    if(names[ending].last_name[cname]=='0' || names[ending].last_name[cname]=='1' ||
                       names[ending].last_name[cname]=='2' || names[ending].last_name[cname]=='3' ||
                       names[ending].last_name[cname]=='4' || names[ending].last_name[cname]=='5' ||
                       names[ending].last_name[cname]=='6' || names[ending].last_name[cname]=='7' ||
                       names[ending].last_name[cname]=='8' || names[ending].last_name[cname]=='9'){
                            flag=1;
                            printf("Invalid entry!\nPlease reenter name:");
                            break;
                    }
                    cname++;
                }
                }while(flag==1);

                printf("Insert day of birth:");
                scanf("%d",&names[ending].birth.day);
                //Validating the day of birth not being less than 1 or more than day 31 of month
                while(names[ending].birth.day<1 || names[ending].birth.day>31){
                    printf("Invalid day!\nPlease reenter day of birth:");
                    scanf("%d",&names[ending].birth.day);
                }

                printf("Insert month of birth:");
                scanf("%d",&names[ending].birth.month);
                //Validating the month of birth not being less than 1 or more than month 12 of year
                while(names[ending].birth.month<1 || names[ending].birth.month>12){
                    printf("Invalid month!\nPlease reenter month of birth:");
                    scanf("%d",&names[ending].birth.month);
                }

                printf("Insert year of birth:");
                scanf("%d",&names[ending].birth.year);
                //Validating the year of birth being within a reasonable range
                while(names[ending].birth.year<1900 || names[ending].birth.year>2019){
                    printf("Invalid year!\n Please reenter year of birth:");
                    scanf("%d",&names[ending].birth.year);
                }

                printf("Insert address:");
                scanf("%c",&bluff);
                scanf("%[^\n]",names[ending].address);
                printf("Insert email:");
                do{
                scanf("%s",names[ending].email);
                flag=0;
                cname=0;
                while(names[ending].email[cname]!='\0'){
                        cname++;}
                finalchar=cname;
                    cname=0;
                    //To make sure that email contains "@" and ".com"
                    while(names[ending].email[cname]!='\0'){
                    if(names[ending].email[cname]=='@' && names[ending].email[finalchar-4]=='.'&&
                    names[ending].email[finalchar-3]=='c' && names[ending].email[finalchar-2]=='o'&& 
                    names[ending].email[finalchar-1]=='m'){ flag=1;}
                    cname++;
                    }
                    if(flag!=1) printf("Invalid entry!\nPlease reenter email:");
                }while(flag!=1);
                printf("Insert phone number:");
                scanf("%d",&names[ending].phone_number);

                validifier=(1.0*names[ending].phone_number)/pow(10,10);

                while(!(validifier>0.1&&validifier<1)){
                    printf("Invalid number of digits,\nPlease enter an 11 digit number:");
                    scanf("%d",&names[ending].phone_number);
                    validifier=(1.0*names[ending].phone_number)/pow(10,10);
                }
                printf("\nSuccessfully added record!");
                return ++ending;

}

/***
To delete one of the contacts that already exists in the telephone book
***/

int delete_record(){
            char first[20],last[20];
            int deletecmp1,deletecmp2,temp1,flag=0,choice,k;

            printf("Insert first name of record to be deleted:");
            scanf("%s",first);

            printf("Insert last name of record to be deleted:");
            scanf("%s",last);
            i=0;

            printf("ending is:%d",ending);
            while(i<=ending){
                deletecmp1=strcasecmp(first,names[i].first_name);
                deletecmp2=strcasecmp(last,names[i].last_name);
                if(deletecmp1==0 && deletecmp2==0){

                printf("First name:%s\n",names[i].first_name);
                printf("Last name:%s\n",names[i].last_name);
                printf("Date of Birth:%d/%d/%d\n",names[i].birth.day,names[i].birth.month,names[i].birth.year);
                printf("Address:%s\n",names[i].address);
                printf("Email:%s\n",names[i].email);
                printf("Phone number:0%d\n\n",names[i].phone_number);

                 flag=1;
                 printf("Is this the record you want to to delete?\nIf yes please enter 1,else enter any number:");
                 scanf("%d",&choice);
                if(choice==1){
                 for(k=i;k<ending;k++){
                        temp1=k;
                        names[k]=names[temp1+1];}
                 printf("\nSuccessfully deleted!\n");
                 break;
                }
            }

            ++i;}
            if(flag!=1){
                    printf("\nRecord does not exist!\n");
                }
            else return --ending;

}

/***
To alter the data of a certain contact by first searching for that contact then specifying which field you would like to alter
***/

void modify(FILE*fp)
{
    ending++;
    char bluff;
    int cname,finalchar;
    printf("Enter last name you want to modify\n");
    char wanted_name[20];
    scanf("%s",wanted_name);
    for(i=0; i<ending; i++)
    {
        if(!strcasecmp(wanted_name,names[i].last_name))
        {
            nooflname++;
        }}
        if(nooflname==1)
        {
                printf("Insert first name of new record:");
                scanf("%s",names[i].first_name);
                printf("Inset last name:");
                do{
                    flag=0;
                    scanf("%s",names[ending].last_name);
                    cname=0;
                //To check that name doesn't include a number by mistake
                while(names[ending].last_name[cname]!='\0'){
                    if(names[ending].last_name[cname]=='0' || names[ending].last_name[cname]=='1' ||
                       names[ending].last_name[cname]=='2' || names[ending].last_name[cname]=='3' ||
                       names[ending].last_name[cname]=='4' || names[ending].last_name[cname]=='5' ||
                       names[ending].last_name[cname]=='6' || names[ending].last_name[cname]=='7' ||
                       names[ending].last_name[cname]=='8' || names[ending].last_name[cname]=='9'){
                            flag=1;
                            printf("Invalid entry!\nPlease reenter name:");
                            break;
                    }
                    cname++;
                }
                }
                while(flag==1);
                printf("Insert day of birth:");
                scanf("%d",&names[i].birth.day);
                //Validating the day of birth not being less than 1 or more than day 31 of month
                while(names[i].birth.day<1 || names[i].birth.day>31){
                    printf("Invalid day!\nPlease reenter day of birth:");
                    scanf("%d",&names[i].birth.day);
                }
                printf("Insert month of birth:");
                scanf("%d",&names[i].birth.month);
                //Validating the month of birth not being less than 1 or more than month 12 of year
                while(names[i].birth.month<1 || names[i].birth.month>12){
                    printf("Invalid month!\nPlease reenter month of birth:");
                    scanf("%d",&names[i].birth.month);
                }
                printf("Insert year of birth:");
                scanf("%d",&names[i].birth.year);
                //Validating the year of birth being within a reasonable range
                while(names[i].birth.year<1900 || names[i].birth.year>2019){
                    printf("Invalid year!\n Please reenter year of birth:");
                    scanf("%d",&names[i].birth.year);
                }
                printf("Insert address:");
                scanf("%c",&bluff);
                scanf("%[^\n]",names[i].address);
                printf("Insert email:");
                do{
                scanf("%s",names[ending].email);
                flag=0;
                cname=0;
                while(names[ending].email[cname]!='\0'){
                        cname++;}
                finalchar=cname;
                    cname=0;
                    //Making sure email contains "@" and ".com"
                    while(names[ending].email[cname]!='\0'){
                    if(names[ending].email[cname]=='@'
                       &&names[ending].email[finalchar-4]=='.'
                       &&names[ending].email[finalchar-3]=='c'
                       &&names[ending].email[finalchar-2]=='o'
                       &&names[ending].email[finalchar-1]=='m'){ flag=1;}
                    cname++;
                    }
                    if(flag!=1) printf("Invalid entry!\nPlease reenter email:");
                }while(flag!=1);
                printf("Insert phone number:");
                scanf("%d",&names[i].phone_number);

                validifier=(1.0*names[i].phone_number)/pow(10,10);

                while(!(validifier>0.1&&validifier<1)){
                    printf("Invalid number of digits\nPlease enter an 11 digit number");
                    scanf("%d",&names[i].phone_number);
                    validifier=(1.0*names[i].phone_number)/pow(10,10);
                }
            flag=1;
        }else if(nooflname>1){
            printf("There is more than one record with this last name,\nPlease enter phone number:\n");
            int wanted_number;
            scanf("%d", &wanted_number);
            for(i=0; i<ending; i++)
            {
                if(wanted_number==names[i].phone_number)
                {
                printf("Insert first name of new record:");
                scanf("%s",names[i].first_name);
                printf("Inset last name:");
                scanf("%s",names[i].last_name);
                printf("Insert day of birth:");
                scanf("%d",&names[i].birth.day);
                //Validating the day of birth not being less than 1 or more than day 31 of month
                while(names[i].birth.day<1 || names[i].birth.day>31){
                    printf("Invalid day!\nPlease reenter day of birth:");
                    scanf("%d",&names[i].birth.day);
                }
                printf("Insert month of birth:");
                scanf("%d",&names[i].birth.month);
                //Validating the month of birth not being less than 1 or more than month 12 of year
                while(names[i].birth.month<1 || names[i].birth.month>12){
                    printf("Invalid month!\nPlease reenter month of birth:");
                    scanf("%d",&names[i].birth.month);
                }
                printf("Insert year of birth:");
                scanf("%d",&names[i].birth.year);
                //Validating the year of birth being within a reasonable range
                while(names[i].birth.year<1900 || names[i].birth.year>2019){
                    printf("Invalid year!\n Please reenter year of birth:");
                    scanf("%d",&names[i].birth.year);
                }
                printf("Insert address:");
                scanf("%c",&bluff);
                scanf("%[^\n]",names[i].address);
                printf("Insert email:");
                scanf("%s",names[i].email);
                printf("Insert phone number:");
                scanf("%d",&names[i].phone_number);
                validifier=(1.0*names[i].phone_number)/pow(10,10);
                while(!(validifier>0.1&&validifier<1)){
                    printf("Invalid number of digits\nPlease enter an 11 digit number");
                    scanf("%d",&names[i].phone_number);
                    validifier=(1.0*names[i].phone_number)/pow(10,10);
                }
                    flag=1;
                }
            }
        }
   if(flag==1){
    printf("\nSuccessfully modified record!\n");
    }else if(flag==0){
        printf("\nRecord doesn't exist!\n");
    }}

void sort_by_lastName(){
        int k,temp2,cmp1;
        //Sorting using bubble sort algorithm with O(n^2)
        for(i=0;i<ending-1;i++){
        for(k=0;k<ending-i-1;k++){
            temp2=k;
            cmp1=strcasecmp(names[k].last_name,names[++temp2].last_name);
            temp2=k;
            if(cmp1>0){
        names[101]=names[k];
        names[k]=names[k+1];
        names[k+1]=names[101];
            }
        }
     }
}

/***
To sort the contacts by means of date of birth in ascending form
***/

void sort_by_DOB(){
    int temp2,k;
    //Sorting using bubble sort algorithm with O(n^2)
    for(i=0;i<ending-1;i++){
        for(k=0;k<ending-i-1;k++){
            temp2=k+1;
    if(names[k].birth.year>names[temp2].birth.year){
                names[101]=names[k];
                names[k]=names[k+1];
                names[k+1]=names[101];
                }
                else if(names[k].birth.year==names[temp2].birth.year &&
                        names[k].birth.month>names[temp2].birth.month){
                names[101]=names[k];
                names[k]=names[k+1];
                names[k+1]=names[101];
                }
                else if(names[k].birth.year==names[temp2].birth.year &&
                        names[k].birth.month==names[temp2].birth.month &&
                        names[k].birth.day>names[temp2].birth.day){
                        names[101]=names[k];
                        names[k]=names[k+1];
                        names[k+1]=names[101];
                        }

        }
    }

}

void print_sort(){
    i=0; int k,temp2,choice;
    int cmp1;
    printf("Please choose either sorting by last name or by Date Of Birth:");
    printf("\nTo sort by last name please enter 1,to sort by DOB please enter 2:");
    scanf("%d",&choice);
    while(choice>2 || choice<1){
        printf("Invalid entry please enter either 1 for sorting by last name or 2 for sorting by DOB:");
        scanf("%d",&choice);
    }
            if(choice==1){
            sort_by_lastName();
            }
        else if(choice==2){
                sort_by_DOB();
    }
    i=0;
    while(i<ending){
        printf("First name:%s\n",names[i].first_name);
        printf("Last name:%s\n",names[i].last_name);
        printf("Date of Birth:%d/%d/%d\n",names[i].birth.day,names[i].birth.month,names[i].birth.year);
        printf("Address:%s\n",names[i].address);
        printf("Email:%s\n",names[i].email);
        printf("Phone number:0%d\n\n",names[i].phone_number);
        i++;
}
printf("\nSuccessfully sorted!\n");
}

/***
To write the updated version in a comma separated value form before quitting
***/

void save(FILE*fp){
    fp=fopen("project.txt","w");
                i=0;
                printf("ending is:%d",ending);
                //Saving data in a comma seperated form
                while(i<ending){
                    fprintf(fp,"%s,%s,%d-%d-%d,%s,%s,%d\n",names[i].last_name,
                            names[i].first_name,names[i].birth.day,
                            names[i].birth.month,names[i].birth.year,
                            names[i].address,names[i].email,
                            names[i].phone_number);
                    ++i;
                }
                fclose(fp);
    printf("\nSuccessfully saved!\n");
}
int quit(){
        int to_quit;
        printf("Warning! All unsaved data will be lost!\nAre you sure you want to quit?\n\nIf yes please press 0, if no please enter any number:");
        scanf("%d",&to_quit);
        if(to_quit==0){exit(0);}
        }
int main()
{
    FILE *fp,*fp2;
    printf("\t\t\t Welcome to the Telebook \t\t\t\n\t\t\t ______________________");
    printf("\n\tMenu\n\t____\n1.Load\n2.Search\n3.Add\n4.Delete\n5.Modify\n6.Sort\n7.Save\n8.Quit\n\nPlease load the file first by pressing 1,\n");

    int option,deletecmp3,choice,loaded;

    char comp[100],line1[100],emp[10],ch='0';

    strcpy(emp,"\0");

    do{
    printf("Insert option:");
    scanf("%d",&option);

    while(option>8 || option<1){
        printf("Invalid entry, please enter a valid option:");
        scanf("%d",&option);
    }

    printf("\nRunning your choice...\n\n");

    switch(option){
        case 1:
            loaded=1;
            load(fp);
            temp=i+1;
            ending=temp;
        break;

        case 2:
            if(loaded!=1){
            break;}
        search();
        break;

        case 3:
            if(loaded!=1){
            break;}
            temp=add();
            ending=temp;
            break;

        case 4:
            if(loaded!=1){
            break;}
            temp=delete_record(fp);
            ending=temp;
            break;

        case 5:
            if(loaded!=1){
            break;}
            modify(fp);
            break;

        case 6:
            if(loaded!=1){
            break;}
            print_sort();
            ending=temp;
            break;

        case 7:
            if(loaded!=1){
            break;}
            save(fp);
            break;

        case 8:
        option=quit();
        break;
}
        printf("\n\tMenu\n\t____\n1.Load\n2.Search\n3.Add\n4.Delete\n5.Modify\n6.Sort\n7.Save\n8.Quit\n");
}while(option!=0);

}
