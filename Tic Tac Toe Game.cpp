#include <iostream>
using namespace std;

char game_params[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char symbol = 'x';
bool tie = false;;
string oga1 = "";
string oga2 = "";
void functionOne(){



  cout<< "   |	   |  \n";
  cout<<" "<<game_params[0][0]<<" |  "<<game_params[0][1]<<"    | "<<game_params[0][2]<<" \n";
  cout<< "___|_______|___\n";
  cout<< "   |	   |   \n";
  cout<<" "<<game_params[1][0]<<" |  "<<game_params[1][1]<<"    |  "<<game_params[1][2]<<"  \n";
  cout<< "___|_______|___ \n";
  cout<< "   |	   |  \n";
  cout<<" "<<game_params[2][0]<<" |  "<<game_params[2][1]<<"    |  "<<game_params[2][2]<<"  \n";
  cout<< "   |       |  \n";
}

void functionTwo() {


	int num;

	if (symbol == 'x')
	{
		cout << oga1 << " please enter a number: ";
		cin >> num;
	}

	if (symbol == '0')
	{
		cout << oga2 << " please enter a number: ";
		cin >> num;
	}


	if (num == 1)
	{
		row = 0;
		column = 0;
	}
	if (num == 2)
	{
		row = 0;
		column = 1;
	}
	if (num == 3)
	{
		row = 0;
		column = 2;
	}if (num == 4)
	{
		row = 1;
		column = 0;
	}if (num == 5)
	{
		row = 1;
		column = 1;
	}if (num == 6)
	{
		row = 1;
		column = 2;
	}if (num == 7)
	{
		row = 2;
		column = 0;
	}if (num == 8)
	{
		row = 2;
		column = 1;
	}if (num == 9)
	{
		row = 2;
		column = 2;
	}

	else if(num<1 || num>9){
		cout << "invalid !!!" <<endl;
	}

	if (symbol == 'x' && game_params[row][column] != 'x' && game_params[row][column] != '0')
	{
		game_params[row][column] = 'x';
		symbol = '0';
	}
	else if (symbol == '0' && game_params[row][column] != 'x' && game_params[row][column] != '0')
	{
		game_params[row][column] = '0';
		symbol = 'x';
	}
	else {
		cout << "There is no empty space!" << endl;
		functionTwo();
	}
	
}

  bool functionThree()
  {
	  for (int i = 0; i < 3; i++)
	  {
		  if (game_params[i][0] == game_params[i][1] && game_params[i][0] == game_params[i][2] || game_params[0][i] == game_params[1][i] && game_params[0][i] == game_params[2][i])
			  return true;
	  }
	  if (game_params[0][0] == game_params[1][1] && game_params[1][1] == game_params[2][2] || game_params[0][2] == game_params[1][1] && game_params[1][1] == game_params[2][0])
	  {
		  return true;
	  }

	  for (int i = 0; i < 3; i++)
	  {
		  for (int j = 0; j < 3; j++)
		  {
			  if (game_params[i][j] != 'x' && game_params[i][j] != '0')
			  {
				  return false;
			  }
		  }
	  }
	  tie = true;
	  return false;
  }

  int main()
  {
	  
	  cout << "Enter the name of the first player : ";
	  cin>> oga1;
	  cout << "Enter the name of the second player : ";
	  cin >> oga2;
	  cout << oga1 << " is player1 so they will play first \n";
	  cout << oga2 << " is player2 so they will play second \n";

	  while (!functionThree())
	  {
		  functionOne();
		  functionTwo();
		  functionThree();

	  }
	  functionOne();
	  if (symbol == 'x' && tie == false)
	  {
		  cout << oga2 << " Wins!!" << endl;

	  }
	  else if (symbol == '0' && tie == false)
	  {
		  cout << oga1 << " Wins!!" << endl;

	  }
	  else 
	  {
		  cout << "It's a draw!" << endl;
	  }
  }

