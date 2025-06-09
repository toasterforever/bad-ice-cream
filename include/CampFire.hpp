//
// Created by User on 2025/06/09.
//

#ifndef CAMPFIRE_HPP
#define CAMPFIRE_HPP

#include "floor.hpp"
#include <chrono>
class CampFire : public Floor {
public:
    explicit CampFire(const std::string& ImagePath);
    void ImageUpdate(int count);
    void TimeUpdate(bool Ice);

    void SetFired(bool const Fired){fired=Fired;}
    bool GetFired(){return fired;}

private:
    std::chrono::steady_clock::time_point lastIceTime;  // 記錄上次創建冰的時間
    std::chrono::steady_clock::time_point lastUnIceTime;  // 記錄上次按按鈕的時間
    const std::chrono::milliseconds cooldownTime{3000};
    const std::chrono::milliseconds cooldownTimeReady{2000};
    std::string m_ImagePath;
    bool fired = false;
};

#endif //CAMPFIRE_HPP
