#include "shape.h"
#include <exception>
#include<cstring>
#include "circle.h"
/**
 * @brief Construct a new circle::circle object
 * @details 继承于shape类的构造函数，只是将type的值更改了
 */
circle::circle():shape()
{
    type = "图形种类为：圆形";
}
/**
 * @brief 设置圆形参数
 * @details 通过输入确定圆形的直径，同时修改圆形的面积，均只保留三位小数
 * @exception 长度参数必须在设置范围内，即MINVALUE到MAXVALUE之间，否则抛出const char[]异常 ："输入参数错误！"
 * @param input_d 圆形的直径
 */
void circle::set_param(double input_d)
{
    if((input_d - 0 > MINVALUE) && (input_d < MAXVALUE))
    {
        diameter = cut_to_3(input_d);
        area = cut_to_3(pi * diameter * diameter / 4);
        length_info = "该圆的直径为" + to_string(diameter) + "厘米";
    }
    else
    {
        throw "输入参数错误！";
    }
}
/**
 * @brief 用于圆形对象的use_centi()函数
 * @details 该函数继承了shape中原函数更改面积的特点，增加了更改圆形的直径的功能，圆形对象应该调用该函数而不是shape类中的原函数
 * @note 该函数只能在单位从英寸变为厘米时使用，如果已经选择厘米，再次选择厘米时不能调用，而且不要在厘米与英寸之间反复切换
 */
void circle::use_centi()
{
    shape::use_centi();
    diameter = cut_to_3(diameter * INCH);
}
/**
 * @brief 用于圆形对象的use_inch()函数
 * @details 该函数继承了shape中原函数更改面积的特点，增加了更改圆形的直径的功能，圆形对象应该调用该函数而不是shape类中的原函数
 * @note 该函数只能在单位从厘米变为英寸时使用，如果已经选择英寸，再次选择英寸时不能调用，而且不要在厘米与英寸之间反复切换
 */
void circle::use_inch()
{
    shape::use_inch();
    diameter = cut_to_3(diameter / INCH);
}
/**
 * @brief 返回以厘米为单位的圆形的直径，保留三位小数
 * @return double 圆形的直径
 */
double circle::get_diameter()
{
    return diameter;
}