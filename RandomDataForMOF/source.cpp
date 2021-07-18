#include "Polygon.h"
#include "DATA_MOF.h"
#include <fstream>
double random(double min, double max)
{
	return (double)(rand()) / RAND_MAX * (max - min) + min;
}
int main()
{
	srand(time(NULL));

	const int examples = 100;

	ofstream fout("input_MOF.txt");
	fout << examples << endl;

	DATA_FOR_MOF* data = new DATA_FOR_MOF[examples];
	for (int i = 0; i < examples; i++) {
		// генерируем данные
		data[i].startRand(6, 13.5 + i / 2., 25.3 + i / 2., random(0.3, 0.6));
		fout << data[i] << endl;
	}

}
