//
//  Menu.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/13.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <cstdio>
#include <iostream>

#include "User.hpp"

//（主）菜单类
class MainMenu {
    void LoadAd(); //加载广告
    void LoadAnnouncement(); //加载公告
    void ShowMenuHead(); //输出菜单头部
    void ShowMenuInfo(); //输出菜单内容
    void ShowMenuBottom(); //输出菜单底部
    void ShowAd(); //输出广告内容
    void ShowAnnouncement(); //输出公告
    void MenuRun(); //运行菜单
    void Input(); //从键盘接收指令
    void ShowError(); //输出异常信息
};

//商家登录注册菜单类，继承菜单类
class MerchantLogMenu : public MainMenu {
    void MenuShow(); //输出菜单
    void MenuRun(); //运行菜单
    friend Merchant;
};
//商家操作菜单类，继承菜单类
class MerchantDoMenu : public MainMenu {
    void MenuShow(); //输出菜单
    void MenuRun(); //运行菜单
    friend Merchant;
};

//买家登录注册菜单类，继承菜单类
class PurchaserLogMenu : public MainMenu {
    void MenuShow(); //输出菜单
    void MenuRun(); //运行菜单
    friend Purchaser;
};
//买家操作菜单类，继承菜单类
class PurchaserDoMenu : public MainMenu {
    void MenuShow(); //输出菜单
    void MenuRun(); //运行菜单
    friend Purchaser;
};


#endif /* Menu_hpp */
