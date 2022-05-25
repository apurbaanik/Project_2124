/*
    Name: Anik Barua
    Version: 1.0
    Date: 02-04-2022
    Program: rec02
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct Molecular
{
    int carbon;
    int hydrogen;
    vector<string> name;
};

// Prototypes
void openStream(ifstream& reader); // hydrocarbs.txt
size_t findLocation(int carbon, int hydrogen, const vector<Molecular>& molecules);
void insertNew(const string& newMole, int carbon, int hydrogen, vector<Molecular>& molecules);
void fillVector(vector<Molecular>& molecules, ifstream& reader);
void sortVector(vector<Molecular>& molecules);
void print(const Molecular& mole);
void display(const vector<Molecular>& molecules);

// Main
int main()
{
    ifstream reader;
    vector<Molecular> molecules;
    openStream(reader);
    fillVector(molecules, reader);
    sortVector(molecules);
    display(molecules);
    return 0;
}

void openStream(ifstream& reader)
{
    do
    {
        reader.close();
        reader.clear();
        cout << "Filename? ";
        string value;
        cin >> value;
        reader.open(value);
    } while (!reader);
}

size_t findLocation(int carbon, int hydrogen, const vector<Molecular>& molecules)
{
    for (size_t i = 0; i != molecules.size(); ++i)
    {
        if (molecules[i].carbon == carbon && molecules[i].hydrogen == hydrogen)
        {
            return i;
        }
    }
    return molecules.size();
}

void insertNew(const string& newMole, int carbon, int hydrogen, vector<Molecular>& molecules)
{
    size_t position = findLocation(carbon, hydrogen, molecules);
    if (position == molecules.size())
    {
        Molecular molecule;
        molecule.carbon = carbon;
        molecule.hydrogen = hydrogen;
        molecule.name.push_back(newMole);
        molecules.push_back(molecule);
    }
    else
    {
        molecules[position].name.push_back(newMole);
    }
}

void fillVector(vector<Molecular>& molecules, ifstream& reader)
{
    string name;
    int carbon, hydrogen;
    char charCarbon, charHydro;
    while (reader >> name >> charCarbon >> carbon >> charHydro >> hydrogen)
    {
        insertNew(name, carbon, hydrogen, molecules);
    }
}

void print(const Molecular& mole)
{
    cout << "C" << mole.carbon << "H" << mole.hydrogen << " ";
    for (const string& name : mole.name)
    {
        cout << name << " ";
    }
    cout << "\n";
}

void display(const vector<Molecular>& molecules)
{
    for (const Molecular& mole : molecules)
    {
        print(mole);
    }
}

void sortVector(vector<Molecular>& molecules)
{
    for (size_t i = 0; i < molecules.size(); ++i)
    {
        for (size_t j = 0; j < molecules.size() - 1; ++j)
        {
            if (molecules[j].carbon > molecules[j + 1].carbon ||
                (molecules[j].carbon == molecules[j + 1].carbon && molecules[j].hydrogen > molecules[j + 1].hydrogen))
            {
                Molecular temp = molecules[j];
                molecules[j] = molecules[j + 1];
                molecules[j + 1] = temp;
            }
        }
    }
}