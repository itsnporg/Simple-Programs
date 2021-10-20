#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<vector>
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989
using namespace std;



void fillColor(int x,int y, int oldcolor, int newcolor){
	if(getpixel(x,y) == oldcolor){
		putpixel(x,y,newcolor);
		fillColor(x+1,y,oldcolor,newcolor);
		fillColor(x,y+1,oldcolor,newcolor);
		fillColor(x-1,y,oldcolor,newcolor);
		fillColor(x,y-1,oldcolor,newcolor);
	}
	return;
}

void draw(void);
void setup(void);
int main(){
	setup();
	int page = 0;
	while(true){
		setvisualpage(page);
		setactivepage(1-page);
		cleardevice();
		draw();
		page = 1-page;
	}
	getch();
}


void setup(){
	initwindow(1080,720);
//	printf("%d %d",getmaxx(),getmaxy());
}

int intersectY(int x1, int y1, int x2,int y2, int x3, int y3, int x4, int y4){
	int up = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3);	
	int down = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	float u = float(up)/float(down);
	return (y3 + u*(y4 - y3));
}

int intersectX(int x1, int y1, int x2,int y2, int x3, int y3, int x4, int y4){
	int up = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3);	
	int down = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	float u = float(up)/float(down);
	return (x3 + u*(x4 - x3));
}

int dist(int x1, int y1, int x2, int y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) *(y2 - y1));
}

void drawTriangle(int height, int x, int y){
	
}
void draw(){
	
	
	setcolor(WHITE);
	rectangle(0,0,getmaxx(),getmaxy());
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(50,50,WHITE);
	
	setcolor(BLACK);
	int ab_len = 200;
	int a_x = 500;
	int a_y = 500;
	
	int b_x = a_x + ab_len;
	int b_y = a_y;
//	line ab
	line(a_x,a_y,b_x,b_y);
	
	int ac_len = ab_len + ab_len/3;
	int c_x = a_x;
	int c_y = a_y - ac_len;
//	line ac
	line(a_x,a_y,c_x,c_y);
	
	
	int ad_len = ab_len;
	int d_x = a_x;
	int d_y = a_y - ad_len;
//	line bd
//	setcolor(8);
//	line(b_x,b_y,d_x,d_y); 
	 
	int e_offset = sqrt((ab_len*ab_len)/2);
	int e_x = b_x - e_offset;
	int e_y = a_y - e_offset;
//	line be
	line(b_x,b_y,e_x,e_y);	
//	imaginary line from e to d
//	line(e_x,e_y,d_x,d_y);
	
	int f_x=a_x;
	int f_y=e_y;
	int g_x = b_x;
	int g_y = e_y;
//	imaginary line from f tp e
//	line(f_x,f_y,e_x,e_y);
//	line eg
	line(e_x,e_y,g_x,g_y);
//	line cg
	line(c_x,c_y,g_x,g_y);
	
	int h_len = ab_len/4;
	int h_x = a_x + h_len;
	int h_y = a_y;
//	imaginary line from h to max
//	line(h_x,h_y,h_x,0);
	
	int i_x = h_x;
	int i_y = intersectY(h_x,h_y,h_x,0,c_x,c_y,g_x,g_y);
	
	
	int cf_len = f_y + c_y;
	int j_x = a_x;
	int j_y = cf_len/2;
	
//	imaginary line jg
//	line(j_x,j_y,g_x,g_y);
//	setcolor(15);imaginary line from jk // to ab
//	line(j_x,j_y,getmaxx(),j_y);
	
	int k_x = intersectX(j_x,j_y,getmaxx(),j_y,c_x,c_y,g_x,g_y);
	int k_y = j_y;
//	circle(k_x,k_y,5);
	
	int l_x = intersectX(j_x,j_y,k_x,k_y,h_x,h_y,i_x,i_y);
	int l_y = intersectY(j_x,j_y,k_x,k_y,h_x,h_y,i_x,i_y);;
//	circle(l_x,l_y,5);
	
	int m_x = intersectX(j_x,j_y,g_x,g_y,h_x,h_y,i_x,i_y);
	int m_y = intersectY(j_x,j_y,g_x,g_y,h_x,h_y,i_x,i_y);
//	circle(m_x,m_y,5);
	
	int n_x = intersectX(b_x,b_y,d_x,d_y,h_x,h_y,i_x,i_y);
	int n_y = intersectY(b_x,b_y,d_x,d_y,h_x,h_y,i_x,i_y) - 20;
	
//	imaginary line o-inf // to AB
	int o_x = a_x;
	int o_y = m_y;
//	line(o_x,o_y,getmaxx(),o_y);
	
	
//	fpr moon
//	lower
	int ln_radius = dist(n_x,n_y,l_x,l_y) ;
	arc(l_x,l_y,180,360,ln_radius);

	int p_x = l_x - ln_radius + 4;
	int p_y = o_y ;
	int q_x = l_x + ln_radius - 4;
	int q_y = o_y;
	
	int mq_radius = dist(m_x, m_y, q_x,q_y);
	arc(m_x,m_y,180,360,mq_radius);
	
	int mn_radius = dist(m_x,m_y,n_x,n_y);
//	arc(n_x,n_y,0,180,mn_radius);
	
	int r_x = n_x - mn_radius + 2;
	int r_y = n_y - 5; 
	int s_x = n_x + mn_radius - 2;
	int s_y = n_y - 5;
	
//	line(r_x,r_y,s_x,s_y);	
	
	int t_x = intersectX(r_x,r_y,s_x,s_y,h_x,h_y,i_x,i_y);
	int t_y = intersectY(r_x,r_y,s_x,s_y,h_x,h_y,i_x,i_y);
	
	int ts_radius = dist(t_x,t_y,s_x,s_y);
	arc(t_x,t_y,0,180,ts_radius);
	
//	draw triangle on 



//	draw sun
	
	int af_len = dist(a_x,a_y,f_x,f_y);
	int u_x = a_x;
	int u_y = a_y - af_len/2;
	
	
//	line(u_x,u_y,getmaxx(),u_y);
	setcolor(BLACK);
	
	int v_x = intersectX(u_x,u_y,getmaxx(),u_y,d_x,d_y,b_x,b_y);
	int v_y = intersectY(u_x,u_y,getmaxx(),u_y,d_x,d_y,b_x,b_y);;
	
	
	int w_x = intersectX(n_x,h_y,i_x,i_y,u_x,u_y,v_x,v_y);
	int w_y = intersectY(n_x,h_y,i_x,i_y,u_x,u_y,v_x,v_y);
	
//	circle(w_x,w_y,mn_radius);
//	circle(w_x,w_y,ln_radius);
	
	int tri_height = ln_radius - mn_radius;
	
	float angle = 0;

	for(int i=0;i<12;i++){
		int tri_sm_x = w_x + mn_radius * cos(angle);
		int tri_sm_y = w_y + mn_radius * sin(angle);
		int tri_lg_x = w_x + ln_radius * cos(angle);
		int tri_lg_y = w_y + ln_radius * sin(angle);
		
		int prevX =  w_x + mn_radius * cos(angle - 120.1/PI);
		int prevY =  w_y + mn_radius * sin(angle - 120.1/PI);
		int nextX =  w_x + mn_radius * cos(angle + 120.1/PI);
		int nextY =  w_y + mn_radius * sin(angle + 120.1/PI);
		
		line(prevX,prevY,tri_lg_x,tri_lg_y);
		line(nextX,nextY,tri_lg_x,tri_lg_y);
		
		angle += 120.1/PI;
		putpixel(tri_lg_x,tri_lg_y,RED);

	}	
//	fillColor(w_x,w_y,BLACK,WHITE);
	fillColor(550,300,WHITE,RED);
//	border construction
	int border_length = dist(t_x,t_y,n_x,n_y) ;
	
	int tl_x = c_x - border_length;
	int tl_y = c_y - 2*border_length ;
	
	int bl_x = a_x - border_length;
	int bl_y = a_y + border_length;
	
	
	int br_x = b_x + 3*border_length;
	int br_y = b_y + border_length;
	
	int tl_d_x = c_x;
	int tr_x = g_x + 3*border_length ;
	int tr_y = g_y + border_length;
	
	int mr_x = e_x + 2*border_length;
	int mr_y = e_y + border_length;
		
	line(tl_x,tl_y,bl_x,bl_y);
	line(bl_x,bl_y,br_x,br_y);
	line(tl_x,tl_y,tr_x,tr_y);
	line(tr_x,tr_y,mr_x,mr_y);
	line(mr_x,mr_y,br_x,br_y);
	
	fillColor(498,402,WHITE,BLUE);

	
	
	delay(500);
}

