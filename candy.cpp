#include<iostream>
#include<conio.h>
#include <ctime>
#include <cstdlib>


using namespace std;
const int MAXCOLUMNSIZE = 7;
const int MAXROWSIZE = 7;
void loadArrayGrid(int arr[][MAXCOLUMNSIZE]);
void printArrayGrid(int arr[][MAXCOLUMNSIZE]);
void getUserInput(int&, int&, char&);
void findPattern(int arr[][MAXCOLUMNSIZE], int&);
void doUserMove(int&, int&, char&, int arr[][MAXCOLUMNSIZE]);
int main()
{
	
	int arrGrid[MAXROWSIZE][MAXCOLUMNSIZE] = { 0 };
	int row = 0, col = 0, score = 0, winLimit=4;
	char move='a';
	srand(time(NULL));
	loadArrayGrid(arrGrid);
	while (score < winLimit) {
		findPattern(arrGrid,score);
		if (score >= winLimit)
		{
			break;
		}
		printArrayGrid(arrGrid);
		cout << endl << "Your Score is : " << score;
		getUserInput(row, col, move);
		doUserMove(row, col, move, arrGrid);
	}
	system("CLS");
	cout << "                    CANDY CRUSH" << endl << endl;
	cout << "        ";
	cout <<"Your Score is : " << score;
	_getch();

	return 0;
}

void loadArrayGrid(int arr[][MAXCOLUMNSIZE]) {
	for (int i = 0; i < MAXCOLUMNSIZE; i++)
	{
		for (int k = 0; k < MAXCOLUMNSIZE; k++)
		{
			arr[i][k] = rand() % (MAXCOLUMNSIZE - 1) + 1;
		}
	}
}
void printArrayGrid(int arr[][MAXCOLUMNSIZE]) {
	system("CLS");
	cout << "                    CANDY CRUSH" << endl <<endl;
	cout << "        ";
	for (int i = 0; i < MAXCOLUMNSIZE; i++) {
		cout << i << "   ";
	}
	cout << endl << endl;
	for (int i = 0; i < MAXCOLUMNSIZE; i++)
	{
		
		//Horizontal Formating
		cout << "        ";
		for (int k = 0; k < MAXCOLUMNSIZE; k++)
		{
				cout << "====";	
		}
		cout << endl << "    ";
		cout << i << "   ";
		for (int k = 0; k < MAXCOLUMNSIZE; k++)
		{	
			if (k == (MAXCOLUMNSIZE - 1)) {
				cout << arr[i][k] << "|";
			}
			else {
				cout << arr[i][k] << "| |";
			}
		}	
		cout << endl;
	}
}
void getUserInput(int &r, int &c, char &m) {
	cout << endl << "Enter Row you want to move: ";
	cin >> r;
	cout << endl << "Enter Column you want to move: ";
	cin >> c;
	cin.ignore();
	cout << "Enter Where do you want to move it" << endl << "l > Left" << endl << "r > Right" << endl << "u > Up" << endl << "d > Down" << endl;
	m = getchar();
}
void findPattern(int arr[][MAXCOLUMNSIZE], int &score) {
	int rowInt[MAXCOLUMNSIZE];
	int colInt[MAXCOLUMNSIZE];
	
	for(int count=1;count>0;count--)
	{	//Rows Pattern Matching  Loop
		for (int i = 0; i < MAXCOLUMNSIZE; i++) {
			for (int j = 0; j < MAXCOLUMNSIZE; j++)
			{
				rowInt[j] = arr[i][j];
			}

			for (int j = 0; j < MAXCOLUMNSIZE; j++)
			{
				if (j < MAXCOLUMNSIZE - 1) {
					if (rowInt[j] == rowInt[j + 1] && rowInt[j] == rowInt[j + 2])
					{
						count++;
						cout << "Pattern Found at Row"<< i  << endl;
						cout << "Pattern Found of" << rowInt[j] << endl;
						score++;
						//FOR J
						for (int k = i;k > 0;k--)
						{
							arr[k][j] = arr[k - 1][j];
						}
						
							arr[0][j] = rand() % (MAXCOLUMNSIZE - 1) + 1;
						
						//FOR J+1
						for (int k = i;k > 0;k--)
						{
							arr[k][j + 1] = arr[k - 1][j + 1];
						}
						
							arr[0][j + 1] = rand() % (MAXCOLUMNSIZE - 1) + 1;
						
						//For J+2
						for (int k = i;k > 0;k--)
						{
							arr[k][j + 2] = arr[k - 1][j + 2];
						}
						
							arr[0][j + 2] = rand() % (MAXCOLUMNSIZE - 1) + 1;
						
						j++;
						j++;
					}
					
				}
				
			}
		}
		//Columns Pattern Matching  Loop
		for (int i = 0; i < MAXCOLUMNSIZE; i++)
			{
			for (int j = 0; j < MAXCOLUMNSIZE; j++)
			{
					colInt[j] = arr[j][i];
			}

			for (int j = 0; j < MAXCOLUMNSIZE; j++) //j is index of colInT or Rows of that Column
			{
				if (j < MAXCOLUMNSIZE - 1) {
					if (colInt[j] == colInt[j + 1] && colInt[j] == colInt[j + 2])
						{
						count++;
							cout << "Pattern Found at Column" << i << endl;
							cout << "Pattern Found of" << colInt[j] << endl;
							score++;
							for (int k = j;k > 0;k--)
							{
								arr[k + 2][i] = arr[k - 1][i];
							}
							for (int k = 0; k < 3; k++)
							{
								arr[k][i] = rand() % (MAXCOLUMNSIZE - 1) + 1;
							}
							j++;
							j++;
					}
					
					}

				}
			}
		
	}
}

void doUserMove(int &r, int &c, char &m, int arr[][MAXCOLUMNSIZE]) {
	int temp=0;
	switch (m)
	{
	case 'l':
		if (c != 0) {
			temp = arr[r][c];
			arr[r][c] = arr[r][c - 1];
			arr[r][c - 1] = temp;
		}
		break;
	case 'r':
		if (c < MAXCOLUMNSIZE) {
			temp = arr[r][c];
			arr[r][c] = arr[r][c + 1];
			arr[r][c + 1] = temp;
		}
		break;
	case 'u':
		if (r > 0) {
			temp = arr[r][c];
			arr[r][c] = arr[r-1][c];
			arr[r-1][c] = temp;
		}
		break;
	case 'd':
		if (r < MAXCOLUMNSIZE) {
			temp = arr[r][c];
			arr[r][c] = arr[r + 1][c];
			arr[r + 1][c] = temp;
		}
		break;
	default:
		cout << "Invalid Move";
		break;
	}
}