//
//  Hash.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/7.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "Hash.hpp"

//默认构造函数
HashTable::HashTable() : first(MAXSIZE) {
    length = 0; //哈希表长度初始化为0
    for (int i = 0; i < 500; i++) {
        first[i] = NULL; //将哈希表每个位置的结点指针都指向NULL
    }
}
//哈希函数,返回一个哈希表的下标
const int HashTable::Hash(const string &flower_name) const {
    int frt, sed, trd, sum;
    frt = flower_name[0];
    sed = flower_name[1];
    trd = flower_name[2];
    frt = abs(frt)%10;
    sed = abs(sed)%10;
    trd = abs(trd)%10;
    sum = ((frt+sed+trd)%10*83+frt*100+sed*10+trd)%500;
    return sum;
}
//同名不同商家的花卉采用链地址法处理冲突
void HashTable::AddChain(int index, LNode* &p) {
    LNode *r = first[index];
    p->next = r->next;
    r->next = p;
}
//商家下架花卉时对同名花卉删除
bool HashTable::DeleteNode(int index, string &shop_name) {
    LNode *r = first[index];
    if(r->flower->ShopNameInfo() == shop_name) {
        first[index] = r->next;
        delete r;
        return true;
    }
    while(r->next) {
        if(r->next->flower->ShopNameInfo() == shop_name) {
            LNode *p = r->next;
            r->next = p->next;
            delete p;
            return true;
        }
        r = r->next;
    }
    return false;
}
//不同命花卉二次探测法处理处理冲突
const int HashTable::DetectSecond(const int index, int times) const {
    int detection;
    int k = 1;
    for (int i = 1; i <= times; i++) {
        if (i % 2 == 1)
            detection = k * k;
        else
            detection = -k * k;
        if (i % 2 == 0)
            ++k;
    }
    if (detection > 0)
        return (index + detection) % MAXSIZE;
    else if (index + detection >= 0)
        return index + detection;
    else {
        int sum = 500;
        while (sum < -detection - index) {
            sum += 500;
        }
        return sum - (-detection - index);
//        500 20 21 499
//        1000 20 521 499
    }
    
}
//读取文件建立哈希表
void HashTable::InitHashTable() {
    ifstream OutMyFile;
    OutMyFile.open(FLOWER_FILE_NAME);
    while (!OutMyFile.eof()) {
        LNode *p = new LNode;
        string flower_name; //花卉名称
        string shop_name; //花卉所在的店名
        string petal_color; //花卉花瓣颜色
        float flower_price; //花卉价格
        int flower_number; //花卉数量
        int year, month, day; //花卉上架日期
        OutMyFile>>flower_name;
        OutMyFile>>shop_name;
        OutMyFile>>petal_color;
        OutMyFile>>flower_price;
        OutMyFile>>flower_number;
        OutMyFile>>year;
        OutMyFile>>month;
        OutMyFile>>day;
        p->flower = new Flower(flower_name, shop_name, petal_color, flower_price, flower_number, year, month, day);
        AddFlower(p, 1);
    }
    OutMyFile.close();
}
//建立哈希表时向哈希表添加花卉
void HashTable::AddFlower(LNode* &p, int times) {
    int index = Hash(p->flower->FlowerNameInfo());
    if (first[index] == NULL) {
        first[index] = p;
    }
    //同名不同商家花卉链地址处理法处理冲突
    else if (first[index]->flower->FlowerNameInfo() == p->flower->FlowerNameInfo()) {
        AddChain(index, p);
    }
    //不同名花卉二次探测法处理冲突
    else {
        index = DetectSecond(index, times);
        if (first[index] == NULL) {
            first[index] = p;
        }
        //同名不同商家花卉链地址处理法处理冲突
        else if (first[index]->flower->FlowerNameInfo() == p->flower->FlowerNameInfo()) {
            AddChain(index, p);
        }
        //探测次数加1，再次探测
        else {
            ++times;
            if (times == HASH_MAX) { //哈希函数阈值
                cout << "需重写哈希函数" << endl;
                exit(0);
            }
            AddFlower(p, times);
        }
    }
}
//下架花卉
bool HashTable::DeleteFlower(string &flower_name, string &shop_name, int times) {
    int index = Hash(flower_name);
    if (first[index] == NULL) {
        return false;
    }
    if (first[index]->flower->FlowerNameInfo() == flower_name) {
        return DeleteNode(index, shop_name);
    }
    //不同名花卉二次探测法处理冲突
    else {
        index = DetectSecond(index, times);
        //同名不同商家花卉链地址处理法处理冲突
        if (first[index]->flower->FlowerNameInfo() == flower_name) {
            return DeleteNode(index, shop_name);
        }
        //探测次数加1，再次探测
        else {
            ++times;
            return DeleteFlower(flower_name, shop_name, times);
        }
    }
}
//在哈希表查找花卉并返回下标
int HashTable::SearchFlower(string &flower_name, int times) {
    int index = Hash(flower_name);
    if (first[index] == NULL)
        return -1;
    if (first[index]->flower->FlowerNameInfo() == flower_name) {
        return index;
    }
    //不同名花卉二次探测法处理冲突
    else {
        index = DetectSecond(index, times);
        //同名不同商家花卉链地址处理法处理冲突
        if (first[index]->flower->FlowerNameInfo() == flower_name) {
            return index;
        }
        //探测次数加1，再次探测
        else {
            ++times;
            if (times == HASH_MAX) //若不存在或者哈希函数不够好返回-1
                return -1;
            return SearchFlower(flower_name, times);
        }
    }
}
//该函数在哈希表的析构函数中，用于程序主动退出或意外结束时进行保存
void HashTable::SaveHashTable() {
    bool flag = false; //控制写入文件的开头时是否换行
    ofstream InMyFile;
    InMyFile.open(FLOWER_FILE_NAME);
    for (int i = 0; i < MAXSIZE; ++i) {
        LNode *p = first[i];
        while (p != NULL) {
            if (flag == true)
                InMyFile<<endl;
            flag = true;
            InMyFile<<p->flower->FlowerNameInfo()<<" "<<p->flower->ShopNameInfo()<<" "<<p->flower->PetalColorInfo()<<" "<<p->flower->FlowerPriceInfo()<<" "<<p->flower->FlowerNumberInfo()<<" "<<p->flower->YearInfo()<<" "<<p->flower->MonthInfo()<<" "<<p->flower->DayInfo();
            p = p->next;
        }
    }
    InMyFile.close();
}
HashTable::~HashTable() {
    SaveHashTable();
}


