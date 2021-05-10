#include "main.hpp"

static void usage()
{
	cout << "./test file_name1" << endl;
	exit(0);
}

void check(int ac, char **av)
{
	if (string("-h") == av[1])
		usage();
	if (ac != 2 || ac == NULL)
		usage();

	ifstream file1;
	file1.open (av[1]);
	if (!file1)
		usage();
	file1.close();
}

int main(int ac, char **av)
{
	check(ac, av);
	algo();
	return (84);
}
