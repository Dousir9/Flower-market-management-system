//
//  Purchaser.cpp
//  基于青岛市枯桃花卉市场的交易管理系统
//
//  Created by 🍓XJK on 2019/12/16.
//  Copyright © 2019 🍓XJK. All rights reserved.
//

#include "Purchaser.hpp"

#include "Hash.hpp"
extern HashTable hashtable;
extern char leftad1[30], leftad2[30], leftad3[30], leftad4[30], leftad5[30], leftad6[30], leftad7[30], leftad8[30], leftad9[30], leftad10[30];
extern char rightad1[30], rightad2[30], rightad3[30], rightad4[30], rightad5[30], rightad6[30], rightad7[30], rightad8[30], rightad9[30], rightad10[30];
extern char announcement1[100], announcement2[100], announcement3[100], announcement4[100], announcement5[100];

//默认构造函数
Purchaser::Purchaser() {
    LinkList = NULL;
    log_success = false;
}
//进行初始化的构造函数
Purchaser::Purchaser(const string &user_name, const string &password) : User(user_name, password){
    LinkList = NULL;
    log_success = false;
}
//买家注册
void Purchaser::Logging() {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    //    Sleep(5);
    string user_name;
    string password1, password2;
    cout<<endl<<"                                           请输入注册用户名: ";
    cin >> user_name;
    //验证用户名是否存在
    ifstream InMyFile1;
    InMyFile1.open(PURCHASER_FILE_NAME);
    string file_user_name, file_password;
    while (!InMyFile1.eof()) {
        InMyFile1>>file_user_name>>file_password;
        if (file_user_name == user_name) {
            InMyFile1.close();
            cout<<endl<<"                                         该用户名已被注册，注册失败"<<endl;
            MY_PAUSE();
            return ;
        }
    }
    InMyFile1.close();
    cout<<endl<<"                                         请输入密码(不小于8位): ";
    cin >> password1;
    if (password1.length() < 8) {
        cout<<endl<<"                                      密码长度应不小于8位，注册失败"<<endl;
        MY_PAUSE();
        return ;
    }
    cout<<endl<<"                                           请再次输入密码: ";
    cin >> password2;
    MY_FLUSH();
    if (password1 != password2) {
        cout<<endl<<"                                      两次输入的密码不一致，注册失败"<<endl;
        MY_PAUSE();
        return ;
    }
    fstream InMyFile2;
    InMyFile2.open(PURCHASER_FILE_NAME, ios::app);
    InMyFile2.seekg(0, ios::end); //将文件指针指向文件末端
    streampos fp = InMyFile2.tellg(); //fp为文件指针的偏移量
    if (int(fp) != 0) // 偏移量为0，证明文件为空，为首次进入系统,不是首次进入系统就换行
        InMyFile2<<endl;
    InMyFile2<<user_name<<" "<<password1;
    InMyFile2.close();
    cout <<endl<<"                                                  注册成功"<<endl;
    MY_PAUSE();
}
//买家登录
Purchaser Purchaser::Loggin() {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    //    Sleep(5);
    string user_name;
    string password;
    cout<<endl<<"                                       请 输 入 用 户 名:";
    cin >> user_name;
    cout<<endl<<"                                        请 输 入 密 码:";
    cin >> password;
    string file_user_name; //文件中的用户名
    string file_password; //文件中的密码
    ifstream OutMyFile;
    OutMyFile.open(PURCHASER_FILE_NAME);
    while (!OutMyFile.eof()) {
        OutMyFile>>file_user_name>>file_password;
        if (file_user_name == user_name) {
            if (file_password == password) {
                OutMyFile.close();
                cout<<endl<<"                                           密码正确,正在登录...."<<endl;
                sleep(2);
                Purchaser p(user_name, password);
                p.ModifyLogStatus(true);
                return p;
            } else {
                OutMyFile.close();
                cout<<endl<<"                                     密码错误，正在返回买家界面...."<<endl;
                sleep(2);
                Purchaser p;
                return p;
            }
        }
    }
    cout<<endl<<"                                     该用户名不存在，正在返回买家界面...."<<endl;
    sleep(2);
    OutMyFile.close();
    Purchaser p;
    return p;
}
//查看所有上架花卉
void Purchaser::CheckALLFlower() const {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    //    Sleep(5);
    printf("    花卉名称          花店名          花卉颜色             单价              数量             上架日期  \n");
    for (int i = 0; i < MAXSIZE; ++i) {
        LNode *p = hashtable.first[i];
        while (p != NULL) {
            printf("      %-8s         %-8s           %-5s              %5.1f               %-3d            ", p->flower->FlowerNameInfo().c_str(), p->flower->ShopNameInfo().c_str(), p->flower->PetalColorInfo().c_str(),p->flower->FlowerPriceInfo(),  p->flower->FlowerNumberInfo());
            //用到运算符重载 <<
            cout<<p->flower->FlowerDateInfo();
            p = p->next;
            usleep(25000);
        }
    }
}
//查找花卉
void Purchaser::SearchFlower() const {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    LNode* linklist;
    linklist = NULL;
    string flower_name;
    cout <<endl<< "                                      请输入你要查找的花卉名称 :";
    cin >> flower_name;
    int index = hashtable.SearchFlower(flower_name, 1);
    if (index == -1) {
        cout <<endl<< "                                        你要查找的花卉不存在" << endl;
        return ;
    } else {
        LNode *p = hashtable.first[index];
        cout <<endl<< "                                        你要查找的花卉信息为: " << endl;
        printf("    花卉名称          花店名          花卉颜色             单价              数量             上架日期  \n");
        while (p != NULL) {
            printf("      %-8s         %-8s           %-5s              %5.1f               %-3d            ", p->flower->FlowerNameInfo().c_str(), p->flower->ShopNameInfo().c_str(), p->flower->PetalColorInfo().c_str(),p->flower->FlowerPriceInfo(),  p->flower->FlowerNumberInfo());
            //用到运算符重载 <<
            cout<<p->flower->FlowerDateInfo();
            p = p->next;
            usleep(25000);
        }
        bool flag = 1;
        LNode *q;
        while (flag) {
            cout <<endl<< "                                             1.按单价排序" << endl;
            cout <<endl<< "                                             2.按数量排序" << endl;
            cout <<endl<< "                                             3.按上架日期排序" << endl;
            cout <<endl<< "                                             4.返回" << endl;
            char ch;
            cin >> ch;
            fflush(stdin);
            switch (ch) {
                case '1':
                    system("clear");
                    cout<<endl<<TT<<TT;
                    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
                    q = MergeSort1(hashtable.first[index]);
                    hashtable.first[index] = q;
                    cout <<endl<< "                                               按单价排序: " << endl<<endl;
                    printf("    花卉名称          花店名          花卉颜色             单价              数量             上架日期  \n");
                    while (q != NULL) {
                        printf("      %-8s         %-8s           %-5s              %5.1f               %-3d            %-2d/%-2d/%-2d\n", q->flower->FlowerNameInfo().c_str(), q->flower->ShopNameInfo().c_str(), q->flower->PetalColorInfo().c_str(),q->flower->FlowerPriceInfo(),  q->flower->FlowerNumberInfo(),
                               q->flower->YearInfo(), q->flower->MonthInfo(), q->flower->DayInfo());
                        q = q->next;
                        usleep(25000);
                    }
                    MY_PAUSE();
                    break;
                case '2':
                    system("clear");
                    cout<<endl<<TT<<TT;
                    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
                    q = MergeSort2(hashtable.first[index]);
                    hashtable.first[index] = q;
                    cout <<endl<< "                                               按数量排序: " << endl <<endl;
                    printf("    花卉名称          花店名          花卉颜色             单价              数量             上架日期  \n");
                    while (q != NULL) {
                        printf("      %-8s         %-8s           %-5s              %5.1f               %-3d            %-2d/%-2d/%-2d\n", q->flower->FlowerNameInfo().c_str(), q->flower->ShopNameInfo().c_str(), q->flower->PetalColorInfo().c_str(),q->flower->FlowerPriceInfo(),  q->flower->FlowerNumberInfo(),
                               q->flower->YearInfo(), q->flower->MonthInfo(), q->flower->DayInfo());
                        q = q->next;
                        usleep(25000);
                    }
                    MY_PAUSE();
                    break;
                case '3':
                    system("clear");
                    cout<<endl<<TT<<TT;
                    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
                    q = MergeSort3(hashtable.first[index]);
                    hashtable.first[index] = q;
                    cout <<endl<< "                                              按上架日期排序: " << endl<<endl;
                    printf("    花卉名称          花店名          花卉颜色             单价              数量             上架日期  \n");
                    while (q != NULL) {
                        printf("      %-8s         %-8s           %-5s              %5.1f               %-3d            %-2d/%-2d/%-2d\n", q->flower->FlowerNameInfo().c_str(), q->flower->ShopNameInfo().c_str(), q->flower->PetalColorInfo().c_str(),q->flower->FlowerPriceInfo(),  q->flower->FlowerNumberInfo(),
                               q->flower->YearInfo(), q->flower->MonthInfo(), q->flower->DayInfo());
                        q = q->next;
                        usleep(25000);
                    }
                    MY_PAUSE();
                    break;
                case '4':
                    flag = 0;
                    break;
                default:
                    cout <<endl<< "                                       无效的输入,请重新输入" << endl;
            }
        }
        return ;
    }
}
//价格归并排序1
LNode* Purchaser::MergeList1(LNode *L1, LNode *L2) const {
    LNode *p, *q, *L, *r;
    p = L1;
    q = L2;
    if(p&&q&&p->flower->FlowerPriceInfo()<=q->flower->FlowerPriceInfo()){
        L = p;
        p = p->next;
        r = L;
    }
    else if(p&&q){
        L = q;
        q = q->next;
        r = L;
    }
    while(p&&q){
        if(p->flower->FlowerPriceInfo()<=q->flower->FlowerPriceInfo()){
            r->next = p;
            r = p;
            p = p->next;
        }
        else{
            r->next = q;
            r = q;
            q = q->next;
        }
    }
    p = p?p:q;
    r->next = p;
    return L;
}
//价格归并排序2
LNode* Purchaser::MergeSort1(LNode *head) const {
    if(head==NULL||head->next==NULL)
        return head;
    LNode *slow, *fast;
    slow = head;
    fast = head->next;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    LNode *lefthead = head, *righthead = slow->next;
    slow->next = NULL;
    lefthead = MergeSort1(lefthead);
    righthead = MergeSort1(righthead);
    return MergeList1(lefthead, righthead);
}
//数量归并排序1
LNode* Purchaser::MergeList2(LNode *L1, LNode *L2) const {
    LNode *p, *q, *L, *r;
    p = L1;
    q = L2;
    if(p&&q&&p->flower->FlowerNumberInfo()<=q->flower->FlowerNumberInfo()){
        L = p;
        p = p->next;
        r = L;
    }
    else if(p&&q){
        L = q;
        q = q->next;
        r = L;
    }
    while(p&&q){
        if(p->flower->FlowerNumberInfo()<=q->flower->FlowerNumberInfo()){
            r->next = p;
            r = p;
            p = p->next;
        }
        else{
            r->next = q;
            r = q;
            q = q->next;
        }
    }
    p = p?p:q;
    r->next = p;
    return L;
}
//数量归并排序2
LNode* Purchaser::MergeSort2(LNode *head) const {
    if(head==NULL||head->next==NULL)
        return head;
    LNode *slow, *fast;
    slow = head;
    fast = head->next;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    LNode *lefthead = head, *righthead = slow->next;
    slow->next = NULL;
    lefthead = MergeSort2(lefthead);
    righthead = MergeSort2(righthead);
    return MergeList2(lefthead, righthead);
}
//上架日期归并排序1
LNode* Purchaser::MergeList3(LNode *L1, LNode *L2) const {
    LNode *p, *q, *L, *r;
    p = L1;
    q = L2;
    if(p&&q&&p->flower->YearInfo()==q->flower->YearInfo()){
        if(p->flower->MonthInfo()==q->flower->MonthInfo()){
            if(p->flower->DayInfo()<=q->flower->DayInfo()){
                L = p;
                p = p->next;
                r = L;
            } else {
                L = q;
                q = q->next;
                r = L;
            }
        } else if (p->flower->MonthInfo()<=q->flower->MonthInfo()) {
            L = p;
            p = p->next;
            r = L;
        } else {
            L = q;
            q = q->next;
            r = L;
        }
    } else if (p&&q&&p->flower->YearInfo()<q->flower->YearInfo()) {
        L = p;
        p = p->next;
        r = L;
    } else {
        L = q;
        q = q->next;
        r = L;
    }
    while(p&&q){
        if(p->flower->YearInfo()<=q->flower->YearInfo()){
            if(p->flower->MonthInfo()<=q->flower->MonthInfo()) {
                if(p->flower->DayInfo()<=q->flower->DayInfo()) {
                    r->next = p;
                    r = p;
                    p = p->next;
                } else {
                    r->next = q;
                    r = q;
                    q = q->next;
                }
            } else {
                r->next = q;
                r = q;
                q = q->next;
            }
        } else {
            r->next = q;
            r = q;
            q = q->next;
        }
    }
    p = p?p:q;
    r->next = p;
    return L;
}
//上架日期归并排序2
LNode* Purchaser::MergeSort3(LNode *head) const {
    if(head==NULL||head->next==NULL)
        return head;
    LNode *slow, *fast;
    slow = head;
    fast = head->next;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    LNode *lefthead = head, *righthead = slow->next;
    slow->next = NULL;
    lefthead = MergeSort3(lefthead);
    righthead = MergeSort3(righthead);
    return MergeList3(lefthead, righthead);
}
//预约花卉
void Purchaser::ReserveFlower() const {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    //    Sleep(5);
    string flower_name;
    cout <<endl<< "                                      请输入您要预约的花卉名称 :";
    cin >> flower_name;
    fflush(stdin);
    int index = hashtable.SearchFlower(flower_name, 1);
    if (index == -1) {
        cout <<endl<< "                                        您要预约的花卉不存在" << endl;
        return ;
    } else {
        LNode *p = hashtable.first[index];
        cout <<endl<< "                                        您可以预约的花卉如下: " << endl;
        printf("    花卉名称          花店名          花卉颜色             单价              数量             上架日期  \n");
        while (p != NULL) {
            printf("      %-8s         %-8s           %-5s              %5.1f               %-3d            %-2d/%-2d/%-2d\n", p->flower->FlowerNameInfo().c_str(), p->flower->ShopNameInfo().c_str(), p->flower->PetalColorInfo().c_str(),p->flower->FlowerPriceInfo(),  p->flower->FlowerNumberInfo(),
                   p->flower->YearInfo(), p->flower->MonthInfo(), p->flower->DayInfo());
            p = p->next;
        }
        string shop_name;
        cout <<endl<< "                                       请输入您要预约花卉的花店名: ";
        cin >> shop_name;
        fflush(stdin);
        p = hashtable.first[index];
        while (p != NULL) {
            if (p->flower->ShopNameInfo() == shop_name) {
                cout <<endl<< "                                         请输入您要预约的数量: ";
                int num;
                cin >> num;
                fflush(stdin);
                if (p->flower->FlowerNumberInfo() < num) {
                    cout <<endl<< "                                        预约数量大于库存，预约失败" << endl;
                    return ;
                } else {
                    p->flower->ModifyFlowerNumber(p->flower->FlowerNumberInfo() - num);
                    string file_name = FILE_ADDRESS + UserNameInfo() + FILE_TYPE;
                    fstream InMyFile;
                    InMyFile.open(file_name, ios::app);
                    InMyFile.seekg(0, ios::end); //将文件指针指向文件末端
                    streampos fp = InMyFile.tellg(); //fp为文件指针的偏移量
                    if (int(fp) != 0) // 偏移量为0，证明文件为空，为首次进入系统,不是首次进入系统就换行
                        InMyFile<<endl;
                    InMyFile<<p->flower->FlowerNameInfo()<<" "<<p->flower->ShopNameInfo()<<" "<<p->flower->PetalColorInfo()<<" "<<p->flower->FlowerPriceInfo()<<" "<<num<<" "<<p->flower->YearInfo()<<" "<<p->flower->MonthInfo()<<" "<<
                    p->flower->DayInfo();
                    InMyFile.close();
                    cout <<endl<< "                                                预约成功" << endl;
                    return ;
                }
            }
            p = p->next;
        }
        cout <<endl<< "                                              该商家不存在" << endl;
        return ;
    }
}

//查看预约
void Purchaser::CheckReservation() const{
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    //    Sleep(5);
    cout <<endl<< "                                            您预约的花卉如下: " <<endl<<endl;
    string flower_name;
    string shop_name;
    string flower_color;
    float flower_price;
    int flower_number;
    int year, month, day;
    fstream OutMyFile;
    string file_name = FILE_ADDRESS + UserNameInfo() + FILE_TYPE;
    OutMyFile.open(file_name);
    OutMyFile.seekg(0, ios::end); //将文件指针指向文件末端
    streampos fp = OutMyFile.tellg(); //fp为文件指针的偏移量
    if (int(fp) == 0) { // 偏移量为0，证明文件为空，为首次进入系统,不是首次进入系统就换行
        cout <<endl<< "                                           您没有预约花卉" << endl;
        return ;
    }
    OutMyFile.close();
    OutMyFile.open(file_name);
    printf("    花卉名称          花店名          花卉颜色             单价              数量             上架日期  \n");
    while (!OutMyFile.eof()) {

        OutMyFile>>flower_name>>shop_name>>flower_color>>flower_price>>flower_number>>year>>month>>day;
        printf("      %-8s         %-8s           %-5s              %5.1f               %-3d            %-2d/%-2d/%-2d\n", flower_name.c_str(), shop_name.c_str(), flower_color.c_str(),flower_price,  flower_number,
               year, month, day);
        usleep(25000);
    }
    OutMyFile.close();
}
//花卉推荐
void Purchaser::RecommendFlower() const {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    //    Sleep(5);
    cout<<endl;
    cout<<endl;cout<<TT;cout<<TT;
    printf("        "); cout<<STAR; printf(" ");
    cout<<SOFTWARE;printf(" ");cout<<STAR; cout<<NEW_LINE; cout<<NEW_LINE;
    printf("                         {@}                                                    {@}   \n");
    printf("                          |                   ①  日 期 范 围                     |    \n");
    printf("                         \\|/                  ②  鲜 花 用 途                    \\|/ \n");
    printf("                          |                                                      |    \n");
    printf("                          |                                                      |    \n");
    int n;
    char ch, ch2;
    cin >> ch;
    fflush(stdin);
    time_t timep;
    struct tm *p;
    time(&timep);
    p=gmtime(&timep);
    int flag = 0;
    int now_year, now_month, now_day;
    now_year = 1900+p->tm_year;
    now_month = 1+p->tm_mon;
    now_day = p->tm_mday;
    //圣诞节
    const int shengdan_year = now_year, shengdan_month = 12, shengdan_day = 25;
    switch (ch) {
        case '1':
            printf("\n                                             请设置日期范围:");
            cin >> n;
            fflush(stdin);
            system("clear");
            printf("\n");
            cout<<TT;cout<<TT;
            printf("        "); cout<<STAR; printf(" "); cout<<SOFTWARE;printf(" ");cout<<STAR; cout<<NEW_LINE; cout<<NEW_LINE;
            printf("\n                                            今天是%d月%d日\n", now_month, now_day);
//            Sleep(1);
            if(DateCompare(now_year, now_month, now_day, shengdan_year, shengdan_month, shengdan_day)<=n){
                printf("\n                                         距离圣诞节(12月25日)有%d天\n", DateCompare(now_year, now_month, now_day, shengdan_year, shengdan_month, shengdan_day));
//                Sleep(1);
                printf("送恋人:\n");
//                Sleep(1);
                printf("红玫瑰: 众所周知玫瑰是代表爱情的花朵，红玫瑰更是代表热情，爱恋的意思，要问给女朋友圣诞节送什么花?红玫瑰当然是首选了，既能表达你们的感情热情如火，又能增加浪漫度。\n");
//                Sleep(1);
                printf("百合:   在大家的心中百合花是纯洁无暇、天真无邪的，加上百合花的花语是纯洁的爱。在圣诞节这一天除了考虑送玫瑰花，也可以送百合花哦，如果是表白可以事先弄清楚对方的喜好，会事半功倍的。\n");
//                Sleep(1);
                printf("郁金香: 郁金香的花语为博爱、体贴、高雅、富贵、能干、聪颖。不同的花色也有着不同的花语，例如：红色郁金香代表热烈的爱意、粉色郁金香代表永远的爱、黄色郁金香代表开朗、白色郁金香代表纯洁清高的恋情、黑色郁金香代表爱的表白，永恒的祝福。\n");
//                Sleep(1);
                printf("送老师:\n");
//                Sleep(1);
                printf("康乃馨: 康乃馨的花语是爱，魅力和尊敬之情。像粉色康乃馨较适合送给女老师，黄色康乃馨较适合送给男老师。\n");
//                Sleep(1);
                printf("向日葵、石竹梅: 表达自己的感恩和祝福之情。\n");
//                Sleep(1);
                flag = 1;
            }
            if(flag==0){
                printf("\n                                         您设置日期范围内没有节日\n");
                printf("\n                                            ");
            }
            printf("\n                                            ");
            break;
        case '2':
            system("clear");
            printf("\n");
            cout<<TT;cout<<TT;
            printf("        "); cout<<STAR; printf(" "); cout<<SOFTWARE;printf(" ");cout<<STAR; cout<<NEW_LINE; cout<<NEW_LINE;
            cout<<endl<<"                                                请选择事件: "<<endl;
            cout<<endl<<"                                                1.爱情鲜花 "<<endl;
            cout<<endl<<"                                                2.生日鲜花 "<<endl;
            cout<<endl<<"                                                3.友情鲜花 "<<endl;
            cout<<endl<<"                                                4.问候长辈 "<<endl;
            cout<<endl<<"                                                5.探病慰问 "<<endl;
            cout<<endl<<"                                                6.婚庆鲜花 "<<endl;
            cout<<endl<<"                                                7.商务鲜花 "<<endl;
            cin >> ch2;
            fflush(stdin);
            if(ch2=='1'){
                system("clear");
                printf("\n");
                cout<<TT;cout<<TT;
                printf("        "); cout<<STAR; printf(" "); cout<<SOFTWARE;printf(" ");cout<<STAR; cout<<NEW_LINE; cout<<NEW_LINE;
                printf("\n                                                爱情鲜花:\n\n");
                printf("                                                 郁金香:\n"
                       "                                        爱的表白、荣誉、祝福、永恒\n\n"
                       "                                                郁金香(紫):\n"
                       "                                             无尽的爱、最爱\n\n"
                       "                                                康乃馨(白):\n"
                       "                                          吾爱永在、真情、纯洁\n\n"
                       "                                                红玫瑰:\n"
                       "                                          热恋 粉玫瑰 永远的爱\n\n"
                       "                                                星辰花:\n"
                       "                                               永不变心\n\n"
                       "                                                孤挺花:\n"
                       "                                               喋喋不休\n\n"
                       "                                              嘉德利亚兰:\n"
                       "                                                贵妇人\n\n"
                       "                                                蝴蝶兰:\n"
                       "                                             幸福逐渐到来\n\n"
                       "                                                文心兰:\n"
                       "                                              隐藏的爱\n\n"
                       "                                                秋石斛:\n"
                       "                                                 迷惑\n\n");
            }
            else if(ch2=='2'){
                system("clear");
                printf("\n");
                cout<<TT;cout<<TT;
                printf("        "); cout<<STAR; printf(" "); cout<<SOFTWARE;printf(" ");cout<<STAR; cout<<NEW_LINE; cout<<NEW_LINE;
                printf("\n                                                生日鲜花\n\n");
                printf("                                                朋友生日:\n");
                printf("                            红月季、满天星、石榴花、象牙红代表火红年华、前程似锦\n");
                printf("                                                长辈生日:\n");
                printf("                             长寿花、白百合、万年青等,寓意福如东海，寿比南山\n");
                printf("                                                同事生日:\n");
                printf("                       百合、天堂鸟、非洲菊、圣诞百合等,象征着祝福身体健康，事业蒸蒸日上\n");
                printf("                                                妈妈生日: \n");
                printf("     当然是送伟大的母爱之花——康乃馨了，粉色是女性的颜色，那康乃馨层层的花瓣代表着母亲对子女绵绵不断的感情。\n");
                printf("                              送一束康乃馨给妈妈，是对妈妈生日的最大感恩。\n");
                printf("                                                夫妻生日: \n");
                printf("                           百合象征着百年好合，长相厮守,玫瑰象征着爱意的表达\n");
            }
            else if(ch2=='3'){
                system("clear");
                printf("\n");
                cout<<TT;cout<<TT;
                printf("        "); cout<<STAR; printf(" "); cout<<SOFTWARE;printf(" ");cout<<STAR; cout<<NEW_LINE; cout<<NEW_LINE;
                printf("\n                                                 友情鲜花:\n\n");
                printf("                                                  百合花：\n"
                       "                                                纯洁的友谊\n\n"
                       "                                                 黄色鸢尾: \n"
                       "                                             友谊永固、热情开朗\n\n"
                       "                                                黄色夹竹桃：\n"
                       "                                                深刻的友情\n\n "
                       "                                                 黄康乃馨：\n"
                       "                                                长久的友谊\n\n"
                       "                                                 白康乃馨：\n"
                       "                                                纯结的友谊 \n\n"
                       "                                                  勿忘我：\n"
                       "                                            浓情厚意，永恒的友谊 \n\n"
                       "                                                 黄玫瑰花:\n"
                       "                                                 友谊之情 \n\n"
                       "                                                   木棉：\n"
                       "                                                友谊天长地久 \n\n"
                       "                                                  百日草：\n"
                       "                                           想念远方朋友，天长地久\n\n"
                       "                                                  万年春：\n"
                       "                                                 友谊长存 \n\n"
                       "                                                  秋海棠：\n"
                       "                                                诚挚的友谊\n \n"
                       "                                                  茉莉花：\n"
                       "                                             纯洁、清操和友谊\n\n"
                       "                                                  荷花：\n"
                       "                                              友谊的象征和使者\n\n");
            }
            else if(ch2=='4'){
                system("clear");
                printf("\n");
                cout<<TT;cout<<TT;
                printf("        "); cout<<STAR; printf(" "); cout<<SOFTWARE;printf(" ");cout<<STAR; cout<<NEW_LINE; cout<<NEW_LINE;
                printf("\n                                                问候长辈\n\n");
                printf("                                                  佛手：\n"
                       "                            佛与福音近，被视为吉祥之物，赠送长者，寓意多福多寿\n\n"
                       "                                                   菊花：\n"
                       "                别名“寿客”。为老人祝寿，颜色可挑红色、粉红色、紫色，寓意高风亮节，健康长寿\n\n"
                       "                                                 长寿花：\n"
                       "                                        可用来祝福家乐长寿，吉祥\n\n"
                       "                                                富贵龟背竹：\n"
                       "                                      被称为“植物乌龟”象征长寿吉祥\n\n"
                       "                                                  铁树：\n"
                       "                                                寓意吉祥\n\n"
                       "                                            长寿松树、鹤望兰：\n"
                       "                                      松鹤延年，是祝贺老人长寿的花木\n\n"
                       "                                              万年青、寿星草：\n"
                       "                                          祝贺老人延年益寿的花木\n\n"
                       "                                                  牡丹：\n"
                       "                                            贺富贵荣华的鲜花\n\n"
                       "                                                  剑兰：\n"
                       "                                            祝贺老人福寿康宁\n\n"
                       "                                                 南天竹：\n"
                       "                                           祝贺幸福长寿的花木\n\n"
                       "                                          紫薇、一品红、仙客来：\n"
                       "                                               寓意健康长寿\n\n"
                       "                                                寿星鸡冠：\n"
                       "                                             祝老人幸福长寿\n\n");
            }
            else if(ch2=='5'){
                system("clear");
                printf("\n");
                cout<<TT;cout<<TT;
                printf("        "); cout<<STAR; printf(" "); cout<<SOFTWARE;printf(" ");cout<<STAR; cout<<NEW_LINE; cout<<NEW_LINE;
                printf("\n                                                   探病慰问\n\n");
                printf("                探病送花，含有关怀、慰问、祝福病患平安、早日康复之意。此时应选用花色、香味淡雅的鲜花，\n"
                       "                如唐菖蒲、兰花、金桔、六出花、玫瑰及康乃馨等。忌送白色、蓝色、黑色花卉，鉴于病人的心\n"
                       "                情极为复杂，探病送花要注意防止产生误会。尽可能送些病人平常所喜欢，或较为娇艳的花草，绝\n"
                       "                不可送白的、蓝的或黑的花卉。还要注意忌送的数目：4、9、13 。另外还可选择香石竹、月季花、\n"
                       "                             水仙花、兰花等，配以文竹、满天星或石松，以祝愿贵体早日康复。\n");
                printf("                给病人送花有很多禁忌，探望病人时不要送整盆的花，以免病人误会为久病成根。香味很浓的花对\n"
                       "                手术病人不利，易引起咳嗽;颜色太浓艳的花，会刺激病人的神经，激发烦躁情绪;山茶花容易落蕾，\n"
                       "                被认为不吉利。看望病人宜送兰花、水仙、马蹄莲等，或选用病人平时喜欢的品种，有利病人怡情养性，\n"
                       "                                                   早日康复。\n");
                
            }
            else if(ch2=='6'){
                system("clear");
                printf("\n");
                cout<<TT;cout<<TT;
                printf("        "); cout<<STAR; printf(" "); cout<<SOFTWARE;printf(" ");cout<<STAR; cout<<NEW_LINE; cout<<NEW_LINE;
                printf("\n                                                婚庆鲜花:\n\n");
                printf("                                                  玫瑰:\n"
                       "         玫瑰是爱情的最佳代言人，自然也是婚花的首选。但是不同颜色的玫瑰表达不同的祝福：红玫瑰表达“深情”,\n"
                       "           粉红玫瑰表达“爱的宣言”。当然，还有白玫瑰。婚礼花最好是鲜艳的颜色，所以不推荐使用白玫瑰。\n\n");
                printf("                                                 蝴蝶兰: \n"
                       "        蝴蝶兰代表着情侣间的真爱。它看起来像一只色彩鲜艳的蝴蝶，花美丽动人。在婚礼上出现，绝对是一件非常\n"
                       "                                               漂亮的装饰品。\n\n");
                printf("                                                 百合花: \n"
                       "      百合花象征着纯洁和纯真。百合花加着麦穗作为新娘的头饰，意味着一百年的丰收。在现代婚礼中，百合花也\n"
                       "                               很受欢迎，因为它们具有“百年好合”的含义。\n\n");
                printf("                                                 康乃馨: \n"
                       "                 康乃馨代表着爱、魅力和尊重，作为婚花，可以表达“相敬如宾、”的祝福。\n\n");
                printf("                                                 剑兰: \n"
                       "              剑兰代表怀旧之情，也表达爱、意、寿、康、福。它隐含着“幸福与美满”的含义。\n\n");
                printf("                                                 涪陵花: \n"
                       "      涪陵花一般用来祝福“事业成功，前途光明”，但它也象征着坚持不懈，不怕困难。它能表达祝愿新婚夫妇相互\n"
                       "                                          尊重和相爱的美好意义。\n\n");
            }
            if(ch2=='7'){
                system("clear");
                printf("\n");
                cout<<TT;cout<<TT;
                printf("        "); cout<<STAR; printf(" "); cout<<SOFTWARE;printf(" ");cout<<STAR; cout<<NEW_LINE; cout<<NEW_LINE;
                printf("\n                                               商务鲜花\n\n");
                printf("                                                送客户:\n:"
                       "                                老虎百合【卷丹花】---财富，骄傲，繁荣\n\n"
                       "                                            喇叭水仙---尊敬\n\n"
                       "                                       天堂鸟---自由，幸福，吉祥\n\n"
                       "                                  金百合【女性】---高贵艳丽中显纯洁\n\n"
                       "                                             薄荷花---美德\n\n");
                printf("                                                送老板: \n");
                printf("      一般情况送领导可以送百合、康乃馨，向日葵，如果你是女孩子，领导是先生那么可以考虑送玫瑰（玫瑰色一\n"
                       "      定不能送红玫瑰，以免误会），反之男下属送女上司也是一样，女下属送女上司这个红玫瑰无关尽要，只要领\n"
                       "      导喜欢，为了更好的表达情感百合其实是不错的选择，全球共认的吉祥花，它的花朵大，花期长，并且还有香\n"
                       "                           味，做出来的花束会比别的花更显得大气，可以送一大束百合。\n\n");
                printf("                                                送领导: \n");
                printf("      如果是女领导的话，送那种不要带有强烈感情色彩的花就行，红玫瑰一定不适合，送康乃馨+百合花或许比较好。\n"
                       "      如果是给男领导送花以盆栽花卉为宜。盆栽花卉气派、有生命力，不管是摆放在宽敞的办公室还是家里，都具有\n"
                       "                                 很好的装饰作用。像大花蕙兰、君子兰等。\n\n");
            }
            printf("\n                                            ");
            break;
        default:
            printf("\n                                               输入有误\n\n");
            printf("\n                                            ");
            break;
    }
}
//比较日期，返回差值 (yy2/mm2/dd2 - yy1/mm1/dd1)
const int Purchaser::DateCompare(int yy1, int mm1, int dd1, int yy2, int mm2, int dd2) const {
    int sum = 0;
    if (mm1==mm2) {
        return dd2 - dd1;
    }
    else if (mm1 < mm2-1) {
        switch (mm1) {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                sum += 31 - dd1 + 1;
                break;
            case 4:case 6:case 9:case 11:
                sum += 30 - dd1 + 1;
                break;
            case 2:
                if ((yy1%4==0 && yy1%100!=0) || yy1%400==0)
                    sum += 29 - dd1 + 1;
                else
                    sum += 28 - dd1 + 1;
        }
        while (mm1 < mm2) {
            switch (mm1) {
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                    sum += 31;
                    break;
                case 4:case 6:case 9:case 11:
                    sum += 30;
                    break;
                case 2:
                    if((yy1%4==0 && yy1%100!=0) || yy1%400==0)
                        sum += 29;
                    else
                        sum += 28;
            }
            mm1++;
        }
        sum += dd2 - 1;
        return sum;
    }
    else if (mm1 < mm2) {
        switch (mm1) {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                sum += 31 - dd1 + 1;
                break;
            case 4:case 6:case 9:case 11:
                sum += 30 - dd1 + 1;
                break;
            case 2:
                if((yy1%4==0 && yy1%100!=0) || yy1%400==0)
                    sum += 29 - dd1 + 1;
                else
                    sum += 28 - dd1 + 1;
        }
        sum += dd2 - 1;
        return sum;
    }
    else if (mm1 > mm2) {
        switch (mm1) {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                sum += 31 - dd1 + 1;
                break;
            case 4:case 6:case 9:case 11:
                sum += 30 - dd1 + 1;
                break;
            case 2:
                if((yy1%4==0 && yy1%100!=0) || yy1%400==0)
                    sum += 29 - dd1 + 1;
                else
                    sum += 28 - dd1 + 1;
        }
        while (mm1 < 13) {
            switch (mm1) {
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                    sum += 31;
                    break;
                case 4:case 6:case 9:case 11:
                    sum += 30;
                    break;
                case 2:
                    if((yy1%4==0 && yy1%100!=0) || yy1%400==0)
                        sum += 29;
                    else
                        sum += 28;
            }
            mm1++;
        }
        mm1 = 1;
        if(mm1 < mm2-1){
            switch (mm1) {
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                    sum += 31 - dd1 + 1;
                    break;
                case 4:case 6:case 9:case 11:
                    sum += 30 - dd1 + 1;
                    break;
                case 2:
                    if((yy2%4==0 && yy2%100!=0)||yy2%400==0)
                        sum += 29 - dd1 + 1;
                    else
                        sum += 28 - dd1 + 1;
            }
            while(mm1 < mm2) {
                switch (mm1) {
                    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                        sum += 31;
                        break;
                    case 4:case 6:case 9:case 11:
                        sum += 30;
                        break;
                    case 2:
                        if((yy2%4==0 && yy2%100!=0) || yy2%400==0)
                            sum += 29;
                        else
                            sum += 28;
                }
                sum += dd2 - 1;
                return sum;
            }
        }
        else if (mm1 < mm2) {
            switch (mm1) {
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                    sum += 31 - dd1 + 1;
                    break;
                case 4:case 6:case 9:case 11:
                    sum += 30 - dd1 + 1;
                    break;
                case 2:
                    if((yy1%4==0 && yy1%100!=0) || yy1%400==0)
                        sum += 29 - dd1 + 1;
                    else
                        sum += 28 - dd1 + 1;
            }
            sum += dd2 - 1;
            return sum;
        }
    }
    return 0;
}
//花店地址导航
void Purchaser::NavigateShopAddress() const {
    cout<<endl<<TT<<TT;
    cout<<"        "<<STAR<<" "<<SOFTWARE<<" "<<STAR<<endl<<endl;
    Map m;
    m.InitMap();
    cout <<endl<< "                                       请输入要搜索的商家店名: ";
    string shop_name;
    cin >> shop_name;
    MapNode node = m.SearchMap(shop_name);
    if (node.x == -1) {
        cout <<endl<< "                                        您要搜索的商家不存在" << endl;
        return ;
    }
    cout <<endl<< "                                               地图信息如下: "<<endl<<endl;
    m.ShowMap();
    cout <<endl<< "                                            请输入您所在位置: ";
    char x, y;
    cin >> x >> y;
    path_node start = m.locate(x, y);
    m.ChangeMap(node, start);
    cout <<endl<< "                                            已为您规划最短路线: " << endl;
    m.ShowMap();
    cout << endl;
}
