#include<iostream>
#include<vector>
#include<utility>
#include<math.h>
#include<graphics.h>
#define  TOTAL_POINTS 200

using namespace std;



void setup(void);
void draw(void);
float factor = 1;
int color = 15;
bool auto_play = true;
// int frame = 0;


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

void fill_circle(int x, int y, int radius) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    circle(x, y, radius);
    floodfill(x, y, color);
}
void setup() {
    float x = 10;
    int y = x + 1;
    cout << y % 10 << endl;
    initwindow(1000, 1000);
}

float map(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) / (in_max - in_min) * (out_max - out_min) + out_min;
}
void display_factor() {
    string s = to_string(factor);
    char factor_float[10];
    snprintf(factor_float, sizeof(factor_float), "%0.2f", factor);
    char factor_txt[100];
    strcpy(factor_txt, "Factor: ");
    strcat(factor_txt, factor_float);

    settextstyle(2, 0, 15);
    outtextxy(10, 10, factor_txt);

}
void display_instruction() {
    char* c = "Press Space to Autoplay";
    char* c1 = "Press Arrow Keys to Pause";
    char* c2 = "Arrow Keys -> Increase / Decrease Factor";
    settextstyle(2, 0, 7);
    outtextxy(10, 80, c);

    settextstyle(2, 0, 7);
    outtextxy(10, 110, c1);

    settextstyle(2, 0, 7);
    outtextxy(10, 140, c2);

    settextstyle(2, 0, 7);
}
void draw() {

    int radius = 400;

    int T_X = getmaxx() / 2;
    int T_Y = getmaxy() / 2;
    circle(T_X, T_Y, radius);
    // circle(T_X, T_Y, radius);
    vector<pair<float, float>> Points;
    for (int i = 0;i < TOTAL_POINTS;i++) {
        float angle = map(i, 0, TOTAL_POINTS, 0, 2 * M_PI);
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        pair<float, float> point = make_pair(T_X + x, T_Y + y);
        Points.push_back(point);
        fill_circle(T_X + x, T_Y + y, 2);
    }


    display_factor();
    display_instruction();



    for (int i = 0;i < TOTAL_POINTS;i++) {
        int idx = fmod(i * factor, TOTAL_POINTS);
        line(Points[i].first, Points[i].second, Points[idx].first, Points[idx].second);
    }

    if (GetAsyncKeyState(VK_SPACE))  auto_play = true;

    if (auto_play) {
        factor = factor + 0.01;
    }
    if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_RIGHT)) { factor = factor + 0.01; auto_play = false; }

    if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(VK_LEFT)) { factor = factor - 0.01; auto_play = false; }



    if (factor < 1) factor = 1;
    delay(1);
}

