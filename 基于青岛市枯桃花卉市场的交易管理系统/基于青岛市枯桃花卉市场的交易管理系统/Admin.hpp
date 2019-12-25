//
//  Admin.hpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/16.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#ifndef Admin_hpp
#define Admin_hpp

#include <iostream>
#include <string>
#include <fstream>

#include "Global.hpp"
#include "Flower.hpp"
#include "Hash.hpp"
#include "User.hpp"
#include "Merchant.hpp"
#include "Purchaser.hpp"

//管理员类,可进行任何操作,方便对系统进行测试，继承买家、卖家类，此时买家卖家类要设置虚基类
class Admin : public Merchant, public Purchaser {
 public:
    Admin();
    bool Loggin(); //管理员登录，登录成功返回true，失败返回false
    void Announce(); //发布公告
    void ClearAn(); //清空公告
    void SetAd(); //设置广告
    void ClearAd(); //广告一键清空并显示: 广告位招租
    void ClearAd2(char ch); //广告置空，设置新的广告前先将广告置空;
    void MerchantRetrievePassword(); //商家找回密码
    void PurchaserRetrievePassword(); //买家找回密码
 private:
    const string admin_password = ADMIN_PASSERWORD; //管理员密码
};

#endif /* Admin_hpp */
