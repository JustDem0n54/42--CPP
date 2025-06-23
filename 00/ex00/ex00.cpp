#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	int i = 0;
	
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int y = 1; argv[y]; y++)
	{
		i = 0;
		while (argv[y][i])
		{
			argv[y][i] = toupper(argv[y][i]);
			i++;
		}
		std::cout << argv[y];
		if (argv[y][i - 1] != ' ' && y < argc - 1 && argv[y + 1] && argv[y + 1][0] != ' ')
			std::cout << ' ';
	}
	std::cout << std::endl;
}
