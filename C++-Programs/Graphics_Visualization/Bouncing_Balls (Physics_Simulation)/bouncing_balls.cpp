#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<vector>
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989
#define BOUNDRY_OFFSET 50



using namespace std;

void draw(void);
void setup(void);



struct Point {
	float x;
	float y;
	float old_x;
	float old_y;
	int id;
};

struct Stick {
	Point p0;
	Point p1;
	float length;
};
int max_width = getmaxx() - BOUNDRY_OFFSET;
int max_height = getmaxy() - BOUNDRY_OFFSET;
int min_width = BOUNDRY_OFFSET;
int min_height = BOUNDRY_OFFSET;
int size = 10;

vector<Point> points;
float bounce = 0.9;
float gravity = 0.99;
float friction = 0.999;

float distance_pt(Point p0, Point p1) {
	float dx = p0.x - p1.x;
	float dy = p0.y - p1.y;
	return sqrt(dx * dx + dy * dy);
}

void draw_boundry() {
	setcolor(2);
	line(BOUNDRY_OFFSET, BOUNDRY_OFFSET, getmaxx() - BOUNDRY_OFFSET, BOUNDRY_OFFSET);
	line(BOUNDRY_OFFSET, getmaxy() - BOUNDRY_OFFSET, getmaxx() - BOUNDRY_OFFSET, getmaxy() - BOUNDRY_OFFSET);
	line(BOUNDRY_OFFSET, BOUNDRY_OFFSET, BOUNDRY_OFFSET, getmaxy() - BOUNDRY_OFFSET);
	line(getmaxx() - BOUNDRY_OFFSET, BOUNDRY_OFFSET, getmaxx() - BOUNDRY_OFFSET, getmaxy() - BOUNDRY_OFFSET);
	setcolor(15);
}

int main() {
	setup();
	Point p1 = { 100, 100, 95, 95, 1 };

	Point p2 = { 200, 100, 200, 100, 2 };

	points.push_back(p1);
	points.push_back(p2);


	int page = 0;
	int i = 0;
	while (true) {
		setvisualpage(page);
		setactivepage(1 - page);
		cleardevice();
		draw_boundry();
		draw();
		page = 1 - page;
		i++;
	}
	getch();
}


void update_points() {
	for (int i = 0;i < points.size();i++) {
		float vel_x = friction * (points[i].x - points[i].old_x);
		float vel_y = friction * (points[i].y - points[i].old_y);

		points[i].old_x = points[i].x;
		points[i].old_y = points[i].y;
		points[i].x += vel_x;
		points[i].y += vel_y;
		points[i].y += gravity;

	}
}

void constrainPoints() {
	for (int i = 0; i < points.size(); i++) {
		float vx = (points[i].x - points[i].old_x) * friction;
		float vy = (points[i].y - points[i].old_y) * friction;

		if (points[i].x > getmaxx() - BOUNDRY_OFFSET) {
			points[i].x = getmaxx() - BOUNDRY_OFFSET - size;
			points[i].old_x = points[i].x + vx * bounce;
		}
		else if (points[i].x < BOUNDRY_OFFSET) {
			points[i].x = BOUNDRY_OFFSET + size;
			points[i].old_x = points[i].x + vx * bounce;
		}
		if (points[i].y > getmaxy() - BOUNDRY_OFFSET) {
			points[i].y = getmaxy() - BOUNDRY_OFFSET - size;
			points[i].old_y = points[i].y + vy * bounce;
		}
		else if (points[i].y < BOUNDRY_OFFSET) {
			points[i].y = BOUNDRY_OFFSET + size;
			points[i].old_y = points[i].y + vy * bounce;
		}
	}
}

void render_points() {
	for (int i = 0;i < points.size();i++) {
		circle(int(points[i].x), int(points[i].y), size);
	}
}

void setup() {
	initwindow(1080, 720);
	cout << getmaxx() << " " << getmaxy();
}

void draw() {
	update_points();
	constrainPoints();
	render_points();
	delay(1);
}
