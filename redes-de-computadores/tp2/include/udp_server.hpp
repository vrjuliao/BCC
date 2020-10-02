#ifndef UDP_SERVER_TP2_REDES
#define UDP_SERVER_TP2_REDES

#include <sys/socket.h>
#include <cstdlib>

class UDPServer{
private:
    sockaddr_storage sck_addr, cli_sockaddr;
	int server_sck_id;

    void init_server_socket(const char *sck_port);
public:
	UDPServer(const char *sck_port);
	std::string recv_hostname();
	void send_hostaddress(const std::string &msg);
	~UDPServer();
};

#endif