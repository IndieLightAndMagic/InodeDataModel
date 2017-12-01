#include "Device.h"

#include <cstdlib>
#include <iostream>
#include <ctime>


using namespace std;
class test{

	int random_variable;
public:
	int routers,customers,switches;
	test(){
		std::srand(std::time(0));
		random_variable = rand();

		routers = (random_variable & 0xf) + 1;
		random_variable >>= 4;
		switches = (random_variable & 0x2f) + 1;
		random_variable >>= 6;
		customers = (random_variable & 0xff) + 1;

		cout << "routers : " << routers << "\n";
		cout << "switches : " << switches << "\n";
		cout << "customers : " << customers << "\n";
	

	}

};


int main(void)
{

	test a;

	
	
	std::shared_ptr<Inode<float>> i = std::make_shared<Device>();
	std::shared_ptr<Device> j = std::make_shared<Device>();	
	i->connectSinkNode(j);
	return 0;

}