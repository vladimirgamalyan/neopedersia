#include <stdlib.h>
#include "Pony.h"
#include "../World.h"

Pony::Pony()
{
    state = Still;
    target = nullptr;
    directionRight = true;
    hp = 100;
}

void Pony::update()
{
    if (isDead())
        return;

    if (state == Pass)
        return;

    if (state == Still)
    {
        // Random pos.
        //int fromX = x / Common::MAP_CELL_SIZE;
        //int fromY = y / Common::MAP_CELL_SIZE;
        Vec2 targetPos(rand() % (48 * 8), rand() % (48 * 8));

        // Get target.
//        target = world->getNearestTarget( x, y, 100000000, true );
//
//        if ( target )
//        {
//            toX = target->x / Common::MAP_CELL_SIZE + 2;
//            toY = target->y / Common::MAP_CELL_SIZE + 2;
//        }
//
        if (world->find(pos, targetPos, path) == 0)
        {
            state = Running;
            step = 0;
        }
    }

    if (state == Running)
    {
        // Target destroyed.
//        if ( target )
//        {
//            if ( target->isDead() )
//            {
//                state = Still;
//                return;
//            }
//        }
//        else
//        {
//            // Target appeared.
//            Unit* t = world->getNearestTarget( x, y, 100000000, true );
//            if ( t )
//            {
//                state = Still;
//                return;
//            }
//        }

        // Finish moving.
        if (step >= static_cast< int >( path.size()))
        {
            // Attack target.
            if (target)
            {
                state = Attack;
                //attackDelay = 0;
            }
            else
            {
                // Get new target.
                state = Still;
                return;
            }
        }
        else
        {
            // Move in progress.
            Vec2 t = path.at(step);

            //int targetX = path.at( step ).x * Common::MAP_CELL_SIZE;
            //int targetY = path.at( step ).y * Common::MAP_CELL_SIZE;

            if (pos.x < t.x)
            {
                pos.x++;
                directionRight = true;
            }
            if (pos.x > t.x)
            {
                pos.x--;
                directionRight = false;
            }
            if (pos.y < t.y)
            {
                pos.y++;
                directionRight = false;
            }
            if (pos.y > t.y)
            {
                pos.y--;
                directionRight = true;
            }

            if ((pos.x == t.x) && (pos.y == t.y))
            {
                step++;
            }
        }
    }

//    if ( state == Attack )
//    {
//        if ( !target )
//        {
//            state = Still;
//            return;
//        }
//
//        if ( target->isDead() )
//        {
//            state = Still;
//            return;
//        }
//
//        if ( attackDelay < getAttackDelay() )
//        {
//            attackDelay++;
//            return;
//        }
//
//        attackDelay = 0;
//        target->hit( getAttackPower() );
//    }
}

void Pony::render(const WorldPainter &worldPainter) const
{
    if (isDead())
    {
        worldPainter.draw(pos, "assets/pony/ponyDied.png");
        return;
    }
    if (directionRight)
        worldPainter.draw(pos, "assets/pony/ponyRight.png");
    else
        worldPainter.draw(pos, "assets/pony/ponyLeft.png");
}
