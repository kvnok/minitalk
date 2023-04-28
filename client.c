/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 16:52:08 by kkroon        #+#    #+#                 */
/*   Updated: 2023/01/27 16:52:34 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	specialatoi(char *s)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i] == '0')
		i++;
	if (i >= 1)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (-1);
		num = (num * 10) + (s[i] - '0');
		if (i > 10)
			return (-1);
		i++;
	}
	return (num);
}

void	sendbits(int pid, int c)
{
	int	mod;

	mod = 128;
	while (mod != 0)
	{
		if (c >= mod)
		{
			c = c - mod;
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(200);
		mod = mod / 2;
	}
}

void	sender(int pid, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		sendbits(pid, (int)s[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	serverpid;

	if (argc != 3)
		return (1);
	if (argv[2][0] == '\0')
	{
		write(1, "ERROR: string is empty\n", 23);
		return (1);
	}
	serverpid = specialatoi(argv[1]);
	if (serverpid < 0)
	{
		write(1, "ERROR: pid format is incorrect\n", 31);
		return (1);
	}
	sender(serverpid, argv[2]);
	return (0);
}
