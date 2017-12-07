#ifndef TOOLS_H
#define TOOLS_H
#include <iostream>
#include <cstdio>
#include <chrono>
#include <thread>
#include <ctime>
#include <cstring>
#include <mutex>
#include <thread>
#include <bitset>
//#include <QtCore>
//#include <QUdpSocket>
//#include <QNetworkInterface>
#include <list>

//class Tools
//{
//public:
//    Tools();
//};

using namespace std;

class Tools
{

public:
    enum FIXED_VALUE{
        PATH_LENGTH=200,
        BUF_LENGTH=200
    };
    static mutex lock;
private:
    int cc=0;

    static  char filename[FIXED_VALUE::PATH_LENGTH];
    const int static buf_size=200;


public:

    Tools()
    {
    }
    inline static void prt(const char *buf,const int line_no,const char *func_name,const char *file_name,const char *label,const char *time)
    {
        char buffer[buf_size];
        memset(buffer,0,buf_size);
        memcpy(buffer,time,strlen(time));
        int i;
        for( i=0;buffer[i]!='\n';i++)
            ;
        buffer[i]='\0';

        cout<<"("<<buf<<")"<<'['<<line_no<<']'<<'['<<func_name<<']'<<'['<<file_name<<']'<<'['<<buffer<<']'<<'['<<label<<']'<<endl;

    }
    inline static char* get_time()
    {
        chrono::system_clock::time_point today= chrono::system_clock::now();
        time_t tt= chrono::system_clock::to_time_t(today);
        return ctime(&tt);
    }
    static void init(const char *)
    {
    }
    static int  aaaa;
    static const int ss=123;
    enum test{
        ABC=1,
        BCD=2
    };
    typedef test sss;

    void aaa()
    {



    }
};
#define prt(label,...) {Tools::lock.lock(); Tools::init("log.txt"); char buf[1000];sprintf(buf,__VA_ARGS__);\
    Tools::prt(buf,__LINE__,__FUNCTION__,__FILE__,#label,Tools::get_time());Tools::lock.unlock();}
#endif // TOOLS_H
