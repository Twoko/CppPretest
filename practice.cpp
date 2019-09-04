#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <limits>


using namespace std;

//---------------
//STRUCT GLOBAL
//---------------
struct ball{
    char Color[50];
    char Texture[50];
    int ID;
    double Diameter;
};

//wipe the buffer up to newline
void * clearStream(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//---------------
//READ FILE OUT TO STRUCT BALL ARRAY AND RETURN POINTER TO IT
//---------------
ball * readData(int & n);
ball * readData(int & n){
    ball * ptr = new ball[n];
    string filename = "data.txt";
    fstream rw;
    rw.open(filename);
    rw.seekg(0, rw.beg);
    int i = 0;

    string color, tex;
    double dia;
    int id;
    while (rw >> color >> tex >> dia >> id){
         //first name needs to be 9 characters
        color = color.substr(0, 9);
        //last name needs to be 10 characters
        tex = tex.substr(0, 10);
        //fultex assignment/concatenation
        string name = color + ' ' ;

        //copy fultex to struct name, which is char
        strcpy(ptr[i].Color, color.c_str());
        strcpy(ptr[i].Texture, tex.c_str());


        //assign the struct's Diameter variable
        ptr[i].Diameter = dia;
        ptr[i].ID = id;
        i++;
    }
    rw.close();
    return ptr;
}

//---------------
//DISPLAY EACH ITEM IN STRUCT ARRAY AS CUSTOMER DATA
//---------------
void display(ball * p, int n){
    //easy string for spacing
    string spacer = string(12, ' ');

    cout << spacer << "ID"<< "Color" << spacer << "Texture" << "Diameter" << endl;
    cout << string(47, '-') << endl;
    for (int i = 0; i < n; i++){
        cout << spacer << p[i].ID << " " << p[i].Color << " " << p[i].Texture << " " << p[i].Diameter << endl;
    }
    cout << string(47, '-') << endl;
}

//displays options menu
void menu(){
    cout << "1. Display all." << endl;
    cout << "2. Find the balls with diameters above 10mm" << endl;
//List balls with less or equal to 10mm"
//4.Show all balls that are smooth"<<"\n";
//cout<<" 5. Show all balls that are rough"<<"\n";
//cout<<" 6.Find a ball by ID"<<"\n";
//cout<<" 7.List by Color"<<"\n";
  //  cout << "3. Add to a record" << endl;
    cout << "4. Save to the file" << endl;
cout << "5. Exit" << endl;
}
//
//---------------
//FIND THE ACCOUNT WITH HIGHEST Diameter
//---------------
void FindAboveTen(ball * p, int n){
    //value to hold the index of the current richest customer
    int dia_grt_ten = 0;
    for (int i = 0; i < n; i++){
        //if the current item is greater than the current set "richest",
        if (p[i].Diameter > p[dia_grt_ten].Diameter){
            //update richest index to the current item
            dia_grt_ten = i;
        }
    }
    cout << "\nThe balls with greater than 10mm in Diameter are  " << p[dia_grt_ten].Color << '\n' ;
}
void FindbelowTen(ball * p, int n){
    //value to hold the index of the current richest customer
    int dia_les_eq_ten = 0;
    for (int i = 0; i < n; i++){
        //if the current item is greater than the current set "richest",
        if (p[i].Diameter <= p[dia_les_eq_ten].Diameter){
            //update richest index to the current item
            dia_les_eq_ten = i;
        }
    }
    cout << "\nThe balls with less than or equal 10mm in Diameter are  " << p[dia_les_eq_ten].Color << '\n' << '\n';
}
//---------------
//"DEPOSIT" MONEY TO AN ACCOUNT
//---------------
int search(ball *p, int id,int itemcount){

int found =-1;
for (int i = 0; i < itemcount && found==-1; i++)
{

if (p[i].ID == id) found=i;

else found=-1 ;
}

return found;

}
void Add(ball * p, int& itemcount){
  again:
  cout<<"\nEnter Ball's ID: ";
  cin>>p[itemcount].ID;
  if(search(p,p[itemcount].ID,itemcount)!=-1)
  {
  cout<<"This ID already exists\n";
  goto again;
  }

  cout<<"Enter Ball's Color:";
  cin>>p[itemcount].Color;
  cout<<"Enter ball's texture(Smooth or Rough):";cin>>p[itemcount].Texture;
  cout<<"Enter ball's diameter in mm:";cin>>p[itemcount].Diameter;


  ++itemcount;
  // /  int indexOfBall = -1;
  //   for (int i = 0; i < n; i++){
  //       //convert cstring to string
  //       string pColorStr = p[i].Color;
  //       //compare strings
  //       if (ballColor == pColorStr){
  //           indexOfBall = i;
  //       }
  //   }
  //   p[indexOfBall].Diameter += diameter;
  //   p[indexOfBall].Texture +=
  //   cout << p[indexOfBall].Color << " " << p[indexOfBall].Diameter << "mm" << " " << p[indexOfBall].Texture << "ball is added!" ;
}


//Helper to grab customer deposit information
void IDLookup(ball * p, int n, int ballid, double &diameter, bool &isValid){
    int indexOfBall = -1;
    for (int i = 0; i < n; i++)
    {
        //convert cstring to string
        int pid = p[i].ID;
        //compare strings
        if (ballid == pid)
        {
            indexOfBall = i;

          }
    //if int was never changed, just return
    if (indexOfBall == -1)
    {
        cout << "\nCould not find the ball.\n" << endl;
    }
    //if correct name
    else {
        //grab the diameter
        cout << p[indexOfBall].Color << " " << p[indexOfBall].Diameter << "mm" << " " << p[indexOfBall].Texture << "Found!" ;
        }
}
}


//---------------
//WRITE NEW ARRAY DATA BACK TO FILE
//---------------
void NewCopy(string filename, ball * p, int n){
    //open an fstream and truncate the file
    fstream ww(filename, std::fstream::out | std::fstream::trunc);
    for (int i = 0; i < n; i++){
        //copy the array into the file in the same format
        ww << "ID: " << p[i].ID << " " <<"Color: "<< p[i].Color << " " <<"Diameter: " << p[i].Diameter <<"mm" << " " << "Texture: " << p[i].Texture << endl;
    }
    ww.close();
    cout << "File Updated..." << endl;


}

int main()
{

    string filename = "data.txt";
    fstream rw;
    rw.open(filename);
    //count words in the file (3 per line)
    int count = 0;
    string word;
    while (rw >> word){
        count++;
    }
    //close the file for now
    rw.close();
    //find number of people listed in file
    int n = count / 3;
    //read file data to an array of type struct and return a pointer to the array
    ball * ballPtr = readData(n);

    //create a loop that displays account Diameters, a menu, and asks for input
    char k;
    while (k != '5'){

        //Display the menu
        menu();
        //Ask user to pick a menu item
        cout << "Please choose an option by typing its number: ";
        cin >> k;
        clearStream();
        if(k == '1'){
            //Display all accounts
            display(ballPtr, n);
        }
        else if(k == '2'){
            //Find the highest Diameter
            FindAboveTen(ballPtr, n);
        }
        else if(k == '3'){
            //Ask for name first
            int ballid;
            int input;
            double diameter;
            bool isValid = false;
            cout << "Enter ID to look up: ";
            cin >> input;
            if (input == ballid) {
              /* code */
              //Deposit Flow
              IDLookup(ballPtr, n, ballid, diameter, isValid);
              //if name and diameter are both valid
              if (isValid){
                  //process the deposit
                  Add(ballPtr, n);
              }
            }

            //Update the txt file
            //NewCopy(filename, ballPtr, n);
        }
        else if(k == '4'){
            //Update the txt file
            NewCopy(filename, ballPtr, n);
        }
        else if(k == '5'){
            //clear out the "new" ball array we created earlier
            delete [] ballPtr;
            //exit option
            cout << "Goodbye" << endl;
        }
        else{
            //notice of wrong input
            cout << "Invalid Input" << endl;
        }



    return 0;

}
}
