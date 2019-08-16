#include "ChatClient.h"

// TcpClient绑定回调函数，当连接或者断开服务器时调用
void ChatClient::onConnection(const muduo::net::TcpConnectionPtr &con)
{
	/*
	连接服务器成功后，开启和服务器的交互通信功能
	*/
	if (con->connected()) // 和服务器连接成功
	{
		LOG_INFO << "connect server success!";
		// 启动线程专门处理用户的输入操作
		_pool.run(bind(&ChatClient::userClient, this, con));
	}
	else // 和服务器连接失败
	{

	}
}

// TcpClient绑定回调函数，当有数据接收时调用
void ChatClient::onMessage(const muduo::net::TcpConnectionPtr &con,
	muduo::net::Buffer *buf,
	muduo::Timestamp time)
{
	/*
	负责接收服务器响应的消息，在客户端进行显示
	*/
}

// 处理用户的输入操作
void ChatClient::userClient(const muduo::net::TcpConnectionPtr &con)
{

}