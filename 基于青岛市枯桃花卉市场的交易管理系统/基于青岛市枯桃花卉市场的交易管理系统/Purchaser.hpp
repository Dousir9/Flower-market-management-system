//
//  Purchaser.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/16.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef Purchaser_hpp
#define Purchaser_hpp

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <unistd.h>

#include "Global.hpp"
#include "Flower.hpp"
#include "Hash.hpp"
#include "User.hpp"
#include "Map.hpp"

//买家类,继承用户类
class Purchaser : virtual public User {
public:
    Purchaser();  //默认构造函数
    Purchaser(const string &user_name, const string &password);
    void Logging(); //买家注册，注册成功返回true，失败返回false
    Purchaser Loggin(); //买家登录，登录成功返回true，失败返回false
    void CheckALLFlower() const; //查看所有商家花卉
    void SearchFlower() const; //查找花卉
    void ReserveFlower() const; //花卉预约
    void CheckReservation() const; //查看预约
    void RecommendFlower() const; //花卉推荐
    const int DateCompare(int yy1, int mm1, int dd1, int yy2, int mm2, int dd2) const; //比较日期返回差值(yy2/mm2/dd2 - yy1/mm1/dd1)
    void NavigateShopAddress() const; //花店地址导航
    LNode* MergeList1(LNode *L1, LNode *L2) const; //价格归并排序
    LNode* MergeSort1(LNode *head) const;          //价格归并排序
    LNode* MergeList2(LNode *L1, LNode *L2) const; //数量归并排序
    LNode* MergeSort2(LNode *head) const;          //数量归并排序
    LNode* MergeList3(LNode *L1, LNode *L2) const; //日期归并排序
    LNode* MergeSort3(LNode *head) const;          //日期归并排序
private:
    LNode *LinkList; //存放预约的花卉的链表
};

#endif /* Purchaser_hpp */
