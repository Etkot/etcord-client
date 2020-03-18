#ifndef TCPMESSAGESEND_H
#define TCPMESSAGESEND_H

#include <string>
#include "server.h"

namespace tcp {
	void request_clients(Server* server);
	void request_channels(Server* server);

	void send_chat_message(Server* server, std::string message);
}

#endif // TCPMESSAGESEND_H
