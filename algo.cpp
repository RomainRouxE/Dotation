#include "main.hpp"

int algo()
{
	string data[400][204];
	ifstream file("dotation.csv");

	for (int row = 0; row < 400; ++row)
	{
		string line;
		getline(file, line);
		if (!file.good())
			break;

		stringstream iss(line);

		for (int col = 0; col < 204; ++col)
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

	for (int i = 1; i < 400; ++i)
	{
		for (int j = 1; j < 204; ++j)
		{
			newfile << data[i][0];
			newfile << ";";
			newfile << data[0][j];
			newfile << ";";
			if (data[i][j] == "")
				newfile << "0";
			else
				newfile << data[i][j];
			newfile << '\n';
		}
		newfile << '\n';
	}
}
