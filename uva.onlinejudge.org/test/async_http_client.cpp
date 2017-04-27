/*
 * async_http_client.cpp
 *
 *  Created on: Apr 25, 2017
 *      Author: frank
 */
#include <iostream>
#include "async_http_client.h"

using namespace std;

//====================================================================
//class Poller
int ClientPoller::Init()
{
    //create epoll fd
    epoll_fd_ = epoll_create(256);
    if(-1 == epoll_fd_)
    {
        //TODO: errno
        return -1;
    }

    pool_.resize(pool_size_);
    for(auto it = pool_.begin(); it != pool_.end(); ++it)
    {
        free_list_.push_back(&*it);
    }

    return 0;
}

int ClientPoller::ProcessEvents()
{
    struct epoll_event events[100];
    int nfds = epoll_wait(epoll_fd_, events, 100, 0); // 0 ms at most
    if(-1 == nfds)
    {
        //TODO: errno
        return -1;
    }

    for(int i = 0; i < nfds; ++i)
    {

    }

    return nfds;
}

int ClientPoller::GetRequest(std::string host, std::string path)
{
    int fd = socket(AF_INET, SOCK_STREAM|SOCK_NONBLOCK, 0);
    if(-1 == fd)
    {
        //TODO: errno
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    if(0 == inet_aton(host.c_str(), &serv_addr.sin_addr))
    {
        //TODO: inet_aton error
        return -1;
    }

    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = fd;
    if(-1 == epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, fd, &ev))
    {
        cout<<"epoll_ctl error, errno:"<<errno<<endl;
        return -1;
    }

    if(-1 == connect(fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)))
    {
        //TODO: errno
        cout<<"connect, errno:"<<errno<<"\n";
        return -1;
    }

    // send message
}
