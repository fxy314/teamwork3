/**
 * @file shape.h
 * @author fxy314 付翔宇 u201811690@hust.edu.cn
 * @brief 包含shape及其四个子类的声明
 * @version 0.1
 * @date 2021-08-19
 * @copyright Copyright (c) 2021
 * @note 本文件中只注释了变量，函数在实现的文件shape.cpp中注释
 */
#include<iostream>
using namespace std;
#ifndef SHAPE_H
#define SHAPE_H

/**
 * @class shape
 * @brief shape类，无具体形状，其他四个类均为其子类
 * @param area 面积
 * @param INCH 1英寸 = 2.54厘米
 * @param INCH2 1平方英寸 = 2.54*2.54平方厘米
 * @param MINVALUE 可输入的长度最小值
 * @param MAXVALUE 可输入的长度最大值
 * @param area_info 说明面积大小的字符串
 * @param length_info 说明边长信息的字符串
 * @param type 说明形状信息的字符串
 * 以上各字符串可直接用于打印以输出计算结果
 */
class shape
{
protected:
    double area;
    const double INCH2 = 2.54 * 2.54;
    const double INCH = 2.54;
    const double MINVALUE = 0.0001;
    const double MAXVALUE = 1000000000;
    string area_info;
    string length_info;
    string type;
public:
    shape();
    void use_inch();
    void use_centi();
    double get_area();
    string show_area();
    string show_param();
    string show_type();
    static double cut_to_3(double origin);
};



#endif
