#include "shape.h"
#include <exception>
#include<cstring>
#include "square.h"
/**
 * @brief Construct a new square::square object
 * @details 继承于shape类的构造函数，只是将type的值更改了
 */

square::square():shape()
{
    type = "图形种类为：正方形";
}

/**
 * @brief 设置正方形参数
 * @details 通过输入确定正方形的边长，同时修改正方形的面积，均只保留三位小数
 * @exception 长度参数必须在设置范围内，即MINVALUE到MAXVALUE之间，否则抛出const char[]异常 ："输入参数错误！"
 * @param input_len 正方形的边长
 */
void square::set_param(double input_len)
{
    if((input_len - 0 > MINVALUE) && (input_len < MAXVALUE))
    {
        length = cut_to_3(input_len);
        area = cut_to_3(length * length);
        length_info = "该正方形长度为" +  to_string(length) + "厘米";
    }
    else
    {
        throw "输入参数错误！";
    }
}


/**
 * @brief 返回以厘米为单位的正方形边长，保留三位小数
 * @return double 正方形边长
 */
double square::get_length()
{
    return length;
}

/**
 * @brief 用于正方形对象的use_inch()函数
 * @details 该函数继承了shape中原函数更改面积的特点，增加了更改边长的功能，正方形对象应该调用该函数而不是shape类中的原函数
 * @note 该函数只能在单位从厘米变为英寸时使用，如果已经选择英寸，再次选择英寸时不能调用，而且不要在厘米与英寸之间反复切换
 */
void square::use_inch()
{
    shape::use_inch();
    length = cut_to_3(length * INCH);
}

/**
 * @brief 用于正方形对象的use_centi()函数
 * @details 该函数继承了shape中原函数更改面积的特点，增加了更改边长的功能，正方形对象应该调用该函数而不是shape类中的原函数
 * @note 该函数只能在单位从英寸变为厘米时使用，如果已经选择厘米，再次选择厘米时不能调用，而且不要在厘米与英寸之间反复切换
 */
void square::use_centi()
{
    shape::use_inch();
    length = cut_to_3(length / INCH);
}