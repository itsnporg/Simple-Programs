#include<iostream>
#include<vector>
#include<math.h>
#include<utility>
#include<graphics.h>
#include<conio.h>

using namespace std;

void setup(void);
void draw(void);

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

int collatz_congeture_val(int n) {
    if (n % 2 == 0) return n / 2;
    return 3 * n + 1;
}

void setup() {
    initwindow(1000, 1000);
}
float offset = 100;
void line_graph_collatz_conjecture(float val) {
    pair<float, float> origin = make_pair(offset, getmaxy() - offset);
    pair<float, float>value = make_pair(origin.first, origin.second - val);
    while (val > 1) {
        if (int(val) % 2 == 0) val = val / 2;
        else val = 3 * val + 1;

        float x = value.first;
        float y = value.second;

        value.first += 10;
        value.second = origin.second - val;
        line(x, y, value.first, value.second);
        circle(value.first, value.second, 2);
        line(origin.first, origin.second, origin.first, offset);
        line(origin.first, origin.second, getmaxx() - offset, origin.second);
    }
}

pair<float, float> rotate(float radius, float angle) {
    float x = radius * cos(angle);
    float y = radius * sin(angle);
    return make_pair(x, y);
}


void draw() {
    // float val = 100;
    float length_edge = 25;
    float angle = -1 * M_PI / 2;
    pair<float, float> origin = make_pair(offset, getmaxy() - offset);
    pair <float, float> node_center = make_pair((origin.first + getmaxx() - origin.first) / 2, origin.second);
    setcolor(15);
    circle(node_center.first, node_center.second, 10);
    int color = 1;
    for (int i = 2;i < 1000;i++) {
        int val = i;
        color = (color + 1) % 16;
        if (color == 0) color = 1;
        setcolor(color);
        while (val > 1) {
            float cur_x = node_center.first;
            float cur_y = node_center.second;

            if (int(val) % 2 == 0) {
                val = val / 2;
                angle -= 5;
                node_center.first += length_edge * cos(angle);
                node_center.second += length_edge * sin(angle);
            }
            else {
                val = 3 * val + 1;
                angle += 5;
                node_center.first += length_edge * cos(angle);
                node_center.second += length_edge * sin(angle);
            }
            angle = -1 * M_PI / 2;
            line(cur_x, cur_y, node_center.first, node_center.second);
            circle(node_center.first, node_center.second, 5);
        }
        node_center = make_pair((origin.first + getmaxx() - origin.first) / 2, origin.second);
    }
    delay(1);
}

