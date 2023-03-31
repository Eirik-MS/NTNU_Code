#include "MinesweeperWindow.h"
#include <iostream>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines}
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp); 
		}
	}
	//legg til miner et tilfeldig sted paa brettet
	for (int i = 0; i < mines; ++i) {
		int x = rand() % width;
		int y = rand() % height;
		at(Point{ x * cellSize, y * cellSize })->setIsMine(true);
	}
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	int tileNr = xy.x / (cellSize) + (xy.y / cellSize) * width;
	if (tiles.at(tileNr)->getState() == Cell::closed) {
		tiles.at(tileNr)->open();
	}
	if (!at(xy)->getIsMine()) {
		int adjMines = countMines(adjacentPoints(xy));
		at(xy)->setAdjMines(adjMines);
		if (adjMines == 0) {
			for (Point p : adjacentPoints(xy)) {
				openTile(p);
			}
		}
	}
	else {
		// Game over
		for (auto &tile : tiles) {
			tile->open();
		}
	}
		
}

void MinesweeperWindow::flagTile(Point xy) {
	int tileNr = xy.x / (cellSize) + (xy.y / cellSize) * width;
	if (tiles.at(tileNr)->getState() != Cell::open) {
		tiles.at(tileNr)->flag();
	}
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	
	Point xy{this->get_mouse_coordinates()};
	std::cout << xy.x << " " << xy.y <<": " << xy.x / (cellSize) + (xy.y / cellSize) * width<<"\n";

	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down()) {
		openTile(xy);
	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}
}

int MinesweeperWindow::countMines(vector<Point> coords) const {
	int count = 0;
	
	for (Point p : coords) {
		if (at(p)->getIsMine()) {
			++count;
		}
	}
	return count;
}
