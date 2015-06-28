#pragma once

#include "Point.h"
#include <vector>
#include "micropather.h"

class PathFinder : public micropather::Graph
{
public:
    static const int MAP_WIDTH = 64;
    static const int MAP_HEIGHT = 64;
	typedef int MapCell;
	MapCell cells[MAP_WIDTH][MAP_HEIGHT];

	//bool isPointEmpty( int x, int y ) const;

	// Найти маршрут (результат сбрасывается в Path).
	int find(const Point& from, const Point& to, std::vector<Point>& path);

private:
	virtual float LeastCostEstimate( void* stateStart, void* stateEnd );
	virtual void AdjacentCost( void* state, std::vector< micropather::StateCost > *adjacent );
	virtual void PrintStateInfo( void* state );
    Point NodeToPoint(void* node);
	void* PointToNode(const Point& point);
	bool passable( int nx, int ny );
};
