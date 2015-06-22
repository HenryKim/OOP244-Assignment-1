#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
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
        fscanf(fp,"%d%d%d",&a,&ps,&pl);
        if (a == area){
			ck=1;
		}
	}
    return ck;
}

int minNoDigits(FILE* fp, int area){
    int a, minno=0;
    char ps[10],pl[10];
    if(fp!=NULL){
        rewind(fp);
		while(!feof(fp) && minno==0){
            fscanf(fp,"%d%s%s",&a,&ps,&pl);
            if(a==area){
                minno=2;
			}
			else if(area>a){
				minno=1;
			}
			else if(area<a){
				minno=0;
			}
		}
	}

return minno;
}

int isRegistered(FILE* fp, int area, const char p[]){
	int a;
    int ck=0;
	int minck;
    char pu[10],pl[10];
    int is,il,ii;
    if(fp !=NULL){
		rewind(fp);		
        fscanf(fp,"%d%s%s",&a,pu,pl);
        if(a == area){
            if(strlen(p)==strlen(pu)){
				if((strcmp(p,pu) >=0) && (strcmp(p,pl)<=0)){
					ck=1;
				}
			}
		}//a==area;
	}// if !=NULL
    return ck;
}

int close(FILE* fp){
	int ck=0;
	if(fp!=NULL){
		fclose(fp);
		ck=1;
	}
	return ck;
}
