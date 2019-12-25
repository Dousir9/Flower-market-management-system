//
//  Flower.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/7.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "Flower.hpp"

//默认构造函数
Flower::Flower() {
    flower_name = "";
    shop_name = "";
    flower_color = "";
    flower_price = 0;
    flower_number = 0;
    //flower_date调用默认构造函数
}
//进行初始化的构造函数
Flower::Flower(string &f_name, string &s_name, string &f_color, float f_price, int f_number, int yy, int mm, int dd) : flower_date(yy, mm ,dd) {
    flower_name = f_name;
    shop_name = s_name;
    flower_color = f_color;
    flower_price = f_price;
    flower_number = f_number;
}
//设置花卉信息
void Flower::SetFlowerInfo(string &f_name, string &s_name, string &f_color, float f_price, int f_number, int yy, int mm, int dd) {
    flower_name = f_name;
    shop_name = s_name;
    flower_color = f_color;
    flower_price = f_price;
    flower_number = f_number;
    flower_date.SetDateInfo(yy, mm, dd);
}
//修改花卉价格
void Flower::ModifyFlowerPrice(const float &f_price) {
    flower_price = f_price;
}
//修改花卉数量
void Flower::ModifyFlowerNumber(const int &f_number) {
    flower_number = f_number;
}
//修改花卉上架日期
void Flower::ModifyFlowerDate(int yy, int mm, int dd) {
    flower_date.SetDateInfo(yy, mm, dd);
}
//修改花卉的花瓣颜色
void Flower::ModifyPetalColor(const string &f_color) {
    flower_color = f_color;
}
//返回花卉名称
const string& Flower::FlowerNameInfo() const {
    return flower_name;
}
//返回花卉所在的店名
const string& Flower::ShopNameInfo() const {
    return shop_name;
}
//返回花卉价格
const float& Flower::FlowerPriceInfo() const {
    return flower_price;
}
//返回花卉的花瓣颜色
const string& Flower::PetalColorInfo() const {
    return flower_color;
}
//返回花卉数量
const int& Flower::FlowerNumberInfo() const {
    return flower_number;
}
//返回年份信息
const int& Flower::YearInfo() {
    return flower_date.YearInfo();
}
//返回月份信息
const int& Flower::MonthInfo() {
    return flower_date.MonthInfo();
}
//返回年份信息
const int& Flower::DayInfo() {
    return flower_date.DayInfo();
}
//返回花卉上架日期
const FlowerDate& Flower::FlowerDateInfo() const {
    return flower_date;
}
