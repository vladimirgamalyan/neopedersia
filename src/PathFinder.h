#pragma once

#include "Vec2.h"
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
	int find(const Vec2& from, const Vec2& to, std::vector<Vec2>& path);

private:
	virtual float LeastCostEstimate( void* stateStart, void* stateEnd );
	virtual void AdjacentCost( void* state, std::vector< micropather::StateCost > *adjacent );
	virtual void PrintStateInfo( void* state );
	Vec2 NodeToPoint(void* node);
	void* PointToNode(const Vec2& point);
	bool passable( int nx, int ny );
};
