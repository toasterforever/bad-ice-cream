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
        lastIceTime = std::chrono::steady_clock::now();
    }
    else
    {
        lastUnIceTime=std::chrono::steady_clock::now();
    }
}

bool Block::ChangeIce()
{
    switch (m_Block)
    {
    case Model::Block::Fire:
        return lastIceTime-lastUnIceTime > cooldownTime;
    case Model::Block::Ice:
        return lastUnIceTime-lastIceTime > cooldownTime;
    }
}

