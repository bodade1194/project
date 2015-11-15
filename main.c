
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

int main() {       
        int choice = 0 ;
   
        printf("\n\t\t *** LIBRARY MANAGEMENT SYSTEM *** \n");
    
        do {
                printf("\n\t~~MENU~~\n 1> Add A New Book\n 2> Search a book \n 3> Display Complete Information\n 4> Display All Books of An Author\n 5> List Count of Books (Issued & On Stock)\n 6> To Issue a Book \n 7> To Return a Book \n 8> Add A New Member\n 9> Exit the program\n\n\t Enter your choice : ");
    
                scanf("%i",&choice);

       
                switch (choice) {   
                        case 1:
                                system("clear");
                                Addbook();
                               
                                break;
                        case 2:
                                system("clear");
                                Searchbook();
                                
                                break;
                        case 3:
                                system("clear");
                                Displaybook();
                              
                                break;
                        case 4:
                                system("clear");
                                Author();
                             
                                break;
                        case 5:
                                system("clear");
                                Stock();
                             
                                break;
                        case 6:
                                system("clear");
                                Issue();
                             
                                break;
                        case 7:
                                system("clear");
                                bookret();
                              
                                break;
                        case 8:
                                system("clear");
                                Addmembr();
                          
                                break;
                        case 9:
                                Exit();
                        default:
                                printf(" ! Invalid Input...\n");
                }
        }while(choice != 9);
        return (0);
}
