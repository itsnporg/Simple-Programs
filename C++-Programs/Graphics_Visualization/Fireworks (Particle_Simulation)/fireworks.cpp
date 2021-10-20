#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<vector>

using namespace std;


template<typename T,typename U>
pair<T,U> add_pair(pair<T,U> & p1, pair<T,U> & p2){
	return make_pair(p1.first+p2.first,p1.second+p2.second);
}

template<typename T,typename U,typename V>
pair<T,U> multiply_pair(pair<T,U> & p1, V value){
	return make_pair(p1.first*value,p1.second*value);
}


int random(int low,int big){
	return rand()%((big-low)+1)+low;
}

class Particle{
	public:
		pair<int,int> position;
		pair<int,int> acceleration;
		pair<int,int> velocity;
		bool firework;
		int lifeSpan = 15;
	public:
		Particle(){}
		Particle(int x, int y,bool firework){
			this->firework = firework;
			this->position = make_pair(x,y);
			//rand() % ((bigger - lower)+1)+lower				
			if(firework){
				this->velocity = make_pair(0,random(-35,-15));				
			}
			else{
				this->velocity = make_pair(random(-10,10),random(-35,-15));
			}
			this->acceleration = make_pair(0,0);
		}
		
		void applyForce(pair<int,int> force){
			acceleration = add_pair(acceleration, force);
		}
		void update(){
			if(!firework){
				velocity = multiply_pair(velocity,1);
				lifeSpan-=1;
			}
			
			velocity = add_pair(velocity, acceleration);
			position = add_pair(position, velocity);
			acceleration = multiply_pair(acceleration, 0);
		}
		
		void show(){
			if(!firework){
				setcolor(lifeSpan);
				setfillstyle(SOLID_FILL,lifeSpan);
				circle(position.first,position.second,2);
				floodfill(position.first,position.second,lifeSpan);	
			}
			else{
				setcolor(WHITE);
				setfillstyle(SOLID_FILL,WHITE);
				circle(position.first,position.second,3);
				floodfill(position.first,position.second,WHITE);	
			}
		}
		
		bool done(){
			return lifeSpan <= 0;			
		}
};

pair<float,float> gravity;

class Firework{
	Particle firework;
	vector<Particle> particles;
	bool exploded = false;
	public:
		Firework(){
			firework = Particle(rand()%getmaxx(),getmaxy(),true);
		}
		void explode(){
			for(int i=0;i<100;i++){
				Particle p = Particle(firework.position.first,firework.position.second,false);
				particles.push_back(p);
			}
		}
		
		void update(){
			if(!exploded){
				firework.applyForce(gravity);
				firework.update();
				if(firework.velocity.second >=0){
					exploded = true;
					explode();			
				}	
			}
			for(int i=particles.size()-1;i>=0;i--){
				particles[i].applyForce(gravity);
				particles[i].update();
				
				if(particles[i].done()){
					particles.erase(particles.begin()+i);
				}
			}			
		}
		
		void show(){
			if(!exploded){
				firework.show();	
			}
			for(int i=0;i<particles.size();i++){
				particles[i].show();
			}
			
		}
};

void draw(void);
void setup(void);

vector<Firework> fireworks;


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
	printf("%d %d",getmaxx(),getmaxy());
	gravity = make_pair(0,1);
}

void draw(){
	
		if(random(1,2)==1){
			fireworks.push_back(Firework());	
		}
		
		for(int i=0;i<fireworks.size();i++){
			
			fireworks[i].update();
			fireworks[i].show();
		}
		
		delay(1);
}
