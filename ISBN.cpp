//hyungi kim 025 741 125//
//oop244//
//assignment1//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "ISBN.h"
using namespace std;
	int isValid(const char str[])
{
  int sum = 0, rc = 0;  
  int i = 0, m = 0, n = 0;
  if(str != NULL){
  for(i = 0; i < 10; i++)
  {
      m = str[i]-'0';  
      n = 10-i;
      sum += m * n;
  }
  if(str[9] == 'x'){
	  rc=0;
	  return rc;
  }
  if(sum % 11 == 0){ 
       rc = 1;}
  else{
	  rc=0;
  }
  }
//!NULL
  return rc;
	}
int isRegistered(FILE* fp, const char str[], char area[], char publisher[], char title[]){
	int rc=0,x=0,temp,tempz,r,i,y;
	rewind (fp);
	if(str == NULL){
		return rc;
	}
	if(isValid(str)==0){
		rc=0;
		return rc;
	}
	else{
		rc=1;
                for(i=0;i<5;i++){
                        if(i == 5){
                                rc=0;
                                return rc;
                        }
                        area[i]=str[i];
                        area[i+1]='\0';
                        tempz=atoi(area);
                        if(isRegistered(fp,tempz)==1){
                                temp=minNoDigits(fp,tempz);
                                for(y=0;y<8;y++){
                                        if(y==8){
                                                rc=0;
                                                return rc;
                                        }
                                        publisher[y]=str[temp+y];
                                        publisher[y+1]='\0';
                                        if(isRegistered(fp,tempz,publisher)==1){
                                                for(int z=0;z+temp+y<8;z++){
                                                        title[z]=str[temp+y+z+1];
                                                        title[z+1]='\0';
                                                }//title
return rc;
					}
					publisher[y]=str[temp+y];
					publisher[y+1]='\0';
					if(isRegistered(fp,tempz,publisher)==1){
						for(int z=0;z+temp+y<8;z++){
							title[z]=str[temp+y+z+1];
							title[z+1]='\0';
						}//title
						return rc;
					}//publisher ==1?
				}//publisher 2nd
			}//area ==1?
			
		}//area
	}
	return rc;
}//end

