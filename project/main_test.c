
#include "ft_printf.h"
// #include ""

int main()
{
	char	*p;

	p = 'a';
	printf("[%010.5s] [%.8s] [%.2s] \n","hellooooo", "hello", "HIfriends ");
	ft_printf("[%010.5s] [%.8s] [%.2s]\n","hellooooo", "hello", "HIfriends ");

	printf("[%023.5d] [%.8d] [%.2d] \n", -100, 3241,  10);
	ft_printf("[%023.5d] [%.8d] [%.2d] \n", -100, 3241,  10);

	// printf("[%023.5c] \n", 'a');
	// ft_printf("[%023.5c] \n", 'a');


	printf("[%#023.5X] \n", 100);
	ft_printf("[%#023.5X] \n", 100);

	printf("their[%#023.5o] \n", 100);
	ft_printf("minee[%#023.5o] \n", 100);
	printf("their[%#023.1o] \n", 100);
	ft_printf("minee[%#023.1o] \n", 100);
	printf("their[%#5o] \n", 100);
	ft_printf("minee[%#5o] \n", 100);
	printf("their[%5o] \n", 100);
	ft_printf("minee[%5o] \n", 100);
	printf("their[%.5o] \n", 100);
	ft_printf("minee[%.5o] \n", 100);

	printf("their[%-020.5p] \n", p);
	ft_printf("minee[%-020.5p] \n", p);
		// ft_printf("[%.8d][%.2d] \n", 3241, 10);

	//    printf("their[Hello %d%d%d%d%d%d%d%d%d  %d  ] \n", 123, 4872, 34, 7647787, 4535, 75667, 45377, 75438, 9354, 10);
	// ft_printf("minee[Hello %d%d%d%d%d%d%d%d%d  %d  ] \n", 123, 4872, 34, 7647787, 4535, 75667, 45377, 75438, 9354, 10);
	// ft_printf("minee[Hello %d%d%d%d%d%d%d%d%d  %d  ] \n", 123, 4872, 34, 7647787, 4535, 75667, 45377, 75438, 9354, 10);
	// ft_printf("minee[Hello %d%d%d%d%d%d%d%d%d  %d  ] \n", 123, 4872, 34, 7647787, 4535, 75667, 45377, 75438, 9354, 10);
	// ft_printf("minee[Hello %d%d%d%d%d%d%d%d%d  %d  ] \n", 123, 4872, 34, 7647787, 4535, 75667, 45377, 75438, 9354, 10);
	// ft_printf("minee[Hello %d%d%d%d%d%d%d%d%d  %d  ] \n", 123, 4872, 34, 7647787, 4535, 75667, 45377, 75438, 9354, 10);

	//    printf("their[Hello %s %s %s] \n", "this is going to be one", "massive string, likke", "a huge one, a very long long long l ong one!");
	// ft_printf("minee[Hello %s %s %s] \n", "this is going to be one", "massive string, likke" ,"a huge one, a very long long long l ong one!");
	//    printf("their[Hello %s %x HELLO] \n", "this is going", 56498);
	// ft_printf("minee[Hello %s %x HELLO] \n", "this is going", 56498);

	//    printf("their[Hello %s %O %c %C HELLO] \n", "this is going", 56498, 'a', 'b');
	// ft_printf("minee[Hello %s %O %c %C HELLO] \n", "this is going", 56498, 'a', 'b');


	// printf("their [%-10d] \n", 10);
	// ft_printf("minee [%-10d] \n", 10);

   	// printf("their[[% 23m] [%m] %20d% 1s] \n",  -100, "hello");
	// ft_printf("minee[[% 23m] [%m] %20d% 1s] \n",  -100, "hello");
	// printf("their[%20d  ] \n",  -100);
	// ft_printf("minee[%20d  ] \n",  -100);
	// printf("their[% 020d] \n",  -100);
	// ft_printf("minee[% 020d] \n",  -100);
	// printf("their[%020d] \n",  100);
	// ft_printf("minee[%020d] \n",  100);
	// printf("their[% 20d] \n",  100);
	// ft_printf("minee[% 20d] \n",  100);
	// printf("their[% 020-d] \n",  100);
	// ft_printf("minee[% 020-d] \n",  100);
	// printf("their[%20d] \n",  100);
	// ft_printf("minee[%20d] \n",  100);
	// printf("---------------------\n");
	// printf("their[%020s] \n",  "-100");
	// ft_printf("minee[%020s] \n",  "-100");
	// printf("their[% 20s] \n",  "-100");
	// ft_printf("minee[% 20s] \n",  "-100");
	// printf("their[% 020s] \n",  "-100");
	// ft_printf("minee[% 020s] \n",  "-100");
	// printf("their[%020s] \n",  "100");
	// ft_printf("minee[%020s] \n",  "100");
	// printf("their[% 20s] \n",  "100");
	// ft_printf("minee[% 20s] \n",  "100");
	// printf("their[% 020s] \n",  "100");
	// ft_printf("minee[% 020s] \n",  "100");
	// printf("their[%20s] \n",  "100");
	// ft_printf("minee[%20s] \n",  "100");
    // printf("their %#x \n", 10);
	// ft_printf("minee %#x \n", 10);
	// // printf("their %#X \n", 10);
	// ft_printf("minee %#X \n", 10);
    // // printf("their %#o \n", 10);
	// ft_printf("minee %#o \n", 10);
	// // printf("their [%s]\n", NULL);
	// ft_printf("minee [%s]\n", NULL);

	// ft_printf("hello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng hello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdhello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng hello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdhello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng hello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp   hello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng hello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsd hello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng hello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsd hello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng hello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdniopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsd\n");

	return (1);
}

// int main(void)
// {
//     int i;
//     setlocale(LC_ALL, "");
//     i = 0;
//     while (i < 0xffff)
//     {
//         ft_printf("%x - %lc", i, i);
//         i++;
//     }
//     return (0);
// }


// 	if (chr <= 0x7F)
// 		chr_len = 1;
// 	else if (chr <= 0x7FF)
// 		chr_len = 2;
// 	else if (chr <= 0xFFFF)
// 		chr_len = 3;
// 	else if (chr <= 0x10FFFF)
// 		chr_len = 4;
// 	else
// 		chr_len = 0;