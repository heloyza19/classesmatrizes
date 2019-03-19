

#include "pch.h"
#include <iostream>

#include "matriz.h"
#include "vetor.h"

using namespace std;

int main() {

	int tam = 3;
	double* A = new double[tam] {5, 7, 19};
	double* B = new double [tam] {7, 5, 13};

	vetor U(tam);
	U.setV(A);
	double *vetor1 = U.getV();

	cout << "U";
	U.print();

	vetor V(tam);
	V.setV(B);
	cout << "V";
	V.print();

	cout << "\nTestes vetores\n\n";

	vetor A1 = U + V;
	cout << "U + V=" << endl;
	A1.print();

	double A2 = U * V;
	cout << "U * V= " << A2 << endl;


	vetor A3 = U.cross(V);
	cout << "U x V=" << endl;
	A3.print();


	int l = 3, c = 3;
	int L = 3, C = 3;

	double **M1 = new double*[l];
	double **M2 = new double*[L];

	for (int i = 0; i < l; i++)
	{
		M1[i] = new double[c];
	}

	for (int i = 0; i < L; i++)
	{
		M2[i] = new double[C];
	}


	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < c; j++)
		{
			*(*(M1 + i) + j) = (i + 2) + j;
		}
	}

	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < C; j++)
		{
			*(*(M2 + i) + j) = (i + 2)*(j + 1);
		}
	}



	matriz Mat(l, c);
	Mat.setM(M1);
	cout << "Matriz 1=";
	Mat.print();

	matriz Mat2(L, C);
	Mat2.setM(M2);
	cout << "Matriz 2=";
	Mat2.print();

	matriz Mati(3, 3);
	Mati.eye();
	cout << "Matriz identidade=";
	Mati.print();

	
	matriz Mat3(4, 5);
	Mat3.ones();
	Mat3.print();

	matriz Matz(3, 5);
	Matz.zeros();
	Matz.print();
	


	//Matriz * Vetor
	cout << "Matriz 1 * U=";
	matriz R = Mat * U;
	R.print();

	cout << "Matriz 1 * Matriz 2=";
	matriz R1 = Mat * Mat2;
	R1.print();

	matriz Mats(L, C);
	Mats = Mat + Mat2;
	cout << "Matriz 1 + Matriz 2 =";
	Mats.print();

	matriz Mats2 = Mat + Mat2 + Mats;
	cout << "Matriz 1 + Matriz 2 + Mat3 =";
	Mats2.print();

	matriz Mat4(L, C);
	Mat4 = Mat - Mat2;
	cout << "Matriz 1 - Matriz 2 =";
	Mat4.print();

	matriz Mat5 = Mat * Mat2;
	cout << "Matriz 1 * Matriz 2 =";
	Mat5.print();


	matriz Mat6 = Mat * 2;
	cout << "Matriz 1 * 2=";
	Mat6.print();

	system("PAUSE");

	return 0;
}

