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
        lastIceTime=std::chrono::steady_clock::now();
        lastUnIceTime=std::chrono::steady_clock::now();
    }
private:

    std::chrono::steady_clock::time_point lastIceTime;  // 記錄上次創建冰的時間
    std::chrono::steady_clock::time_point lastUnIceTime;  // 記錄上次按按鈕的時間
    const std::chrono::milliseconds cooldownTime{3000};
    std::string m_ImagePath;
    Model::Block m_Block;
};
#endif //BLOCK_HPP
