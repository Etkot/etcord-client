#include "server.h"

#include "tcp/tcpmessagesend.h"

Server::Server(tcp::Client* connection)
{
	tcp_client = connection;

	tcp::request_clients(this);
	tcp::request_channels(this);
}



void Server::on_receive_clients(std::vector<Client*>& client_list) {
	for (unsigned int i = 0; i < clients.size(); i++) {
		delete clients.at(i);
	}

	clients = client_list;
}
void Server::on_receive_channels(std::vector<Channel*>& channel_list) {
	for (unsigned int i = 0; i < channels.size(); i++) {
		delete channels.at(i);
	}

	channels = channel_list;
}
