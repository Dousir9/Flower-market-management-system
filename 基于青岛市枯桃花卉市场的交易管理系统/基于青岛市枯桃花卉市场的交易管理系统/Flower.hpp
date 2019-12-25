//
//  Flower.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/7.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef Flower_hpp
#define Flower_hpp

#include <iostream>
#include <string>

#include "FlowerDate.hpp"

using namespace std;

//花类
class Flower {
 public:
    Flower(); //默认构造函数
    Flower(string &f_name, string &s_name, string &f_color, float f_price, int f_number, int yy, int mm, int dd);//进行初始化的构造函数
    void SetFlowerInfo(string &f_name, string &s_name, string &f_color, float f_price, int f_number, int yy, int mm, int dd); //设置花卉信息
    void ModifyFlowerPrice(const float &f_price); //修改花卉价格
    void ModifyFlowerNumber(const int &f_number); //修改花卉数量
    void ModifyFlowerDate(int yy, int mm, int dd); //修改花卉上架日期
    void ModifyPetalColor(const string &f_color); //修改花卉的花瓣颜色
    const string& FlowerNameInfo() const; //返回花卉名称
    const string& ShopNameInfo() const; //返回花卉所在的店名
    const string& PetalColorInfo() const; //返回花卉的花瓣颜色
    const float& FlowerPriceInfo() const; //返回花卉价格
    const int& FlowerNumberInfo() const; //返回花卉数量
    const FlowerDate& FlowerDateInfo() const; //返回花卉上架日期
    const int& YearInfo(); //返回年份信息
    const int& MonthInfo(); //返回月份信息
    const int& DayInfo(); //返回日信息
 private:
    string flower_name; //花卉名称
    string shop_name; //花卉所在的店名
    string flower_color; //花卉花瓣颜色
    float flower_price; //花卉价格
    int flower_number; //花卉数量
    FlowerDate flower_date; //花卉上架日期
};

#endif /* Flower_hpp */
