#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>

namespace funkcje
{
	bool D(int n, double **A, double *B, double epsilon, int MaxIteracji, double **alpha, double *beta, double *residuum, double *X, int LiczbaIteracji, std::string PlikWyj);
	double Norma1(double** alpha, int n);
	double Norma2(double** alpha, int n);
	double Norma3(double** alpha, int n);

	bool CzytajPlik(double** A, double* B, int n, std::string Plik) //najpierw z pliku czyta wektor B a potem macierz A
	{
		std::ifstream PlikStream(Plik);

		if (!PlikStream) return false;

		for (int i = 0; i < n; i++)
		{
			PlikStream >> B[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				PlikStream >> A[i][j];
			}
		}

		PlikStream.close();
		return true;
	}

	int SzukajMaxBezwzg(double tab[], int n) // poszukuje w tablicy jednowymiarowej numeru elementu najbardziej oddalonego od zera
	{
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			if (abs(tab[i]) > abs(tab[max]))
			{
				max = i;
			}
		}
		return max;
	}

	bool A(double** &A, double* &B, int &n, int &MaxIteracji, double &epsilon, std::string Plik)
	{
		std::ifstream plikstream;
		plikstream.open(Plik); 
		if (!plikstream) //spawdza, czy plik istnieje
		{
			return 0;
		}
		plikstream.close();

		//czyta wymagane rzeczy z klawiatury
		std::cout << "Podaj rozmiar macierzy n: "; 
		std::cin >> n;
		std::cout << std::endl << "Podaj dokladosc epsilon: ";
		std::cin >> epsilon;
		std::cout << std::endl << "Podaj maksymalna liczbe iteracji: ";
		std::cin >> MaxIteracji;

		A = new double*[n]; //tworzenie dynamicznej tablicy dwuwymiarowej

		for (int i = 0; i < n; i++)
		{
			A[i] = new double[n];
		}
		B = new double[n]; //tworzenie dynamicznej tablicy

		return CzytajPlik(A, B, n, Plik);
	}

	bool B(double** A, double* B, double** alpha, double* beta, int n)
	{
		int i = 0, j;
		bool NoIllegalDivision = true;
		while (i < n && NoIllegalDivision) //wykonuje sie conajwyzej n razy i przestaje sie wykonywac przy wykrytym dzieleniu przez 0
		{
			j = 0;
			while (j < n && NoIllegalDivision) //wykonuje sie conajwyzej n * n razy i przestaje sie wykonywac przy wykrytym dzieleniu przez 0
			{
				if (i == j)
				{
					alpha[i][j] = 0;
				}
				else
				{
					if (A[i][i] == 0) 
					{
						NoIllegalDivision = false; //istnieje dzielenie przez zero
					}
					else
					{
						alpha[i][j] = -A[i][j] / A[i][i]; 
					}

				}
				j++; //przesuwa do nast. elementu
			}
			if (A[i][i] != 0)
			{
				beta[i] = B[i] / A[i][i];
			}
			else
			{
				NoIllegalDivision = false;
			}
			i++;
		}
		return NoIllegalDivision;
	}

	int C(double** A, double* B, double** alpha, double* beta, double* X, int n, int MaxIteracji, double epsilon, std::string plik)
	{
		int s;
		int LiczbaIteracji = 0;
		double * Residuum = new double[n];
		for (int i = 0; i < n; i++) //ustawienie poczatkowych wartosci X i Residuum
		{
			X[i] = 0;
			Residuum[i] = beta[i];
		}
		s = SzukajMaxBezwzg(Residuum, n); //wyszukuje liczbe najdalsza od zera w Residuum
		while (LiczbaIteracji < MaxIteracji && epsilon < abs(Residuum[s])) // wykonywanie az nie przekroczony zostanie max iteracji lub epsilon bedzie wiekszy od najwiekszgo modulu liczby z Residuum
		{
			X[s] += Residuum[s];

			for (int i = 0; i < s; i++)
			{
				Residuum[i] += alpha[i][s] * Residuum[s];
			}

			for (int i = s + 1; i < n; i++)
			{
				Residuum[i] += alpha[i][s] * Residuum[s];
			}
			Residuum[s] = 0;
			s = SzukajMaxBezwzg(Residuum, n); //wyszukuje liczbe najdalsza od zera w Residuum
			LiczbaIteracji++;
		}
		D(n, A, B, epsilon, MaxIteracji, alpha, beta, Residuum, X, LiczbaIteracji, plik); //wywolanie funkcji D aby zapisac raport

		delete[] Residuum;
		return LiczbaIteracji; 
	}

	
	bool D(int n, double **A, double *B, double epsilon, int MaxIteracji, double **alpha, double *beta, double *residuum, double *X, int LiczbaIteracji, std::string PlikWyj)
	{ //wypisanie do pliku raportu
		std::ofstream PlikStream(PlikWyj);
		if (!PlikStream)
		{
			return false; //nie mozna bylo stworzyc pliku
		}
		PlikStream << "Epsilon wynosil: " << epsilon << ", Liczba iteracji: " << LiczbaIteracji
			<< "/" << MaxIteracji << std::endl << "Macierz A:" << std::endl;
			


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				PlikStream << A[i][j] << " ";
			}
			PlikStream << std::endl;
		}

		PlikStream << std::endl << "Wektor B:" << std::endl;
		for (int j = 0; j < n; j++)
		{
			PlikStream << B[j] << std::endl;
		}

		PlikStream << std::endl << "Macierz Alpha: " << std::endl;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				PlikStream << alpha[i][j] << " ";
			}
			PlikStream << std::endl;
		}

		PlikStream << std::endl << "Wektor beta:" << std::endl;
		for (int j = 0; j < n; j++)
		{
			PlikStream << beta[j] << std::endl;
		}



		PlikStream << std::endl << "Wektor residuum:" << std::endl 
			<< std::scientific << std::setprecision(10); //ustawienie postaci wykladniczej i precyzji na mantysie do 10 znakow po przecinku;
		for (int j = 0; j < n; j++)
		{
			PlikStream << residuum[j] << std::endl;
		}

		PlikStream << std::endl << "Wektor przyblizonego rozwiazania:" << std::endl;
		for (int j = 0; j < n; j++)
		{
			PlikStream << X[j] << std::endl;
		}

		PlikStream << std::endl << "Wektor bledu bezwzglednego:" << std::endl;
		for (int j = 0; j < n; j++)
		{
			PlikStream << abs(X[j] - 1) << std::endl;
		}

		PlikStream << "Norma1 = " << Norma1(alpha, n) << std::endl;
		PlikStream << "Norma2 = " << Norma2(alpha, n) << std::endl;
		PlikStream << "Norma3 = " << Norma3(alpha, n) << std::endl;
	}
	
	bool D(std::string PlikWyj)
	{
		std::ofstream PlikStream(PlikWyj);
		if (!PlikStream)
		{
			return false;
		}
		PlikStream << "Dzielenie przez zero";
		return true;
	}

	double SumaABSWzdluz(double** tab, int n, int x, int y, int dx, int dy)
	{
		double a = 0;
		while (x < n && y < n)
		{
			a += abs(tab[x][y]);
			x += dx;
			y += dy;
		}
		return a;
	}

	double Norma1(double** alpha, int n)
	{
		double max = SumaABSWzdluz(alpha, n, 0, 0, 0, 1); //suma modulow pierwszej kolumny
		double tmp;
		for (int i = 1; i < n; i++)
		{
			tmp = SumaABSWzdluz(alpha, n, i, 0, 0, 1); //sumy modulow zawartosci kazdej z kolejnych kolumn
			if (max < tmp)
			{
				max = tmp;
			}
		}
		return max;
	}

	double Norma2(double** alpha, int n)
	{
		double max = SumaABSWzdluz(alpha, n, 0, 0, 1, 0); //suma modulow pierwszego wiersza
		double tmp;
		for (int i = 1; i < n; i++)
		{
			tmp = SumaABSWzdluz(alpha, n, 0, i, 1, 0); //sumy modulow zawartosci kazdego z kolejnych wierszy
			if (max < tmp)
			{
				max = tmp;
			}
		}
		return max;
	}

	double Norma3(double** alpha, int n)
	{
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				sum += alpha[i][j] * alpha[i][j];
			}
		}
		return sqrt(sum);
	}
}

int main()
{
	char z;
	std::string wej, wyj;
	std::cout << "Ktory zestaw? ";
	std::cin >> z;

	switch (z)
	{
	case '1':
		wej = "Macierze1.txt";
		wyj = "PlikWyj1.txt";
		break;

	case '2':
		wej = "Macierze2.txt";
		wyj = "PlikWyj2.txt";
		break;

	case '3':
		wej = "Macierze3.txt";
		wyj = "PlikWyj3.txt";
		break;

	case '4':
		wej = "Macierze4.txt";
		wyj = "PlikWyj4.txt";
		break;

	case '5':
		wej = "Macierze5.txt";
		wyj = "PlikWyj5.txt";
		break;

	case '6':
		wej = "Macierze6.txt";
		wyj = "PlikWyj6.txt";
		break;

	case 'o':
	case 'n':
	case 'e':
		wej = "Macierze.txt";
		wyj = "PlikWyj.txt";
		break;

	default:
		return 1;
		break;
	}

	int n, MaxIteracji;
	double epsilon;
	
	double** A = NULL;
	double* B = NULL;
	
	if (!funkcje::A(A, B, n, MaxIteracji, epsilon, wej)) //otworzenie pliku z macierzami
	{
		std::cout << "Nie znaleziono pliku z macierzami";
		return -1;
	}

	double** alpha = new double*[n];//tworzenie dynamicznej tablicy dwuwymiarowej
	for (int i = 0; i < n; i++)
	{
		alpha[i] = new double[n];  //tworzenie dynamicznej tablicy dwuwymiarowej
	}
	double* beta = new double[n];//tworzenie dynamicznej tablicy
	double* X = new double[n];//tworzenie dynamicznej tablicy


	if (!funkcje::B(A, B, alpha, beta, n)) //wywolanie funkcji b. sprawdzenie czy jest dzielenie przez zero
	{
		funkcje::D(wyj); //wypisanie do pliku, ze nastapiloby dzielenie przez zero
		return -2;
	}
	else
	{
		funkcje::C(A, B, alpha, beta, X, n, MaxIteracji, epsilon, wyj); //wywolanie funkcji c, ktora rowniez wywoluje funkcje d
	}


	std::cout << std::scientific << std::setprecision(10);

	//usuwanie z pamieci
	for (int i = 0; i < n; i++)
	{
		delete[] A[i];
		delete[] alpha[i];
	}
	delete[] A;
	delete[] alpha;
	delete[] B;
	delete[] beta;
	delete[] X;

	return 0;
}