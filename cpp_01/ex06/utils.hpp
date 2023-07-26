/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:32:19 by chris             #+#    #+#             */
/*   Updated: 2023/07/26 09:10:49 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include <string>
# include <iostream>
# include <fstream>

# define RESET   "\033[0m"
# define RED     "\033[1;31m"
# define GREEN   "\033[32m"
# define B_CYAN    "\033[1;36m"
#define YELLOW  "\033[33m"
#define B_BLUE    "\033[1;34m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define B_CYAN    "\033[1;36m"
#define MAGENTA "\033[35m"
void    error(std::string  const s1, const char *s2);

#endif /* UTILS_HPP */