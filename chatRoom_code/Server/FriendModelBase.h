#pragma once

#include "MySQL.h"

// Model��ĳ�����
class FriendModelBase
{
public:
	// ���Ӻ�����Ϣ
	virtual void add(int userid, int friendid) = 0;
};

// Friend���Model�����
class FriendModel : public FriendModelBase
{
public:
	void add(int userid, int friendid)
	{
	
	}
};
