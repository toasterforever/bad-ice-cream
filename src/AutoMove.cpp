//
// Created by User on 2025/05/09.
//

#include "Enemies.hpp"
#include "Namespace_Model.hpp"
#include <random>
struct State
{
    int x,y;
    Model::Direction dir;
    int steps;
    int turns;
    Model::Direction FirstDir;
    State operator+(const State& s) const
    {
        return State{x+s.x,y+s.y,s.dir,steps+1,turns,FirstDir};
    }
};
Model::Direction Enemies::AutoMove(glm::vec2 MainPosition)
{
    std::vector<std::pair<int,int>> DirMove = {
        {0,-1},
        {0,1},
        {-1,0},
        {1,0}
    };
    auto Dir     = {Model::Direction::Up,Model::Direction::Down,Model::Direction::Left,Model::Direction::Right};
    Model::Direction dirNow = GetDirection();
    bool visited[10][10][4];
    std::vector<State> MoveAndTurn;
    State current={int(MainPosition.x),int(MainPosition.y),dirNow,0,0,Model::Direction::None};
    MoveAndTurn.push_back(current);
    for (auto dir :Dir)
    {
        for (auto Now : MoveAndTurn)
        {
            State Next=Now;
            if (dir!=dirNow&&dirNow!=Model::Direction::None)
            {
                Next.turns=Now.turns+1;
            }
            if (TowardHasThings(dir)&&!visited[Now.x][Now.y][static_cast<int>(dir)])
            {
                visited[Now.x][Now.y][static_cast<int>(dir)]=true;
                switch (dir)
                {

                    case Model::Direction::Up:

                        if (Now.FirstDir == Model::Direction::None)
                        {
                            Next=Now+ State {DirMove[0].first,DirMove[0].second,Model::Direction::Up,0,0,dir};
                        }
                        else
                        {
                            Next=Now+ State {DirMove[0].first,DirMove[0].second,Model::Direction::Up,0,0,Now.FirstDir};
                        }
                        MoveAndTurn.push_back(Next);
                    break;
                    case Model::Direction::Down:

                        if (Now.FirstDir == Model::Direction::None)
                        {
                            Next=Now+ State {DirMove[1].first,DirMove[1].second,Model::Direction::Down,0,0,dir};
                        }
                        else
                        {
                            Next=Now+ State {DirMove[1].first,DirMove[1].second,Model::Direction::Down,0,0,Now.FirstDir};
                        }
                        MoveAndTurn.push_back(Next);
                    break;
                    case Model::Direction::Left:
                        if (Now.FirstDir == Model::Direction::None)
                        {
                            Next=Now+ State {DirMove[2].first,DirMove[2].second,Model::Direction::Left,0,0,dir};
                        }
                        else
                        {
                            Next=Now+ State {DirMove[2].first,DirMove[2].second,Model::Direction::Left,0,0,Now.FirstDir};
                        }
                        MoveAndTurn.push_back(Next);
                    break;
                    case Model::Direction::Right:
                        if (Now.FirstDir == Model::Direction::None)
                        {
                            Next=Now+ State {DirMove[3].first,DirMove[3].second,Model::Direction::Right,0,0,dir};
                        }
                        else
                        {
                            Next=Now+ State {DirMove[3].first,DirMove[3].second,Model::Direction::Right,0,0,Now.FirstDir};
                        }
                        MoveAndTurn.push_back(Next);

                    break;

                }
            }
        }
    }
    std::vector<State> Maybe;
    int minTurns,minSteps;
    for (auto Now : MoveAndTurn)
    {
        if (Now.x==MainPosition.x&&Now.y==MainPosition.y)
        {
            if (Maybe.empty())
            {
                minTurns=Now.turns;
                minSteps=Now.steps;
                Maybe.push_back(Now);
            }
            else
            {
                if (Now.turns<minTurns)
                {
                    minTurns=Now.turns;
                    minSteps=Now.steps;
                    Maybe.clear();
                    Maybe.push_back(Now);
                }
                else if (Now.turns==minTurns)
                {
                    if (Now.steps<minSteps)
                    {
                        minTurns=Now.turns;
                        minSteps=Now.steps;
                        Maybe.clear();
                        Maybe.push_back(Now);
                    }
                    else if (Now.steps==minSteps)
                    {
                        Maybe.push_back(Now);
                    }
                }
            }

        }
    }


    if (Maybe.empty())
    {
        return GetRandomDirection();
    }
    else
    {
        return Maybe[rand() % Maybe.size()].FirstDir;
    }

}