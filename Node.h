#pragma once
#include <stdio.h>
namespace dbms
{
	struct USERDATA
	{
		unsigned int age;
		char name[32];
		char phone[32];
		USERDATA* pNext;
	};

	class Node
	{
	public:
		Node();
		~Node();
		bool AddNewNode(unsigned int age, const char* pszName, const char* pszPhone);
		bool RemoveNode(USERDATA* pPrev);
		USERDATA* SearchByName(const char* pszName);
		bool SerachToRemove(const char* pszName);
		void PrintList() const;
		static bool LoadList();
		static bool SaveList(USERDATA* datas);
	
	private:
		USERDATA* mHeadNode;
	};
}