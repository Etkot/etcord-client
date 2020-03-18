#include "tcpmessagereceive.h"

#include <cstring>
#include "tcpmessagetypes.h"


namespace tcp {
	void get_clients(Server* server, char* buffer, int length); // TCP_GET_CLIENTS
	void get_channels(Server* server, char* buffer, int length); // TCP_GET_CHANNELS

	void chat_message(Server* server, char* buffer, int length); // TCP_CHAT_MESSAGE
}


void tcp::read_messages(Server* server) {
	char buffer[1024] = {0};
	while (true) {
		int len = server->tcp_client->read(buffer, 1024);

		if (len == 0) break;

		char message_type = buffer[0];
		switch (message_type) {
		case TCP_ERROR:

			break;
		case TCP_GET_CLIENTS:
			get_clients(server, buffer + 1, len - 1);
			break;
		case TCP_GET_CHANNELS:
			get_channels(server, buffer + 1, len - 1);
			break;
		case TCP_GET_TEXT_HISTORY:

			break;
		case TCP_CHAT_MESSAGE:
			chat_message(server, buffer + 1, len - 1);
			break;
		case TCP_VOICE_CHANNEL_JOIN:

			break;
		case TCP_VOICE_CHANNEL_LEAVE:

			break;
		default:
			// Unsupported message type

			break;
		}
	}
}



// TCP_GET_CLIENTS
void tcp::get_clients(Server* server, char* buffer, int length) {
	if (length % sizeof(::Client) != 0) {
		// Buffer has invalid length
		return;
	}

	std::vector<::Client*> clients;

	for (unsigned int i = 0; i < length / sizeof(::Client); i++) {
		::Client* c = new ::Client();
		clients.push_back(c);

		memcpy(c, buffer + (sizeof(::Client) * i), sizeof(::Client));
	}

	server->on_receive_clients(clients);
}

// TCP_GET_CHANNELS
void tcp::get_channels(Server* server, char* buffer, int length) {
	if (length % sizeof(::Channel) != 0) {
		// Buffer has invalid length
		return;
	}

	std::vector<::Channel*> channels;

	for (unsigned int i = 0; i < length / sizeof(::Channel); i++) {
		::Channel* c = new ::Channel();
		channels.push_back(c);

		memcpy(c, buffer + (sizeof(::Channel) * i), sizeof(::Channel));
	}

	server->on_receive_channels(channels);
}



// TCP_CHAT_MESSAGE
void tcp::chat_message(Server* server, char* buffer, int length) {
	//if (buffer[0] == channelID) {
	//	print(buffer + 1, length - 1);
	//}
}
