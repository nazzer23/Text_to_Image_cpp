#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "EasyBMP.hpp"

using namespace std;

void encode(string message);
string* chunk_split(string str, int chunk);

int main()
{
	encode("I am never coding in C++ again.");
}

void encode(string message) {
	string* arr = chunk_split(message, 3);
	float arrsize = ((float)message.length() / (float)3);
	
	int** rgb = new int* [arrsize];
	for (int i = 0; i < arrsize; i++) {
		rgb[i] = new int[3];
	}

	for (int i = 0; i < arrsize; i++) {
		int count = 0;
		for (int a = 0; a < 3; a++) {
			count++;
			int data = 0;
			cout << arr[i].length() << "\n";
			if (arr[i].length() >= count) {
				data = arr[i][a];
				cout << data << "\n";
			}
			else {
				data = 0;
			}
			if (count == 1) {
				rgb[i][0] = data;
			}
			if (count == 2) {
				rgb[i][1] = data;
			}
			if (count == 3) {
				rgb[i][2] = data;
			}
		}
	}

	EasyBMP::RGBColor black(0, 0, 0);
	EasyBMP::Image img(ceil(arrsize), 1, "sample.bmp", black);

	for (int i = 0; i < ceil(arrsize); i++) {
		img.SetPixel(i,0, EasyBMP::RGBColor(rgb[i][0], rgb[i][1], rgb[i][2]));
	}
	img.Write();
}
string* chunk_split(string str, int chunk) {
	float temp = ((float) str.length() / (float)chunk);
	float arraySize = ceil(temp);
	cout << arraySize << "\n";
	string* chunks = new string[arraySize];

	for (int i = 0; i < arraySize; i++) {
		chunks[i] = str.substr(i * chunk, chunk);
		cout << i << " - " << chunks[i] << "\n";
	}

	return chunks;
}
