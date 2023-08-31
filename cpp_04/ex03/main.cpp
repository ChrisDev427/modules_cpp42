/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:02:47 by chris             #+#    #+#             */
/*   Updated: 2023/08/30 15:58:33 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "policeColor.hpp"

bool printConstDest = false;


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
    delete src;

}
void test2( void ) {

    IMateriaSource* src = new MateriaSource(); 
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    

    Character* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    me->printInventory();

    Character* Bob = new Character( "Bob" ); 

    me->use(0, *Bob);
    me->use(1, *Bob);
    me->use(2, *Bob);
    me->use(3, *Bob);

    Character* cpy = new Character( *me );
    Character* cpy2 = new Character( *me );
    Character* cpy3 = new Character( *me );

    cpy->printInventory();
    cpy2->printInventory();
    cpy3->printInventory();

    me->unequip( 0 );
    me->unequip( 1 );
    me->printInventory();

   
    Character::printMatToFree();

    delete Bob; 
    delete me; 
    delete src;
    delete cpy;
    delete cpy2;
    delete cpy3;
}

void test3( void ) {

    IMateriaSource* src = new MateriaSource(); 
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    

    Character* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

   

    me->printInventory();
    

    Character Bob;
    Bob = *me;
    Bob.printInventory();

    delete me; 
    delete src;
}

void test4( void ) {

   
    IMateriaSource* src = new MateriaSource(); 
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    
    Character* me = new Character("me");
    Character* Bob = new Character( "Bob" );

    AMateria* cure1;
    cure1 = src->createMateria("cure");
    me->equip(cure1);

    AMateria* cure2;
    cure2 = src->createMateria("cure");
    Bob->equip(cure2);

    AMateria* cure3;
    cure3 = src->createMateria("cure");
    me->equip(cure3);

    AMateria* cure4;
    cure4 = src->createMateria("cure");
    Bob->equip(cure4);

    AMateria* ice1;
    ice1 = src->createMateria("ice");
    me->equip(ice1);

    AMateria* ice2;
    ice2 = src->createMateria("ice");
    Bob->equip(ice2);

    AMateria* ice3;
    ice3 = src->createMateria("ice");
    Bob->equip(ice3);

    AMateria* ice4;
    ice4 = src->createMateria("ice");
    me->equip(ice4);
    me->unequip(3);
    me->use(3, *Bob);
    Bob->unequip(2);
    Bob->equip(ice4);


    me->printInventory();
    Bob->printInventory();

    Bob->use(0, *me);
    me->use(0, *Bob);
    Bob->use(1, *me);
    me->use(1, *Bob);
    Bob->use(2, *me);
    me->use(2, *Bob);
    Bob->use(3, *me);
    me->use(3, *Bob);

    Character::printMatToFree();

    me->unequip( 0 );
    me->unequip( 1 );
    me->unequip( 2 );
    me->unequip( 3 );

    Bob->unequip( 0 );
    Bob->unequip( 1 );
    Bob->unequip( 2 );
    Bob->unequip( 3 );

    Character::printMatToFree();
    
    Bob->printInventory();
    me->printInventory();

    Bob->equip(cure1);

    me->equip(cure2);

    Character::printMatToFree();

    me->equip(cure3);
    me->equip(cure4);
    me->equip(ice1);
    me->equip(ice2);
    me->use(0, *me);
    Bob->use( 2, *me );

    Character::printMatToFree();
    Bob->printInventory();
    me->printInventory();
    Character::printMatToFree();

    delete src;
    delete Bob; 
    delete me; 
 
}

void testCopy( void ) {

    IMateriaSource* src = new MateriaSource(); 
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());

//----------------------------------------------------------------------

    Character* Bob = new Character( "Bob" );
    Bob->printInventory();

    AMateria* tmp;

    tmp = src->createMateria("ice");
    Bob->equip(tmp);
        
    tmp = src->createMateria("cure");
    Bob->equip(tmp);
    
    tmp = src->createMateria("ice");
    Bob->equip(tmp);
        
    tmp = src->createMateria("cure");
    Bob->equip(tmp);
       
    Bob->printInventory();

//----------------------------------------------------------------------

    Character* chris = new Character("Chris");
    chris->printInventory();

    tmp = src->createMateria("ice"); 
    chris->equip(tmp);

    tmp = src->createMateria("cure");
    chris->equip(tmp);

    tmp = src->createMateria("ice"); 
    chris->equip(tmp);

    tmp = src->createMateria("ice");
    chris->equip(tmp);

    chris->printInventory();

std::cout << "********************************************************************************" << std::endl;
std::cout << "********************************************************************************\n" << std::endl;
    

    Character* carol = new Character(*Bob); // Copy
    carol->printInventory();

std::cout << "********************************************************************************" << std::endl;
std::cout << "********************************************************************************\n" << std::endl;

    *chris = *Bob; // Assignment
    chris->printInventory();
    
    delete carol;
    delete Bob;
    delete chris;
    delete src;
}

int main() {

    // test1();
    // test2();
    // test3();
    test4();
    // testCopy();
   
    // system ("leaks a.out");
    return 0;
}