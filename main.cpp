#include <stdio.h>
#include "Ui.h"
#include "Node.h"
using namespace dbms;
int main(void) {

	Node* node = new Node();
	eUiType menu = EXIT;

	while ((menu = Ui::PrintMenu()) != EXIT)
	{
		switch (menu)
		{
		case dbms::EXIT:
			printf("EXIT\n");
			break;
		case dbms::NEW:
			printf("NEW\n");
			Ui::AddNewUser(node);
			break;
		case dbms::LOAD:
			printf("LOAD\n");
			Node::LoadList();
		case dbms::SEARCH:
			printf("SEARCH\n");
			break;
		case dbms::PRINT:
			printf("PRINT\n");
			Ui::PrintUsers(node);
			break;
		case dbms::REMOVE:
			printf("REMOVE");
			break;
		default:
			break;
		}
	}
	return 0;
} 