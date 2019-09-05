#include <iostream>
#include <String>
#include <unistd.h>
#include <fstream>
#include "functions.h"   //file for functions defined to use in code
#include "ball.h"        // class of ball to hold data of balls
using namespace std;

int main() {
	int choice=0;
	Ball temp;
	ifstream rfile;
	while(choice!=8){
		choice=showMenu();   //show menu and get choice from user
		bool found=false;
		if(choice==1){
			Ball b;
			b.input();
			cout<<"Do you want to save this information (Y/N) ? \n";
			char save;
			cin>>save;
			if(save=='Y' || save=='y'){
				b.saveToFile();
				cout<<"Ball Added Successfully...!";
			}
		}
		else if(choice==2){
			rfile.open("balls.txt",ios::in);
			if(!rfile){
				cout<<"No File Found. Please First Add balls to view\n";
				sleep(3);
				return 0;
			}
			while(!rfile.eof()){
				temp.readFromFile(rfile);
				if(temp.getDiameter()>10){
					temp.show();
					found=true;
				}
			}
			if(!found)
				cout<"No Ball Found\n";
			found=false;
			rfile.close();

		}
		else if(choice==3){
			rfile.open("balls.txt",ios::in);
			if(!rfile){
				cout<<"No File Found. Please First Add balls to view\n";
				sleep(3);
				return 0;
			}
			while(!rfile.eof()){
				temp.readFromFile(rfile);
				if(temp.getDiameter()<=10){
					temp.show();
					found=true;
				}
			}
			if(!found)
				cout<<"No Ball Found\n";
			found=false;
			rfile.close();
		}
		else if(choice==4){
			rfile.open("balls.txt",ios::in);
			if(!rfile){
				cout<<"No File Found. Please First Add balls to view\n";
				sleep(3);
				return 0;
			}
			while(!rfile.eof()){
				temp.readFromFile(rfile);
				if(temp.isSmooth()){
					temp.show();
					found=true;
				}
			}
			if(!found)
				cout<<"No Ball Found\n";
			found=false;
			rfile.close();
		}
		else if(choice==5){
			rfile.open("balls.txt",ios::in);
			if(!rfile){
				cout<<"No File Found. Please First Add balls to view\n";
				sleep(3);
				return 0;
			}
			while(!rfile.eof()){
				temp.readFromFile(rfile);
				if(!temp.isSmooth()){
					temp.show();
					found=true;
				}
			}
			if(!found)
				cout<<"No Ball Found\n";
			found=false;
			rfile.close();
		}
		else if(choice==6){
			cout<<"Enter the ID of Ball : ";
			int ballToFind;
			cin>>ballToFind;
			rfile.open("balls.txt",ios::in);
			if(!rfile){
				cout<<"No File Found. Please First Add balls to view\n";
				sleep(3);
				return 0;
			}
			while(!rfile.eof()){
				temp.readFromFile(rfile);
				if(temp.getId()==ballToFind){
					temp.show();
					found=true;
				}
			}
			if(!found)
				cout<<"No Ball Found\n";
			found=false;
			rfile.close();
		}
		else if(choice==7){
			cout<<"Enter the color for which you want to count (in lower case) : ";
			string colToFind;
			cin>>colToFind;
			int count=0;
			rfile.open("balls.txt",ios::in);
			if(!rfile){
				cout<<"No File Found. Please First Add balls to view\n";
				sleep(3);
				return 0;
			}
			while(!rfile.eof()){
				temp.readFromFile(rfile);
				if(temp.getColor()==colToFind){
					found=true;
					count++;
				}
			}
			if(!found)
				cout<<"No Ball Found\n";
			else
				cout<<"Total : "<<count<<" ball(s)"<<endl;
			found=false;
			rfile.close();
		}
		else if(choice==8)
			return 0;
		else
			cout<<"Invalid Key..! Please select (1-8)\n";
		cout<<"\nPress ENTER to Return to Menu or ";
		system("pause");
	}
	return 0;
}
