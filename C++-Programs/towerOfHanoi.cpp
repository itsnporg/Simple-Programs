
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
	if (n == 0) {
		return;
	}

	towerOfHanoi(n - 1, source, destination, auxiliary);

	cout << source << " " << destination << endl;

	towerOfHanoi(n - 1, auxiliary, source, destination);
}


int main()  {  
    int n = 4; // total number of disks to move
    towerOfHanoi(n, 'A', 'C', 'B'); // A,B and C are the towers.
    return 0;  
}