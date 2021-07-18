#include "DATA_MOF.h"
void DATA_FOR_MOF::startRand(int N, double x0, double y0, double r) {
	P.setN(N);
	P.setRandomPoints(x0, y0, r);
	double sqr = P.square(); // �������
	vcon1 = (double)(rand()) / RAND_MAX * (sqr - 0.2) + 0.2; // ��������� �������� ���� 1-�� �������� [1;sqr]
	vcon2 = sqr - vcon1; // ���������� ����� �������� ������ ��������
	c1 = P.getRandomCentroid();
	c2 = P.getRandomCentroid();
}
ostream& operator << (ostream& os, const DATA_FOR_MOF& M) {
	os << M.P << endl << M.vcon1 << " " << M.vcon2 << endl;
	os << M.c1 << " " << M.c2 << endl;
	return os;
}