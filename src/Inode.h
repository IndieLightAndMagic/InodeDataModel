#ifndef __INODE_H__
#define __INODE_H__
#include <tuple>
#include <vector>
#include <memory>
using namespace std;
template <typename T>
class Inode{

protected:
	vector<tuple<T,T,shared_ptr<Inode>>> sinks;
	vector<tuple<T,T,shared_ptr<Inode>>> sources;
public:
	virtual void connectSinkNode(shared_ptr<Inode<T>>) = 0;
	virtual void connectSourceNode(shared_ptr<Inode<T>>) = 0;
	


	virtual ~Inode(){}
};
#endif