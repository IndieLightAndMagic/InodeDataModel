#include "Device.h"

int main(void)
{

	std::shared_ptr<Inode<float>> i = std::make_shared<Device>();
	std::shared_ptr<Device> j = std::make_shared<Device>();	
	i->connectSinkNode(j);
	return 0;

}