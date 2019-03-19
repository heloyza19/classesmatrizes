﻿#include "pch.h"
#include "vetor.h"
#include <iostream>

using namespace std;

vetor::vetor(int t)
{
	size = t;
	double *V = new double(t);
}


vetor::~vetor()
{
	delete[]V;
}

void vetor::print()
{
	cout << "=[";
	for (int i = 0; i < size; i++)
	{
		cout << *(V + i) << " ";
	}
	cout << "]\n";
}

void vetor::setV(double* A)
{
	V = A;
}


double* vetor::getV()
{
	return V;
}





//Sobrecarga do igual
void vetor::operator =(const vetor &A) //const
{

	this->size = A.size;

	double* vetor1 = new double[A.size];
	for (int i = 0; i < A.size; i++)
	{
		*(vetor1 + i) = *(A.V + i);
	}
	this->setV(vetor1);

}


//Sobrecarga do igual
//Construtor de c�pia-
//Por que usar o const na sobrecarga do operador



//Construtor de copia
vetor::vetor(const vetor &A)
{
	this->size = A.size;
	double* c = new double[A.size];
	for (int i = 0; i < A.size; i++)
	{
		*(c + i) = A.V[i];
	}
	this->setV(c);
}

vetor vetor::operator + (vetor &A) {
	if (A.size == this->size) {
		vetor C(A.size);
		double* c = new double[A.size];

		for (int i = 0; i < A.size; i++)
		{
			*(c + i) = this->V[i] + A.V[i];
		}

		C.setV(c);

		return C;
	}
	else {
		cerr << "vetores com tamanhos diferentes\n";
	}
}

vetor vetor::operator - (vetor &A) {
	if (A.size == this->size) {
		vetor C(A.size);
		double* c = new double[A.size];

		for (int i = 0; i < A.size; i++)
		{
			*(c + i) = this->V[i] - A.V[i];
		}

		C.setV(c);

		return C;
	}
	else {
		cerr << "vetores com tamanhos diferentes\n";
	}
}

double vetor::operator *(vetor &B) {
	if (this->size == B.size)
	{
		double p = 0;
		for (int i = 0; i < B.size; i++)
		{
			p += this->V[i] * B.V[i];
		}
		return p;
	}
	else {
		cerr << "Vetores com tamanhos diferentes\n";
	}

}

vetor vetor::cross(vetor &B)
{
	if (this->size == B.size & B.size == 3)
	{
		vetor C(3);
		double*c = new double[3];

		c[0] = (this->V[1] * B.V[2]) - (this->V[2] * B.V[1]);
		c[1] = (this->V[2] * B.V[0]) - (this->V[0] * B.V[2]);
		c[2] = (this->V[0] * B.V[1]) - (this->V[1] * B.V[0]);

		C.setV(c);
		return C;
	}
	else
	{
		cerr << "Erro\n";
	}

}

vetor vetor::operator *(double n)
{
	vetor C(this->size);
	double* c = new double[this->size];
	for (int i = 0; i < this->size; i++)
	{
		c[i] = n * this->V[i];
	}
	C.setV(c);
	return C;
}


