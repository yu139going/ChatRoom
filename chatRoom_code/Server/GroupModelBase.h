#pragma once

#include "GroupDO.h"
#include "MySQL.h"

// Model��ĳ�����
class GroupModelBase
{
public:
	// ���Ӻ�����Ϣ
	virtual void add(GroupDO &grooup) = 0;
};

// Group���Model�����
class GroupModel : public GroupModelBase
{
public:
	void add(GroupDO &group)
	{
		
	}
};