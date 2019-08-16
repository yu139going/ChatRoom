#pragma once

#include <muduo/net/TcpServer.h>
#include <muduo/base/Logging.h>
#include <boost/bind.hpp>
#include <unordered_map>
#include <functional>
#include "public.h"
#include "json.hpp"
using json = nlohmann::json;

/*
ͨ�õķ�����������࣬����ͳһ�ӿڣ�����ͬʱ��չ�����������ͼ�Ⱥ��������������ʵ��
*/
class CommonServiceBase
{	
public:
	CommonServiceBase()
	{
		// ���û��¼������ӿں���
		_handlerMap.insert({ MSG_LOGIN, bind(&CommonServiceBase::login, this, _1, _2, _3) });
		_handlerMap.insert({ MSG_REG, bind(&CommonServiceBase::reg, this, _1, _2, _3) });
		// ������handler�󶨸���Ľӿں���
	}

	// login service
	virtual void login(const muduo::net::TcpConnectionPtr &con,
		json &js, muduo::Timestamp time) = 0;

	// register service
	virtual void reg(const muduo::net::TcpConnectionPtr &con,
		json &js, muduo::Timestamp time) = 0;

	// add friend service
	virtual void addFriend(const muduo::net::TcpConnectionPtr &con,
		json &js, muduo::Timestamp time) = 0;

	// add group service
	virtual void addGroup(const muduo::net::TcpConnectionPtr &con,
		json &js, muduo::Timestamp time) = 0;

	// one to one chat service
	virtual void oneChat(const muduo::net::TcpConnectionPtr &con,
		json &js, muduo::Timestamp time) = 0;

	// group chat service
	virtual void groupChat(const muduo::net::TcpConnectionPtr &con,
		json &js, muduo::Timestamp time) = 0;

	using Handler = std::function<void(const muduo::net::TcpConnectionPtr&, json&, muduo::Timestamp)>;
	std::unordered_map<int, Handler> handler()const { return _handlerMap; }
protected:
	std::unordered_map<int, Handler> _handlerMap;
};