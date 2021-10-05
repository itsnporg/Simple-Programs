#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<vector>
#include<utility>

using namespace std;
void draw(void);
void setup(void);


POINT e;
float prevX = INT_MAX, prevY = INT_MAX;
bool firstIteration = true;


struct Edge {
	pair<float, float> start;
	pair<float, float> end;
	float cost;
};

vector<Edge> edgePool;


int main() {
	system("cls");
	setup();
	int page = 0;
	while (true)
	{
		setvisualpage(page);
		setactivepage(1 - page);
		cleardevice();
		draw();
		page = 1 - page;
	}
}


void setup() {
	initwindow(1080, 720);
	printf("%d %d", getmaxx(), getmaxy());
}


void drawJoinCircles(pair<float, float> startPt, pair<float, float> endPt, float cost) {

	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	circle(startPt.first, startPt.second, 10);
	floodfill(startPt.first, startPt.second, WHITE);

	if (startPt != endPt) {
		line(startPt.first, startPt.second, endPt.first, endPt.second);

		int c = cost;
		char d[100];
		sprintf(d, "%d", c);

		outtextxy((startPt.first + endPt.first) / 2, (startPt.second + endPt.second) / 2, d);
	}


}

float distance(float x1, float y1, float x2, float y2) {
	float X = (x1 - x2) * (x1 - x2);
	float Y = (y1 - y2) * (y1 - y2);
	return sqrt(X + Y);
}

void draw() {
	char* c = "Click Anywhere to Place Point";
	settextstyle(2, 0, 7);
	outtextxy(10, 10, c);

	GetCursorPos(&e);
	if (GetAsyncKeyState(VK_LBUTTON)) {
		struct Edge edge;

		pair<float, float> startPoints;

		if (firstIteration) {
			startPoints.first = e.x;
			startPoints.second = e.y;

			edge.start = startPoints;
			edge.end = startPoints;
			edge.cost = 0;

			edgePool.push_back(edge);

			drawJoinCircles(startPoints, startPoints, edge.cost);
		}
		else {
			pair<float, float> endPoints;

			endPoints.first = e.x;
			endPoints.second = e.y;
			edge.end = endPoints;

			float currentCost;
			float minCost = INT_MAX;

			for (int i = 0;i < edgePool.size();i++) {
				currentCost = distance(edgePool[i].end.first, edgePool[i].end.second, endPoints.first, endPoints.second);
				if (currentCost < minCost) {
					minCost = currentCost;
					startPoints.first = edgePool[i].end.first;
					startPoints.second = edgePool[i].end.second;
				}
			}
			edge.start = startPoints;
			edgePool.push_back(edge);
			drawJoinCircles(endPoints, startPoints, minCost);
		}
		firstIteration = false;
	}
	delay(1);
}



