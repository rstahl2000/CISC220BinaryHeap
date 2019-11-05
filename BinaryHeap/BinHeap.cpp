/*
 * BinHeap.cpp
 *
 * 	Robert Stahl, Chris Tiso
 */

#include "BinHeap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
BinHeap::BinHeap(string arr[], int len) {
	heaplen = 0;
	arrlen = len;
	heap = new string[arrlen];
	for (int i = 0; i < len; i++) {
		insertHeap(arr[i]);
	}
	printHeap();
}

BinHeap::~BinHeap() {
	delete [] heap;
}

void BinHeap::printHeap() {
	cout << endl;
	for (int i = 0; i < arrlen;i++) {
		cout << i << ", ";
	}
	cout << endl;
	for (int i = 0; i < heaplen;i++) {
		cout << heap[i] << ", ";
	}
	cout << endl;
	}

int BinHeap::findMax(int x, int y) {
	if ((x < heaplen) && (y < heaplen)) {
		if (heap[x] > heap[y]) {
			return(x);
		}
		else {
			return(y);
		}
	}
	else if (x < heaplen) {
		return x;
	}
	else return -1;
}

void BinHeap::insertHeap(string s) {
	heaplen++;
	heap[heaplen-1]=s;
	bubbleUp(heaplen-1);
}

string BinHeap::deleteHeap() {
	string x=heap[0];
	heap[0]=heap[heaplen-1];
	heaplen--;
	bubbleDown(0);
	return x;
}

void BinHeap::bubbleUp(int i) {
	int pHeight=(i-1)/2;
	int test=i;
	string x;
	bool brk=findMax(test,pHeight)==test;
	while(brk){
		x=heap[test];
		heap[test]=heap[pHeight];
		heap[pHeight]=x;
		test=pHeight;
		if(test==0){
			brk=false;
		}
		else{
			pHeight=(test-1)/2;
			brk=findMax(test,pHeight)==test;
		}
	}
}

void BinHeap::bubbleDown(int i) {
	int chMax=findMax(2*i+1,2*i+2);
	int test=i;
	string x;
	bool brk;
	if(chMax==-1){
		brk=false;
	}
	else{
		brk=findMax(test,chMax)==chMax;
	}
	while(brk){
		x=heap[chMax];
		heap[chMax]=heap[test];
		heap[test]=x;
		test=chMax;
		chMax=findMax(2*test+1,2*test+2);
		if(chMax==-1){
			brk=false;
		}
		else{
			brk=findMax(test,chMax)==chMax;
		}
	}
}

string BinHeap::deleteHeap2() {
	string x=heap[0];
	heap[0]=heap[heaplen-1];
	heap[heaplen-1]=x;
	heaplen--;
	bubbleDown(0);
	return x;
}
void BinHeap::deleteAll() {
	int x=heaplen;
	int y=heaplen;
	while(x!=0){
		deleteHeap2();
		x--;
	}
	heaplen=y;
}

