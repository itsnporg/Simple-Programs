#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
#define PI 3.14159265 


void sinewave() {
	int angle = 0;
	float y;
	int i;
	line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
	line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
	for (i = 0;i < 1440;i++) {
		if (i < 720) {
			y = 50 * sin((angle * PI) / 180);
			y = getmaxy() / 2 - y;
			putpixel(i - 6, y, LIGHTBLUE);
			angle++;
			delay(0);
		}
		else {
			y = 50 * sin((i * PI) / 180);
			y = getmaxy() / 2 - y;
			putpixel(i - 6, y, LIGHTBLUE);
			angle++;
			delay(0);
		}
	}
}

void cosinewave() {
	int angle = 0;
	float y;
	int i;
	line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
	for (i = 0;i < 1440;i++) {
		if (i < 720) {
			y = 50 * cos((angle * PI) / 180);
			y = getmaxy() / 2 - y;
			putpixel(i - 6, y, LIGHTGREEN);
			angle++;
			delay(1);
		}
		else {
			y = 50 * cos((i * PI) / 180);
			y = getmaxy() / 2 - y;
			putpixel(i - 6, y, LIGHTGREEN);
			angle++;
			delay(1);
		}
	}
}
void tangentwave() {
	int angle = 0;
	float y;
	int i;
	line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
	for (i = 0;i < 1440;i++) {
		if (i < 720) {
			y = 50 * tan((angle * PI) / 180);
			y = getmaxy() / 2 - y;
			putpixel(i - 6, y, CYAN);
			angle++;
			delay(1);
		}
		else {
			y = 50 * tan((i * PI) / 180);
			y = getmaxy() / 2 - y;
			putpixel(i - 6, y, CYAN);
			angle++;
			delay(1);
		}
	}
}

void cotecwave() {
	int angle = 0;
	float y;
	int i;

	line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
	line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
	for (i = 0;i < 1440;i++) {
		if (i < 720) {
			y = 50 * 1 / tan((angle * PI) / 180);
			y = getmaxy() / 2 - y;
			putpixel(i - 6, y, RED);
			angle++;
			delay(1);
		}
		else {
			y = 50 * 1 / tan((i * PI) / 180);
			y = getmaxy() / 2 - y;
			putpixel(i - 6, y, RED);
			angle++;
			delay(1);
		}
	}
}

void cosecantwave() {
	int angle = 0;
	float y;
	int i;

	line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
	line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
	for (i = 0;i < 1440;i++) {
		if (i < 720) {
			y = 50 * 1 / sin((angle * PI) / 180);
			y = getmaxy() / 2 - y;
			putpixel(i - 6, y, MAGENTA);
			angle++;
			delay(1);
		}
		else {
			y = 50 * 1 / sin((i * PI) / 180);
			y = getmaxy() / 2 - y;
			putpixel(i - 6, y, MAGENTA);
			angle++;
			delay(1);
		}
	}

}
void secantwave() {
	int angle = 0;
	float y;
	int i;
	line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
	line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
	for (i = 0;i < 1440;i++) {
		if (i < 720) {
			y = 50 * 1 / cos((angle * PI) / 180);
			y = getmaxy() / 2 - y;
			putpixel(i - 6, y, YELLOW);
			angle++;
			delay(1);
		}
		else {
			y = 50 * 1 / cos((i * PI) / 180);
			y = getmaxy() / 2 - y;
			putpixel(i - 6, y, YELLOW);
			angle++;
			delay(1);
		}
	}

}

int main() {
	initwindow(1440, 1080);
	cout << "Drawing SIne Wave!!!!" << endl;
	sinewave();
	cout << "nDrawing Cosine Wave!!!!";
	cosinewave();
	cout << "nDrawing Tangent Wave!!!!" << endl;
	tangentwave();
	cout << "nDrawing Cotec Wave!!!!" << endl;
	cotecwave();
	cout << "nDrawing Cosecant Wave!!!!" << endl;
	cosecantwave();
	cout << "nDrawing Secant Wave!!!!" << endl;
	secantwave();
	cout << "nAll Waves Drawn!!!!!" << endl;
	//	menu();
	getch();
}
