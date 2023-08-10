/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:02:47 by chris             #+#    #+#             */
/*   Updated: 2023/08/10 17:57:53 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void test1( void ) {

    AMateria* I = new Ice();
    AMateria* C = new Cure();

    std::cout << I->getType() << std::endl;
    std::cout << C->getType() << std::endl;

    AMateria* clone = I->clone();
    std::cout << clone->getType() << std::endl;
    ICharacter* src = new Character( "CHRIS" );
    I->use( *src );



    delete I;
    delete C;
    delete clone;

}

void test2( void ) {

    IMateriaSource* src = new MateriaSource(); 
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());

    src->printLearnedMateria();

    ICharacter* me = new Character("me");
    AMateria* tmp;
    puts("AAAAA");
   




    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->use(0, *me);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);


    src->printCreatedMateria();
    me->printInventory();

    me->unequip( 2 );
    me->unequip( 3 );

    // me->printInventory();
    me->equip(tmp);
    me->equip(tmp);
    me->printInventory();

    me->unequip( 0 );
    // me->unequip( 1 );
    // me->unequip( 2 );
    me->unequip( 3 );
    me->printInventory();

    me->equip(tmp);
    me->unequip( 0 );
    me->printInventory();
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);
    me->printInventory();
    me->unequip( 0 );
    me->unequip( 1 );
    me->unequip( 2 );
    me->unequip( 3 );
   
    
    me->printInventory();


    ICharacter* bob = new Character( "bob" ); 

    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    bob->unequip( 3 );

    bob->equip(tmp);



    me->use(1, *bob);
    me->use(0, *bob);
    // me->unequip( 0 );


    // me->printInventory();


    

    delete bob; 
    delete me; 
    delete src;
    


}

int main() {


    // test1();
    test2();
    




    system ("leaks a.out");
    return 0;
}