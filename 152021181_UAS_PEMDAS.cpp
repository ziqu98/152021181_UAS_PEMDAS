// 152021181_UAS_PEMDAS.cpp : This file contains the 'main' function. Program execution begins and ends there.
// IFB-207 PEMROGRAMAN DASAR
// GAMMA RIZQUHA WIRADISASTRA
// 152021181
// UAS - 20230110

#include <iostream>

using namespace std;

struct nilaiData
{
    double x;
    double y;
	double xy;
};

double pearsonAtas(nilaiData _nilai[]);
double pearsonBawah(nilaiData _nilai[]);

nilaiData nilai[50];
int n = 3;

int main()
{
	double rpearson = 0;
	double koef_det = 0;

	for (int i = 0; i < n; i++)
	{
		do
		{
			cout << "Masukkan nilai x" << i + 1 << ": ";
			cin >> nilai[i].x;
			system("cls");
		} while (nilai[i].x < 0);
		do
		{
			cout << "Masukkan nilai y" << i + 1 << ": ";
			cin >> nilai[i].y;
			system("cls");
		} while (nilai[i].y < 0);
		nilai[i].xy = nilai[i].x * nilai[i].y;
	}
	//perhitungan
	rpearson = pearsonAtas(nilai) / pearsonBawah(nilai);
	koef_det = rpearson * rpearson * 100;

	cout << "Nilai Korelasi r: " << rpearson << endl;
	cout << "Koefisien Determinasi: " << koef_det << "%" << endl;
	cout << "Kekuatan hubungan: ";
	if (abs(rpearson) < 0.1)
	{
		cout << "Hubungan relasi diabaikan" << endl;
	}
	else if (abs(rpearson) < 0.3)
	{
		cout << "Hubungan relasi rendah" << endl;
	}
	else if (abs(rpearson) < 0.5)
	{
		cout << "Hubungan relasi moderat" << endl;
	}
	else if (abs(rpearson) < 0.71)
	{
		cout << "Hubungan relasi sedang" << endl;
	}
	else
	{
		cout << "Hubungan relasi sangat kuat" << endl;
	}
	cout << endl;
	if (rpearson > 0)
	{
		cout << "Hubungan antara variabel x dan y adalah positif, dimana jika nilai x bertambah, maka nilai y pun akan bertambah, dan juga sebaliknya" << endl;
	}
	else if (rpearson < 0)
	{
		cout << "Hubungan antara variabel x dan y adalah negatif, dimana jika nilai x bertambah, maka nilai y akan mengecil, dan juga sebaliknya" << endl;
	}
	else
	{
		cout << "Tidak ada hubungan antara variabel x dan y" << endl;
	}
}

double pearsonAtas(nilaiData _nilai[])
{
	double sumx = 0;
	double sumy = 0;
	double sumxy = 0;
	double total = 0;

	for (int i = 0; i < n; i++)
	{
		sumxy += _nilai[i].xy;
		sumx += _nilai[i].x;
		sumy += _nilai[i].y;
	}
	total = (n * sumxy) - (sumx * sumy);
	return total;
}

double pearsonBawah(nilaiData _nilai[])
{
	double sumx = 0;
	double sumxx = 0;
	double sumy = 0;
	double sumyy = 0;
	double total = 0;

	for (int i = 0; i < n; i++)
	{
		sumx += _nilai[i].x;
		sumxx += _nilai[i].x * _nilai[i].x;
		sumy += _nilai[i].y;
		sumyy += _nilai[i].y * _nilai[i].y;
	}
	total = sqrt((n * sumxx) - (sumx * sumx)) * sqrt((n * sumyy) - (sumy * sumy));
	return total;
}

// pearsonAtas
// n * jumlah xy - (jumlah x * jumlah y)
//pearsonBawah
// (n * akar(jumlah xx) - (jumlah x)^2) *  (akar(jumlah yy) - (jumlah y)^2)
