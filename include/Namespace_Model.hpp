//
// Created by User on 2025/04/10.
//

#ifndef NAMESPACE_MODEL_HPP
#define NAMESPACE_MODEL_HPP

#include <string>
#include "Util/Input.hpp"


inline int cellSize=60;
inline std::vector<std::string> Map = {
    "############",//0
    "#..........#",//1
    "#..........#",//2
    "#..........#",//3
    "#..........#",//4
    "#..........#",//5
    "#..........#",//6
    "#..........#",//8
    "#..........#",//8
    "#..........#",//9
    "#..........#",//10
    "############"//11
    // "012345678901"
};

inline std::vector<std::string> Map2 = {
    "############",//0
    "#..........#",//1
    "#..........#",//2
    "#..........#",//3
    "#..........#",//4
    "#..........#",//5
    "#..........#",//6
    "#..........#",//8
    "#..........#",//8
    "#..........#",//9
    "#..........#",//10
    "############"//11
    // "012345678901"
};
inline std::vector<std::string> Map3 = {
    "############",//0
    "#..........#",//1
    "#..........#",//2
    "#..........#",//3
    "#..........#",//4
    "#..........#",//5
    "#..........#",//6
    "#..........#",//8
    "#..........#",//8
    "#..........#",//9
    "#..........#",//10
    "############"//11
    // "012345678901"
};
inline glm::vec2 MainCharacterPosition;//讓敵人追蹤的目標，原autoMove調用用變數

namespace Model {
    enum class Fired //敵人釋放火焰的方式
    {
        One,//前方一格
        Three,//面對方向的 左前 前 右前
        Column_Row,// 一整排，射線可能更精確
        Around,//九宮格
        Cross,//十字
        None
    };
    enum class Move { //敵人移動方式
        Row_Move,  //左右移動
        Column_Move, //上下移動
        Around_Move, //上下左右都能動
        // Auto_Move, //追蹤主角，廢案
        Dont_Move
    };
    enum class Direction { //方向
        Up=0,
        Down=1,
        Left=2,
        Right=3,
        None=-1 //預設
    };
    enum class PicureSource //設置位置時的參考參數
    {
        Fruit, //水果圖片
        Locked,//鎖定圖片
        None
    };
    enum class ButtonStyle { //設置位置時的參考參數
        W200H100, //橫條
        W80H80,   //關卡
        Circle60, //關卡內按鈕
        NotDefined
    };
    enum class Block         //特殊方塊
    {
        Ice,     //結凍方塊
        Fire,    //融化方塊
        Melt     //火方塊   敵人放火時顯示
    };

    std::string DirToStr(Model::Direction dir);
    int DirToNum(Model::Direction dir);
    glm::vec2 DirToPos(Model::Direction dir);
}


#endif //NAMESPACE_MODEL_HPP
