#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
int gdriver=DETECT,gmode,x1=0,y1=0,k=0,c,a;
int bufx[150],bufy[150],dist=7,dspeed;
int rndx,rndy,tail=2,size,dash=0,score=0;
int choice;
char name[20];
void gameover();
void randomnumber();
void checkcollision(int x1,int y1);
void checkcapture(int x1,int y1);
void move();
void welcome();
void statusbar();
void record();
void main(){
	// registerfarbgidriver(EGAVGA_driver_far);
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	size=tail;
	welcome();
	re:
	cleardevice();
	gotoxy(1,15);
	printf("1 for easy\n2 for medium\n3 for hard\nEnter difficult:");
	scanf("%d",&choice);
	switch(choice){
	case 1321: dspeed=200;break;
	case 1: dspeed=160;break;
	case 2: dspeed=60;break;
	case 3: dspeed=20;break;
	default: goto re;
	};
	cleardevice();
	statusbar();
	while((c=getch())!='\033'){
	if (c=='\115'&&a!=2) a=1;
	if (c=='\113'&&a!=1) a=2;
	if (c=='\120'&&a!=4) a=3;
	if (c=='\110'&&a!=3) a=4;
	dash=0;
	move();
	}
}
void move(){
	while(!kbhit()){
	k=++k%size;
	//prints body
	setfillstyle(1,10);
	setcolor(0);
	bar3d(x1,y1,x1+dist,y1+dist,0,0);
	setfillstyle(0,0);//emptyfill
	setcolor(0);//black border
	bar3d(bufx[k],bufy[k],bufx[k]+dist,bufy[k]+dist,0,0);//erases tail
	bufx[k]=x1;
	bufy[k]=y1;
	setcolor(15);
	checkcapture(x1,y1);
	if(a==1) x1=x1+dist;//if right
	if(a==2) x1=x1-dist;//if left
	if(a==3) y1=y1+dist;//if down
	if(a==4) y1=y1-dist;//if up
	checkcollision(x1,y1);
	/*prints head the same if no direction is obtained,
	prints new head if direction altered*/
	setfillstyle(1,2);
	bar3d(x1,y1,x1+dist,y1+dist,0,0);
	sound(300);
	delay(dspeed);
	nosound();
	delay(dspeed);
	}
}

void checkcollision(int x1,int y1){
	int i;
	for(i=1;i<=size;i++){
	if((bufx[i]==x1)&&(bufy[i]==y1)) dash=1;
	}
	if((x1<0)||(x1>=400)||(y1<0)||(y1>400)) dash=1;
	if(dash){
	delay(300);
	gameover();
	}
	statusbar();
}

void checkcapture(int x1,int y1){
	if((x1==rndx)&&(y1==rndy)){
	size++;score++;
	sound(500);
	delay(100);
	randomnumber();
	}
	setfillstyle(1,4);
	setcolor(4);
	bar3d(rndx,rndy,rndx+dist,rndy+dist,0,0);
}
void statusbar(){
	setcolor(15);
	setcolor(14);
	rectangle(0,0,400,410);
	gotoxy(55,2);
	printf("Score: %d",score);
	gotoxy(55,5);
	printf("Down: ");
	putchar(31);
	printf("\tUP");
	putchar(30);
	gotoxy(55,6);
	printf("RIGHT :");
	putchar(16);
	printf("\tLEFT :");
	putchar(17);
	gotoxy(55,7);
	printf("Press esc to exit");
	settextstyle(4,0,3);
	outtextxy(410,250,"KhwopaSnake");
}
void randomnumber(){
	rndx=rand()%40*dist;
	rndy=rand()%40*dist;
	}
void gameover(){
	sound(400);
	delay(200);
	nosound();
	cleardevice();
	delay(400);
	setcolor(12);
	settextstyle(5,0,5);
	outtextxy(230,200,"You Died!");
	gotoxy(25,23);
	printf("%s scored %d ",name,score);
	delay(500);

	record();
	fflush(stdin);
	getch();
	exit(0);
}
void record(){
	char c;
	FILE *info;
	cleardevice();
	info=fopen("record.txt","a+");
	fprintf(info,"Playername:%-20s\tScore=%3d\n",name,score);
	fclose(info);

	gotoxy(25,5);
	printf("List of players\n");
	info=fopen("record.txt","r");
	do{
	putchar(c=getc(info));}
	while(c!=EOF);
	fclose(info);
	printf("Press any key to exit");
	delay(5000);
	}
void welcome(){
	gotoxy(25,25);
	printf("Enter your name:");
	gets(name);
	cleardevice();
	delay(100);
	printf("Hello %s!",name);
	delay(300);
	setcolor(14);
	settextstyle(10,0,3);
	outtextxy(20,150,"Welcome to");
	delay(400);
	outtextxy(250,150," khwopa");
	delay(300);
	outtextxy(430,150," snake");
	delay(200);
	printf("Press any key to continue...\n");
	printf("Dont eat yourself");
	getch();

}