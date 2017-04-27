/*
 * http_client.h
 *  very simple http client class.
 *  make it async to put it into epoll.
 *  Created on: Apr 24, 2017
 *      Author: frank
 */

#ifndef _ASYNC_HTTP_CLIENT_H_
#define _ASYNC_HTTP_CLIENT_H_
#include <stdio.h> /* printf, sprintf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <sys/types.h>
#include <sys/socket.h> /* socket, connect */
#include <sys/epoll.h>
#include <fcntl.h>
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h> /* struct hostent, gethostbyname */
#include <arpa/inet.h>
#include <errno.h>
#include <string>
#include <map>
#include <vector>
#include <list>

class AsnycHttpClient
{
public:
    int Get();
    int Post();
private:
    std::string host_;
    int port_;
private:
    int fd_; //sock fd
    std::string resp_; // response
};

class ClientPoller
{
public:
    ClientPoller(size_t pool_size):pool_size_(pool_size){}
    int Init();
    int ProcessEvents();
    int GetRequest(std::string host, std::string path);
private:
    int epoll_fd_ = -1;
    const size_t pool_size_;
    std::vector<AsnycHttpClient> pool_;
    std::list<AsnycHttpClient*> free_list_;
};



#endif /* _ASYNC_HTTP_CLIENT_H_ */
