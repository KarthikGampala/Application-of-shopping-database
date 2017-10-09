#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include"137-assign12.c"
#include"127-assign12.c"
#include"032-assign12.c"
#include"027-assign12.c"

int main(int argc,char *argv[]){
clock_t begin = clock();
   FILE *fp;
   int n,id;
   fp = (argc > 1) ? fopen(argv[1], "r+") : fopen("data.txt", "r+");
 printf("\t\tWELCOME TO IIITS SHOPPING SITE\n");
   printf("1.  LOGIN USER\n2.  SIGN UP\n3.  LOGIN ADMIN\n");
   printf("ENTER YOUR OPTION:");
 scanf("%d",&n);
   head=createDataSet(head);
  switch(n){
     
     case 1:
           logIn();
           break;
     case 2:
           signUp();
           logIn();
           break;
     case 3:
          adminLogin();           
          break;    
   }
   
   fclose(fp);
  // printTree(head);
//   printf("\n"); 

/* here, do your time-consuming job */

clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("%lf",time_spent);
  return 0; 
}

