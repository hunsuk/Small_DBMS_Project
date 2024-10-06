#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Ui.h"
namespace dbms
{
	eUiType Ui::PrintMenu()
	{
		eUiType input = EXIT;
		system("cls");
		printf("[1]New\t[2]Load\t[3]Search\t[4]Print\t[5]Remove\t[0]Exit\n");
		scanf_s("%d%*c", &input);
		return input;
	}

	void Ui::AddNewUser(Node* node)
	{
		unsigned int age = 0;
		char name[32] = { 0 };
		char phone[32] = { 0 };

		printf("age: ");
		scanf_s("%d%*c", &age);

		printf("name: ");
		gets_s(name, sizeof(name));

		printf("phone: ");
		gets_s(phone, sizeof(phone));
	
		node->AddNewNode(age, name, phone);
	}

	void Ui::PrintUsers(Node* node)
	{
		node->PrintList();
		getchar();
	}
}