#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include "tcp/tcpclient.h"
#include "client/client.h"
#include "client/channel.h"

class Server
{
public:
	Server(tcp::Client* connection);
	~Server();

	tcp::Client* tcp_client;

	void on_receive_clients(std::vector<Client*>& client_list);
	void on_receive_channels(std::vector<Channel*>& channel_list);

private:
	// List of clients that are online on this server
	std::vector<Client*> clients;

	// List of this server's channels
	std::vector<Channel*> channels;
};

#endif // SERVER_H
