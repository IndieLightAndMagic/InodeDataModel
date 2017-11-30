#ifndef __DEVICE_H__
#define __DEVICE_H__
#include <iostream>
#include <string>
#include "Inode.h"

using namespace std;
class Device : public Inode<float> {

protected:

	string name;
public:
	void connectSinkNode(shared_ptr<Inode<float>> p) override{ cout << "SINK\n";}
	void connectSourceNode(shared_ptr<Inode<float>> p) override{ cout << "SOURCE\n";}

	~Device() override{ cout << "KILLING\n"; }


};



#endif /* __DEVICE_H__ */
