/*
 * ahttpcli.cpp
 *
 *  Created on: Apr 27, 2017
 *      Author: frank
 */
#include "async_http_client.h"
#include <iostream>

using namespace std;

int main()
{
    ClientPoller poller(10);
    int ret = poller.Init();
    if(0 != ret)
    {
        cout<<"poller init error:"<<ret<<endl;
        return 0;
    }

    ret = poller.GetRequest("14.17.32.211", "/");
    if(0 != ret)
    {
        cout<<"get request eror, ret="<<ret<<endl;
        return 0;
    }

    for(int i = 0; i < 1000; ++i)
    {
        poller.ProcessEvents();
    }

    return 0;
}



