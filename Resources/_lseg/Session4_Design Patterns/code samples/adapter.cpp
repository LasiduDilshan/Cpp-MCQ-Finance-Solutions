#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <memory>
#include <string>

class Message
{
public:
	Message() {}
	virtual ~Message() {}
};

class Encoder
{
public:
	Encoder() {}
	virtual ~Encoder() {}

	virtual const std::string encode(Message& msg) = 0;
};

class JsonEncoder : public Encoder
{
public:
	JsonEncoder() {}
	virtual ~JsonEncoder() {}

	const std::string encode(Message& msg) override /*final also available*/
	{
		std::cout << "JsonEncoder::encode" << std::endl;
		return "JsonEncoder - encoded buffer";
	}
};

class OldXMLEncoder
{
public:
	OldXMLEncoder() {}
	virtual ~OldXMLEncoder() {}

	const void encode(Message& msg, std::string& encoded)
	{
		std::cout << "OldXMLEncoder::encode" << std::endl;
		encoded = "OldXMLEncoder - encoded buffer";
	}
};

class XMLEncoder : public Encoder
{
public:
	XMLEncoder() {}
	virtual ~XMLEncoder() {}

	const std::string encode(Message& msg) override /*final also available*/
	{
		std::cout << "XMLEncoder::encode" << std::endl;
		std::string encodedBuffer;
		m_oldEncoder.encode(msg, encodedBuffer);
		return encodedBuffer;
	}

private:
	OldXMLEncoder m_oldEncoder;
};


int main()
{
	Message msg;
	std::unique_ptr<Encoder> e1 = std::make_unique<JsonEncoder>();
	std::cout << e1->encode(msg) << std::endl;

	std::cout << std::endl;
	std::unique_ptr<Encoder> e2 = std::make_unique<XMLEncoder>();
	std::cout << e2->encode(msg) << std::endl;

	std::cin.get();
}

