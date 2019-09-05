#include <iostream>
#include <String>
#include <unistd.h>
#include <fstream>
using namespace std;
class Ball{
	private:
		int id;
		double diameter;
		string color;
		bool surface;
	public:
		void input(){
			cout<<"Enter ID of Ball : ";
			cin>>id;
			cout<<"Enter Diameter of Ball : ";
			cin>>diameter;
			cout<<"Enter Color of Ball (in lower case) : ";
			cin>>color;
			cout<<"Ball is Smooth or Rough (Press 0 for rough 1 for smooth) : ";
			cin>>surface;
		}
		void show(){
			cout<<"\nID : "<<id<<endl;
			cout<<"Diameter : "<<diameter<<endl;
			cout<<"Color : "<<color<<endl;
			if(surface==1)
				cout<<"Surface : Smooth "<<endl;
			else
				cout<<"Surface : Rough"<<endl;
		}
		void saveToFile(){
			ofstream wrfile;
			wrfile.open("balls.txt",ios::out|ios::app);
			wrfile<<id<<" "<<diameter<<" "<<color<<" "<<surface<<endl;
			wrfile.close();
		}
		void readFromFile(ifstream &rfile){
			char endchar;
			rfile>>id>>diameter>>color>>surface;
			rfile>>endchar;

		}
		int getId(){
			return id;
		}
		double getDiameter(){
			return diameter;
		}
		string getColor(){
			return color;
		}
		bool isSmooth(){
			return surface;
		}
};
