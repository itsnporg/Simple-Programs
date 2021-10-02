#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>
 
using namespace std;


int main(){
	int length=500;
	float angle=45;
	float aVel=0.0;
	float aAcel=0.0;
	sf::RenderWindow window(sf::VideoMode(800,600),"hello");
	//rectangle
	
	//circle
	sf::CircleShape circle;
	circle.setFillColor(sf::Color::Red);
	circle.setRadius(32);
	
	bool running=true;
	while(running){
		sf::Event event;
		if(window.pollEvent(event)){
			if(event.type==sf::Event::Closed){
				running=false;
			}
		}
		
		float x=400+length*sin(angle);
		float y=length*cos(angle);
		sf::Vertex line[] =
		{
		sf::Vertex(sf::Vector2f(400, 0)),
		sf::Vertex(sf::Vector2f(x, y))
		};
		circle.setPosition(x-32,y-16);
		cout <<x,y;
		 
		window.clear();
		window.draw(line,2,sf::Lines);
		window.draw(circle);
		window.display();
		aAcel=-0.0001*sin(angle);
		angle+=aVel;
		aVel+=aAcel;
		aVel*=0.9999;
		 
	}
	return EXIT_SUCCESS;

}
