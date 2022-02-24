#include<iostream>
#include<ctime>
#include<conio.h>
#include<vector>
#include<fstream>
using namespace std;
#define MAX_SIZE 100

struct t_player { int x, y; };

int main()
{
	t_player player;
	int i = 0, j = 0, n, a, m, b;
	int M[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], A[MAX_SIZE][MAX_SIZE], size;
	char secim,again;
	int gold = 0, flag = 0,loop=0;
	fstream dataFile;
	
	dataFile.open("way.txt", ios::out);

	cout << "\nPlease enter size of the labirent: ";
	cin >> size;
	srand(time(NULL));

		system("cls");


		while (1)
		{
			while(size>100||size<10)
			{
			cout << "Please enter labirent size bigger than 10 and smaller than 100! ";
			cin >> size;
			}

			if(size<=100||size>=10)
			{
				for (i = 0; i < size; i++)
				{
					for (j = 0; j < size; j++)
					{
						M[i][j] = (rand() % 2);
						if (i == 0 && j == 0)
						{
							M[0][0] = 0;
						}
					}
				}
				cout << endl << endl;

				//WAY//

				for (i = 0; i < size; i++)
				{
					if (i < size - 1 && i>-1)
					{
						for (j = 0; j < size; j++)
						{
							if (j == 0)
							{
								if (M[i][j + 1] != 0 && M[i + 1][j] != 0)
								{
									M[i][j + 1] = 0;
								}
							}
							else if (j == size - 1)
							{
								if (M[i + 1][j] != 0 && M[i][j - 1] != 0)
								{
									M[i + 1][j] = 0;
								}
							}
							else
							{
								if (M[i + 1][j] != 0 && M[i][j + 1] != 0)
								{
									M[i + 1][j] = 0;
								}
							}
						}
					}
				}

				//MONSTERS AND GOLDS//

				n = size * 3;
				m = size * 3;
				for (a = 0; a < n; a++)
				{
					i = (rand() % size + 1);
					j = (rand() % size + 1);
					B[i][j] = M[i][j];
				}
				for (a = 0; a < m; a++)
				{
					i = (rand() % size + 1);
					j = (rand() % size + 1);
					A[i][j] = M[i][j];
				}

				//LABIRENT//

				for (i = 0; i < size; i++)
				{
					for (j = 0; j < size; j++)
					{
						if (M[i][j] == 0 && M[i][j] == B[i][j])
						{
							M[i][j] = 3;
						}
						else if (M[i][j] == 0 && M[i][j] == A[i][j])
						{
							M[i][j] = 8;
						}
					}
				}

				for (i = 0; i < size; i++)
				{
					for (j = 0; j < size; j++)
					{
						if (j == 0)
						{
							if (M[i][j + 1] != 0 && M[i + 1][j] != 0 && M[i][j + 1] != 8 && M[i + 1][j] != 8)
							{
								M[i][j + 1] = 0;
							}
						}
						else if (j == size - 1)
						{
							if (M[i + 1][j] != 0 && M[i][j - 1] != 0 && M[i + 1][j] != 8 && M[i][j - 1] != 8)
							{
								M[i + 1][j] = 0;
							}
						}
						else
						{
							if (M[i + 1][j] != 0 && M[i][j + 1] != 0 && M[i + 1][j] != 8 && M[i][j + 1] != 8)
							{
								M[i + 1][j] = 0;
							}
						}

					}
				}

				for (i = 0; i < size; i++)
				{
					for (j = 0; j < size; j++)
					{
						if (M[i][j] == 3)
							cout << "*" << "\t";
						else if (M[i][j] == 8)
							cout << "$" << "\t";
						else
							cout << M[i][j] << "\t";
					}
					cout << endl << endl;
				}

				//THE GAME//
				dataFile << "x\ty\n----------\n";

				cout << "\t$:Golds\n\t*:Monsters\n";

				cout << "\tBaslamak icin herhangi bir tusa basiniz.\n";

				do
				{
					loop++;
					cout << "\t[W] - Up\n";
					cout << "\t[S] - Down\n";
					cout << "\t[A] - Left\n";
					cout << "\t[D] - Right\n";

					secim = _getch();
					system("cls");

					if (flag == 1)
					{
						secim = 'P';
						flag = 0;
					}

					if (secim == 'P' || secim == 'p'||loop==1)//to play
					{
						player.x = 0;
						player.y = 0;
					}

					else if (secim == 'W' || secim == 'w')//move up
					{
						if (M[player.y - 1][player.x] != 1 && player.y != 0)
							player.y = player.y - 1;
					}

					else if (secim == 'S' || secim == 's')//move down
					{
						if (M[player.y + 1][player.x] != 1)
							player.y = player.y + 1;
					}

					else if (secim == 'A' || secim == 'a')//move left
					{
						if (M[player.y][player.x - 1] != 1&&player.x!=0)
							player.x = player.x - 1;
					}

					else if (secim == 'D' || secim == 'd')//move right
					{
						if (M[player.y][player.x + 1] != 1&&player.x!=size-1)
							player.x = player.x + 1;
					}

					else if (secim == 'Q' || secim == 'q')
						exit(0);

					else
					{
						secim = _getch();
						system("cls");
					}


					cout << endl << endl;
					for (i = 0; i < size; i++)
					{
						for (j = 0; j < size; j++)
						{

							if (i == player.y && j == player.x)
							{

								if (M[i][j] == 3)
								{
									gold = 0;
									flag = 1;
									system("cls");
									cout << "Canavarla karsilastiniz!Oyuna yeniden baslamak icin bir tusa basiniz.";
									break;
								}
								else if (M[i][j] != 3)
								{
									if (flag == 1)
									{
										break;
									}
									cout << "[" << "X" << "]" << "\t";

									if (M[i][j] == 8)
									{
										gold++;
									}

								}

							}
							else if (M[i][j] == 3)
							{
								if (flag == 1)
									break;

								cout << "*" << "\t";
							}
							else if (M[i][j] == 8)
							{
								if (flag == 1)
									break;

								cout << "$" << "\t";
							}
							else
							{
								if (flag == 1)
									break;

								cout << M[i][j] << "\t";
							}
						}
						cout << endl << endl;
					}
					if (flag == 1)
					{
						dataFile.close();
						dataFile.open("way.txt", ios::out);
						dataFile << "x\ty\n----------\n";
					}
					else
					{
						dataFile << player.x << "\t" << player.y << endl;
					}
					if (player.y == size - 1)
					{
						break;
					}

				} while (secim != 'Q' || secim != 'q');
				system("cls");
				cout << "\nTebrikler labirenti tamamladiniz! \n";
				cout << "Toplanan altin sayisi: " << gold << endl;
				dataFile.close();
			}
			cout << "\n\tYeniden oynamak ister misiniz? \n\t[Y]: Evet\n\t[N]: Hayir " << endl;
			cin >> again;
			if (again == 'Y' || again == 'y')
			{
				gold = 0;
				loop = 0;
				cout << "\nPlease enter size of the labirent: ";
				cin >> size;
				system("cls");
				dataFile.close();
				dataFile.open("way.txt", ios::out);
			}
			else if (again == 'N' || again == 'n')
			{
				exit(0);
			}
			else
			{
				exit(0);
			}
		}


		cout << endl << endl;
		system("pause");
		return 0;

}

