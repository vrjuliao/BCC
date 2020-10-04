#ifndef UDP_CLIENT_TP2_REDES
#define UDP_CLIENT_TP2_REDES

#include <sys/socket.h>
#include <cstdlib>
#include <string>

class UDPClient{
private:
    sockaddr_storage sck_addr;
	int sck_id;
    
	// create a client socket with the server information (ipaddr, sck_port)
    void init_client_socket(const char *ipaddr, const char *sck_port);
public:
	UDPClient(const char *ipaddr, const char *sck_port);

	// request an hostname and get the response
	std::string ask_by_hostname(const std::string &hostname);

	virtual ~UDPClient();
};

#endif