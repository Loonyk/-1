#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

void inFile()
{
    string line;
    list<int> doubleList; //пустой двусвязный список
    ifstream flow("text.txt"); // для чтения из файла
    if(!flow.is_open())
        cout << "Error!File is not open (not found)" <<endl;
    else{
        cout << "File:" << endl;
        while(getline(flow,line)){
            doubleList.push_back(line.length());
            cout << line << endl;
        }
        cout <<"\nList items: ";
        copy(doubleList.begin(), doubleList.end(), ostream_iterator<int>(cout," "));
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Laboratory work" << endl;
    cout << "Task: Working with a double linked list\n" << endl;
    inFile();

    return a.exec();
}
