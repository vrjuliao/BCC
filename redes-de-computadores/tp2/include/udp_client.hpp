#ifndef UDP_CLIENT_TP2_REDES
#define UDP_CLIENT_TP2_REDES

#include <sys/socket.h>
#include <cstdlib>
#include <string>

class UDPClient{
private:
    sockaddr_storage sck_addr;
	int sck_id;
    
    void init_client_socket(const char *ipaddr, const char *sck_port);
public:
	UDPClient(const char *ipaddr, const char *sck_port);
	std::string ask_by_hostname(const std::string &hostname);

	// @override QuickSort_Median::QuickSort::begin
	// calculate quantity of elements necessary to start insertion sort and start the recursivity of quicksort 
	// virtual void begin(unsigned int vector[], int num_elements) override;
	virtual ~UDPClient();
};

#endif