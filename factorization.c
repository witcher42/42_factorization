/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junelee <junelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 23:46:53 by junelee           #+#    #+#             */
/*   Updated: 2020/04/02 23:46:53 by junelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void            ft_prime(long long prime)
{
        long long        temp;

        temp = prime - 1;
        while (temp > 1)
        {
                if (prime % temp == 0)
                        return ;
                else
                        --temp;
        }
        printf("%llu ", prime);
}

long long       ft_atoi(const char *str)
{
        long long        atoi_number;

        atoi_number = 0;
        while (*str && (*str == '0' || *str == ' ' || *str == '\n' || \
                *str == '\t' || *str == '\v' || *str == '\f' || *str == '\r'))
        {
                return 0;
        }
        while (*str && *str >= '0' && *str <= '9')
        {
                atoi_number = atoi_number * 10 + (*str - 48);
                ++str;
        }
        if ((*str < '0' || *str > '9') && *str != '\0')
                return 0;
        return (atoi_number);
}

int             main (int argc, char **argv)
{
        long long        atoi_number;
        long long        prime;

        if (argc == 2)
        {
                atoi_number = ft_atoi(argv[1]);
                if (atoi_number >= 2 && atoi_number <= 4294967295)
                {
                        prime = 2;
                        while (prime <= atoi_number)
                        {
                                if (atoi_number % prime == 0)
                                {
                                        ft_prime(prime);
                                        atoi_number = atoi_number / prime;
                                }
                                ++prime;
                        }
                }
                else if (atoi_number > 4294967295)
                        printf("%llu draws Overflow Error.", atoi_number);
                else if (atoi_number == 1)
                        printf("%llu is not a prime number.", atoi_number);
                else
                        printf("Input Error");
        }
        else
        {
                printf("Argc Error");
        }
        printf("\n");
        return 0;
}