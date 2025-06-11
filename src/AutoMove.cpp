//
// Created by User on 2025/05/09.
//

#include "Enemies.hpp"
#include "Namespace_Model.hpp"
#include <random>

#include "spdlog/spdlog.h"
#include "Util/Logger.hpp"

// // Model::Direction Enemies::AutoMove(glm::vec2 MainPosition)
// // {
// //     return GetRandomDirection();
// // }
// struct State
// {
//     float x,y;
//     Model::Direction dir;
//     int steps;
//     int turns;
//     Model::Direction FirstDir;
//     std::vector<Model::Direction> Dirs;
//     State operator+(const State& s) const
//     {
//         std::vector<Model::Direction>dirs;
//         dirs = this->Dirs;
//         dirs.push_back(this->dir);
//         int newturns =this->turns;
//         if(this->dir!=s.dir&&this->dir!=Model::Direction::None){
//             newturns+=1;
//         }
//         if(FirstDir==Model::Direction::None){
//             FirstDir;
//         }
//         return State{x+s.x,y+s.y,s.dir,steps+1,newturns,FirstDir,dirs};
//     }
// };
//
// void LOGState(State z)
// {
//     LOG_INFO(z.x);
//     LOG_INFO(z.y);
//     LOG_INFO(Model::DirToStr(z.dir));
//     LOG_INFO(z.turns);
//     LOG_INFO(z.steps);
//     LOG_INFO(Model::DirToStr(z.FirstDir));
// }
//
// bool Enemies::AutoMoveTest(Model::Direction Now,Model::Direction New, glm::vec2 NowPos)
// {
//     if (
//                 (New==Model::Direction::Up&&NowPos.y==1)||
//                 (New==Model::Direction::Down&&NowPos.y==10)||
//                 (New==Model::Direction::Left&&NowPos.x==1)||
//                 (New==Model::Direction::Right&&NowPos.x==10)
//                 )
//     {
//         return true;
//     }
//     if (Now==Model::Direction::Up&&New==Model::Direction::Down)
//     {
//         return true;
//     }
//     if (Now==Model::Direction::Down&&New==Model::Direction::Up)
//     {
//         return true;
//     }
//     if (Now==Model::Direction::Left&&New==Model::Direction::Right)
//     {
//         return true;
//     }
//     if (Now==Model::Direction::Right&&New==Model::Direction::Left)
//     {
//         return true;
//     }
//     return false;
// }
//
// Model::Direction Enemies::AutoMove(glm::vec2 MainPosition)
// {
//
//     auto Dir     = {Model::Direction::Up,Model::Direction::Down,Model::Direction::Left,Model::Direction::Right};
//
//     bool visited[10][10][4]={};
//     std::vector<State> MoveAndTurn;
//     State current={float(GetI()),float(GetJ()),GetDirection(),0,0,GetDirection()};
//     MoveAndTurn.push_back(current);
//
//     std::vector<State> Maybe;
//     int minSteps;
//
//     for (int i = 0; i < MoveAndTurn.size(); ++i)
//     {
//         State Now=MoveAndTurn[i];
//
//         for (auto dir :Dir)
//         {
//
//             State Next=Now;
//
//             if (visited[int(Now.x)-1][int(Now.y)-1][Model::DirToNum(dir)]==true)
//             {
//                 continue;
//             }
//             visited[int(Now.x)-1][int(Now.y)-1][Model::DirToNum(dir)]=true;
//
//             if (AutoMoveTest(Now.dir,dir,glm::vec2{Now.x,Now.y}))
//             {
//                 continue;
//             }
//             if (Next.FirstDir == Model::Direction::None)
//             {
//                 Next.FirstDir=dir;
//
//             }
//
//             Next=Next+ State {Model::DirToPos(dir).x,Model::DirToPos(dir).y,dir,0,0,Now.FirstDir,{}};
//             if (Next.x==MainPosition.x&&Next.y==MainPosition.y)
//             {
//                 if (Maybe.empty())
//                 {
//                     minSteps=Next.steps;
//                 }
//                 else if (minSteps>Next.steps)
//                 {
//                     Maybe.clear();
//                     minSteps=Next.steps;
//                 }
//                 Maybe.push_back(Next);
//                 MoveAndTurn.push_back(Next);
//             }
//             else if (!TowardHasThings(Next.x,Next.y)&&Maybe.empty())
//             {
//                 MoveAndTurn.push_back(Next);
//             }
//
//         }
//
//     }
//     for (auto Now : MoveAndTurn){};
//     for (auto Now : Maybe){};
//     // for (auto Now : MoveAndTurn)
//     // {
//     //     if (Now.x < 1 || Now.x > 10 || Now.y < 1 || Now.y > 10)
//     //     {
//     //
//     //         continue;
//     //     }
//     //     if (Now.x==MainPosition.x&&Now.y==MainPosition.y)
//     //     {
//     //         LOGState(Now);
//     //         if (Maybe.empty())
//     //         {
//     //             minSteps=Now.steps;
//     //             Maybe.push_back(Now);continue;
//     //         }
//     //
//     //         if (Now.steps<minSteps){
//     //
//     //                 minSteps=Now.steps;
//     //                 Maybe.clear();
//     //                 Maybe.push_back(Now);
//     //         }
//     //         else if (Now.steps==minSteps)
//     //         {
//     //             Maybe.push_back(Now);
//     //         }
//     //
//     //     }
//     // }
//     //
//     // for (auto Now :Maybe)
//     // {
//     //     LOG_DEBUG(DirToStr(Now.dir));
//     //
//     // }
//     std::cout<<std::endl;
//     if (Maybe.empty())
//     {
//         LOG_DEBUG("None\n");
//         return Model::Direction::None;
//         // return GetRandomDirection();
//     }
//     else
//     {
//         return Maybe[rand() % Maybe.size()].FirstDir;
//     }
//
// }