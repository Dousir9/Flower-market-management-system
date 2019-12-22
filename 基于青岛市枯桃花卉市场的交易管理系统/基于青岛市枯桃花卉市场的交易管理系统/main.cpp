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
#include "Map.hpp"

using namespace std;

HashTable hashtable;
char leftad1[30], leftad2[30], leftad3[30], leftad4[30], leftad5[30], leftad6[30], leftad7[30], leftad8[30], leftad9[30], leftad10[30];
char rightad1[30], rightad2[30], rightad3[30], rightad4[30], rightad5[30], rightad6[30], rightad7[30], rightad8[30], rightad9[30], rightad10[30];
char announcement1[100], announcement2[100], announcement3[100], announcement4[100], announcement5[100];

int main() {
//    Map m;
//    m.InitMap();
//    m.ShowMap();
//    m.SaveMap();
//    char s12, s3,sdd;
//    cin>>s12;
//    cin>>s3;
//    printf("%c\n" , s12);
//    printf("%c\n" , s3);
//    scanf("%c", &sdd);
//    printf("%cdd\n" , sdd);
    hashtable.InitHashTable();
    MainMenu M;
    M.LoadAd();
    M.LoadAnnouncement();
    M.MenuRun();
//    string dd = "，";
//    cout << dd[0] << dd[1] << dd[2] << endl;
    
    
    
    
//    M.ShowAnnouncement(announcement1);
//    cout << endl;
//    M.ShowAnnouncement(announcement2);
//    cout << endl;
//    M.MenuRun();
//    ifstream fl;
//    fl.open(LEFT_AD_FILE_NAME);
//    string tg;
//    char ch1, ch2, ch3;
//    ch1 = fl.get();
//    ch2 = fl.get();
//    ch3 = fl.get();
//    cout<<ch1<<ch2<<ch3<<endl;
////    hashtable.InitHashTable();
//    fl.close();
//    M.LoadAd();
//    M.ShowAd(leftad1);
//    cout << endl;
//    M.ShowAd(leftad2);
//    cout << endl;
//    M.ShowAd(leftad3);
//    cout << endl;
//    M.ShowAd(leftad4);
//    cout << endl;
//    M.ShowAd(leftad5);
//    cout << endl;
//    M.ShowAd(leftad6);
//    cout << endl;
//    M.ShowAd(leftad7);
//    cout << endl;
//    M.ShowAd(leftad8);
//    cout << endl;
//    M.ShowAd(leftad9);
//    cout << endl;
//    M.ShowAd(leftad10);
//    cout << endl;
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

//月季 花开富贵 粉红 19.899 14 2019 12 10
//荷花 一个花店 绿 20.5 25 2019 12 14
//满天星 花开富贵 蓝 19.8 40 2019 12 14
//康乃馨 一个花店 白 40.5 100 2019 12 16
//兰花 花开富贵 蓝 24.948 50 2019 12 12
//兰花 花花世界 白 45.2 30 2019 12 20
//牡丹 一个花店 黄 12.1 10 2019 12 15
//菊花 花开富贵 蓝 24.948 30 2019 12 12
//玫瑰 花花世界 红 25.542 55 2019 12 19
//玫瑰 花开富贵 红 15.642 19 2019 12 15
//玫瑰 一个花店 红 10.8 33 2019 12 11
//玫花 花开富贵 蓝 21.978 15 2019 12 12
//玫三 花开富贵 红 15.642 34 2019 12 13
//玫二 花开富贵 红 15.642 21 2019 12 16
//玫一 花开富贵 红 15.642 18 2019 12 14
//仙人掌 一个花店 绿 6.8 70 2019 12 13
//丁香 花开富贵 红 22.869 5 2019 12 14
//荷花 幽香阁 绿 11.8 26 2019 12 12
//金莲花 幽香阁 红 12.4 73 2019 12 19
//文殊兰 花开富贵 绿 12.5 52 2019 12 15
//白兰花 幽香阁 白 17.4 97 2019 12 22
//百合花 幽香阁 白 1.3 26 2019 12 20
//蔷薇 花开富贵 紫 1.2 9 2019 12 17
//月季 幽香阁 红 1.2 83 2019 12 18
//石榴花 幽香阁 红 0.9 13 2019 12 19
//李花 一个花店 黄 41.7 48 2019 12 18
//梨花 幽香阁 黄 39.2 90 2019 12 19
//玫瑰 幽香阁 红 24.3 33 2019 12 14
//琼花 花开富贵 黄 21.9 95 2019 12 13
//山茶 幽香阁 绿 14.5 84 2019 12 18
//桃花 幽香阁 桃红 14.4 19 2019 12 14
//杜鹃 花开富贵 红 14.2 123 2019 12 19
//玫瑰 花花世界 红 12.2 20 2019 12 13
//月季花 花花世界 红 9.4 100 2019 12 19
//梅花 花花世界 白 22.8 25 2019 12 12
//兰花 一个花店 绿 34.2 17 2019 12 15
//牡丹 花花世界 黄 19.8 32 2019 12 16
//海棠 一个花店 绿 13.9 12 2019 12 21
//菊花 花花世界 黄 10.0 32 2019 12 20
//木笔 花花世界 紫 9.9 69 2019 12 18
//紫荆花 一个花店 紫 20.0 12 2019 12 18
//连翘花 花花世界 绿 15.8 21 2019 12 18
//金钟花 一个花店 黄 27.5 52 2019/10/8
//丁香花 花花世界 红 22.8 71 2019/10/14
