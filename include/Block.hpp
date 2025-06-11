//
// Created by User on 2025/06/09.
//

#ifndef BLOCK_HPP
#define BLOCK_HPP
#include "floor.hpp"
#include <chrono>
class Block : public Floor {
public:
    explicit Block(const std::string& ImagePath,Model::Block block);

    void TimeUpdate(bool Ice);

    bool ChangeIce();

    void ResetTimer()
    {
        lastTime=std::chrono::steady_clock::now();
        lastUnTime=std::chrono::steady_clock::now();
    }
    void ChangeUpdate(bool Ice)
    {
        Update=Ice;
    }
    bool GetUpdate()
    {
        return Update;
    }
private:

    std::chrono::steady_clock::time_point lastTime;  // 記錄上次創建冰的時間
    std::chrono::steady_clock::time_point lastUnTime;  // 記錄上次按按鈕的時間
    const std::chrono::milliseconds cooldownTime{2000};
    std::string m_ImagePath;
    Model::Block m_Block;
    bool Update=false;
};
#endif //BLOCK_HPP
