#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "planet.h"
#include "readValue.h"

using namespace std;

void Input(vector<Planet> &l);
bool Insert(vector<Planet> &l, Planet val, int pos);
void Remove(vector<Planet> &l);
bool Delete(vector<Planet> &l, int pos);
void Display(vector<Planet> &l);
void Sort(vector<Planet> &l);
long LinearSearch(vector<Planet> &l, string planetName);
void nameSearch(vector<Planet> &l);
void menu(vector<Planet> &l);

void Display(vector<Planet> &l)
{
    if (l.empty() == 1)
    {
        cout << "\nList is empty.\n";
    }
    else
    {
        long len = l.size();
        for (long i = 0; i < len; i++)
        {
            l[i].Display();
        }
        cout << endl;
    }
}

void Input(vector<Planet> &l)
{
    bool rv = false;
    do
    {
        Planet p;
        p.Input();
        int position = ReadValue<int>("\nEnter position: ", 0, l.size());
        rv = Insert(l, p, position);
    } while (rv == false);
}

bool Insert(vector<Planet> &l, Planet val, int pos)
{
    bool rv = false;

    if (l.empty())
    {
        l.push_back(val);
        rv = true;
    }
    else if (pos >= 0 && pos <= l.size())
    {
        rv = true;
        Planet end;
        // add room for the value to be stored
        l.push_back(end);
        // shift values to the right to make room
        for (int i = l.size() - 1; i >= pos; i--)
        {
            l[i] = l[i - 1];
        }
        l[pos] = val;
    }
    return rv;
}

bool Delete(vector<Planet> &l, int pos)
{
    bool rv = false;
    if (pos >= 0 and pos < l.size())
    {
        rv = true;
        // shift values to left, overwriting value to be deleted
        for (int i = pos; i < l.size() - 1; i++)
        {
            l[i] = l[i + 1];
        }
        // remove last element in the list
        l.pop_back();
    }
    return rv;
}

void Remove(vector<Planet> &l)
{
    bool rv = false;
    do
    {
        int position = ReadValue<int>("\nEnter position to delete: ", 0, l.size() - 1);
        rv = Delete(l, position);
    } while (rv == false);
}

long LinearSearch(vector<Planet> &l, string planetName)
{
    long pos = -1;
    long len = l.size() - 1;

    string nameChecked;
    nameChecked += toupper(planetName[0]);
    for (int i = 1; i < planetName.length(); i++)
    {
        nameChecked += tolower(planetName[i]);
    };

    for (long i = 0; i <= len && pos == -1; i++)
    {
        if (l[i].name.GetPlanetName() == nameChecked)
        {
            pos = i;
        }
    };
    return pos;
}

void Sort(vector<Planet> &l)
{

    int end = l.size();

    for (int i = 0; i < end; i++)
    {
        for (int j = 0; j < end - 1; j++)
        {
            if (l[j].name.GetPlanetName()[0] > l[j + 1].name.GetPlanetName()[0])
            {
                Planet tmp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = tmp;
            }
            else if (l[j].name.GetPlanetName()[0] == l[j + 1].name.GetPlanetName()[0])
            {
                if (l[j].name.GetPlanetName()[1] > l[j + 1].name.GetPlanetName()[1])
                {
                    Planet tmp = l[j];
                    l[j] = l[j + 1];
                    l[j + 1] = tmp;
                }
                else if (l[j].name.GetPlanetName()[1] == l[j + 1].name.GetPlanetName()[1])
                {

                    if (l[j].name.GetPlanetName()[2] > l[j + 1].name.GetPlanetName()[2])
                    {
                        Planet tmp = l[j];
                        l[j] = l[j + 1];
                        l[j + 1] = tmp;
                    }
                }
            }
        }
    }

    cout << "\n\nPlanets were successfully sorted!\n\n";
};

void nameSearch(vector<Planet> &l)
{
    string name;
    cout << "\nEnter the name of the planet: ";
    cin >> name;
    int pos = LinearSearch(l, name);
    if (pos != -1)
    {
        cout << "\nPlanet's Position: " << pos << endl;
        l[pos].Display();
    }
    else
    {
        cout << "\nPlanet was not found, check spelling. \n";
    };
}

void menu(vector<Planet> &l)
{
    ifstream input;
    input.open("data", ios::in);

    if (input.is_open() == 1)
    {
        string name;
        double mass, diameter;
        while (input.eof() == 0 && input.fail() == 0)
        {
            input >> name >> mass >> diameter;
            if (input.fail() == 0)
            {
                Planet p;
                p.name.SetPlanetName(name);
                p.mass.SetMass(mass, Mass::KGS);
                p.diameter.SetDiameter(diameter, Diameter::Kilometers);
                l.push_back(p);
            }
            else
            {
                if (input.eof() == 0)
                {
                    cerr << "\nError! Cannot read data!\n";
                }
                else
                {
                    cout << "\nInput file was successfully read.\n\n";
                }
            }
        }
        input.close();
    }

    int menuChoice;
    const int ADD = 1, DELETE = 2, FIND = 3, DISPLAY = 4, SORT = 5, QUIT = 6;
    menuChoice = ReadValue<int>("\n--PLANETS--\n1.ADD / 2. REMOVE / 3. FIND / 4. DISPLAY / 5. SORT / 6. QUIT\nSelection: ", 1, 6);
    while (menuChoice != QUIT)
    {
        switch (menuChoice)
        {
        case ADD:
            Input(l);
            break;
        case DELETE:
            Remove(l);
            break;
        case FIND:
            nameSearch(l);
            break;
        case DISPLAY:
            Display(l);
            break;
        case SORT:
            Sort(l);
            break;
        }
        menuChoice = ReadValue<int>("\n--PLANETS--\n1.ADD / 2. REMOVE / 3. FIND / 4. DISPLAY / 5. SORT / 6. QUIT\nSelection: ", 1, 6);
    }

    ofstream output;
    output.open("data", ios::out);

    for (int i = 0; i <= l.size() - 1; i++)
    {
        output << l[i].name.GetPlanetName() << endl;
        output << l[i].mass.GetMass() << endl;
        output << l[i].diameter.GetDiameter() << endl;
    };

    if (output.fail() == 1)
    {
        cerr << "Error writing output file !" << endl;
    };

    output.close();

    cout << "\nOutput file was successfully written.\n";
    cout << "\nGoodbye!\n\n";
};