//
// Created by 26219 on 2021/8/29 0029.
//

#ifndef TEAMWORK2_MASTER_TRIANGLE_H
#define TEAMWORK2_MASTER_TRIANGLE_H

/**
 * @class triangle
 * @brief 三角形类，继承于shape，用于创建三角形对象
 * @param length 三角形底边长
 * @param height 该底边上的高
 */
class triangle : public shape
{
private:
    double length;
    double height;
public:
    triangle();
    void set_param(double input_len, double input_hei);
    void use_inch();
    void use_centi();
    double get_length();
    double get_height();
};


#endif //TEAMWORK2_MASTER_TRIANGLE_H
