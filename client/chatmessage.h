#ifndef CHATMESSAGE_H
#define CHATMESSAGE_H

#include <string>
#include "client.h"

struct ChatMessage
{
	Client* sender;
	std::string content;
};

#endif // CHATMESSAGE_H
