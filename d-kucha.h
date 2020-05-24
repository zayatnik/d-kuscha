#include <iostream>
using namespace std;
#pragma once

class kucha {
protected:
	int* mas;
	int size;
	int heapsize;
public:
	kucha() {
		mas = new int[1];
		size = 1;
		heapsize = 0;
	}

	~kucha() {
		delete[] mas;
		size = 0;
		heapsize = 0;
	}

	int leftchild(int i) {
		int ind = i * 2 + 1;
		if (ind > size - 1)
			return (-1);
		else
			return ind;
	}

	int rightchild(int i) {
		int ind = i * 2 + 2;
		if (ind > size - 1)
			return (-1);
		else
			return ind;
	}

	int parent(int i) {
		if (i == 0)
			return (-1);
		else
			return ((i - 1) / 2);
	}

	int minchild(int i) {
		if ((leftchild(i) >= 0) && (rightchild(i) >= 0)) {
			if (mas[leftchild(i)] <= mas[rightchild(i)])
				return leftchild(i);
			else
				return rightchild(i);
		}
		if ((leftchild(i) >= 0) && (rightchild(i) <= 0))
			return leftchild(i);
		if ((leftchild(i) <= 0) && (rightchild(i) <= 0))
			return (-1);
	}

	void diving(int i) {
		int j1 = i;
		int j2 = minchild(i);
		while ((j2 != - 1) && (mas[j1] > mas[j2]) && (mas[j2] > 0)) {
			swap(mas[j1], mas[j2]);
			j1 = j2;
			j2 = minchild(j1);
		}
	}

	void emersion(int i) {
		int j1 = i;
		int j2 = parent(i);
		while ((j2 != -1) && (mas[j1] < mas[j2])) {
			swap(mas[j1], mas[j2]);
			j1 = j2;
			j2 = parent(j1);
		}
	}

	void insert(int w) {
		if (heapsize == size) {
			int *tmp = new int[size * 2];
			for (int i = 0; i < size; i++) {
				tmp[i] = mas[i];
			}
			delete[] mas;
			mas = tmp;
			size = size * 2;
		}
			heapsize += 1;
			mas[heapsize - 1] = w;
			emersion(heapsize - 1);
	}

	void deletemin() {
		mas[0] = mas[heapsize - 1];
		heapsize -= 1;
		diving(0);
	}

	void decreaseweight(int i, int delta) {
		mas[i] -= delta;
		emersion(i);
	}

	void del(int i) {
		decreaseweight(i, std::numeric_limits<int>::max());
		deletemin();
	}

	void print() {
		for (int i = 0; i < heapsize; i++)
			cout << mas[i] << " ";
	}
};
