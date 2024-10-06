#pragma once
#include "Node.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
namespace dbms
  { 
	Node::Node()
	{
		mHeadNode = NULL;
	}

	Node::~Node()
	{
		USERDATA* pTmp = mHeadNode;
		USERDATA* pDelete;
		while (pTmp != NULL)
		{
			pDelete = pTmp;
			pTmp = pTmp->pNext;
			
			printf("DELETE: [%p] %d, %s, %s [%p]\n", pDelete, pDelete->age, pDelete->name, pDelete->phone, pDelete->pNext);
			delete pDelete;
		}
	}
	bool Node::AddNewNode(unsigned int age, const char* pszName, const char* pszPhone)
	{
		if (pszName == NULL || pszPhone == NULL)
			return false;

		USERDATA* pNewNode = new USERDATA();
		pNewNode->age = age;
		memcpy(pNewNode->name, pszName, 32);
		memcpy(pNewNode->phone, pszPhone, 32);
		pNewNode->pNext;
		if (mHeadNode == NULL)
		{
			mHeadNode = pNewNode;
		}
		else
		{
			USERDATA* pTail = mHeadNode;
			while (pTail->pNext != NULL)
			{
				pTail = pTail->pNext;
			}
			pTail->pNext = pNewNode;
		}

		return true;
	}

	bool Node::RemoveNode(USERDATA* pPrev)
	{
		USERDATA* pRemove = NULL;
		if (pPrev == NULL)
		{
			if (mHeadNode == NULL)
				return false;
			else
			{
				pRemove = mHeadNode;
				mHeadNode = mHeadNode->pNext;
				printf("REMOVE NODE : %s\n", pRemove->name);
				delete pRemove;
				return true;
			}
		}
		else
		{
			pRemove = pPrev->pNext;
			pPrev->pNext = pRemove->pNext;
			printf("REMOVE NODE : %s\n", pRemove->name);
			delete pRemove;
			return true;
		}
	}

	USERDATA* Node::SearchByName(const char* pszName)
	{
		USERDATA* pTemp = mHeadNode;
		while (pTemp != NULL)
		{
			if (strcmp(pTemp->name, pszName) == 0)
			{
				printf("%s FOUND\n", pszName);
				return pTemp;
			}
			else
			{
				pTemp = pTemp->pNext;
			}
		}
		printf("%s NOT FOUND\n", pszName);
		return NULL;
	}

	bool Node::SerachToRemove(const char* pszName)
	{
		USERDATA* pTarget = SearchByName(pszName);
		if (pTarget != NULL)
		{
			RemoveNode(pTarget);
			return true;
		}
		
		return false;
	}
	bool Node::LoadList()
	{
		FILE* fp = NULL;
		fopen_s(&fp, "listData.dat", "rb");
		if (fp == NULL)
		{
			printf("Failed open File [ERROR CODE: %d]", GetLastError());
			return false;
		}

		USERDATA user = { 0 };
		while (fread(&user, sizeof(USERDATA), 1, fp) > 0)
		{
			printf("%d, %s, %s\n", user.age, user.name, user.phone);
			memset(&user, 0, sizeof(USERDATA));
		}
		fclose(fp);
		return true;
	}
	bool Node::SaveList(USERDATA* datas)
	{
		FILE* fp = NULL;
		fopen_s(&fp, "listData.dat", "wb");
		if (fp == NULL)
		{
			printf("Failed open File [ERROR CODE: %d]", GetLastError());
			return false;
		}
		
		USERDATA* pUser = &datas[0];
		while (pUser != NULL)
		{
			fwrite(pUser, sizeof(USERDATA),1 ,fp);
			pUser = pUser->pNext;
		}
		fclose(fp);
		return true;
	}

	void Node::PrintList() const
	{
		USERDATA* pUser = mHeadNode;
		while (pUser != NULL)
		{
			printf("[%p] %d, %s, %s, [next: %p]\n",
				pUser,
				pUser->age, pUser->name, pUser->phone,
				pUser->pNext);
			pUser = pUser->pNext;
		}
	}
}