#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <memory>
#include <list>
#include <string>

class Socket;
class SocketObserver
{
public:
	SocketObserver() {}
	virtual ~SocketObserver() {}
	virtual void update(Socket& socket, const std::string data) = 0; 
	//Instead of update can use meaningful name like onData, onRecvData, etc ...
};

class Socket
{
public:
	Socket() {}
	virtual ~Socket() {}
	void onData(const std::string data)
	{
		notifyObservers(data);
	}

	void registerObserver(std::shared_ptr<SocketObserver> observer)
	{
		m_observers.push_back(observer);
	}

private:
	void notifyObservers(const std::string data)
	{
		for (auto observer : m_observers)
		{
			observer->update(*this, data);
		}
	}
	std::list<std::shared_ptr<SocketObserver>> m_observers;
};

class WindowObserver : public SocketObserver
{
public:
	WindowObserver() {}
	virtual ~WindowObserver() {}
	void update(Socket& socket, const std::string data) override
	{
		std::cout << "Data received by WindowObserver. Data:" << data << std::endl;
	}
};

class ContainerObserver : public SocketObserver
{
public:
	ContainerObserver() {}
	virtual ~ContainerObserver() {}
	void update(Socket& socket, const std::string data) override
	{
		std::cout << "Data received by ContainerObserver. Data:" << data << std::endl;
	}
};

int main()
{
	std::unique_ptr<Socket> socket = std::make_unique<Socket>();
	std::shared_ptr<SocketObserver> observer1 = std::make_shared<WindowObserver>();
	std::shared_ptr<SocketObserver> observer2 = std::make_shared<ContainerObserver>();
	socket->registerObserver(observer1);
	socket->registerObserver(observer2);

	socket->onData("Test data");

	std::cin.get();
}


