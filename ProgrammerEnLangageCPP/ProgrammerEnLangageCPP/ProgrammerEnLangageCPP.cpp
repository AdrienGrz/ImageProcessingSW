// ProgrammerEnLangageCPP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include<map>

using namespace std;

void echange(int a, int b);

void echangeRef(int &a, int &b);

void displayNewStep(string s);

int i; // variable globale
void optimist();

template<typename T>
void affiche(typename T);

bool impair(int n);

int main()
{

	// passage par valeur
	int n = 10, p = 20;
	cout << "passage par valeur" << endl;
	cout << "avant echange : " << n << " " << p << endl;
	echange(n, p);
	cout << "apres echange : " << n << " " << p << endl << endl;

	// passage par reference
	cout << "passage par reference" << endl;
	cout << "avant echange : " << n << " " << p << endl;
	echangeRef(n, p);
	cout << "apres echange : " << n << " " << p << endl;

	// variable globale
	for (i = 1; i <= 5; i++) optimist();

	// STL

	// parcourir un conteneur avec un iterateur
	{
		displayNewStep("parcourir un conteneur avec un iterateur");
		vector<int> vint;
		for (int i = 0; i < 5; i++) { vint.push_back(i); }

		vector<int>::iterator itv;
		for (itv = vint.begin(); itv != vint.end(); itv++) {
			cout << "current vint value is " << *itv << endl;
		}


	}
	
	
	// fonction unaire sur un conteneur
	{
		displayNewStep("appliquer une fonction unaire sur un vector");
		vector<int> vint;
		for (int i = 0; i < 5; i++) { vint.push_back(i); }
		for_each(vint.begin(), vint.end(), affiche<int>);
	}

	// algo count
	{
		displayNewStep("algo count");
		vector<int> vint2(3, 6); // {6,6,6}
		for_each(vint2.begin(), vint2.end(), affiche<int>);

		std::cout << "le nombre 6 apparait ";
		n = count(vint2.begin(), vint2.end(), 6);
		std::cout << n << " fois" << endl;
	}

	// insert operation
	{
		displayNewStep("insert operation");
		std::cout << "\n";
		vector<string> vstring;
		vstring.push_back("bonjour");
		vstring.push_back("tout");
		vstring.push_back("monde");

		// declare a random access iterator
		vector<string>::iterator its = vstring.begin() + 2;
		vstring.insert(its, "le");
		for_each(vstring.begin(), vstring.end(), affiche<string>);
	}
	
	// copy algorithm
	{
		
		displayNewStep("copy algorithm");
		vector<string> vstring;
		vstring.push_back("hello");
		vstring.push_back("to");
		vstring.push_back("you");

		vector<string> vstring2;
		//copy(vstring.begin(), vstring.end(), vstring2.begin());

		//for_each(vstring2.begin(), vstring2.end(), affiche<string>);
		

	}

	// utilisation d'un prédicat (fonction bool)
	{
		displayNewStep("predicat avec find_if");
		list<int> lint(3, 2);
		lint.push_back(7);

		list<int>::iterator ilint;
		ilint = find_if(lint.begin(), lint.end(), impair);
		if (*ilint) {
			cout << "un nombre impair a ete trouve" << endl;
		}
	}

	// construction a partir d une sequence
	{
		displayNewStep("construction a partir d une sequence");
		vector<int> vint5(10, 3);

		cout << "sequence des 3 premiers elements " << endl;
		vector<int>::iterator itv5 = vint5.begin() + 3; //4rd element
		vector<int> vint6(vint5.begin(), itv5);
		for_each(vint6.begin(), vint6.end(), affiche<int>);
	}

	// suppression sur liste
	{
		displayNewStep("suppression par valeur dans une liste");

		int t[] = { 1,5,4,6,7,5,4,8,4 };
		list<int> lint(t, t + 8);
		std::cout << "list avant suppression" << endl;
		for_each(lint.begin(), lint.end(), affiche<int>);

		lint.remove(4);
		std::cout << "list apres suppression" << endl;
		for_each(lint.begin(), lint.end(), affiche<int>);
	
		displayNewStep("suppression par predicat");
		lint.remove_if(impair);
		std::cout << "suppression des valeurs impair" << endl;
		for_each(lint.begin(), lint.end(), affiche<int>);

	}

	// tri d'une liste
	{
		displayNewStep("tri d'une liste");
		int t[] = { 4,7,1,9,4,8,9,7 };
		list<int> lint(t, t + 7);
		std::cout << "liste avant tri \n";
		for_each(lint.begin(), lint.end(), affiche<int>);

		lint.sort();
		std::cout << "liste apres tri \n";
		for_each(lint.begin(), lint.end(), affiche<int>);

		std::cout << "suppression des doublons \n";
		lint.unique();
		for_each(lint.begin(), lint.end(), affiche<int>);

	}

	// conteneurs associatifs
	displayNewStep("conteneurs associatifs");

	// map
	{
		displayNewStep("map");
		std::cout << "construction d une map \n";
		map<char, int> m;
		m['c'] = 3;
		m['b'] = 2;
		map<char, int>::iterator im;
		for (im = m.begin(); im != m.end(); im++) {
			std::cout << "m['" << (*im).first << "'] =" << (*im).second << endl;
		}

	}

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// version de la fonction pour un passage par valeur
void echange(int a, int b)
{
	int c;
	cout << "debut echange : " << a << " " << b << endl;
	c = a;
	a = b;
	b = c;
	cout << "fin echange : " << a << " " << b << endl;
}

// version de la fonction pour un passage par reference
void echangeRef(int &a, int &b)
{
	int c;
	cout << "debut echange : " << a << " " << b << endl;
	c = a;
	a = b;
	b = c;
	cout << "fin echange : " << a << " " << b << endl;
}

// utilisation de variable globale
void optimist()
{
	cout << "il fait beau aujourd'hui " << i << " fois" << endl;
}

// fonction unaire affiche
template<typename T>
void affiche(T e)
{
	cout << e << endl;
}


// display step
void displayNewStep(string s)
{	
	std::cout << "\n";
	std::cout << "###	 " << s << "		###" << "\n\n";
}

// impair
bool impair(int n) { return (n % 2); }