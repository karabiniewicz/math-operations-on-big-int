#include <iostream>
#include <string>

using namespace std;

class Liczba {
public:
	string liczba;

	Liczba() : liczba("") {}

	Liczba(int wejscie) {
		*this = to_string(wejscie);
	}

	Liczba(string wejscie) {
		*this = wejscie;
	}

	void operator =(string wejscie) {
		liczba = wejscie;
		
		reverse(liczba.begin(), liczba.end());
	}

	Liczba operator +(Liczba wejscie) {
		Liczba aktualna = *this;

		Liczba wynik;

		for (int i = 0, zmienna = 0; i < liczba.size() || i < wejscie.liczba.size() || zmienna; ++i) {
			if (i < aktualna.liczba.size()) {
				zmienna += aktualna.liczba[i] - '0';
			}
			if (i < wejscie.liczba.size()) {
				zmienna += wejscie.liczba[i] - '0';
			}

			wynik.liczba += (zmienna % 10 + '0');
			zmienna /= 10;
		}

		return wynik;
	}


	Liczba operator *(Liczba wejscie) {
		Liczba wynik("0");

		for (int i = 0, j = liczba[i] - '0'; i < liczba.size(); ++i, j = liczba[i] - '0') {
			while (j--) {
				wynik = (wynik + wejscie);
			}
			wejscie.liczba.insert(wejscie.liczba.begin(), '0');
		}

		return wynik;
	}

	friend ostream& operator <<(ostream& wyjscie, const Liczba& wejscie) {
		string wynik = wejscie.liczba;

		reverse(wynik.begin(), wynik.end());
		wyjscie << wynik;

		return wyjscie;
	}
};

int main() {
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i) {
		int wierzcholki = 0;
		int krawedzie = 0;
		int potega = 0;
		int wejscie;
		Liczba m2, n2, m1, n1, n1m2, n2m1, m1m2razy2, dwa("2");

		scanf_s("%d%d", &wierzcholki, &potega);

		for (int j = wierzcholki * wierzcholki; j > 0; --j) {
			scanf_s("%d", &wejscie);
			if (wejscie)
				++krawedzie;
		}

		krawedzie >>= 1;

		n1 = n2 = wierzcholki;
		m1 = m2 = krawedzie;
		for (int j = 1; j < potega; ++j) {
			n1m2 = n1 * m2;
			n2m1 = n2 * m1;
			m1m2razy2 = dwa * m1 * m2;
			m1 = n1m2 + n2m1;
			m1 = m1 + m1m2razy2;
			n1 = n1 * n2;
		}
		cout << m1;
		printf("\n");
	}
	return 0;
}