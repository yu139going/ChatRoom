#include "ChatClient.h"

// TcpClient�󶨻ص������������ӻ��߶Ͽ�������ʱ����
void ChatClient::onConnection(const muduo::net::TcpConnectionPtr &con)
{
	/*
	���ӷ������ɹ��󣬿����ͷ������Ľ���ͨ�Ź���
	*/
	if (con->connected()) // �ͷ��������ӳɹ�
	{
		LOG_INFO << "connect server success!";
		// �����߳�ר�Ŵ����û����������
		_pool.run(bind(&ChatClient::userClient, this, con));
	}
	else // �ͷ���������ʧ��
	{

	}
}

// TcpClient�󶨻ص��������������ݽ���ʱ����
void ChatClient::onMessage(const muduo::net::TcpConnectionPtr &con,
	muduo::net::Buffer *buf,
	muduo::Timestamp time)
{
	/*
	������շ�������Ӧ����Ϣ���ڿͻ��˽�����ʾ
	*/
}

// �����û����������
void ChatClient::userClient(const muduo::net::TcpConnectionPtr &con)
{

}