/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:02:47 by chris             #+#    #+#             */
/*   Updated: 2023/08/25 15:33:51 by chris            ###   ########.fr       */
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

}
void test2( void ) {

    IMateriaSource* src = new MateriaSource(); 
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    
    src->printLearnedMateria();

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
    
    src->printLearnedMateria();

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
    
    src->printLearnedMateria();

    IMateriaSource* src2 = new MateriaSource(); 
    src2->learnMateria(new Ice()); 
    src2->learnMateria(new Cure());
    src2->learnMateria(new Ice()); 
    src2->learnMateria(new Cure());

    src2->printLearnedMateria();

    Character* me = new Character("me");
    Character* Bob = new Character( "Bob" ); 
    AMateria* tmp;
    AMateria* tmp2;

   
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp2 = src2->createMateria("ice");
    Bob->equip(tmp2);

    
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp2 = src2->createMateria("ice");
    Bob->equip(tmp2);

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp2 = src2->createMateria("cure");
    Bob->equip(tmp2);

    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp2 = src2->createMateria("cure");
    Bob->equip(tmp2);



    me->printInventory();
    Bob->printInventory();

    // Bob->use(0, *me);
    // me->use(0, *Bob);
    // Bob->use(1, *me);
    // me->use(1, *Bob);
    // Bob->use(2, *me);
    // me->use(2, *Bob);
    // Bob->use(3, *me);
    // me->use(3, *Bob);
    Character::printMatToFree();


    me->unequip( 0 );
    me->unequip( 1 );
    me->unequip( 2 );
    me->unequip( 3 );



    Bob->unequip( 0 );
    Bob->unequip( 1 );
    Bob->unequip( 2 );
    Bob->unequip( 3 );

    // Character::printMatToFree();
    Bob->printInventory();
    me->printInventory();

    // Bob->equip(tmp);

    // me->equip(tmp);
    Character::printMatToFree();

    me->equip(tmp2);
    me->equip(tmp);
    me->equip(tmp2);
    me->equip(tmp);
    me->use(0, *me);
    Character::printMatToFree();
    Bob->printInventory();
    me->printInventory();
    // me->unequip( 0 );

    Character::printMatToFree();
    Bob->printInventory();
    me->printInventory();
    // Bob->unequip(0);


    Character::printMatToFree();

    // Bob->equip(tmp2);
    // Bob->printInventory();
    
   
    // me->printInventory();
    // Bob->printInventory();

    // Character* cpy = new Character( *me );
    // Character* cpy2 = new Character( *me );
    // Character* cpy3 = new Character( *me );

    // cpy->printInventory();
    // cpy2->printInventory();
    // cpy3->printInventory();



    // Character::printMatToFree();

   



    

    delete src;
    delete src2;
    delete Bob; 
    delete me; 
    // delete cpy;
    // delete cpy2;
    // delete cpy3;
    


}

void testReequip( void ) {

    IMateriaSource* src = new MateriaSource(); 
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());

  

    Character* me = new Character("me");
    Character* Bob = new Character( "Bob" ); 
    AMateria* tmp;
    AMateria* tmp2;

    tmp = src->createMateria("ice");
    tmp2 = src->createMateria("cure");
    me->equip(tmp);
    Bob->equip(tmp);
    me->printInventory();

    me->use(0, *Bob);

    Bob->equip(tmp2);

    me->unequip(0);
    me->printInventory();

    Bob->equip(tmp);
    Bob->printInventory();

    Character::printMatToFree();

    delete src;
    delete me;
    delete Bob;


}

void testCopy( void ) {

    IMateriaSource* src = new MateriaSource(); 
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    src->printLearnedMateria();

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

    delete carol;

    carol = new Character(*chris);
    carol->printInventory();

    *chris = *Bob; // Assignment
    chris->printInventory();
    delete carol;
    delete Bob;
    delete chris;
    delete src;
}

int main() {


    // test1();
    // test3();
    // test4();
    // testReequip();

    testCopy();

    

    




    system ("leaks a.out");
    return 0;
}