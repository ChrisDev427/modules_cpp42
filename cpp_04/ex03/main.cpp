/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:02:47 by chris             #+#    #+#             */
/*   Updated: 2023/08/14 19:30:02 by chris            ###   ########.fr       */
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
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    
    src->printLearnedMateria();

    IMateriaSource* src2 = new MateriaSource(); 
    src2->learnMateria(new Ice()); 
    src2->learnMateria(new Cure());
    src2->learnMateria(new Ice()); 
    src2->learnMateria(new Cure());

    src2->printLearnedMateria();

    ICharacter* me = new Character("me");
    std::cout << "instances = " << Character::getInstNb() << std::endl;
    ICharacter* bob = new Character( "bob" ); 
    std::cout << "instances = " << Character::getInstNb() << std::endl;
    AMateria* tmp;
    AMateria* tmp2;

   
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp2 = src2->createMateria("ice");
    bob->equip(tmp2);

    
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp2 = src2->createMateria("ice");
    bob->equip(tmp2);

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp2 = src2->createMateria("cure");
    bob->equip(tmp2);

    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp2 = src2->createMateria("cure");
    bob->equip(tmp2);



    src->printCreatedMateria();
    me->printInventory();
    bob->printInventory();

    bob->use(0, *me);
    me->use(0, *bob);
    bob->use(1, *me);
    me->use(1, *bob);
    bob->use(2, *me);
    me->use(2, *bob);
    bob->use(3, *me);
    me->use(3, *bob);

    me->unequip( 0 );
    me->unequip( 1 );
    me->unequip( 2 );
    me->unequip( 3 );

    bob->unequip( 0 );
    bob->unequip( 1 );
    bob->unequip( 2 );
    bob->unequip( 3 );

   
    me->printInventory();
    bob->printInventory();

   



    

    delete bob; 
    delete me; 
    delete src;
    delete src2;
    


}

int main() {


    // test1();
    test2();
    




    system ("leaks a.out");
    return 0;
}