/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:58:57 by chris             #+#    #+#             */
/*   Updated: 2023/07/25 16:59:51 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "FileCopy.hpp"


int main(int ac, char **av) {
    
    if ( ac == 4) {

       FileCopy inst(av[1], av[2], av[3]);
       inst.fileCopy(inst.ifs, inst.ofs);

    }
    else
        error("this program need 3 args", NULL);
    
    return 0; 
}