// Library Management System
//
// Copyright (C) 2015 Pankaj Bodade. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 
// 1. Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.  
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.  
// 3. Neither the name of the project nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission. 
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
// SUCH DAMAGE.

#include<stdio.h>
#include"library.h"

char info[500];
char info2[500];
/*initializing the files used in the program */

FILE *librecord;
FILE *membrrecord;
FILE *fp1;
FILE *fp2;
FILE *temp1;
FILE *temp2;

/* addbook function to add book to the library*/

void Addbook() {
            book.status=IN;
            /* opening book file */
            librecord = fopen("librecord.txt","a+");
            printf("Enter The uniqueid of The Book : \n");
            scanf("%d",&book.book_id);
            printf("Enter The Name of Author :\n");
            scanf("%s",book.author);
            printf("Enter The Title Of The Book : \n");
            scanf("%s",book.title);    
            fprintf(librecord,"\n%d\t%s\t%d\t%s",book.book_id,book.author,book.status,book.title);
            fclose(librecord);
            printf(" ***** New Book has been Added Successfully...\n");

}

/* displaybook to display all the saved contents */

void Displaybook() {
        librecord = fopen("librecord.txt","a+");            /* books information */
        printf(" ****** Books information *******");
        printf("\nBookid\tAuthor\tStatus\tTitle\n");
        do {
                fgets(info,500,librecord);                  /* fgets to store contents of librecord.txt to info */
                printf("%s",info);
        }while(!feof(librecord));
    
        fclose(librecord);
        membrrecord = fopen("membrrecord.txt","a+");         /* library member information */
        printf(" \n\n****** Member information ******");
        printf("\nMid\tName\tDept\tPh.no\tAvailablecards\n");
        do {
                fgets(info2,500,membrrecord);                /* fgets to store contents of membrrecord.txt to info2 */
                printf("%s",info2);
        }while(!feof(membrrecord));
    
        fclose(membrrecord);

}

/* searchbook function searches book in the librecord.txt */

void Searchbook( ) {
        char Target[25],stats[3];
        int Found=0;
      
        if((librecord = fopen("librecord.txt","r")) == NULL)
                printf(" ! The File is Empty...\n\n");
        else {
                printf("\nEnter The Title Of Book : ");
                scanf("%s",Target);
                while(!feof(librecord) && Found == 0) {
                        fscanf(librecord,"%d %s %d %s", &book.book_id,book.author,&book.status,book.title);
                        if(strcmp(Target,book.title) == 0)
                                Found = 1;
                }
                if(Found) {
                        if(book.status == IN)
                                strcpy(stats,"IN");
                        else
                                strcpy(stats,"OUT");
           
                printf("\nThe Unique ID of The Book :  %d\nThe Title of Book is      :  %s\n",book.book_id,book.title);
                printf("The Author is                 :  %s\nThe Book Status           :%s\n",book.author,stats);
                }
                else if(!Found)
                        printf("! There is no such Entry...\n");
        fclose(librecord);
    }

}

/* prints all the books of author */

void Author( ) {
    
        char Target[500];
        int Found = 0;
        if((librecord = fopen("librecord.txt","r")) == NULL)
                printf(" ! The file is empty... \n\n");
        else {
                printf("\nEnter The Name Of Author : ");
                scanf("%s",Target);
                printf("\nBooks:");
                while(!feof(librecord)) {
                        fscanf(librecord,"%d %s %d %s",&book.book_id,book.author,&book.status,book.title);
                        if(strcmp(Target,book.author) == 0) {
                                Found = 1;
                                printf("\n\t%s",book.title);
                        }
                }
                if(!Found)
                        printf(" ! There is no such Entry...\n");
        fclose(librecord);
        }

}

/* stock function keeps count of books and members */
void Stock() {
        int issuecount = 0, stockcount = 0;   
 
        if((librecord = fopen("librecord.txt","r")) == NULL)
                printf(" ! The file is empty...\n\n");
        else {
                while(!feof(librecord)) {
                        fscanf(librecord,"%d %s %d %s",&book.book_id,book.author,&book.status,book.title);
                        if(book.status == IN)
                                stockcount++;
                        else
                                issuecount++;
                }
                fclose(librecord);
                printf("\nCount of issued Books:%d\nCount of Books in Stock:%d\n",issuecount,stockcount);
        }
}

/* addmember adds member to the membrecord.txt file */

void Addmembr() {
        
        membrrecord = fopen("membrrecord.txt","a+");
        printf("Enter The userid of the Member :\n");
        scanf("%d",&membr.mid);
        printf("Enter The Name of the Member :\n");
        scanf("%s",membr.mname);
        printf("Enter The Department\n");
        scanf("%s",membr.department);
   
        printf("Enter The phone number of the member:\n");
        scanf("%d",&membr.phno);
        membr.availibcard=5;
        fprintf(membrrecord,"\n%d\t%s\t%s\t%d\t%d\t",membr.mid,membr.mname,membr.department,membr.phno,membr.availibcard);
        fclose(membrrecord);
        printf("\nAdded  A New member Successfully...\n");
}

/* issue function issues book for particular member */

void Issue() {
        int mid, Found1 = 0, Found2 = 0, flag = 0;
        char issubookname[20];
        printf("\nEnter The userid of the Member : \n");
        scanf("%d",&mid);
        if((membrrecord = fopen("membrrecord.txt","r")) == NULL)
                printf(" ! The file is empty...\n\n");
        else {
                while(!feof(membrrecord) && Found1 == 0) {
                        fscanf(membrrecord,"%d %s %s %d %d ",&membr.mid,membr.mname,membr.department,&membr.phno,&membr.availibcard);
                        if(mid == membr.mid)
                                Found1=1;
                }
                if(Found1) {
                        if(membr.availibcard < 1)
                                printf(" ! Library card not available...\n");
                        else {    
                                printf("\nEnter The Name of book :");
                                scanf("%s",issubookname);
                                if((librecord = fopen("librecord.txt","r")) == NULL)
                                        printf(" ! The file is empty...\n\n");
                                else {
                                        while(!feof(librecord) && Found2 == 0 ) {
                                                fscanf(librecord,"%d %s %d %s", &book.book_id, book.author, &book.status, book.title);
                                                if(strcmp(issubookname, book.title) == 0)
                                                        
                                                        Found2 = 1;
                                        }
                                        if(Found2 == 1 && flag == 0) {
                                                if(flag == 1) 
                                                        printf(" ! Book already issued...\n");
                                                else {   
                                                        fp2 = fopen("fp2.txt","w");
                                                        if((temp2 = fopen("membrrecord.txt","r")) == NULL)
                                                                printf(" ! The file is empty...\n\n");
                                                        else {
                                                                while(!feof(temp2)) {
                                            fscanf(temp2,"%d %s %s %d %d ",&membr.mid,membr.mname,membr.department,&membr.phno,&membr.availibcard);
                                                                        if(mid==membr.mid) {
                                                                                membr.availibcard--;
                                 fprintf(fp2,"\n %d\t%s\t%s\t%d\t%d\t",membr.mid,membr.mname,membr.department,membr.phno,membr.availibcard);
                                                                        }
                                                                        else {
                                      fprintf(fp2,"\n %d\t%s\t%s\t%d\t%d\t",membr.mid,membr.mname,membr.department,membr.phno,membr.availibcard);
                                                                         }
                                                                        if(feof(temp2))
                                                                                break;
                                                                }
                                                         }
                                                            fclose(temp2);
                                                            fclose(fp2);
                                                            fp1 = fopen("fp1.txt","w");
                                                                if((temp1 = fopen("librecord.txt","r")) == NULL)
                                                                        printf(" ! The file is empty...\n\n");
                                                                else {
                                                                        while(!feof(temp1)) {
                                                                fscanf(temp1,"%d %s %d %s", &book.book_id,book.author,&book.status,book.title);
                                                                                if(feof(temp1))
                                                                                        break;
                                                                                if(strcmp(issubookname,book.title) != 0) {
                                                        fprintf(fp1,"\n%d\t%s\t%d\t%s\n",book.book_id,book.author,book.status,book.title);
                                    }
                                                                                else {
                                                                                book.status = 0; 
                                        fprintf(fp1,"\n%d\t%s\t%d\t%s\t",book.book_id,book.author,book.status,book.title);
                                    }
                                    
                                }
                            }
                            fclose(temp1);
                            fclose(fp1);
                            fclose(librecord);
                            fclose(membrrecord);
                            remove("librecord.txt");
                            rename("fp1.txt","librecord.txt");
                            remove("membrrecord.txt");
                            rename("fp2.txt","membrrecord.txt");
                            printf(" Book Successfully issued...\n");
                            flag  = 1;
                        }               
                    }
                    else if(!Found2)
                        printf(" ! There is no such Book...\n");
               
                }
            }
        }
        else if(!Found1)
            printf(" ! Invalid User id...\n");
       

    }
   
}

/* bookret function returns book issued by particular member */

void bookret() {
        int mid, Found1 = 0, Found2 = 0;
        char retbookname[20];
        temp1 = librecord;
        temp2 = membrrecord;
        printf("\nEnter The userid of the Member :\n");
        scanf("%d",&mid);
        if((membrrecord = fopen("membrrecord.txt","r")) == NULL)
                printf(" ! The file is empty...\n\n");
        else {
                while(!feof(membrrecord) && Found1 == 0) {
                        fscanf(membrrecord,"%d %s %s %d %d ",&membr.mid,membr.mname,membr.department,&membr.phno,&membr.availibcard);
                        if(mid == membr.mid) {
                                Found1=1;
                        }
                }
                if(Found1) {
                        if(membr.availibcard >= 5) {
                                printf(" ! Error...\n");
                        }
                        else {    
                                printf("\nEnter The Name of book :");
                                scanf("%s",retbookname);
                                if((librecord = fopen("librecord.txt","r")) == NULL)
                                        printf(" ! The file is empty\n\n");
                                else {
                                        while(!feof(librecord) && Found2 == 0) {
                                                fscanf(librecord,"%d %s %d %s", &book.book_id,book.author,&book.status,book.title);
                                                if(strcmp(retbookname,book.title)==0)
                                                        Found2=1;
                                        }
                                        if(Found2) {
                                                if(book.status==1) 
                                                        printf(" ! Error:Book already in stock...\n");
                                                else {   
                                                        fp2=fopen("fp2.txt","w");
                                                        if((temp2 = fopen("membrrecord.txt","a+")) == NULL)
                                                                printf(" ! The file is empty...\n\n");
                                                        else {
                                                                while(!feof(temp2)) {
                                    fscanf(temp2,"%d %s %s %d %d ",&membr.mid,membr.mname,membr.department,&membr.phno,&membr.availibcard);
                                                                if(mid==membr.mid) {
                                                                        membr.availibcard++;
                                   fprintf(fp2,"\n %d\t%s\t%s\t%d\t%d\t",membr.mid,membr.mname,membr.department,membr.phno,    membr.availibcard);
                                                                }
                                                                else {
                                        fprintf(fp2,"\n %d\t%s\t%s\t%d\t%d\t",membr.mid,membr.mname,membr.department,membr.phno,membr.availibcard);
                                                                }
                                                                if(feof(temp2))
                                                                        break;
                                                                }
                                                        }
                                                        fclose(temp2);
                                                        fclose(fp2);
                                                        fp1=fopen("fp1.txt","w");
                                                        if((temp1 = fopen("librecord.txt","r")) == NULL)
                                                                printf(" ! The file is empty...\n\n");
                                                        else {
                                                                while(!feof(temp1)) {
                                                                    fscanf(temp1,"%d %s %d %s", &book.book_id,book.author,&book.status,book.title);
                                                                        if(feof(temp1))
                                                                                break;
                                                                        if(strcmp(retbookname,book.title)!=0) {
                                                                fprintf(fp1,"\n%d\t%s\t%d\t%s\t",book.book_id,book.author,book.status,book.title);
                                                                        }
                                                                        else {
                                                                        fprintf(fp1,"\n%d\t%s\t%d\t%s\t",book.book_id,book.author,1,book.title);
                                                                        }
                
                                        fscanf(temp1,"%s",book.title);
                                        fprintf(fp1,"%s\t",book.title);
                                    
                                }
                            }
                            fclose(temp1);
                            fclose(fp1);
                            fclose(librecord);
                            fclose(membrrecord);
                            printf("Book Successfully Returned...\n");
                            remove("librecord.txt");
                            rename("fp1.txt","librecord.txt");
                            remove("membrrecord.txt");
                            rename("fp2.txt","membrrecord.txt");

                        }               
                    }
                    else if(!Found2)
                        printf("! There is no such Book...\n");
               
                }
            }
        }
        else if(!Found1)
            printf("! Invalid User id...\n");
       

    }
   
}
void Exit() {
  exit(0);
}
