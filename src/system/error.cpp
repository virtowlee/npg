/*
 * socket_error.cpp
 *
 *  Created on: 2011-8-23
 *      Author: Young <public0821@gmail.com>
 */

#include "error.h"
#include "system/os.h"

Error::Error()
:m_is_error(false)
{
	bzero(m_error, sizeof(m_error));
}

Error::~Error()
{
	// TODO Auto-generated destructor stub
}
