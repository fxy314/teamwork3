/**
 * @file shape.cpp
 * @author fxy314 付翔宇 u201811690@hust.edu.cn
 * @brief 相关函数的实现
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include"shape.h"
#include <exception>
#include<cstring>

/*————————————————————————以下为shape类）——————————————————————————————*/
/**
 * @brief 创建一个shape类对象
 * @details area 初始化为0.0, length_info, type, area_info均初始化为空字符串
 */
shape::shape()
{
    area =0.0;
    length_info = "";
    type = "";
    area_info = "";
}

/**
 * @brief 将输入的长度单位上设置为厘米
 * @details 只在将长度设置从英寸改变为厘米时调用，由于面积始终用平方厘米表示，
 * 调用时将面积数值除6.4516（6.4516 = 2.54 * 2.54）
 * @note 此函数调用了cut_to_3()函数，多次调用会降低精度，所以应避免在计算前反复更改单位。由于该函数不会改边长，实际使用时，应先创建子类对象，子类对象使用子类的该函数
 * @example 矩形长宽均为1英寸时，面积为6，4516平方厘米，改变单位为厘米时（不改变数值），长宽均变为1厘米，调用该函数，面积变成1平方厘米
 */
void shape::use_centi()
{
    area = cut_to_3((area)/INCH2);
}
/**
 * @brief 将输入的长度单位上设置为英寸
 * @details 只在将长度设置从厘米改变为英寸时调用，由于面积始终用平方厘米表示，
 * 调用时将面积数值乘6.4516（6.4516 = 2.54 * 2.54）
 * @note 此函数调用了cut_to_3()函数，多次调用会降低精度，所以应避免在计算前反复更改单位。由于该函数不会改边长，实际使用时，应先创建子类对象，子类对象使用子类的该函数
 */
void shape::use_inch()
{
    area = cut_to_3((area) * INCH2);
}

/**
 * @brief 返回图形的面积
 * @details 四种图形均用该函数返回面积，面积单位时平方厘米，返回值保留三位小数
 * @return double 面积的数值
 */
double shape::get_area()
{
    area = cut_to_3(area);
    return area;
}

/**
 * @brief 返回说明面积的字符串
 * @details 返回值只保留三位小数，可用于打印显示计算结果
 * @return string  格式为"面积为XX（数字）平方厘米"
 */
string shape::show_area()
{
    area_info = "面积为" + to_string(cut_to_3(area)) + "平方厘米";
    return area_info;
}

/**
 * @brief 返回说明边长信息的字符串
 * @details 返回值只保留三位小数，可用于打印显示输入
 * @return string  格式为"XX（边）为XX（数字）厘米"，有多条边中间用逗号隔开，"XX（边）为XX（数字）厘米，XX（边）为XX（数字）厘米"
 */
string shape::show_param()
{
    return length_info;
}

/**
 * @brief 返回说明面积大小的字符串
 * @details 返回值只保留三位小数，可用于打印显示选择的图形
 * @return string 格式为“图形种类为：XX”
 */
string shape::show_type()
{
    return type;
}
/**
 * @brief 此静态函数用于将一个double类的数只保留小数点后三位，并返回
 * @details 此函数并未设置输入范围限制，只在面积计算函数中设置了
 * @param origin 输入的浮点数
 * @return double 只保留三位后的结果
 * @note 此函数在其他函数中多次被调用，每次调用都可能会降低计算精度
 */
double shape::cut_to_3(double origin)
{
    long int temp = (long int)(origin * 1000);
    double output = (double(temp)/1000);
    return output;
}


