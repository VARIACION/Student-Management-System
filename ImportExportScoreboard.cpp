#include "ImportExportScoreboard.h"

void drawFieldImportExportScoreboard()
{
	system("cls");
	gotoXY(65, 6);
	cout << "IMPORT / EXPORT LIST SCOREBOARDS";
	drawLabel(50, 18, 6, 70, "");
	gotoXY(47, 18);
	cout << "File to export";
	gotoXY(47, 22);
	cout << "Class to export";
	gotoXY(47, 14);
	cout << "File to import";
	drawLabel(65, 14, 1, 45, "");
	drawLabel(65, 18, 1, 45, "");
	drawLabel(65, 22, 1, 45, "");
	drawLabel(53, 28, 1, 15, "Import");
	drawLabel(73, 28, 1, 15, "Export");
	drawLabel(93, 28, 1, 15, "Back");
	_getch();
}