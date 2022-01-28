#include "main.hpp"

/* Algo to put data in dotationFinal.csv file. */
int algo(int col)
{
	string data[2][150];
	ifstream file("dotation.csv");
	ofstream newfile("dotationFinal.csv");

	string line;
	int numCol = col + 1;

	for (int row = 0;; ++row)
	{
		getline(file, line);
		if (!file.good())
			break;

		stringstream iss(line);

		if (row == 0)
		{
			for (int col1 = 0; col1 < numCol; ++col1)
			{
				string val;
				getline(iss, val, ',');
				if (!iss.good())
					break;

				stringstream convertor(val);
				convertor >> data[row][col1];
			}
		}
		else
		{
			for (int col = 0; col < numCol; col++)
			{
				string val;
				getline(iss, val, ',');
				if (!iss.good())
					break;

				stringstream convertor(val);
				convertor >> data[1][col];
				cout << data[1][col] + ",";
			}
			cout << endl;
			for (int j = 1; j < numCol; ++j)
			{
				newfile << data[1][0];
				newfile << ";";

				newfile << data[0][j];
				newfile << ";";

				newfile << data[1][j];
				cout << data[1][j] + ",";

				newfile << '\n';
			}
			cout << endl;
		}
	}
}
