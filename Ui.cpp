#pragma once

#include "Ui.h"
#include <stdio.h>
#include <stdlib.h>
namespace dbms
{
	eUiType Ui::PrintMenu()
	{
		eUiType input = EXIT;
		system("cls");
		printf("[1]New\t[2]Search\t[3]Print\t[4]Remove\t[0]Exit\n");
		scanf_s("%d%*c", &input);
		return input;
	}
}