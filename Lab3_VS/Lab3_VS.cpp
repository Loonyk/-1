////#include "stdafx.h"
//#include <iostream>
//using namespace std;
//const int n = 5;
//int i, j;
//bool* visited = new bool[n];
////матрица смежности графа
//int graph[n][n] =
//{
//{0, 0, 1, 0, 1},
//{0, 0, 1, 1, 1},
//{1, 1, 0, 0, 0},
//{0, 1, 0, 0, 1},
//{1, 1, 0, 1, 0}
//};
////поиск в глубину
//void DFS(int st)
//{
//	int r;
//	cout << st + 1 << " ";
//	visited[st] = true;
//	for (r = 0; r <= n; r++)
//		if ((graph[st][r] != 0) && (!visited[r]))
//			DFS(r);
//}
////главная функция
//void main()
//{
//	setlocale(LC_ALL, "Rus");
//	int start;
//	cout << "Матрица смежности графа: " << endl;
//	for (i = 0; i < n; i++)
//	{
//		visited[i] = false;
//		for (j = 0; j < n; j++)
//			cout << " " << graph[i][j];
//		cout << endl;
//	}
//	cout << "Стартовая вершина >> "; 
//	cin >> start;
//	//массив посещенных вершин
//	bool* vis = new bool[n];
//	cout << "Порядок обхода: ";
//	DFS(start - 1);
//	delete[]visited;
//	system("pause>>void");
//}

//#include <iostream>
//#include <conio.h>
//#include <fstream>
//#include <iomanip>
//using namespace std;
//int** graph; //матрица смежности
//int* ways; // путь
//bool* include; //включена ли точка в путь
//int s, f, iskomaya, i, j, N, start, finish; // s - точка, из которой делается шаг, f - конечная точка, iskomaya - номер и скомой точки маршрута, N - количество вершин в графе, start и finish -начальная и конечная точки
//void poisk(int s, int f, int iskomaya);
//void main() {
//	setlocale(LC_ALL, "Russian");
//	cout << "Введите количество элементов массива N="; cin >> N; cout << endl;
//	graph = new int* [N];
//	for (int i = 0; i < N; i++)
//		graph[i] = new int[N];
//	cout << "Введите элементы массива: 1-если вершины смежны, 0 - если вершины не смежны"; cout << endl;
//	for (i = 0; i < N; i++)
//		for (j = 0; j < N; j++) cin >> graph[i][j];
//	for (i = 0; i < N; i++) {
//		for (j = 0; j < N; j++) cout << setw(4) << graph[i][j] << " "; cout << endl;
//	}
//
//	ways = new int[N];
//	for (i = 0; i < N; i++) {
//		ways[i] = 0;
//	}
//	include = new bool[(bool)N];
//	for (i = 0; i < N; i++) {
//		include[i] = 0;
//	}
//	cout << "Введите первую вершину поиска(от которой будем искать)"; cin >> start; cout << endl;
//	if (start == N || start > N) {
//		cout << "Введите первую вершину поиска(от которой будем искать)";
//		cin >> start;
//	}
//
//	cout << "Введите вторую вершину поиска(путь до которой нужно найти)"; cin >> finish; cout << endl;
//	if (finish == 0 || finish > N) {
//		cout << "Введите вторую вершину поиска(путь до которой нужно найти)";
//		cin >> finish;
//	}
//	ways[0] = start;
//	include[start] = true;
//	poisk(start, finish, 1);
//
//
//
//}
//
//void poisk(int s, int f, int iskomaya) {
//	int tek; // точка, в которую делается шаг
//	if (s == f) {
//		for (i = 0; i < iskomaya; i++) {
//			cout << ways[i] << " ";
//			//cout<<endl;
//		}
//	}
//	else
//		for (tek = 0; tek < N; tek++) {
//			if ((graph[s][tek] == 1 || graph[tek][s] == 1) && (!include[tek])) {
//				ways[iskomaya] = tek;
//				include[tek] = true;
//				poisk(tek, f, iskomaya + 2);
//				include[tek] = false;
//				ways[iskomaya] = 0;
//			}
//		}
//	//cout<<ways[i]<<" "; cout<<endl;
//
//}
#include <Windows.h>
#include <iostream>
using namespace std;
const int V = 6;
//алгоритм Дейкстры
void Dijkstra(int GR[V][V], int st)
{
	int distance[V], count, index, i, u, m = st + 1;
	bool visited[V];
	for (i = 0; i < V; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0;
	for (count = 0; count < V - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i < V; i++)
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; index = i;
			}
		u = index;
		visited[u] = true;
		for (i = 0; i < V; i++)
			if (!visited[i] && GR[u][i] && distance[u] != INT_MAX &&
				distance[u] + GR[u][i] < distance[i])
				distance[i] = distance[u] + GR[u][i];
	}
	cout << "Стоимость пути из начальной вершины до остальных:\t\n";
	for (i = 0; i < V; i++) 
		if (distance[i] != INT_MAX) {
			cout << m << " > " << i + 1 << " = " << distance[i] << endl;
			/*cout << "Удовлетворяющие условию пути\n";
			if (distance[i] <= 100)
				cout << m << " > " << i + 1 << " = " << distance[i] << endl;*/
		}
		else cout << m << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
	cout << "Удовлетворяющие условию пути:\n";
	for (i = 0; i < V; i++) {
		if (distance[i] <= 100)
			cout << m << " > " << i + 1 << " = " << distance[i] << endl;
	}
	
}
//главная функция
void main()
{
	setlocale(LC_ALL, "Rus");
	

	int start, GR[V][V] = {
	{0, 70, 0, 80, 60},
	{70, 0, 90, 70, 0},
	{0, 90, 0, 65, 80},
	{80, 70, 65, 0, 70},
	{60, 0, 80, 70, 0} };
	while (true)
	{
		cout << "Начальная вершина >> "; cin >> start;
		Dijkstra(GR, start - 1);
		system("pause>>void");
	}
}