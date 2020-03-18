#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <string>

namespace tcp {
	enum class Status { Unconnected=0, Connected=1, Disconnected=2 };

	class Client
	{
	public:
		Client();

		bool connect(char *address, ushort &port);
		void disconnect();
		bool send(char *message, int length);
		int read(char *buffer, int size);

		Status get_status() { return status_; }

	private:
		int sock_ = 0;
		Status status_;
	};
}

#endif // TCPCLIENT_H
