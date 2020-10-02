#ifndef UDP_CLIENT_TP2_REDES
#define UDP_CLIENT_TP2_REDES

#include <sys/socket.h>
#include <cstdlib>

class UDPClient{
private:
    sockaddr_storage *sck_addr;
    
	int mPercentual; //Define the percentual of elements that will be sorted by 'insertion sort'
	int mNumElementsToBeginInsertionSort;

	//sort by insertion algorithm
	void insertion_sort(unsigned int vector[], int left, int right);
    void init_client_socket(const char *ipaddr, const char *sck_port);
public:
	UDPClient(const char *ipaddr, const char *sck_port);

	// @override QuickSort_Median::QuickSort::begin
	// calculate quantity of elements necessary to start insertion sort and start the recursivity of quicksort 
	// virtual void begin(unsigned int vector[], int num_elements) override;
protected:
	// @override QuickSort_Median::QuickSort::sort
	// verify if the quantity of elements is correct to begin insertion sort
	// start insertion sort or restart the recursivity of quicksort according the quantity of elements on the sub-vector
	// virtual void sort(unsigned int vector[], int &left, int &right) override;
	virtual ~UDPClient();
};

#endif