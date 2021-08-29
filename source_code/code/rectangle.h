//
// Created by 26219 on 2021/8/29 0029.
//

#ifndef TEAMWORK2_MASTER_RECTANGLE_H
#define TEAMWORK2_MASTER_RECTANGLE_H

/**
 * @brief 矩形类，继承于shape，用于创建矩形对象
 * @class rectangle
 * @param length 长方形的长，数值认为以厘米为单位
 * @param height 长方形的宽，应该叫width的，将错就错吧
 */
class rectangle : public shape
{
private:
    double length;
    double height;
public:
    rectangle();
    void set_param(double input_length, double input_height);
    void use_inch();
    void use_centi();
    double get_length();
    double get_height();
};
#endif //TEAMWORK2_MASTER_RECTANGLE_H
