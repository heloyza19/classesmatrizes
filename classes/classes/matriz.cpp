#include "pch.h"
#include <iostream>
#include "matriz.h"

matriz::matriz(int l, int c) 
{
	size[0] = l;
	size[1] = c;
	M = new double*[l];

	for (int i = 0; i < l; i++)
	{
		M[i] = new double[c];
	}
}





void matriz::setM(double** M1)
{
	M = M1;
}

double** matriz::getM()
{
	return M;
}

void matriz::print()
{
	std::cout << std::endl;
	for (int i = 0; i < size[0]; i++) 
	{
		for (int j = 0; j < size[1]; j++) 
		{
			std::cout << *(*(M + i) + j) << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void matriz::eye()
{
	if(size[0]==size[1])
	{
		//double** m = new double*[size[0]];
		for (int i = 0; i < size[0]; i++)
		{
			//m[i] = new double[size[0]];
			for (int j = 0; j < size[0]; j++)
			{
				if (i == j) {
					this->M[i][j] = 1;
				}
				else {
					this->M[i][j]= 0;
				}

			
			}
		}
		//this->setM(m);
		}
	else {
		std::cerr << "A matriz nao e quadrada\n";
	}
}


void matriz::ones()
{
	//double** m = new double*[size[0]];
	for (int i = 0; i < size[0]; i++)
	{
		//m[i] = new double[size[1]];
		for (int j = 0; j < size[1]; j++)
		{
			
		 this->M [i][j] = 1;
		}
	}
	//this->setM(m);

}


void matriz::zeros() {
	//double** m = new double*[size[0]];
	for (int i = 0; i < size[0]; i++)
	{
		//m[i] = new double[size[1]];
		for (int j = 0; j < size[1]; j++)
		{

			this->M[i][j]= 0;
		}
	}
	//this->setM(m);

}


//Sobrecarga do igual

void matriz::operator =(const matriz &A) //const
{

	this->size[0] = A.size[0];
	this->size[1] = A.size[1];

	for (int i = 0; i < A.size[0]; i++)
	{
		
	}

	for (int i = 0; i < A.size[0]; i++)
	{
		for (int j = 0; j < A.size[1]; j++) 
		{

			this->M[i][j] = *(*(A.M + i) + j);

		}
	}

	//this->setM(matriz1);
}


//Construtor de copia
matriz::matriz(const matriz &A)
{
	this->size[0] = A.size[0];
	this->size[1] = A.size[1];

	double** m = new double*[A.size[0]];
	for (int i = 0; i < A.size[0]; i++)
	{
		*(m + i) = new double[A.size[1]];
	}

	for (int i = 0; i < A.size[0]; i++)
	{
		for (int j = 0; j < A.size[1]; j++) 
		{
			*(*(m + i) + j) = A.M[i][j];
		}
	}
	this->setM(m);
}

//operador +
matriz matriz::operator + (matriz &A)
{
	if (A.size[0] == this->size[0] & A.size[1] == this->size[1])
	{
		matriz C(A.size[0], A.size[1]);
	

		for (int i = 0; i < A.size[0]; i++)
		{
			
			for (int j = 0; j < A.size[1]; j++)
			{

				C.M[i][j] = this->M[i][j] + A.M[i][j];
			}
		}
	
		return C;
	}
	else
	{
		std::cerr << "Matrizes com dimensoes diferentes\n";
	}
}

//operador -
matriz matriz::operator - (matriz &A)
{
	if (A.size[0] == this->size[0] & A.size[1] == this->size[1])
	{
		matriz C(A.size[0], A.size[1]);
		

		for (int i = 0; i < A.size[0]; i++)
		{

			for (int j = 0; j < A.size[1]; j++)
			{

				C.M[i][j] = this->M[i][j] - A.M[i][j];
			}
		}
		
		return C;
	}
	else 
	{
		std::cerr << "Matrizes com dimensoes diferentes\n";
	}
}

matriz matriz::operator * (matriz &B)
{
	if (this->size[1] == B.size[0])      //numero de colunas em A == numero de colunas em B
	{
		matriz P(this->size[0], B.size[1]);

	


		for (int i = 0; i < this->size[0]; i++)  //tamanho das linhas da nova matriz
		{
			

			for (int j = 0; j < B.size[1]; j++)    //colunas da nova matriz
			{
				P.M[i][j]= 0;
				for (int k = 0; k < this->size[1]; k++)   //linhas da matriz antiga
				{
					P.M[i][j] += this->M[i][k] * B.M[k][j];
				}
			}
		}
		
		return P;
	}
	else 
	{
		std::cerr << "os requisitos para a multiplicacao nao foram cumpridos" << std::endl;
	}
}

matriz matriz::operator *(double n)
{
	

	matriz M1(this->size[0], this->size[1]);

	for (int i = 0; i < this->size[0]; i++)
	{
		
		for (int j = 0; j < this->size[1]; j++)
		{
			M1.M[i][j] = n * this->M[i][j];
		}
	}
	
	return M1;
}

	
	matriz matriz::operator * (vetor &B)
	{

		if (this->size[1] == 1)      //numero de colunas em A == numero de linhas em B
		{
			matriz P(this->size[0], B.getsize());

			


			for (int i = 0; i < this->size[0]; i++)  //tamanho das linhas da nova matriz
			{
				

				for (int j = 0; j < B.getsize(); j++)    //colunas da nova matriz
				{
				
				P.M[i][j] = this->M[i][0] * B.getV()[j];
						
					
				}
			}
			
			return P;
		}
		else
		{
			std::cerr << "os requisitos para a multiplicacao nao foram cumpridos" << std::endl;
		}
	}
	