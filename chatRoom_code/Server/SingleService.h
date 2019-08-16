#pragma once

#include "CommonServiceBase.h"
#include "UserModelBase.h"
#include "FriendModelBase.h"
#include "GroupModelBase.h"

// ����������ҵ��ʵ��
class SingleService : public CommonServiceBase
{
public:
	static SingleService& getInstance()
	{
		static SingleService instance;
		return instance;
	}
	SingleService(const SingleService&) = delete;
	SingleService& operator=(const SingleService&) = delete;

	// login service
	virtual void login(const muduo::net::TcpConnectionPtr &con,
		json &js, muduo::Timestamp time)
	{
		int id = js["userid"];
		string name = js["username"];
		string pwd = js["userpwd"];

		UserDO user;
		user.setID(id);
		user.setName(name);
		user.setPassword(pwd);

		if (userModelPtr->login(user)) // ��¼�ɹ�
		{
			LOG_INFO << "login service!name->" << name << " pwd->"
				<< pwd << " success!!!";

			json js;
			js["msgid"] = MSG_ACK;
			js["code"] = ACK_SUCCESS;
			// ��¼�ɹ������û���id����
			js["userid"] = user.getID();
			con->send(js.dump());
		}
		else // ��¼ʧ��
		{
			LOG_INFO << "login service!name->" << name << " pwd->"
				<< pwd << " error!!!";

			json js;
			js["msgid"] = MSG_ACK;
			js["code"] = ACK_ERROR;
			con->send(js.dump());
		}
	}

	// register service
	virtual void reg(const muduo::net::TcpConnectionPtr &con,
		json &js, muduo::Timestamp time)
	{
		string name = js["username"].get<string>();
		string pwd = js["userpwd"].get<string>();
		
		UserDO user;
		user.setID(-1);
		user.setName(name);
		user.setPassword(pwd);

		if (userModelPtr->add(user)) // ע��������ݳɹ�
		{
			LOG_INFO << "reg service!name->" << name << " pwd->"
				<< pwd << " success!!!";

			json js;
			js["msgid"] = MSG_ACK;
			js["code"] = ACK_SUCCESS;
			con->send(js.dump());
		}
		else // ע���������ʧ��
		{
			LOG_INFO << "reg service!name->" << name << " pwd->"
				<< pwd << " error!!!";

			json js;
			js["msgid"] = MSG_ACK;
			js["code"] = ACK_ERROR;
			con->send(js.dump());
		}
	}

	// add friend service
	virtual void addFriend(const muduo::net::TcpConnectionPtr &con,
		json &js, muduo::Timestamp time)
	{
	
	}

	// add group service
	virtual void addGroup(const muduo::net::TcpConnectionPtr &con,
		json &js, muduo::Timestamp time)
	{

	}

	// one to one chat service
	virtual void oneChat(const muduo::net::TcpConnectionPtr &con,
		json &js, muduo::Timestamp time)
	{

	}

	// group chat service
	virtual void groupChat(const muduo::net::TcpConnectionPtr &con,
		json &js, muduo::Timestamp time)
	{

	}
private:
	unique_ptr<UserModelBase> userModelPtr;
	unique_ptr<FriendModelBase> friendModelPtr;
	unique_ptr<GroupModelBase> groupModelPtr;

	SingleService()
		: userModelPtr(new UserModel())
		, friendModelPtr(new FriendModel())
		, groupModelPtr(new GroupModel())
	{}
};

// ȫ�ֽӿڣ�����SingleService�����Ψһʵ��
static SingleService& App()
{
	return SingleService::getInstance();
}