/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 16:52:15 by kkroon        #+#    #+#                 */
/*   Updated: 2023/01/27 16:55:49 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	printnum(int n)
{
	char	c;

	if (n > 9)
		printnum(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	bithandler(int signum)
{
	static int	mod = 128;
	static int	c = 0;
	char		letter;

	if (signum == SIGUSR1)
	{
		c = c + mod;
	}
	mod = mod / 2;
	if (mod == 0)
	{
		letter = (char)c;
		write(1, &letter, 1);
		mod = 128;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	printnum(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, bithandler);
	signal(SIGUSR2, bithandler);
	while (1)
	{
		pause();
	}
	return (0);
}
