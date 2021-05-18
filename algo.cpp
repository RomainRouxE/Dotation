#include "main.hpp"

int algo()
{
	string data[350][231];
	ifstream file("dotation.csv");

	for (int row = 0; row < 350; ++row)
	{
		string line;
		getline(file, line);
		if (!file.good())
			break;

		stringstream iss(line);

		for (int col = 0; col < 231; ++col)
		{
			string val;
			getline(iss, val, ';');
			if (!iss.good())
				break;

			stringstream convertor(val);
			convertor >> data[row][col];
		}
	}

	ofstream newfile("New-file.csv");

	int UDIJON = 0;
	int UST = 0;

	for (int i = 1; i < 350; ++i)
	{
		for (int j = 1; j < 231; ++j)
		{
			newfile << data[i][0];
			newfile << ";";
			if (data[0][j] == "UCOTE")
				newfile << "UCOTE OR1";
			else if (data[0][j] == "UDIJON" && UDIJON < 4)
			{
				newfile << "UDIJON CPT21-1";
				++UDIJON;
			}
			else if (data[0][j] == "UDIJON" && UDIJON == 6 || UDIJON == 11)
			{
				newfile << "UDIJON METROPOLE2";
				++UDIJON;
			}
			else if (data[0][j] == "UDIJON")
			{
				newfile << "UDIJON METROPOLE1";
				++UDIJON;
			}
			else if (data[0][j] == "USAUVIGNY")
				newfile << "USAUVIGNY LE BOIS1";
			else if (data[0][j] == "UST" && UST == 0 || UST == 1)
			{
				newfile << "UST CLAUDE1";
				++UST;
			}
			else if (data[0][j] == "UST" && UST == 2 || UST == 3)
			{
				newfile << "UST CLAUDE2";
				++UST;
			}
			else if (data[0][j] == "UST" && UST == 4)
			{
				newfile << "UST CLAUDE3";
				++UST;
			}
			else
				newfile << data[0][j];
			newfile << ";";
			if (data[i][j] == "")
				newfile << "0";
			else
				newfile << data[i][j];
			newfile << '\n';
		}
		UDIJON = 0;
		UST = 0;
	}
}
