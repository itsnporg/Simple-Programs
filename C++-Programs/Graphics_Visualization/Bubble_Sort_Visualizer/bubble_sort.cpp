#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include <algorithm>
#define n 1400
using namespace std;




bool draw(void);
void setup(void);

long arr[n];

int main(){
	int page = 0;
	setup();
	while(true){
		setvisualpage(page);
		setactivepage(1-page);
		
		cleardevice();
		
		if(draw())break;
		
		page = 1-page;
	}
	getch();
}


void setup(){
	initwindow(1080,720);
	printf("%d %d",getmaxx(),getmaxy());
	
	for(int i=0;i<n;i++){
		arr[i] = rand() % getmaxx();
	}
}

int i=0;

bool draw(){		
	if(i<n){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}else{
		return true;
	}
	i++;
	
	for(int i=0;i<n;i++){
		line(i,getmaxy(),i,getmaxy()- arr[i]);
	}
	delay(0);
}







