//
//  main.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/6.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "Global.hpp"
#include "Flower.hpp"
#include "Hash.hpp"
#include "Menu.hpp"

using namespace std;

HashTable hashtable;

int main(int argc, const char * argv[]) {
    hashtable.InitHashTable();
//    hashtable.InitHashTable();
    MainMenu M;
    M.MenuRun();
//    string g = "dfddf";
//    hashtable.InitHashTable();
//    hashtable.AddFlower();
//    string a;
//    cin>>a;
//    int b = a[0];
//    int c = a[1];
//    int d = a[2];
//    printf("%d %d %d\n", b, c, d);
//    hashtable.AddFlower();
//    hashtable.AddFlower();
//    hashtable.AddFlower();
//    hashtable.AddFlower();
//    hashtable.AddFlower();
//    hashtable.AddFlower();
//    hashtable.AddFlower();
//    hashtable.AddFlower();
//    hashtable.AddFlower();
//    hashtable.InitHashTable();
//    hashtable.SaveHashTable();
    ifstream myFile;
//    myFile.open(FLOWERFILENAME);
    string a[4];
    int k;
    cin>>k;
    int i = 0, b[4];
    while(!myFile.eof()){
        myFile>>a[i]>>b[i];
        i++;
    }
    myFile.close();
    for(int i = 0; i<4; i++){
        cout<<a[i]<<" "<<b[i]<<endl;
    }
    ofstream omyFile;
//    omyFile.open(FLOWERFILENAME);
    for(int i = 0; i< 4; i++){
        omyFile<<"wwe"<<" "<<23;
        if(i!=3)
            omyFile<<endl;
    }
//    myFile>>a>>b;
//    cout<<a<<endl;
//    cout<<b<<endl;
//    myFile>>sd;
//    printf("%s\n", sd+3);
//    printf("%d%d%d\n", sd[3],sd[4],sd[5]);
//    cout << "Hello, World!\n"<<sd<<endl;
    double value[] = {1.23, 35.36, 653.7, 4358.24};
    string names[] = {"Zoot", "Jimmy", "Al", "Stan"};
    for ( int i = 0; i < 4; i++) {
        cout<<hex<<(float)value[i]<<endl;
    }
    cout<<setiosflags(ios_base::left)<<setw(6)<<names[2]<<endl;
    cout<<setw(6)<<names[0]<<endl;
    cout<<resetiosflags(ios_base::left);
    cout<<setw(6)<<names[1]<<endl;
    return 0;
}
//玫瑰 花开富贵 红 15.8 20 2019 12 10
//玫花 花开富贵 蓝 22.2 15 2019 12 12
//月季 花开富贵 粉红 20.1 14 2019 12 10
//玫瑰 一个花店 红 16.2 22 2019 12 11
//兰花 花开富贵 蓝 25.2 50 2019 12 12
//菊花 花开富贵 蓝 25.2 30 2019 12 12
//荷花 一个花店 绿 20.5 25 2019 12 14
//牡丹 一个花店 黄 12.1 10 2019 12 15
//丁香 花开富贵 红 23.1 5 2019 12 14
//满天星 花开富贵 蓝 20.0 40 2019 12 14
//康乃馨 一个花店 白 40.5 100 2019 12 16
//仙人掌 一个花店 绿 6.8 70 2019 12 13
//玫瑰 幽香阁 粉红 18.8 65 2019 12 9
//玫瑰 花花世界 红 25.6 55 2019 12 13
//玫三 花开富贵 红 15.8 34 2019 12 10
//玫二 花开富贵 红 15.8 21 2019 12 10
//玫一 花开富贵 红 15.8 18 2019 12 10
