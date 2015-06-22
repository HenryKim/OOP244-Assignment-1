//hyungi kim 025 741 125//
//oop244//
//assignment1//
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include"ISBNPrefix.h"
using namespace std;
FILE* open(const char filename[]){
    FILE* fp;

if(filename != NULL){
	fp=fopen(filename,"r");
	return fp;
}
else{
	fp=NULL;
	return fp;
}
}

int isRegistered(FILE* fp, int area){
	int a;
    int ps,pl;
    int ck=0;
    if(fp!=NULL){
		rewind(fp);
        while(ck == 0 && !feof(fp)){
     fscanf(fp, "%d%d%d", &a,&ps,&pl);  
     if(a == area){
       ck= 1;           }//check a==area
		}//while
	}//fp!=null
    return ck;
	}

int minNoDigits(FILE* fp, int area){
    int a, minno=0;
    char ps[10],pl[10];
    if(fp!=NULL){
        rewind(fp);
		while(!feof(fp) && minno==0){
			
            fscanf(fp,"%d%s%s",&a,ps,pl);

            if(area==a){
				if(a==0){
					minno=2;
					return minno;
				}
				minno = (int)(log10((float)a) + 1);
				return minno;
			}
		}
	}

return minno;
}

int isRegistered(FILE* fp, int area, const char publisher[])
{
   int rc = 0, i1 = 0, i2 = 0, i3 = 0, a = 0, i = 0;
   char pu[10], pl[10], p[10];             

   if(fp != NULL){ 
     rewind(fp);
  
   while(EOF != fscanf(fp, "%d%s%s", &a,pu,pl)) 
   {
      if(a == area)
      {                     
        i1 = atoi(pu);     
        i2 = atoi(pl);
        i3 = atoi(publisher);
        if(i3 <= i2 && i3 >= i1 && strlen(publisher) == strlen(pu)){
          rc = 1;
		}
	  }
   }//while

   for(i = 0; i < 2; i++){
     if(publisher[i]-'0' == 1 && publisher[i+1]-'0' == 0)
	 {
       rc = 1;
	 }
   }//for loop
   }//!NULL
   return rc;
}

int close(FILE* fp){
	int ck=0;
	if(fp!=NULL){
		fclose(fp);
		ck=1;
	}
	return ck;
}
