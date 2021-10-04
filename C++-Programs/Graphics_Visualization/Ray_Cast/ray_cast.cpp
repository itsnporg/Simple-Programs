#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<utility>
#include<vector>

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989

using namespace std;

void draw(void);
void setup(void);

int main() {
    setup();
    int page = 0;
    while (true) {
        setvisualpage(page);
        setactivepage(1 - page);
        cleardevice();

        draw();
        page = 1 - page;
    }
    getch();
}


void setup() {
    initwindow(1080, 720);
    printf("%d %d", getmaxx(), getmaxy());
}
POINT cursorPos;
float angle = 0;

class Boundry {
public:
    float x1, y1;
    float x2, y2;
    Boundry(float x1, float y1, float x2, float y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    void showBoundry() {
        line(x1, y1, x2, y2);
    }
};


class Ray {
    float translateX, translateY;
    float dirX, dirY;
    int radius = 20;

    vector < pair < pair < float, float >, pair< float, float > > > allRay;

public:
    Ray(float translateX, float translateY) {
        this->translateX = translateX;
        this->translateY = translateY;
    }
    void show() {
        float x, y;
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        circle(translateX, translateY, radius - 10);
        floodfill(translateX, translateY, WHITE);
        setcolor(WHITE);
        for (int i = 0;i <= 60;i++) {
            x = radius * cos(i);
            y = radius * sin(i);
            dirX = x;
            dirY = y;
            line(translateX, translateY, x + translateX, y + translateY);

            pair<float, float> dirPair;
            dirPair.first = dirX;
            dirPair.second = dirY;

            pair<float, float> translatePair;
            translatePair.first = translateX;
            translatePair.second = translateY;

            pair < pair < float, float >, pair < float, float > > ray;

            ray.first = translatePair;
            ray.second = dirPair;

            allRay.push_back(ray);
        }

    }
    void drawCircle(float x, float y) {
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        circle(x, y, 4);
        floodfill(x, y, RED);
    }

    vector < pair < float, float > > castAll(Boundry b) {
        vector < pair < float, float > > finalPoints;
        for (int i = 0;i < allRay.size();i++) {
            float x1 = b.x1;
            float y1 = b.y1;
            drawCircle(x1, y1);

            float x2 = b.x2;
            float y2 = b.y2;
            drawCircle(x2, y2);

            float x3 = allRay[i].first.first;
            float y3 = allRay[i].first.second;
            drawCircle(x3, y3);

            float x4 = allRay[i].second.first + x3;
            float y4 = allRay[i].second.second + y3;
            drawCircle(x4, y4);

            float deno = ((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4));

            pair<float, float> finalPoint;

            if (deno != 0) {
                float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / deno;
                float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / deno;
                if (t > 0 && t < 1 && u>0) {
                    finalPoint.first = x1 + t * (x2 - x1);
                    finalPoint.second = y1 + t * (y2 - y1);
                    finalPoints.push_back(finalPoint);
                }
            }
        }
        return finalPoints;
    }

    float calculateDistance(float x1, float y1, float x2, float y2) {
        float X = (x2 - x1) * (x2 - x1);
        float Y = (y2 - y1) * (y2 - y1);
        return sqrt(X + Y);
    }

    void castAllMultipleBoundries(vector<Boundry> boundries) {
        pair<float, float> finalPoint;
        pair<float, float> closestPoint;
        for (int i = 0;i < allRay.size();i++) {
            float currentDist = INT_MAX;
            for (int j = 0;j < boundries.size();j++) {
                float x1 = boundries[j].x1;
                float y1 = boundries[j].y1;
                drawCircle(x1, y1);
                float x2 = boundries[j].x2;
                float y2 = boundries[j].y2;
                drawCircle(x2, y2);

                float x3 = allRay[i].first.first;
                float y3 = allRay[i].first.second;

                float x4 = allRay[i].second.first + x3;
                float y4 = allRay[i].second.second + y3;

                float deno = ((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4));

                if (deno != 0) {
                    float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / deno;
                    float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / deno;
                    if (t > 0 && t < 1 && u>0) {
                        finalPoint.first = x1 + t * (x2 - x1);
                        finalPoint.second = y1 + t * (y2 - y1);
                        float distance = calculateDistance(translateX, translateY, finalPoint.first, finalPoint.second);
                        if (distance < currentDist) {
                            currentDist = distance;
                            setcolor(WHITE);
                            closestPoint = finalPoint;
                        }
                    }
                }
            }
            setcolor(WHITE);
            line(translateX, translateY, closestPoint.first, closestPoint.second);
            drawCircle(closestPoint.first, closestPoint.second);
        }
    }

};

void draw() {
    int lengthY = getmaxy();
    int lengthX = getmaxx();

    GetCursorPos(&cursorPos);

    int translateX = cursorPos.x;
    int translateY = cursorPos.y;

    Ray r(translateX, translateY);
    r.show();

    vector<Boundry> boundries;

    Boundry b1_(0, 0, getmaxx(), 0);
    b1_.showBoundry();
    boundries.push_back(b1_);

    Boundry b2_(0, 0, 0, getmaxy());
    b2_.showBoundry();
    boundries.push_back(b2_);

    Boundry b3_(0, getmaxy(), getmaxx(), getmaxy());
    b3_.showBoundry();
    boundries.push_back(b3_);

    Boundry b4_(getmaxx(), 0, getmaxx(), getmaxy());
    b4_.showBoundry();
    boundries.push_back(b4_);

    int length = 100;
    Boundry b5_(getmaxx() / 2 - length, getmaxy() / 2 - length, getmaxx() / 2 + length, getmaxy() / 2 - length);
    b5_.showBoundry();
    boundries.push_back(b5_);

    Boundry b6_(getmaxx() / 2 + length, getmaxy() / 2 + length, getmaxx() / 2 - length, getmaxy() / 2 + length);
    b6_.showBoundry();
    boundries.push_back(b6_);

    Boundry b7_(getmaxx() / 2 - length, getmaxy() / 2 - length, getmaxx() / 2 - length, getmaxy() / 2 + length);
    b7_.showBoundry();
    boundries.push_back(b7_);

    Boundry b8_(getmaxx() / 2 + length, getmaxy() / 2 - length, getmaxx() / 2 + length, getmaxy() / 2 + length);
    b8_.showBoundry();
    boundries.push_back(b8_);

    Boundry b9_(getmaxx() / 2 - length * 5, getmaxy() / 2 - length * 5, getmaxx() / 2 - length, getmaxy() / 2 + length);
    b9_.showBoundry();
    boundries.push_back(b9_);

    r.castAllMultipleBoundries(boundries);
    delay(0);
}








