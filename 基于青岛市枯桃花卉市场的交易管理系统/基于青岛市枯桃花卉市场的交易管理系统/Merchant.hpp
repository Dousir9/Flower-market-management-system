//
//  Merchant.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/16.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef Merchant_hpp
#define Merchant_hpp

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdio>
#include <unistd.h>

#include "Global.hpp"
#include "Flower.hpp"
#include "Hash.hpp"
#include "User.hpp"
#include "Map.hpp"

using namespace std;

//商家类，继承用户类
class Merchant : virtual public User {
public:
    Merchant();  //默认构造函数
    Merchant(const string &user_name, const string &password, const string &shop_name);
    void Logging(); //商家入驻
    Merchant Loggin(); //商家登录,登陆成功返回true，失败返回false
    void CheckFlower() const; //查看自家上架花卉
    void AddFlower() const; //上架花卉
    void DeleteFlower() const; //下架花卉
    void ModifyFlowerInfo() const; //修改花卉信息
    void AutoDiscountFlower() const; //花卉自动折扣
    const int FlowerDateCompare(int yy1, int mm1, int dd1, int yy2, int mm2, int dd2) const;
    string& ShopNameInfo(); //返回花店名信息
private:
    string shop_name; //花店名
};

#endif /* Merchant_hpp */
