#pragma once

class Tab2D
{
public:
	int wiersz, kolumna, zakres;
	int** tablica2D;
	int** dodatkowaTablica;
	int** drugaTablica;
	int** trzeciaTablica;
	

	Tab2D(int, int);
	void generate(int z);
	void simplePrint();
	void indexedPrint();
	void scanPDUZ();
	/*void scanLGDJ();*/
};
