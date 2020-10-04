#ifndef UDP_SERVER_TP2_REDES
#define UDP_SERVER_TP2_REDES

#include <sys/socket.h>
#include <cstdlib>
#include <string>

class UDPServer{
private:
    sockaddr_storage sck_addr, cli_sockaddr;
	int server_sck_id;

	// Bind server proccess
	// the IPversion is based on the static attribute Utils::IPVERSION
    void init_server_socket(const char *sck_port);
public:
	UDPServer(const char *sck_port);
	
	// wait a request message asking the hostname
	std::string recv_hostname();

	// send the hostaddress according to hostname asked earlier
	void send_hostaddress(const std::string &msg);
	
	~UDPServer();
};

#endif