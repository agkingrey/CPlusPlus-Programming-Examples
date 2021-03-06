// AustinKingreyHeirarchy.cpp : Defines the entry point for the console application.
//I decided to take the option of writing a fresh program, instead of modifying an existing one.
//This creates a 3 level heirarchy of an animal, dog, and corgi (The animal example has always made sense to me in 2-level).
//To test the effectiveness of the program, simply remove the word "virtual" from the animal class, resulting in all 3 function
//calls doing the same thing.

#include "stdafx.h"
#include <iostream>
using namespace std;

//Example of adt. no implementation, but still carries on the function to inheriting classes
class Animal
{
	public:
		virtual void exFunction(){}
		
};
//dog inherits animal traits
class Dog : public Animal
{
	public:
		void exFunction()
		{
			cout << "Dogs move on four legs." << endl;
		}

};

//corgi inherits the dog traits
class Corgi : public Dog
{
	public:
		void exFunction()
		{
			cout << "Corgis move very slowly." << endl;
		}
};

//function that will call animal's exFunction(without virtual function in Animal and DOG all 3 function calls would produce results from the animal function)
void callFunc(Animal *lvAnimal)
{
	lvAnimal->exFunction();
}

int main()
{
	//creates my animal/dog/corgi objects, using pointers 
	Animal *animal = new Animal;
	Dog *dog = new Dog;
	Corgi *corgi = new Corgi;

	callFunc(animal);
	callFunc(dog);
	callFunc(corgi);

    return 0;
}

