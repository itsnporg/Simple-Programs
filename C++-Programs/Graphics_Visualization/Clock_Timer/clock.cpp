#include<iostream>
#include<vector>
#include<math.h>
#include<graphics.h>
#include<utility>
#include<conio.h>

using namespace std;

void setup(void);
void draw(void);
bool start_frame = true;
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
    initwindow(800, 800);
}

pair<float, float> polar_coordiate(int x, int y, float angle, int radius) {
    float p_x = x + radius * cos(angle);
    float p_y = y + radius * sin(angle);;
    return make_pair(p_x, p_y);
}

float angle_hr = -1 * M_PI / 2;
float angle_min = -1 * M_PI / 2;
float angle_sec = -1 * M_PI / 2;
int hour = 0;
int minute = 0;
int second = 0;
int flag = 0;
void draw() {
    int x = getmaxx() / 2;
    int y = getmaxy() / 2;
    int r = 270;

    int hr_len = 150;
    int min_len = 187;
    int sec_len = 225;


    pair<float, float> hr_xy = polar_coordiate(x, y, angle_hr, hr_len);
    setcolor(RED);
    line(x, y, hr_xy.first, hr_xy.second);
    circle(hr_xy.first, hr_xy.second, 5);
    // circle(x, y, hr_len);


    pair<float, float> min_xy = polar_coordiate(x, y, angle_min, min_len);
    setcolor(BLUE);
    line(x, y, min_xy.first, min_xy.second);
    circle(min_xy.first, min_xy.second, 5);
    // circle(x, y, min_len);

    pair<float, float> sec_xy = polar_coordiate(x, y, angle_sec, sec_len);
    setcolor(GREEN);
    line(x, y, sec_xy.first, sec_xy.second);
    circle(sec_xy.first, sec_xy.second, 5);
    // circle(x, y, sec_len);


    second++;
    angle_sec += M_PI / 30;
    if (second >= 60) {
        second = 0;
        minute++;
        angle_sec = -1 * M_PI / 2;
        angle_min += M_PI / 30;
    }
    if (minute >= 60) {
        minute = 0;
        second = 0;
        hour++;
        angle_min = -1 * M_PI / 2;
        angle_hr += M_PI / 30;
    }
    if (hour > 60) {
        hour = 0;
        minute = 0;
        second = 0;
        angle_hr = -1 * M_PI / 2;
    }

    setcolor(WHITE);
    circle(x, y, r / 25);

    float factor = 0.05;
    float inner_r = 1 + factor;
    float outer_r = 1 - factor;
    for (float i = 1;i < 1.1;i += 0.001) {
        circle(x, y, r * i);

    }
    // circle(x, y, r * 1.01);

    for (float angle = (-1 * M_PI / 2);angle < 3 * M_PI / 2 - M_PI / 30;angle += M_PI / 30) {
        pair<float, float> inner_xy = polar_coordiate(x, y, angle, r / inner_r);
        pair<float, float> outer_xy = polar_coordiate(x, y, angle, r / outer_r);
        line(inner_xy.first, inner_xy.second, outer_xy.first, outer_xy.second);
    }

    int delay_time = 0;
    if (start_frame) { delay_time = 0; start_frame = false; }
    else delay_time = 1000;

    delay(delay_time);
}

