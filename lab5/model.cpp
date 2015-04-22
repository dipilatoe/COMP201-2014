#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
    Coordinate head;
    Coordinate tail;
    direction = RIGHT;
    head.x = 1;
    head.y = 0;
    tail.x = 0;
    tail.y = 0;
    food.x = 5;
    food.y = 10;
    snake.push_front(head);
    snake.push_back(tail);
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}

bool Model::gameOver() {
    return snake.empty() || snake.size() == width * height;
}

// Which way should the snake face?
void Model::go(Direction d) {
    direction = d;
}

// Move forward
void Model::crawl() {
    Coordinate front = snake.front();
    switch(direction) {
    case UP: front.y--; break;
    case DOWN: front.y++; break;
    case LEFT: front.x--; break;
    case RIGHT: front.x++; break;
    }
    
	if ((front.x > 48 || front.x < 0 || front.y > 48 || front.y < 0)) {
		direction = DEAD;
	}
	
	//TODO: set direction to DEAD if snake touches itself
	for (int x = 0; x < snake.size(); x++) {
		if (front.y == snake[x].y && front.x == snake[x].x) {
			direction = DEAD;
		}
	}
    
    if (direction != DEAD) {
        snake.push_front(front);
    }

	if (front.x == food.x && front.y == food.y) {
		srand (time(NULL));
		food.x = rand() % 48 + 1;
		food.y = rand() % 48 + 1;
	}
	else {
		snake.pop_back();
	}    
}
