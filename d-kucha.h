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
		mas[0] = 0;
	}

	~kucha() {
		delete[] mas;
		size = 0;
		heapsize = 0;
	}

	int leftchild(int i) {
		int ind = i * 2 + 1;
		return ind;
	}

	int rightchild(int i) {
		int ind = i * 2 + 2;
		return ind;
	}

	int parent(int i) {
		int ind = (i - 1) / 2;
		return ind;
	}

	int minchild(int i) {
		if (mas[leftchild(i)] <= mas[rightchild(i)])
			return (i * 2 + 1);
		else
			return (i * 2 + 2);
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
			int *tmp = new int[size + 1];
			for (int i = 0; i < size; i++) {
				tmp[i] = mas[i];
			}
			delete[] mas;
			mas = tmp;
			size += 1;
		}
			heapsize += 1;
			mas[heapsize - 1] = w;
			emersion(heapsize - 1);
	}

	void deletemin() {
		mas[0] = mas[heapsize - 1];
		mas[heapsize - 1] = 0;
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

	void makeheap(kucha w) {
		for (int i = w.heapsize - 1; i >= 0; i--)
			diving(i);
	}

	void heapsort(kucha w){
		makeheap(w);
		for (int i = 0; i < w.size - 1; i++) {
			swap(w.mas[0], w.mas[w.heapsize - 1]);
			w.heapsize -= 1;
			diving(0);
		}
	}

	void print() {
		for (int i = 0; i < size; i++)
			cout << mas[i] << " ";
	}
};
