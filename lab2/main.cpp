#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct Node  //звено дерева
{
    int x;   //число записывается в дерево
    Node *left, *right;   //адресные поля, указатели на новые звенья
};

void inputTree(Node *&Tree)   //функция обхода
{
    if (Tree != NULL)               //Пока не встретится пустое звено
    {
        inputTree(Tree->left);               //Рекурсивная функция для вывода левого поддерева
        cout << Tree->x << endl;               //Отображаем корень дерева
        inputTree(Tree->right);               //Рекурсивная функци для вывода правого поддерева
    }
}

void addElemTree(int x,Node *&Tree) //В функцию принимается записываемый элемент и указатель на ссылку на структуру.
{
    if (NULL == Tree) //если ничего нет
    {
        Tree = new Node; //выделяем память (как на огороде грядку вскопали почти)
        Tree->left = Tree->right = NULL; //очищаем участки для роста
        Tree->x = x; //записали в звено данные
    }else
        if (NULL == Tree->left)
            addElemTree(x,Tree->left); //если слева участок не занят, создаем там подзвено
        else
            addElemTree(x,Tree->right); //если занят, создаем подзвено справа
}

//void addElemTree(int x, Node *&MyTree)   //функция добавления звена
//{
//    if(NULL == MyTree)     //если дерева нет, то создаем
//    {
//        MyTree = new Node; // выделение памяти под звено дерева
//        MyTree->x = x;  //записываем в звено данные
//        MyTree->left = MyTree->right = NULL;     // левые и правые подзвенья равны нулю
//    }

//    if(x < MyTree->x)  //если новый элемент х больше, чем х из созданного дерева, то уходим влево
//    {
//        if(MyTree->left != NULL)   //рекурсией помещаем элемент на свободный участок
//            addElemTree(x, MyTree->left);
//        else   //если элемент получил свой участок, то
//        {
//            MyTree ->left = new Node;  //выделяем память !левому подзвену!.
//            MyTree->left->left = MyTree->left->right = NULL;  //у левого подзвена свои левое и правое подзвенья, равные 0
//            MyTree->left->x = x;    //Записываем в левое подзвено записываемый элемент
//        }
//    }

//    if(x < MyTree->x)  //тоже самое для правого
//    {
//        if(MyTree->right != NULL)
//            addElemTree(x, MyTree->right);
//        else
//        {
//            MyTree ->right = new Node;
//            MyTree->right->left = MyTree->right->right = NULL;
//            MyTree->right->x = x;
//        }
//    }
//}

void delMemory(Node *&Tree)
{
    if (Tree != NULL)                //Пока не встретится пустое звено
       {
          delMemory(Tree->left);                //Рекурсивная функция прохода по левому поддереву
          delMemory(Tree->right);                //Рекурсивная функци для прохода по правому поддереву
          delete Tree;                 //удаляем конечный элемент дерева
          Tree = NULL;                //обнуляем
       }
}

int heightTree(Node *&Tree)  // высота дерева
{
    if(Tree == NULL)
        return 0;
    return 1 + std::max(heightTree(Tree->left), heightTree(Tree->right));
}

int main()
{
//    int x = 0;
//    Node *MyTree = NULL;

//    x = rand() % 5 + 1;

//    cout << "\nLaboratory work number 2" << endl;

//    for(int i = x; i > 0; i--)
//    {
//        addElemTree(i, MyTree);
//    }
//    inputTree(MyTree);
//    cout << endl;
//    delMemory(Tree);

//    cin.get();

    int x;

    int k = 1;
    Node *MyTree = NULL;
    for (int i = 0; i < 7; i++)
    {
        cout << k << ". Node with element = ";
        cin >> x;
        addElemTree(x, MyTree);
        k++;
    }
    inputTree(MyTree);
    cout << "Tree lists= " <<  heightTree(MyTree);
    return 0;
 }



