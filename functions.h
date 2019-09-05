#include <iostream>
using namespace std;
int showMenu(){
	system("cls");
	cout<<"1. Add new Ball \n";
	cout<<"2. List All Balls with Diameter above 10mm \n";
	cout<<"3. List All Balls with less or equal to 10mm  \n";
	cout<<"4. Show All Balls that are Smooth \n";
	cout<<"5. Show All Balls that are Rough \n";
	cout<<"6. Find Ball based on ID \n";
	cout<<"7. No. of Ball for specific Color \n";
	cout<<"8. Press Any Other key to Exit the Programm \n";
	cout<<"\nPlease Select the options (1-8) : ";
	int a;
	cin>>a;
	return a;
}
