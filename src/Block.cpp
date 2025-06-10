//
// Created by User on 2025/06/09.
//
#include "Block.hpp"

Block::Block(const std::string& ImagePath,const Model::Block block): Floor(ImagePath),m_Block(block)
{

}

void Block::TimeUpdate(bool Ice)
{
    if (Ice)
    {
        lastTime = std::chrono::steady_clock::now();
    }
    else
    {
        lastUnTime=std::chrono::steady_clock::now();
    }
}

bool Block::ChangeIce()
{
    switch (m_Block)
    {
    case Model::Block::Fire:
        return lastTime-lastUnTime > cooldownTime;
    case Model::Block::Ice:
        return lastUnTime-lastTime > cooldownTime;
    case Model::Block::Melt:
        return lastTime-lastUnTime < cooldownTime;
    }
}

