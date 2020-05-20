#include <iostream>
using namespace std;

void Euclides (int a, int b, int &mdc)
{	
	if (a%b == 0) mdc = b;
	else Euclides (b, a%b, mdc);
}

void Bezout(int maior, int menor, int mdc, int mat[][4], int l)
{
	if (mat[l][0] != mdc)
	{
		mat[l+1][0] = mat[l-1][0]%mat[l][0];
		mat[l+1][1] = mat[l-1][0]/mat[l][0];
		if (mat[l+1][0]!= mdc) Bezout (maior, menor, mdc, mat, l+1);
	
		for (int i = 1; i <= l; i++)
		{
			mat[i+1][2] = mat[i-1][2] - mat[i+1][1]*mat[i][2];
			mat[i+1][3] = mat[i-1][3] - mat[i+1][1]*mat[i][3];
		}
	
		cout << endl << "Com m=" << mat[l][2] << " e n=" << mat[l][3] << " temos que: " << endl;
	
		cout << maior << '*' << mat[l][2] << " + " << menor << '*' << mat[l][3] << " = " << maior*mat[l][2] + menor*mat[l][3] << endl;
	
		cout << maior*mat[l][2] << " + " << menor*mat[l][3] << " = " << maior*mat[l][2] + menor*mat[l][3] << endl << endl;

	}

	else
	{
		cout << endl << "Com m=" << 0 << " e n=" << 1 << " temos que: " << endl;
	
		cout << maior << '*' << 0 << " + " << menor << '*' << 1 << " = " << maior*0 + menor*1 << endl;
	
		cout << maior * 0 << " + " << menor << " = " << maior*0 + menor*1 << endl << endl;
	}
}

int main()
{	
	cout << "                                                  TEOREMA DE BEZOUT" << endl;
	
	cout << "O teorema de Bezout diz que: Dados inteiros a e b, ambos nao nulos, existem inteiros m e n tais que am + bn = mdc(a, b). " << endl << endl;

	int x, y, maior, menor;
	
	cout << "Insira o seu valor de a: ";
	cin >> x;
	
	cout << "Insira o seu valor de b: ";
	cin >> y;
	
	int mdc = 0;
	
	if (x > y)
	{
		maior = x;
		menor = y;
	}
	
	else
	{
		maior = y;
		menor = x;
	}
	
	Euclides (maior, menor, mdc);
	
	int mat[100][4];
	mat[0][0] = maior;
	mat[0][1] = 0;
	mat[0][2] = 1;
	mat[0][3] = 0;
	
	mat[1][0] = menor;
	mat[1][1] = 0;
	mat[1][2] = 0;
	mat[1][3] = 1;
	
	cout << endl << "O mdc de " << x << " e " << y << " equilave a " << mdc << '.' << endl;
	
	Bezout (maior, menor, mdc, mat, 1);

	return 0;
}
