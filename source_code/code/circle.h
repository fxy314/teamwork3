//
// Created by 26219 on 2021/8/29 0029.
//

#ifndef TEAMWORK2_MASTER_CIRCLE_H
#define TEAMWORK2_MASTER_CIRCLE_H


/**
 * @class circle
 * @brief 圆形类，继承于shape
 * @param diameter 圆的直径
 */
class circle : public shape
{
private:
    double diameter;
    const double pi = 3.141;
public:
    circle();
    void use_inch();
    void use_centi();
    void set_param(double input_diameter);
    double get_diameter();
};
#endif //TEAMWORK2_MASTER_CIRCLE_H
