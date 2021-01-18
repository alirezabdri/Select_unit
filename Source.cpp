#include<iostream>
#include<fstream>

using namespace std;

struct student
{
	long ID_student;
	char name[30], field[30];
};

struct lessen
{
	int ID_lessen, Prerequisite_lessen, number_of_unit, type_lessen;
	char name_lessen[30];
};

struct nomre
{
	int ID_student, ID_lessen;
	float score;
};

struct SelectUnit
{
	int ID_student, ID_Lessen[20], CountUnit = 0, CountLeseon=0;
};

void Add_student()
{
	student st;
	fstream fp;
	fp.open("d:\\project\\student.txt", ios::app | ios::in);
	if (!fp)
	{
		cout << "Error";
		exit(0);
	}
	for (int i = 0; i<1; i++)
	{
		int a, j = 1;
		cout << "name :  ";
		cin >> st.name;
		cout << "ID :  ";
		while (j<2)
		{
			cin >> a;
			if (999 < a && a < 2000)
				st.ID_student = a;
			else
			{
				cout << "please enter true value (1000 to 1999) :";
				cin >> a;
				if (999 < a && a < 2000)
					st.ID_student = a;
			}
			j++;
		}
		cout << "reshte tahsili :  ";
		cin >> st.field;
		fp.write((char*)&st, sizeof(st));
	}
	fp.seekg(0, ios::beg);
	while (fp.read((char*)&st, sizeof(st)))
	{

		cout <<endl<< st.name<< "  " << st.ID_student<< "  "<< st.field << endl;
	}
}

void Add_lessen()
{
	lessen ls;
	fstream fp;

	fp.open("d:\\project\\lessen.txt", ios::app | ios::in);
	if (!fp)
	{
		cout << "Error";
		exit(0);
	}
	for (int i = 0; i < 1; i++)
	{
		int a, j = 1;
		cout << "name :  ";
		cin >> ls.name_lessen;
		cout << "ID :  ";
		while (j<2)
		{
			cin >> a;
			if (99 < a && a < 200)
				ls.ID_lessen = a;
			else
			{
				cout << "please enter true value (100 to 199) :";
				cin >> a;
				if (99 < a && a < 200)
					ls.ID_lessen = a;
			}
			j++;
		}
		cout << "number of unit :  ";
		cin >> ls.number_of_unit;
		cout << "type_lessen ( 1. practical 2. theory ) :  ";
		cin >> ls.type_lessen;
		cout << "Prerequisite lessen :  ";
		cin >> ls.Prerequisite_lessen;
		fp.write((char*)&ls, sizeof(ls));
	}
	fp.seekg(0, ios::beg);
	while (fp.read((char*)&ls, sizeof(ls)))
	{
		cout <<endl<< ls.name_lessen << "  " << ls.ID_lessen << "  " <<
			ls.number_of_unit << "  " << ls.type_lessen<< "  " << ls.Prerequisite_lessen<< endl;
	}
}

void Register_score()
{
	student st;
	lessen ls;
	nomre sc;
	fstream fp;
	ifstream fp_student, fp_lessen;
	fp.open("d:\\project\\score.txt", ios::app | ios::in);
	fp_student.open("d:\\project\\student.txt");
	fp_lessen.open("d:\\project\\lessen.txt");
	if (!fp && !fp_student && !fp_lessen)
	{
		cout << "Error";
		exit(0);
	}
	for (int i = 0; i < 1; i++)
	{
		int temp;
		cout << "ID_student :  ";
		cin >> temp;
		while (fp_student.read((char*)&st, sizeof(st)))
		{
			if (st.ID_student == temp)
			{
				cout << "name student : " << st.name << endl;
				sc.ID_student = temp;
				break;
			}
			else
				cout << "Record Not Found !" << endl;
		}
		fp_student.close();
		cout << "ID_lessen :  ";
		cin >> temp;
		while (fp_lessen.read((char*)&ls.ID_lessen, sizeof(ls)))
		{
			if (ls.ID_lessen == temp)
			{
				cout << "name lessen : " << ls.name_lessen << endl;
				sc.ID_lessen = temp;
				break;
			}
			else
				cout << "Record Not Found !" << endl;
		}
		fp_lessen.close();
		cout << "Score : ";
		cin >> sc.score;
		fp.write((char*)&sc, sizeof(sc));
	}
	fp.seekg(0, ios::beg);
	while (fp.read((char*)&sc, sizeof(sc)))
	{
		cout << endl<<sc.ID_student << "  " << sc.ID_lessen << "  " << sc.score << endl;
	}
}

void Select_unit()
{
	lessen ls;
	student st;
	nomre sc;
	SelectUnit su;
	fstream fp;
	ifstream fp_score, fp_lessen, fp_Student;
	fp.open("d:\\project\\sel_un.txt", ios::app | ios::in);
	fp_Student.open("d:\\project\\student.txt");
	fp_lessen.open("d:\\project\\lessen.txt");
	if (!fp && !fp_score && !fp_lessen && !fp_Student)
	{
		cout << "Error";
		exit(0);
	}

	fp_lessen.seekg(0, ios::beg);
	while (fp_lessen.read((char*)&ls, sizeof(ls)))
	{
		cout << ls.name_lessen << "  " << ls.ID_lessen << "  " << endl;
	}
	fp_lessen.close();
	char ch;
	int temp, temples;
	cout << "ID_student :  ";
	cin >> temp;
	while (fp_Student.read((char*)&st, sizeof(st)))
	{
		if (st.ID_student == temp)
		{
			su.ID_student = temp;
			break;
		}
		else
			cout << "Record Not Found !" << endl;
	}
	fp_Student.close();
	bool tag = false, activeles = true, activepishniaz = false;
	int i = 0;
	while (tag == false && su.CountUnit <= 20)
	{
		bool  activeles = true, activepishniaz = false;
		cout << "ID_lessen :  ";
		cin >> temples;
		fp_lessen.open("d:\\project\\lessen.txt");
		while (fp_lessen.read((char*)&ls, sizeof(ls)))
		{
			if (ls.ID_lessen == temples)
			{
				fp_score.open("d:\\project\\score.txt");
				while (fp_score.read((char*)&sc, sizeof(sc)))
				{
					if (sc.ID_student == temp&&sc.ID_lessen == temples && sc.score > 10)
					{
						cout << "dars gozaronde shode !" << endl;
						activeles = false;
					}
				}
				fp_score.close();
				fp_score.open("d:\\project\\score.txt");
				while (fp_score.read((char*)&sc, sizeof(sc)) && activeles == true)
				{
					if (temp == sc.ID_student && (ls.Prerequisite_lessen == sc.ID_lessen && sc.score>10) || ls.Prerequisite_lessen == 0)
					{
						cout << "pishniaz reayat shode !" << endl;
						activepishniaz = true;
					}
				}
				fp_score.close();
				if (activeles == true && activepishniaz == true)
				{
					su.ID_Lessen[su.CountLeseon] = ls.ID_lessen; su.CountUnit += ls.number_of_unit;
					su.CountLeseon++;
				}
			}
			else
				cout << "Record Not Found !" << endl;
		}
		fp_lessen.close();
		cout << "Do You Want Add Lessen(y/n)? " << endl;
		cin >> ch;
		if (ch == 'n' || ch == 'N')
		{
			if (su.CountUnit < 10)
				cout << "Shoma bayad bishtar az 10 vahed bardarid"
				<< endl << "Tedad vahedeentekhabi shoma ta be alan : " << su.CountUnit << endl;
			else
			{
				tag = true;
			}
		}
	}
	fp.write((char*)&su, sizeof(su));
	fp.close();
	fp.open("d:\\project\\sel_un.txt", ios::app | ios::in);
	while (fp.read((char*)&su, sizeof(su)))
	{

		if (su.ID_student == temp)
		{
			cout << "ID_STUDENT : " << su.ID_student << endl << endl;
			for (int i = 0; i < su.CountUnit; i++)
			{
				cout << su.ID_Lessen[i] << "  " << su.CountUnit << endl;
			}
		}
	}
	fp.close();
}

int main()
{
	cout << "1. Add a new student info " << endl << "2. Add a new lesson info " << endl << "3. Register a student score " << endl
		<< "4. Select student unit " << endl << "5. Exit " << endl;
	int a;
	cin >> a;
	if (a == 1)
		Add_student();
	if (a == 2)
		Add_lessen();
	if (a == 3)
		Register_score();
	if (a == 4)
		Select_unit();
	if (a == 5)
		exit(0);
	system("pause");
}