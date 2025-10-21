#include "Zombie.hpp"

int main() {
	// Heap allocation - zombie exists outside function scope
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	// Stack allocation - zombie destroyed when function returns
	randomChump("StackZombie");

	return 0;
}
