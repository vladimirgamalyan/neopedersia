#pragma once

#include "Vec2.h"
#include <vector>
#include "micropather.h"
#include "Config.h"
#include "worldObjects/WorldObjectId.h"

class PathFinder : public micropather::Graph
{
public:
    WorldObjectId cells[Config::World::WIDTH_CELL][Config::World::HEIGHT_CELL];

	//bool isPointEmpty( int x, int y ) const;

	int find(const Vec2& from, const Vec2& to, std::vector<Vec2>& path);

private:
	virtual float LeastCostEstimate( void* stateStart, void* stateEnd );
	virtual void AdjacentCost( void* state, std::vector< micropather::StateCost > *adjacent );
	virtual void PrintStateInfo( void* state );
	Vec2 NodeToPoint(void* node);
	void* PointToNode(const Vec2& point);
	bool passable( int nx, int ny );
};
