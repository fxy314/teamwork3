#include"shape.h"
#include <exception>
#include<cstring>
#include "rectangle.h"
/**
 * @brief Construct a new rectangle::rectangle object
 * @details 继承于shape类的构造函数，只是将type的值更改了
 */
rectangle::rectangle():shape()
{
    type = "图形种类为：长方形";
}
/**
 * @brief 设置长方形参数
 * @details 通过输入确定长方形的长和宽，同时修改长方形的面积，均只保留三位小数
 * @exception 长度参数必须在设置范围内，即MINVALUE到MAXVALUE之间，否则抛出const char[]异常 ："输入参数错误！"
 * @param input_len 长方形的长 input_hei 长方形的宽
 */
void rectangle::set_param(double input_len, double input_hei)
{
    if( (input_len - 0 > MINVALUE ) && (input_hei - 0 > MINVALUE)
        && (input_len < MAXVALUE) && (input_hei < MAXVALUE))
    {
        length = cut_to_3(input_len);
        height = cut_to_3(input_hei);
        area = cut_to_3(length * height);
        length_info = "该长方形长为" + to_string(length) + "厘米，宽为" + to_string(height) + "厘米";
    }
    else
    {
        throw "输入参数错误！";
    }
};
/**
 * @brief 用于长方形对象的use_centi()函数
 * @details 该函数继承了shape中原函数更改面积的特点，增加了更改长和宽的功能，长方形对象应该调用该函数而不是shape类中的原函数
 * @note 该函数只能在单位从英寸变为厘米时使用，如果已经选择厘米，再次选择厘米时不能调用，而且不要在厘米与英寸之间反复切换
 */
void rectangle::use_centi()
{
    shape::use_centi();
    length = cut_to_3(length * INCH);
    height = cut_to_3(height * INCH);
}
/**
 * @brief 用于长方形对象的use_inch()函数
 * @details 该函数继承了shape中原函数更改面积的特点，增加了更改长和宽的功能，长方形对象应该调用该函数而不是shape类中的原函数
 * @note 该函数只能在单位从厘米变为英寸时使用，如果已经选择英寸，再次选择英寸时不能调用，而且不要在厘米与英寸之间反复切换
 */
void rectangle::use_inch()
{
    shape::use_inch();
    length = cut_to_3(length / INCH);
    height = cut_to_3(height / INCH);
}
/**
 * @brief 返回以厘米为单位的长方形的长，保留三位小数
 * @return double 长方形的长
 */
double rectangle::get_length()
{
    return length;
}
/**
 * @brief 返回以厘米为单位的长方形的宽，保留三位小数
 * @return double 长方形的宽
 */
double rectangle::get_height()
{
    return height;
}