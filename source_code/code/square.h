//
// Created by 26219 on 2021/8/29 0029.
//

#ifndef TEAMWORK2_MASTER_SQUARE_H
#define TEAMWORK2_MASTER_SQUARE_H

/**
 * @class square
 * @brief 正方形类，继承于shape，用于创造正方形对象
 * @param length 正方形的边长，数值认为以厘米为单位
 */
class square : public shape
{
private:
    double length;
public:
    square();
    void set_param(double input_len);
    void use_inch();
    void use_centi();
    double get_length();
};
#endif //TEAMWORK2_MASTER_SQUARE_H
