#include "tcpmessagesend.h"

#include <cstring>
#include "tcpmessagetypes.h"

#include <QDebug>

namespace tcp {
	void request(Server *server, char request_type) {
		char buffer[1] = { request_type };
		server->tcp_client->send(buffer, 1);
	}
}


void tcp::request_clients(Server *server)
{
	request(server, TCP_GET_CLIENTS);
}

void tcp::request_channels(Server *server)
{
	request(server, TCP_GET_CHANNELS);
}



void tcp::send_chat_message(Server *server, std::string message)
{
	int length = 1 + message.length();

	char buffer[length] = { TCP_CHAT_MESSAGE };
	const char* msg = message.c_str();
	memcpy(buffer + 1, msg, strlen(msg));

	server->tcp_client->send(buffer, length);
}
