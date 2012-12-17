/*
 * tcp.h
 *
 *  Created on: 2011-8-23
 *      Author: Young <public0821@gmail.com>
 */

#ifndef TCP_H_
#define TCP_H_

#include "../types.h"
#include <time.h>

class Tcp
{
public:
	Tcp();
	~Tcp();
public:
	bool connect(const char* ip, uint16_t port, time_t timeout);
	bool send(const char* buffer, size_t buffer_len);
	int recv(char* buffer, size_t buffer_len);
	bool setBlocking(bool blocking);
private:
	int m_sockfd;
	bool m_blocking;
};

#endif /* TCP_H_ */