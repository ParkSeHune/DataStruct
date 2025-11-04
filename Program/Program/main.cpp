#include "stdafx.h"

template<typename T>
class Graph
{
public:
	Graph() : size(0), capacity(0), count(0), vertex(nullptr), matrix(nullptr) {}
	~Graph();
	void resize();
	void push(T data);
	void edge(int i, int j);
	friend ostream& operator<<(ostream& ostream, const Graph<T>& graph)
	{
		ostream& out = ostream::operator<<(ostream, "Graph: \n");
		out << "Vertices: ";
		for (int i = 0; i < graph.size; i++)
		{
			out << graph.vertex[i] << " ";
		}
		out << "\nAdjacency Matrix:\n";
		for (int i = 0; i < graph.count; i++)
		{
			for (int j = 0; j < graph.count; j++)
			{
				out << graph.matrix[i][j] << " ";
			}
			out << "\n";
		}
		return out;
	}
private:
	int size;       // 현재 그래프에 저장된 정점의 개수
	int capacity;   // vertex 배열의 총 크기 (정점 저장용 메모리 공간)
	int count;      // 인접행렬(matrix)의 크기 (현재 matrix 행/열 개수)

	T* vertex;      // 정점 목록을 저장하는 1차원 배열
	int** matrix;   // 정점 간 연결 상태를 저장하는 2차원 배열 (인접행렬)
};


template<typename T>
Graph<T>::~Graph()
{
	if (vertex) delete[] vertex;

	if (matrix)
	{
		for (int i = 0; i < count; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;
	}
}

template<typename T>
void Graph<T>::resize()
{
	int** newMatrix = new int * [size];

	for (int i = 0; i < size; i++)
	{
		newMatrix[i] = new int[size] {0};
	}

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			newMatrix[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < count; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
	matrix = newMatrix;
	count = size;
}

template<typename T>
void Graph<T>::push(T data)
{
	if (capacity == 0)
	{
		capacity = 1;
		vertex = new T[capacity];
	}
	else if (size == capacity)
	{
		capacity *= 2;
		T* newVertex = new T[capacity];
		for (int i = 0; i < size; i++)
			newVertex[i] = vertex[i];
		delete[] vertex;
		vertex = newVertex;
	}

	vertex[size] = data;
	size++;

	resize();
}


template<typename T>
void Graph<T>::edge(int i, int j)
{
	if (matrix == nullptr)
	{
		count = size;
		matrix = new int* [count];
		for (int k = 0; k < count; k++)
		{
			matrix[k] = new int[count];
		}
		for (int m = 0; m < count; m++)
		{
			for (int n = 0; n < count; n++)
			{	
				matrix[m][n] = 0;
			}
		}
	}
	matrix[i][j] = 1;
}

int main()
{
	Graph<int> graph;
	return 0;
}
