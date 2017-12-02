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
	void connectSinkNode(shared_ptr<Inode<float>> p) override{ 
		auto t = tuple<float,float,shared_ptr<Inode<float>>>(0.0f, 0.0f, p);
		sinks.push_back(t); 
		cout << "SINK\n";
	}
	void connectSourceNode(shared_ptr<Inode<float>> p) override{ 
		auto t = tuple<float,float,shared_ptr<Inode<float>>>(0.0f, 0.0f, p);
		sources.push_back(t); 
		cout << "SOURCE\n";
	}
	~Device() override{ }


};


#endif /* __DEVICE_H__ */
