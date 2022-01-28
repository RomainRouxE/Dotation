#include "main.hpp"

static void usage()
{
	cout << "./a.exe file_name1" << endl;
	exit(0);
}

/* Check if file exist */
void check(int ac, char **av)
{
	if (ac != 2 || ac == NULL)
		usage();

	ifstream file1;
	file1.open(av[1]);
	if (!file1)
		usage();
	file1.close();
}

/* Copy original file to dotation.csv file
*  Loop a lot of time to replace every " " by "_" and add "0" between every ",,".
*  Use a tempFile.csv to save everytime. 
*  Delete the tempFile.csv a the end.
*/
int fixSynthaxBefore(char **av)
{
	size_t n;
	cout << "fixing synthax ......" << endl;

	ifstream src(av[1], ios::binary);
	ofstream dst("dotation.csv", ios::binary);
	dst << src.rdbuf();
	dst.close();

	for (int i = 0; i < 150; i++)
	{
		rename("dotation.csv", "tempFile.csv");

		ifstream old_file("tempFile.csv");
		ofstream new_file("dotation.csv");

		for (string contents_of_file; getline(old_file, contents_of_file);)
		{
			string::size_type position = contents_of_file.find(",,");
			if (position != string::npos)
				contents_of_file = contents_of_file.replace(position, 2, ",0,");

			position = contents_of_file.find(" ");
			if (position != string::npos)
				contents_of_file = contents_of_file.replace(position, 1, "_");

			if (i == 0)
			{
				n = count(contents_of_file.begin(), contents_of_file.end(), ',');
				new_file << contents_of_file << ",\n";
			}
			else
				new_file << contents_of_file << "\n";
		}
		old_file.close();
		remove("tempFile.csv");
	}
	return n;
}

/* Loop a lot of time to replace every "_" to the original " ".
*  Use a temFile.csv to save every time.
*  Delete the tempFile.csv and the dotation.csv file at the end.
*/
void fixSynthaxAfter()
{
	cout << "\nfixing synthax final file ....." << endl;

	for (int i = 0; i < 150; i++)
	{
		rename("dotationFinal.csv", "tempFile.csv");

		ifstream old_file("tempFile.csv");
		ofstream new_file("dotationFinal.csv");

		for (string contents_of_file; getline(old_file, contents_of_file);)
		{
			string::size_type position = contents_of_file.find("_");
			if (position != string::npos)
				contents_of_file = contents_of_file.replace(position, 1, " ");

			new_file << contents_of_file << "\n";
		}
		old_file.close();
		remove("tempFile.csv");
	}
	remove("dotation.csv");
}

/* Call every function */
int main(int ac, char **av)
{
	check(ac, av);
	int col = fixSynthaxBefore(av);
	algo(col);
	fixSynthaxAfter();
	cout << "Done" << endl;
}
