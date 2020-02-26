#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct teacher{
    char id[50];
    char name [50];
    int salary;
    char sex;
    char routine[500];
    char notice[500];
};


void main(){
    FILE *sth,*trh;
    sth=fopen("teacherhod.dat","rb");
    struct teacher s[1000];
    char ch[5], r[50],notice[500];
    int i=0,num, option, salary;
    int isfound = 0;

        TOP:

            system("cls");

    printf("1. Add teacher \n");
    printf("2. Send Notice \n");
    printf("3. Change Salary \n");
    printf("4. Exit\n");

    scanf("%d", &option);

    if(option == 1){
            i= 0;
            while(fread(&s[i], sizeof(s[i]), 1, sth) == 1){
                 i++;
            }
            fclose(sth);
            sth = fopen("teacherhod.dat","ab");
        while(1){
            printf("Give name of the teacher: ");

            fflush(stdin);
            gets(s[i].name);
            fflush(stdin);

            printf("\nGive id no: ");
            scanf("%s",&s[i].id);
            fflush(stdin);
            printf("\nGive salary: ");
            scanf("%d",&s[i].salary);
            fflush(stdin);
            printf("\nGive gender: ");
            scanf("%c",&s[i].sex);
            fflush(stdin);
            printf("\nGive routine: \n");
            gets(s[i].routine);
            fflush(stdin);
            printf("\nGive notice: \n");
            gets(s[i].notice);
            fflush(stdin);

                       fwrite(&s[i],sizeof(s[i]),1,sth);

            printf("\nEnter no to terminate: ");
            gets(ch);

                    i++;
            if(strcmp(ch,"no")==0){
                                break;
            }

        }
        num=i;
        fclose(sth);
}
    else if(option == 2){
            fflush(stdin);
        printf("\nGive id no of teacher: ");
        gets(r);
        fclose(sth);
        sth = fopen("teacherhod.dat", "rb");


        i = 0;
       while(fread(&s[i], sizeof(s[i]), 1, sth) == 1){

            if(strcmp(r,s[i].id)==0){
                printf("\nThe name of teacher is: %s\n", s[i].name);
                isfound = 1;
                printf("\nNotice: ");
                gets(notice);
                strcpy(s[i].notice,notice);
            }
            i++;
       }

                fclose(sth);
                if(isfound == 1){
                    sth=fopen("teacherhod.dat","wb");
                    for(int k = 0; k < i; k++){
                        fwrite(&s[k], sizeof(s[k]), 1, sth);
                    }
                    fclose(sth);
                }else {
                    printf("\nThere is no teacher with that id no\n");
                }

    }
    else if(option == 3){
                    fflush(stdin);
        printf("\nGive id no of teacher: ");
        gets(r);
        fclose(sth);
        sth = fopen("teacherhod.dat", "rb");


        i = 0;
       while(fread(&s[i], sizeof(s[i]), 1, sth) == 1){

            if(strcmp(r,s[i].id)==0){
                printf("\nThe name of teacher is: %s\n", s[i].name);
                isfound = 1;
                printf("\nNew Salary: ");
                scanf("%d", &salary);
                s[i].salary = salary;
            }
            i++;
       }

                fclose(sth);
                if(isfound == 1){
                    sth=fopen("teacherhod.dat","wb");
                    for(int k = 0; k < i; k++){
                        fwrite(&s[k], sizeof(s[k]), 1, sth);
                    }
                    fclose(sth);
                }else {
                    printf("\nThere is no teacher with that id no\n");
                }


    }
    else if(option == 4)
    {
        exit(0);
    }

    goto TOP;
}
