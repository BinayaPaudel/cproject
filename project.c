#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct student{
    char roll[20];
    char name [50];
    int room;
    char sex;
    char routine[500];
    char notice[500];
};


void main(){
    FILE *sth,*trh;
    sth=fopen("studenthod.dat","rb");
    trh=fopen("teacherhod.dat", "wb");
    struct student s[1000];
    char ch[5], r[50],notice[500];
    int i=0,num, option;
    int isfound = 0;

        TOP:

            system("cls");

    printf("1. Add Student \n");
    printf("2. Send Notice \n");
    printf("3. Exit\n");

    scanf("%d", &option);

    if(option == 1){
            i= 0;
            while(fread(&s[i], sizeof(s[i]), 1, sth) == 1){
                 i++;
            }
            fclose(sth);
            sth = fopen("studenthod.dat","ab");
        while(1){
            printf("Give name of the student: ");

            fflush(stdin);
            gets(s[i].name);
            fflush(stdin);

            printf("\nGive roll no: ");
            scanf("%s",&s[i].roll);
            fflush(stdin);
            printf("\nGive room no: ");
            scanf("%d",&s[i].room);
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
        printf("\nGive roll no of student: ");
        gets(r);

        sth = fopen("studenthod.dat", "rb");


        i = 0;
       while(fread(&s[i], sizeof(s[i]), 1, sth) == 1){
            printf("\nThe name of student is: %s", s[i].name);
            if(strcmp(r, s[i].roll) == 0){
                //printf("\n%s", s[i].name);
                isfound = 1;
                printf("\nNotice: ");
                gets(notice);
                strcpy(s[i].notice,notice);
                break;
            }
            i++;
       }

                fclose(sth);
                if(isfound == 1){
                    sth=fopen("studenthod.dat","wb");
                    for(int k = 0; k <= i; k++){
                        fwrite(&s[k], sizeof(s[k]), 1, sth);
                    }
                    fclose(sth);
                }else {
                    printf("\nThere is no student with that roll no\n");
                }

       getch();

    }
    else if(option == 3)
    {
        exit(0);
    }

    goto TOP;
}
