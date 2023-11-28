#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct Info {
	string namefilm[10];
	string creatorfilm[10];
	string genrefilm[10];

	string symbol;
	string cr;
	string gen;
	int grade[10];
	int userchoice;
};

void Minfo(Info& s) {
	string filmname[10] = { "Star Wars", "Titanic", "E.T. the Extra-Terrestrial", "The Silence of the Lambs", "Forrest Gump", "The Lion King", "The Avengers", "Avatar", "No Country for Old Men", "The Godfather" };
	string creator[10] = { "George Lucas", "James Cameron", "Steven Spielberg", "Jonathan Demme", "Robert Zemeckis", "Rob Minkoff", "Joss Whedon", "Ethan Coen", "Brian Knappenberger", "Francis Ford Coppola" };
	string genre[10] = { "thriller","survival horror","crime","detective movie","thriller","fiction","action thriller","action thriller","documentary","comedy" };

	for (int i = 0; i < 10; i++)
	{
		s.namefilm[i] = filmname[i];
		s.creatorfilm[i] = creator[i];
		s.genrefilm[i] = genre[i];
		s.grade[i] = rand() % 10 + 2;
	}
}

void printinfo(Info& s) {
	for (int i = 0; i < 10; i++)
	{
		cout << s.namefilm[i] << " " << s.genrefilm[i] << "  Оценка: " << s.grade[i] << "\n";
		cout << s.creatorfilm[i] << "\n\n";
	}
}

void search(Info& s)
{
	cout << "Введите филтры для поиска:1-имя/2-режиссёр/3-жанр/4-показать самый популярный фильм: ";
	cin >> s.userchoice;

	switch (s.userchoice)
	{
	case 1:
	{
		cout << "Введите название фильма: ";
		cin.ignore();
		getline(cin, s.symbol);

		for (int i = 0; i < 10; i++)
		{
			if (s.namefilm[i] == s.symbol)
			{
				cout << s.namefilm[i] << " " << s.genrefilm[i] << "  Оценка: " << s.grade[i] << "\n";
				cout << s.creatorfilm[i] << "\n\n";
			}
		}
		break;
	}
	case 2:
	{
		cout << "Введите режиссёра фильма: ";
		cin.ignore();
		getline(cin, s.cr);

		for (int i = 0; i < 10; i++)
		{
			if (s.creatorfilm[i] == s.cr)
			{
				cout << s.creatorfilm[i] << " " << s.namefilm[i] << " " << s.genrefilm[i] << "  Оценка: " << s.grade[i] << "\n";

			}
		}
		break;
	}
	case 3:
	{
		cout << "Введите жанр фильма: ";
		cin.ignore();
		cin >> s.gen;

		for (int i = 0; i < 10; i++)
		{
			if (s.genrefilm[i] == s.gen)
			{
				cout << s.genrefilm[i] << " " << s.namefilm[i] << " " << "  Оценка: " << s.grade << " " << s.genrefilm[i] << "\n";
				cout << s.creatorfilm[i] << "\n\n";
			}
		}
		break;
	}
	case 4:
	{
		cout << " самый популярный фильм: " << "\n";
		for (int i = 0; i < 10; i++)
		{
			if (s.grade[i] >= 10)
			{
				cout << s.namefilm[i] << " " << s.genrefilm[i] << "  Оценка: " << s.grade[i] << "\n";
				cout << s.creatorfilm[i] << "\n\n";
			}
		}
	}
	}
}

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	Info now;
	Minfo(now);
	printinfo(now);
	search(now);
}