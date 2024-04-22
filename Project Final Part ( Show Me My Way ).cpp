#include <iostream>
#include<cstring>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
namespace station_list
{
	string line_one[35] = { "Helwan:None","Ain Helwan:None","Helwan University:None","wadi Hof:None","Hadayek Helwan:None",
						 "El-maasara:None","Tora El-Asmant:None","Kozzika:None","Tora El-Balad:None","Sakanat El-Maadi:None",
						 "Maadi:None","Hadayek El-Maadi:None","Dar El-Salam:None","El-Zahraa':None","Mar Girgis:None",
						 "El-Malak El-Saleh:None","Al-sayeda Zeinab:None","Saad Zaghloul:None","Sadat:Line Two","Nasser:None",
						 "Orabi:None","Al-Shohadda:Line Two","Ghamra:None","El-Demerdash:None","Manshiet El-Sadr:None",
						 "Kobri El-Qobba:None","Hammamat El-Qobba:None","Saray El-Qobba:None","Hadayeq El-Zaitoun:None",
						 "Helmeyet El-Zaitoun:None","El-Matareyya:None","Ain Shams:None","Ezbet El-Nakhl:None","El-Marg:None",
						 "New El-Marg:None"
	};
	string line_two[20] = { "El-Mounib:None","Sakiat Mekky:None","Omm El-Masryeen:None","El Giza:None","Faisal:None","Cairo Unversity:None",
						 "El Bohoth:None","Dokki:None","Opera:None","Sadat:Line One","Mohamed Naguib:None","Attaba:Line Three",
						 "Al-Shohadaa:Line One","Masarra:None","Road El-Farag:None","St. Teresa:None","Khalafawy:None","Mezallat:None",
						 "Kolleyyet El-Zeraa:None","Shubra El-Kheima:None"
	};
	string line_three[19] = { "Adly Mansour:None","El Haykestep:None","Omar Ibn El-Khattab:None","Qobaa:None","Hesham Barakat:None",
						   "El-Nozha:None","Nadi El-Shams:None","Alf Maskan:None","Heliopolis Square:None","Haroun:None","Al-Ahram:None",
						   "Koleyet El-Banat:None","Stadium:None","Fair Zone:None","Abbassia:None",
						   "Abdou Pasha:None","El Geish:None","Bab El Shaaria:None","Attaba:Line Two"
	};
}
class station
{
	string name;
	string connection;
public:
	void getdata(string nameConnection)
	{
		int position = nameConnection.find(":");
		name = nameConnection.substr(0, position);
		connection = nameConnection.substr(position + 1);
	}
	string return_name()
	{
		return name;
	}
	string return_connection()
	{
		return connection;
	}
};
class metroline
{
	station stations[35];
public:
	metroline(const string number_of_line)
	{
		if (number_of_line == "one")
		{

			for (int i = 0; i < 35; i++)
			{
				stations[i].getdata(station_list::line_one[i]);
			}
		}
		else if (number_of_line == "two")
		{

			for (int i = 0; i < 20; i++)
			{
				stations[i].getdata(station_list::line_two[i]);
			}
		}
		else if (number_of_line == "three")
		{

			for (int i = 0; i < 19; i++)
			{
				stations[i].getdata(station_list::line_three[i]);
			}
		}
	}
	void show_station(int num)
	{
		cout << setw(10) << left << num + 1 << setw(30) << left << stations[num].return_name() << setw(50) << left
			<< stations[num].return_connection() << endl;
	}
};
void clrscr();
void menu();
void show_list_of_stations();
void service();
void Metro();
bool correctstation(string);
void printWay(int, int, int, int);
int straitline(int, int, int, int);
void from1to2(int, int, int, int);
void from2to1(int, int, int, int);
void from2to3(int, int, int, int);
void from3to2(int, int, int, int);
void from1to3(int, int, int, int);
void from3to1(int, int, int, int);
void metro_subscriptions();
void subscriptions1();
void subscriptions2();
void price_subscription();
void choice();
int numOfstations();
void startMenu();
void calculatePrice(int numOfStations);
void calculateTime(int numOfStations);
int main()
{
	menu();
	return 0;
}
void clrscr()
{
	system("cls");
}
void menu()
{
	char r_choice;
	do {
		char choice;
		cout << "1.show the list of stations.\n";
		cout << "2.Show Me My Way.\n";
		cout << "3.What Is The Cost Of The Trip And The Trip Time?\n";
		cout << "4.Metro Subscriptions.\n";
		cout << "5.Connect Us.\n";
		cout << "*************************************************************\n";
		cout << "Your Choice :";
		cin >> choice;
		clrscr();
		switch (choice)
		{
		case '1':
		{
			show_list_of_stations();
			break;
		}
		case '2':
		{
			Metro();
			break;
		}
		case '3':
		{
			startMenu();
			break;
		}
		case '4':
		{
			metro_subscriptions();
			break;
		}
		case '5':
		{
			service();
			break;
		}
		default:
			cout << "ERROR !\n";
			menu();
		}
		cout << setfill('_') << setw(45) << "_" << endl;
		cout << "Would you rather continue? (Y : yes || N : NO) : ";
		cin >> r_choice;
		clrscr();
	} while (r_choice == 'y' || r_choice == 'Y');

	//if (r_choice != 'y' || r_choice != 'Y')
	cout << "ThANK YOU ! See you later .. \n";
}
void show_list_of_stations()
{
	char choice;
	metroline one("one"), two("two"), three("three");
	cout << "1.show line number one \n";
	cout << "2.show line number two \n";
	cout << "3.show line number three \n";
	cout << "*************************************************************\n";
	cout << "Your Choice :";
	cin >> choice;
	clrscr();
	switch (choice)
	{
	case '1':
		cout << setfill(' ') << setw(10) << left << "S. No." << setw(30) << left << "Station Name" << setw(50) << left << "Connects to" << endl;
		cout << "------------------------------------------------------\n";
		for (int i = 0; i < 35; i++)
			one.show_station(i);
		break;
	case '2':
		cout << setfill(' ') << setw(10) << left << "S. No." << setw(30) << left << "Station Name" << setw(50) << left << "Connects to" << endl;
		cout << "------------------------------------------------------\n";
		for (int i = 0; i < 20; i++)
			two.show_station(i);
		break;
	case '3':
		cout << setfill(' ') << setw(10) << left << "S. No." << setw(30) << left << "Station Name" << setw(50) << left << "Connects to" << endl;
		cout << "------------------------------------------------------\n";
		for (int i = 0; i < 19; i++)
			three.show_station(i);
		break;
	default:
		cout << "ERRoR ! \n";
		show_list_of_stations();
		break;
	}
}
void service()
{
	cout << "Inquiries and complaints number:-\n";
	cout << "----------------------------------\n";
	cout << "phone    : 16048\n";
	cout << "whatsapp : 0122216048\n\n";
}

void Metro()
{

	string s, e;
	int start, end;
	int lineS, lineE;


	string first_line[36] = { "Helwan","Ain_Helwan","Helwan_University","wadi_Hof","Hadayek_Helwan","El_maasara","Tora_El-Asmant","Kozzika","Tora_El-Balad",
							 "Sakanat_El-Maadi","Maadi","Hadayek_El-Maadi","Dar_El-Salam","El-Zahraa'","Mar_Girgis","El-Malak_El-Saleh","Al-sayeda_Zeinab",
							  "Saad_Zaghloul","Sadat","Nasser","Orabi","Al-Shohadda","Ghamra","El-Demerdash","Manshiet_El-Sadr","Kobri_El-Qobba","Hammamat_El-Qobba",
							   "Saray_El-Qobba","Hadayeq_El-Zaitoun","Helmeyet_El-Zaitoun","El-Matareyya","Ain_Shams","Ezbet_El-Nakhl","El-Marg","New_El-Marg" };

	string second_line[20] = { "El-Mounib","Sakiat_Mekky","Omm_El-Masryeen","El_Giza","Faisal","Cairo_Unversity","El_Bohoth","Dokki","Opera","Sadat","Mohamed_Naguib",
							   "Attaba","Al-Shohadaa","Masarra","Road_El-Farag","St._Teresa","Khalafawy","Mezallat","Kolleyyet_El-Zeraa","Shubra_El-Kheima" };

	string third_line[20] = { "Adly_Mansour","El_Haykestep","Omar_Ibn_El-Khattab","Qobaa","Hesham_Barakat","El-Nozha","Nadi_El-Shams",
							 "Alf_Maskan","Heliopolis_Square","Haroun","Al-Ahram","Koleyet_El-Banat","Stadium","Fair_Zone","Abbassia","Abdou_Pasha","El_Geish",
							 "Bab_El_Shaaria","Attaba" };

	do
	{
		cout << "Enter the Starting station : ";
		cin >> s;

	} while (!correctstation(s));
	clrscr();
	do
	{
		cout << "Enter the End station : ";
		cin >> e;

	} while (!correctstation(e));
	clrscr();

	for (int i = 0; i < 36; i++)
	{
		if (s == first_line[i])
		{
			lineS = 1;
			start = i;
		}
		else if (s == second_line[i])
		{
			lineS = 2;
			start = i;
		}
		else if (s == third_line[i])
		{
			lineS = 3;
			start = i;
		}

		if (e == first_line[i])
		{
			lineE = 1;
			end = i;
		}
		else if (e == second_line[i])
		{
			lineE = 2;
			end = i;
		}
		else if (e == third_line[i])
		{
			lineE = 3;
			end = i;
		}
	}

	// Print the way/journy
	cout << "So, Your Way from ( " << s << " ) to ( " << e << " ) will be : ... \n";
	printWay(start, lineS, end, lineE);
}
bool correctstation(string station)
{
	int exist = 0;
	string first_line[36] = { "Helwan","Ain_Helwan","Helwan_University","wadi_Hof","Hadayek_Helwan","El_maasara","Tora_El-Asmant","Kozzika","Tora_El-Balad",
							 "Sakanat_El-Maadi","Maadi","Hadayek_El-Maadi","Dar_El-Salam","El-Zahraa'","Mar_Girgis","El-Malak_El-Saleh","Al-sayeda_Zeinab",
							  "Saad_Zaghloul","Sadat","Nasser","Orabi","Al-Shohadda","Ghamra","El-Demerdash","Manshiet_El-Sadr","Kobri_El-Qobba","Hammamat_El-Qobba",
							   "Saray_El-Qobba","Hadayeq_El-Zaitoun","Helmeyet_El-Zaitoun","El-Matareyya","Ain_Shams","Ezbet_El-Nakhl","El-Marg","New_El-Marg" };

	string second_line[20] = { "El-Mounib","Sakiat_Mekky","Omm_El-Masryeen","El_Giza","Faisal","Cairo_Unversity","El_Bohoth","Dokki","Opera","Sadat","Mohamed_Naguib",
							   "Attaba","Al-Shohadaa","Masarra","Road_El-Farag","St._Teresa","Khalafawy","Mezallat","Kolleyyet_El-Zeraa","Shubra_El-Kheima" };

	string third_line[20] = { "Adly_Mansour","El_Haykestep","Omar_Ibn_El-Khattab","Qobaa","Hesham_Barakat","El-Nozha","Nadi_El-Shams",
							 "Alf_Maskan","Heliopolis_Square","Haroun","Al-Ahram","Koleyet_El-Banat","Stadium","Fair_Zone","Abbassia","Abdou_Pasha","El_Geish",
							 "Bab_El_Shaaria","Attaba" };

	for (int i = 0; i < 36; i++)
		if (station == first_line[i] || station == second_line[i] || station == third_line[i])
			exist = 1;

	if (exist == 0)
	{
		clrscr();
		cout << "sorry ! There is not a Station called ( " << station << " ) ,Try agagin ..\n";
		return false;
	}
	else
		return true;
}
void printWay(int start, int lineS, int end, int lineE)
{

	if (lineS != lineE)
	{
		if (lineS == 1 && lineE == 2)
			from1to2(start, lineS, end, lineE);

		else if (lineS == 2 && lineE == 1)
			from2to1(start, lineS, end, lineE);

		else if (lineS == 2 && lineE == 3)
			from2to3(start, lineS, end, lineE);

		else if (lineS == 3 && lineE == 2)
			from3to2(start, lineS, end, lineE);

		else if (lineS == 1 && lineE == 3)
			from1to3(start, lineS, end, lineE);

		else if (lineS == 3 && lineE == 1)
			from3to1(start, lineS, end, lineE);
	}

	else
		straitline(start, lineS, end, lineE);
}
int straitline(int start, int lineS, int end, int lineE)
{
	int counter = 0;
	//int t, tt;

	string first_line[36] = { "Helwan","Ain_Helwan","Helwan_University","wadi_Hof","Hadayek_Helwan","El_maasara","Tora_El-Asmant","Kozzika","Tora_El-Balad",
							 "Sakanat_El-Maadi","Maadi","Hadayek_El-Maadi","Dar_El-Salam","El-Zahraa'","Mar_Girgis","El-Malak_El-Saleh","Al-sayeda_Zeinab",
							  "Saad_Zaghloul","Sadat","Nasser","Orabi","Al-Shohadda","Ghamra","El-Demerdash","Manshiet_El-Sadr","Kobri_El-Qobba","Hammamat_El-Qobba",
							   "Saray_El-Qobba","Hadayeq_El-Zaitoun","Helmeyet_El-Zaitoun","El-Matareyya","Ain_Shams","Ezbet_El-Nakhl","El-Marg","New_El-Marg" };

	string second_line[20] = { "El-Mounib","Sakiat_Mekky","Omm_El-Masryeen","El_Giza","Faisal","Cairo_Unversity","El_Bohoth","Dokki","Opera","Sadat","Mohamed_Naguib",
							   "Attaba","Al-Shohadaa","Masarra","Road_El-Farag","St._Teresa","Khalafawy","Mezallat","Kolleyyet_El-Zeraa","Shubra_El-Kheima" };

	string third_line[20] = { "Adly_Mansour","El_Haykestep","Omar_Ibn_El-Khattab","Qobaa","Hesham_Barakat","El-Nozha","Nadi_El-Shams",
							 "Alf_Maskan","Heliopolis_Square","Haroun","Al-Ahram","Koleyet_El-Banat","Stadium","Fair_Zone","Abbassia","Abdou_Pasha","El_Geish",
							 "Bab_El_Shaaria","Attaba" };

	if (end >= start)
		for (int i = start; i <= end; i++)
		{
			counter++;
			cout << counter << " : ";
			switch (lineS)
			{
			case 1:
				cout << first_line[i] << endl;
				break;
			case 2:
				cout << second_line[i] << endl;
				break;
			case 3:
				cout << third_line[i] << endl;
				break;
			}
		}
	else
		for (int i = start; i >= end; i--)
		{
			counter++;
			cout << counter << " : ";
			switch (lineS)
			{
			case 1:
				cout << first_line[i] << endl;
				break;
			case 2:
				cout << second_line[i] << endl;
				break;
			case 3:
				cout << third_line[i] << endl;
				break;
			}
		}
	cout << "No. of Stations = " << counter << endl;

	return counter;
}
void from1to2(int start, int lineS, int end, int lineE)
{
	int counter = 0;
	int t, tt;
	string first_line[36] = { "Helwan","Ain_Helwan","Helwan_University","wadi_Hof","Hadayek_Helwan","El_maasara","Tora_El-Asmant","Kozzika","Tora_El-Balad",
								 "Sakanat_El-Maadi","Maadi","Hadayek_El-Maadi","Dar_El-Salam","El-Zahraa'","Mar_Girgis","El-Malak_El-Saleh","Al-sayeda_Zeinab",
								  "Saad_Zaghloul","Sadat","Nasser","Orabi","Al-Shohadda","Ghamra","El-Demerdash","Manshiet_El-Sadr","Kobri_El-Qobba","Hammamat_El-Qobba",
								   "Saray_El-Qobba","Hadayeq_El-Zaitoun","Helmeyet_El-Zaitoun","El-Matareyya","Ain_Shams","Ezbet_El-Nakhl","El-Marg","New_El-Marg" };

	string second_line[20] = { "El-Mounib","Sakiat_Mekky","Omm_El-Masryeen","El_Giza","Faisal","Cairo_Unversity","El_Bohoth","Dokki","Opera","Sadat","Mohamed_Naguib",
							   "Attaba","Al-Shohadaa","Masarra","Road_El-Farag","St._Teresa","Khalafawy","Mezallat","Kolleyyet_El-Zeraa","Shubra_El-Kheima" };


	for (int i = 0; i < 36; i++)
		for (int j = 0; j < 20; j++)
			if (first_line[i] == second_line[j])
			{
				t = i;
				tt = j;
				break;
			}

	if (t >= start)
		for (int i = start; i < t; i++)
		{
			counter++;
			cout << counter << " : ";
			cout << first_line[i] << endl;
		}
	else
		for (int i = start; i > t; i--)
		{
			counter++;
			cout << counter << " : ";
			cout << first_line[i] << endl;
		}

	if (end >= tt)
		for (int i = tt; i <= end; i++)
		{
			counter++;
			cout << counter << " : ";
			cout << second_line[i] << endl;
		}
	else
		for (int i = tt; i >= end; i--)
		{
			counter++;
			cout << counter << " : ";
			cout << second_line[i] << endl;
		}

	cout << "Transition Station in Station : " << first_line[t] << endl
		<< "No. of Stations = " << counter << endl;

}
void from2to1(int start, int lineS, int end, int lineE)
{
	int counter = 0;
	int t, tt;

	string first_line[36] = { "Helwan","Ain_Helwan","Helwan_University","wadi_Hof","Hadayek_Helwan","El_maasara","Tora_El-Asmant","Kozzika","Tora_El-Balad",
							 "Sakanat_El-Maadi","Maadi","Hadayek_El-Maadi","Dar_El-Salam","El-Zahraa'","Mar_Girgis","El-Malak_El-Saleh","Al-sayeda_Zeinab",
							  "Saad_Zaghloul","Sadat","Nasser","Orabi","Al-Shohadda","Ghamra","El-Demerdash","Manshiet_El-Sadr","Kobri_El-Qobba","Hammamat_El-Qobba",
							   "Saray_El-Qobba","Hadayeq_El-Zaitoun","Helmeyet_El-Zaitoun","El-Matareyya","Ain_Shams","Ezbet_El-Nakhl","El-Marg","New_El-Marg" };

	string second_line[20] = { "El-Mounib","Sakiat_Mekky","Omm_El-Masryeen","El_Giza","Faisal","Cairo_Unversity","El_Bohoth","Dokki","Opera","Sadat","Mohamed_Naguib",
							   "Attaba","Al-Shohadaa","Masarra","Road_El-Farag","St._Teresa","Khalafawy","Mezallat","Kolleyyet_El-Zeraa","Shubra_El-Kheima" };


	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 36; j++)
			if (second_line[i] == first_line[j])
			{
				t = i;
				tt = j;
				break;
			}

	if (t >= start)
		for (int i = start; i < t; i++)
		{
			counter++;
			cout << counter << " : ";
			cout << second_line[i] << endl;
		}
	else // if (start > t)
		for (int i = start; i > t; i--)
		{
			counter++;
			cout << counter << " : ";
			cout << second_line[i] << endl;
		}

	if (end >= tt)
		for (int i = tt; i <= end; i++)
		{
			counter++;
			cout << counter << " : ";
			cout << first_line[i] << endl;
		}
	else
		for (int i = tt; i >= end; i--)
		{
			counter++;
			cout << counter << " : ";
			cout << first_line[i] << endl;
		}

	cout << "Transition Station in Station : " << second_line[t] << endl
		<< "No. of Stations = " << counter << endl;
}
void from2to3(int start, int lineS, int end, int lineE)
{
	int counter = 0;
	int t, tt;

	string second_line[20] = { "El-Mounib","Sakiat_Mekky","Omm_El-Masryeen","El_Giza","Faisal","Cairo_Unversity","El_Bohoth","Dokki","Opera","Sadat","Mohamed_Naguib",
							   "Attaba","Al-Shohadaa","Masarra","Road_El-Farag","St._Teresa","Khalafawy","Mezallat","Kolleyyet_El-Zeraa","Shubra_El-Kheima" };

	string third_line[20] = { "Adly_Mansour","El_Haykestep","Omar_Ibn_El-Khattab","Qobaa","Hesham_Barakat","El-Nozha","Nadi_El-Shams",
							 "Alf_Maskan","Heliopolis_Square","Haroun","Al-Ahram","Koleyet_El-Banat","Stadium","Fair_Zone","Abbassia","Abdou_Pasha","El_Geish",
							 "Bab_El_Shaaria","Attaba" };


	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (second_line[i] == third_line[j])
			{
				t = i;
				tt = j;
				break;
			}

	if (t >= start)
		for (int i = start; i < t; i++)
		{
			counter++;
			cout << counter << " : ";
			cout << second_line[i] << endl;
		}
	else // if (start > t)
		for (int i = start; i > t; i--)
		{
			counter++;
			cout << counter << " : ";
			cout << second_line[i] << endl;
		}

	if (end >= tt)
		for (int i = tt; i <= end; i++)
		{
			counter++;
			cout << counter << " : ";
			cout << third_line[i] << endl;
		}
	else
		for (int i = tt; i >= end; i--)
		{
			counter++;
			cout << counter << " : ";
			cout << third_line[i] << endl;
		}

	cout << "Transition Station in Station : " << second_line[t] << endl
		<< "No. of Stations = " << counter << endl;
}
void from3to2(int start, int lineS, int end, int lineE)
{
	int counter = 0;
	int t, tt;

	string second_line[20] = { "El-Mounib","Sakiat_Mekky","Omm_El-Masryeen","El_Giza","Faisal","Cairo_Unversity","El_Bohoth","Dokki","Opera","Sadat","Mohamed_Naguib",
							   "Attaba","Al-Shohadaa","Masarra","Road_El-Farag","St._Teresa","Khalafawy","Mezallat","Kolleyyet_El-Zeraa","Shubra_El-Kheima" };

	string third_line[20] = { "Adly_Mansour","El_Haykestep","Omar_Ibn_El-Khattab","Qobaa","Hesham_Barakat","El-Nozha","Nadi_El-Shams",
							 "Alf_Maskan","Heliopolis_Square","Haroun","Al-Ahram","Koleyet_El-Banat","Stadium","Fair_Zone","Abbassia","Abdou_Pasha","El_Geish",
							 "Bab_El_Shaaria","Attaba" };


	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (third_line[i] == second_line[j])
			{
				t = i;
				tt = j;
				break;
			}

	if (t >= start)
		for (int i = start; i < t; i++)
		{
			counter++;
			cout << counter << " : ";
			cout << third_line[i] << endl;
		}
	else // if (start > t)
		for (int i = start; i > t; i--)
		{
			counter++;
			cout << counter << " : ";
			cout << third_line[i] << endl;
		}

	if (end >= tt)
		for (int i = tt; i <= end; i++)
		{
			counter++;
			cout << counter << " : ";
			cout << second_line[i] << endl;
		}
	else
		for (int i = tt; i >= end; i--)
		{
			counter++;
			cout << counter << " : ";
			cout << second_line[i][i] << endl;
		}

	cout << "Transition Station in Station : " << third_line[t] << endl
		<< "No. of Stations = " << counter << endl;

}
void from1to3(int start, int lineS, int end, int lineE)
{
	int counter = 0;
	int t, tt2, ttt;

	string first_line[36] = { "Helwan","Ain_Helwan","Helwan_University","wadi_Hof","Hadayek_Helwan","El_maasara","Tora_El-Asmant","Kozzika","Tora_El-Balad",
							 "Sakanat_El-Maadi","Maadi","Hadayek_El-Maadi","Dar_El-Salam","El-Zahraa'","Mar_Girgis","El-Malak_El-Saleh","Al-sayeda_Zeinab",
							  "Saad_Zaghloul","Sadat","Nasser","Orabi","Al-Shohadda","Ghamra","El-Demerdash","Manshiet_El-Sadr","Kobri_El-Qobba","Hammamat_El-Qobba",
							   "Saray_El-Qobba","Hadayeq_El-Zaitoun","Helmeyet_El-Zaitoun","El-Matareyya","Ain_Shams","Ezbet_El-Nakhl","El-Marg","New_El-Marg" };

	string second_line[20] = { "El-Mounib","Sakiat_Mekky","Omm_El-Masryeen","El_Giza","Faisal","Cairo_Unversity","El_Bohoth","Dokki","Opera","Sadat","Mohamed_Naguib",
							   "Attaba","Al-Shohadaa","Masarra","Road_El-Farag","St._Teresa","Khalafawy","Mezallat","Kolleyyet_El-Zeraa","Shubra_El-Kheima" };

	string third_line[20] = { "Adly_Mansour","El_Haykestep","Omar_Ibn_El-Khattab","Qobaa","Hesham_Barakat","El-Nozha","Nadi_El-Shams",
							 "Alf_Maskan","Heliopolis_Square","Haroun","Al-Ahram","Koleyet_El-Banat","Stadium","Fair_Zone","Abbassia","Abdou_Pasha","El_Geish",
							 "Bab_El_Shaaria","Attaba" };


	for (int i = 0; i < 36; i++)
		for (int j = 0; j < 20; j++)
			if (first_line[i] == second_line[j])
			{
				t = i;
				//tt1 = j;
				break;
			}
	counter += straitline(start, 1, t, 1);
	cout << "Transition Station from line 1 to 2 in station : " << first_line[t] << endl;

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (second_line[i] == third_line[j])
			{
				tt2 = i;
				ttt = j;
				break;
			}
	// print the way
	counter += straitline(t, 2, tt2, 2);
	cout << "Transition Station from line 2 to 3 in station : " << second_line[tt2] << endl;
	if (end >= ttt)
		counter += straitline(ttt + 1, 3, end, 3);
	else
		counter += straitline(ttt - 1, 3, end, 3);
	cout << "No. of all stations in the journy : " << counter << endl << endl;
}
void from3to1(int start, int lineS, int end, int lineE)
{

	int counter = 0;
	int t/*, tt1*/, tt2, ttt;

	string first_line[36] = { "Helwan","Ain_Helwan","Helwan_University","wadi_Hof","Hadayek_Helwan","El_maasara","Tora_El-Asmant","Kozzika","Tora_El-Balad",
							 "Sakanat_El-Maadi","Maadi","Hadayek_El-Maadi","Dar_El-Salam","El-Zahraa'","Mar_Girgis","El-Malak_El-Saleh","Al-sayeda_Zeinab",
							  "Saad_Zaghloul","Sadat","Nasser","Orabi","Al-Shohadda","Ghamra","El-Demerdash","Manshiet_El-Sadr","Kobri_El-Qobba","Hammamat_El-Qobba",
							   "Saray_El-Qobba","Hadayeq_El-Zaitoun","Helmeyet_El-Zaitoun","El-Matareyya","Ain_Shams","Ezbet_El-Nakhl","El-Marg","New_El-Marg" };

	string second_line[20] = { "El-Mounib","Sakiat_Mekky","Omm_El-Masryeen","El_Giza","Faisal","Cairo_Unversity","El_Bohoth","Dokki","Opera","Sadat","Mohamed_Naguib",
							   "Attaba","Al-Shohadaa","Masarra","Road_El-Farag","St._Teresa","Khalafawy","Mezallat","Kolleyyet_El-Zeraa","Shubra_El-Kheima" };

	string third_line[20] = { "Adly_Mansour","El_Haykestep","Omar_Ibn_El-Khattab","Qobaa","Hesham_Barakat","El-Nozha","Nadi_El-Shams",
							 "Alf_Maskan","Heliopolis_Square","Haroun","Al-Ahram","Koleyet_El-Banat","Stadium","Fair_Zone","Abbassia","Abdou_Pasha","El_Geish",
							 "Bab_El_Shaaria","Attaba" };


	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (third_line[i] == second_line[j])
			{
				t = i;
				//tt1 = j;
				break;
			}
	counter += straitline(start, 3, t, 3);
	cout << "Transition Station from line 3 to 2 in station : " << third_line[t] << endl;

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 36; j++)
			if (second_line[i] == first_line[j])
			{
				tt2 = i;
				ttt = j;
				break;
			}
	// print the way ....
	counter += straitline(t, 2, tt2, 2);
	cout << "Transition Station from line 2 to 1 in station : " << second_line[tt2] << endl;
	if (end >= ttt)
		counter += straitline(ttt + 1, 1, end, 1);
	else
		counter += straitline(ttt - 1, 1, end, 1);
	cout << "No. of all stations in the journy : " << counter << endl << endl;
}

void metro_subscriptions()
{
	int n;
	cout << "1) New subscription" << endl;
	cout << "2) confirm subscription" << endl;
	cout << "*************************************************************\n";
	cout << "Your Choice :";
	cin >> n;
	switch (n)
	{
	case 1:
		clrscr();
		subscriptions1();
		break;
	case 2:
		clrscr();
		subscriptions2();
		break;

	default:
		clrscr();
		cout << "Not correct answer " << endl;
		choice();
	}

}
void subscriptions1()
{
	int n1;
	cout << "1) student " << endl;
	cout << "2) emloyee " << endl;
	cout << "3) above 65 " << endl;
	cout << "4) another " << endl;
	cout << "*************************************************************\n";
	cout << "Your Choice :";
	cin >> n1;
	switch (n1)
	{
	case 1:
	{
		clrscr();
		cout << "1) price " << endl;
		cout << "2) code for pay " << endl;
		cout << "*************************************************************\n";
		cout << "Your Choice :";
		int a;
		cin >> a;
		if (a == 1)
		{
			clrscr();
			cout << "1) one line " << endl;
			cout << "2) two lines " << endl;
			cout << "3) three lines " << endl;
			cout << "*************************************************************\n";
			cout << "Your Choice :";
			int a1;
			cin >> a1;
			if (a1 == 1)
			{
				int x;
				clrscr();
				x = numOfstations();

				if (x < 9)
				{
					clrscr();
					cout << "the price is 40 LE" << endl;
					choice();
				}
				else
				{
					clrscr();
					cout << "the price is 60 LE" << endl;
					choice();
				}
			}


			else if (a1 == 2)
			{
				int x;
				clrscr();
				x = numOfstations();

				if (x < 9)
				{
					clrscr();
					cout << "the price is 50 LE" << endl;
					choice();
				}
				else
				{
					clrscr();
					cout << "the price is 60 LE" << endl;
					choice();
				}
			}
			else if (a1 == 3)
			{
				int x;
				clrscr();
				x = numOfstations();
				if (x < 9)
				{
					clrscr();
					cout << "the price is 60 LE" << endl;
					choice();
				}
				else
				{
					clrscr();
					cout << "the price is 60 LE" << endl;
					choice();
				}
			}
			else
			{
				clrscr();
				cout << "Not correct answer" << endl;
				choice();
			}

		}
		else if (a == 2)
		{
			clrscr();
			price_subscription();

		}
		else
		{
			clrscr();
			cout << "Not correct answer " << endl;
			choice();
		}

	} break;

	case 2:
	{
		clrscr();

		cout << "1) price " << endl;
		cout << "2) code for pay " << endl;
		cout << "*************************************************************\n";
		cout << "Your Choice :";
		int a;
		cin >> a;
		if (a == 1)
		{
			clrscr();
			cout << "1) one line " << endl;
			cout << "2) two lines " << endl;
			cout << "3) three lines " << endl;
			cout << "*************************************************************\n";
			cout << "Your Choice :";
			int a1;
			cin >> a1;
			if (a1 == 1)
			{
				int x;
				clrscr();
				x = numOfstations();
				if (x < 9)
				{
					clrscr();
					cout << "the price is 70 LE" << endl;
					choice();
				}
				else
				{
					clrscr();
					cout << "the price is 90 LE" << endl;
					choice();
				}
			}
			else if (a1 == 2)
			{
				int x;
				clrscr();
				x = numOfstations();
				if (x < 9)
				{
					clrscr();
					cout << "the price is 90 LE" << endl;
					choice();
				}
				else
				{
					clrscr();
					cout << "the price is 100 LE" << endl;
					choice();
				}
			}
			else if (a1 == 3)
			{
				int x;
				clrscr();
				x = numOfstations();
				if (x < 9)
				{
					clrscr();
					cout << "the price is 100 LE" << endl;
					choice();
				}
				else
				{
					clrscr();
					cout << "the price is 120 LE" << endl;
					choice();
				}
			}
			else
			{
				clrscr();
				cout << "Not correct answer" << endl;
				choice();
			}

		}
		else if (a == 2)
		{
			clrscr();
			price_subscription();
		}
		else
		{
			clrscr();
			cout << "Not correct answer " << endl;
			choice();
		}

	} break;

	case 3:
	{
		clrscr();
		cout << "1) price " << endl;
		cout << "2) code for pay " << endl;
		cout << "*************************************************************\n";
		cout << "Your Choice :";
		int a;
		cin >> a;
		if (a == 1)
		{
			clrscr();
			cout << "the price is 40 LE" << endl;
			choice();
		}

		else if (a == 2)
		{
			clrscr();
			price_subscription();
		}
		else
		{
			clrscr();
			cout << "Not correct answer" << endl;
			choice();
		}
	} break;


	case 4:
	{
		clrscr();
		cout << "1) price " << endl;
		cout << "2) code for pay " << endl;
		cout << "*************************************************************\n";
		cout << "Your Choice :";
		int a;
		cin >> a;
		if (a == 1)
		{
			clrscr();
			cout << "1) one line " << endl;
			cout << "2) two lines " << endl;
			cout << "3) three lines " << endl;
			cout << "Your Choice : ";
			int a1;
			cin >> a1;
			if (a1 == 1)
			{
				int x;
				clrscr();
				x = numOfstations();
				if (x < 9)
				{
					clrscr();
					cout << "the price is 100 LE" << endl;
					choice();
				}
				else
				{
					clrscr();
					cout << "the price is 120 LE" << endl;
					choice();
				}
			}
			else if (a1 == 2)
			{
				int x;
				clrscr();
				x = numOfstations();
				if (x < 9)
				{
					clrscr();
					cout << "the price is 120 LE" << endl;
					choice();
				}
				else
					clrscr();
				{
					cout << "the price is 130 LE" << endl;
					choice();
				}
			}
			else if (a1 == 3)
			{
				int x;
				clrscr();
				x = numOfstations();
				if (x < 9)
				{
					clrscr();
					cout << "the price is 130 LE" << endl;
					choice();
				}
				else
				{
					clrscr();
					cout << "the price is 150 LE" << endl;
					choice();
				}
			}
			else
			{
				clrscr();
				cout << "Not correct answer" << endl;
				choice();
			}

		}
		else if (a == 2)
		{
			clrscr();
			price_subscription();
		}
		else
		{
			clrscr();
			cout << "Not correct answer " << endl;
			choice();
		}

	} break;

	default:
		clrscr();
		cout << "Not correct answer" << endl;
		choice();
	}




}
void subscriptions2()
{
	int y;
	int x[10];
	cout << "enter your code (number by number)" << endl;

	for (int i = 0; i < 10; i++)
		cin >> x[i];
	clrscr();
	cout << "Done..please choose your nearst station" << endl;
	cout << "1) Al-Shohadda" << endl;
	cout << "2) Sadat" << endl;
	cout << "3) Attaba" << endl;
	cout << "*************************************************************\n";
	cout << "Your Choice :";
	cin >> y;
	if (y == 1 || y == 2 || y == 3)
	{
		clrscr();
		cout << "Go to station number " << y << " to get your card " << endl;
		choice();
	}
	else
	{
		clrscr();
		cout << "Not correct answer" << endl;
		choice();
	}
}
void price_subscription()
{
	srand(time(0));
	cout << "The code is ";
	for (int i = 0; i < 10; i++)
	{
		cout << rand() % 10;
	}
	cout << endl;
	choice();

}
void choice()
{
	cout << "Do you want to return to menu of subscriptions" << endl;
	cout << "1) yes" << endl;
	cout << "2) No" << endl;
	cout << "*************************************************************\n";
	cout << "Your Choice :";
	int c;
	cin >> c;
	switch (c)
	{
	case 1:
		clrscr();
		metro_subscriptions();
		break;
	case 2:
		clrscr();
		menu();
		break;
	default:
		clrscr();
		cout << "Not correct answer " << endl;
		choice();
	}
}
int numOfstations()
{


	try
	{
		cout << "enter the number of stations" << endl;
		int x;
		cin >> x;
		if (x == 0 || x > 74)
			throw (x);
		else
			return x;


	}
	catch (int x)
	{
		cout << "invalid number of stations" << endl;
	}
	numOfstations();
}
void startMenu()
{
	cout << "Please enter number of operation to proceed:" << endl;
	cout << "1) Price of entered destination" << endl;
	cout << "2) Time of entered destination" << endl;
	cout << "*************************************************************\n";
	cout << "Your Choice :";
	int answer;
	cin >> answer;
	clrscr();
	switch (answer)
	{
	case 1: {
		cout << "enter number of stations: ";
		unsigned int numOfStations;
		cin >> numOfStations;
		try {
			calculatePrice(numOfStations);
		}
		catch (int numOfStations) {
			system("cls");
			cout << "Something went wrong, error has been thrown." << endl;
			startMenu();
		}
	};
		  break;

	case 2: {
		cout << "enter number of stations: ";
		unsigned int numOfStations;
		cin >> numOfStations;
		try {
			calculateTime(numOfStations);
		}
		catch (string x) {
			cout << "Something went wrong, error has been thrown. " << endl;

		}
	};
		  break;

	default: {
		cout << "Invalid choice." << endl;
	}
	}

}
void calculatePrice(int numOfStations) {
	if (numOfStations <= 0 || numOfStations > 35) {
		throw (numOfStations);
	}
	else {
		if (numOfStations >= 1 && numOfStations <= 9) {
			cout << "You should pay 5 LE." << endl;
		}
		else if (numOfStations >= 10 && numOfStations <= 16) {
			cout << "You should pay 7 LE." << endl;
		}
		else {
			cout << "You should pay 10 LE." << endl;
		}
	}
}
void calculateTime(int numOfStations) {
	if (numOfStations <= 0 || numOfStations > 35) {
		throw (numOfStations);
	}
	else {
		cout << "Expected time = " << numOfStations * 3.0 << " minutes." << endl;
	}
}
