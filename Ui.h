#pragma once
#include "eUiType.h"
#include "Node.h"
namespace dbms
{
	class Ui
	{
	public:
		static eUiType PrintMenu();
		static void AddNewUser(Node* node);
		static void PrintUsers(Node* node);
	};
}