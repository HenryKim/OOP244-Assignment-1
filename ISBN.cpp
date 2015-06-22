#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ISBN.h"
#include "ISBNPrefix.h"
using namespace std;
int isValid(const char str[]){
	int total=0;
	int ck=0;
	int c=0;
	if (str!=NULL){
	for(int i=0;i<10;i++){
		total+=(str[i]-'0')*(10-i);
	}
	c=total%11;
		if(c==0){
			ck=1;
		}
	}
		return ck;
}
int isRegistered(FILE* fp, const char str[], char area[], char publisher[],char title[]){
	int ck=0,ck2=0,ck3=0,temp,mck,x=0;
	int c;
	if (str!=NULL && fp!=NULL){
		if(isValid(str)==1){
for(int i=0;i<5;i++){
	area[i]=str[i];
	area[i+1]='\0';
	temp=isRegistered(fp,atoi(area));
	if(!temp==1){
		x=i;
		i=5;
		ck2=1;
		temp=0;
	}
}//for for area
mck=minNoDigits(fp,atoi(area));
if(ck2==1){
for(int i=0;i<7;i++){
	publisher[i]=str[x+i];
	publisher[i+1]='\0';
	temp=isRegistered(fp,atoi(area),publisher);
	if(!temp==1){
		i=mck+1;
		ck3=1;
	}
}//for for publisher
}//trigger
if(ck2 && ck3){
	ck=1;
}//trigger no2.
	return ck;
		}
	}
}