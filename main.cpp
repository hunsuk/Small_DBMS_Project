#include "Ui.h"
#include "stdio.h"
using namespace dbms;
int main(void) {

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
			break;
		case dbms::SEARCH:
			printf("SEARCH\n");
			break;
		case dbms::PRINT:
			printf("PRINT\n");
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