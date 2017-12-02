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

	auto produceDevices = [](int nDevices)
	{
		std::vector<std::shared_ptr<Inode<float>>>devices;
		while (nDevices--)
		{
			devices.push_back(std::make_shared<Device>());
		}
		return devices;
	};

	auto relateParentsAndSons = [](auto parents, auto sons, std::string message)
	{	
		auto nParents = parents.size();
		cout << message << " >\n";
		auto selectSonByIndex = 0;
		for(auto son:sons)
		{
			auto selectParentByIndex = rand()%nParents;
			son -> connectSourceNode(parents[selectParentByIndex]);
			parents[selectParentByIndex] -> connectSinkNode(son);
			cout << "parent: " << selectParentByIndex << " -> son: " << selectSonByIndex++ << "\n";  
		}

	};

	test a;


	auto routers = produceDevices(a.routers);
	auto switches = produceDevices(a.switches);
	auto customers = produceDevices(a.customers);

	relateParentsAndSons(routers,switches,"routers parenting switches!");
	relateParentsAndSons(switches,customers,"switches parenting customers!");

	return 0;

}