#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "WordSearch.h"
#include "Tries.h"
#include "ArtList.h"
#include "Song.h"
#include "Heap.h"
#include "GenreHash.h"
#include "Parse.h"
using namespace std;


int main() {
	string filu = "lol.csv";
	int op = -1;

	while (op != 0) {

		cout << "Welcome! Please select one of the options: " << endl;
		cout << endl;
		cout << "1.Play Wordsearch!" << endl;
		cout << "2.Search song by name" << endl;
		cout << "3.Number of songs of all artist" << endl;
		cout << "4.Search songs based on genre" << endl;
		cout << "5.Display most popular song" << endl;
		cout << "6.Display the least popular song" << endl;
		cout << "7.Display the shortest song" << endl;
		cout << "8.Display the longest song" << endl;
		cout << "0.To Exit"<<endl;

		cin >> op;

		switch (op) {
		case 1: {
			MainParser p;
			string gen;
			hashTable h;
			cout << "Enter your favourite genre from the ones below: " << endl;
			for (string i : h.genre) {
				cout << i << " ";
			}
			cout << endl;
			cin >> gen;
			cout << "Generating Grid..." << endl;
			
			WordSearch w1;
			w1.GenerateMatrix();
			p.ReadHash("Book1.csv", h);


			string words[4] = { h.getstring(gen),h.getstring(gen),h.getstring(gen),h.getstring(gen) };


			Tries t;
			Tries* root = t.CreateNode();
			cout << "Search the following artists: "<<endl;
			for (string i : words) {
				t.InsertWord(root, i);
				w1.InsertInMatrix(i);
				cout << i << endl;
			}
			w1.PrintMatrix();


			string artist = "";

			while (artist != "x") {
				cout << "Enter artist: ";
				cin >> artist;

				if (t.SearchWord(root, artist)) {
					cout << "FOUND!" << endl;
					break;
				}
				else {
					cout << "NOT FOUND!" << endl;
				}
			}
		}
			  break;

		case 2: {
			MainParser p;
			cout << "Enter song name: " << endl;;
			string song;
			cin.ignore();
			getline(cin, song);

			SongAVLTree sat;
			p.ReadAVL(filu, sat);
			TrackNode* t1;

			t1 = sat.search(sat.root, song);
			if (t1 != NULL) {
				cout << "SONG FOUND!" << endl;
				cout << "Song Details: " << endl;
				cout << t1->song_name + " by " + t1->artist_name + " release in " + t1->release_year << endl;
				cout << "Stats:" << endl;
				cout << "BPM	Danceability	Energy	Duration	Loudness	Speechiness		Popularity" << endl;
				cout << t1->bpm + "	" + t1->danceability + "		" + t1->energy + "      " + t1->duration + "		" + t1->loudness + "		" + t1->speechiness + "			" + t1->popularity << endl;
			}
			else {
				cout << "SONG NOT FOUND!";
			}
			cout << endl;
		}
			  break;
		case 3: {
			MainParser p;
			SongAVLTree s;
			ArtistsList l;

			p.ReadAVL(filu, s);
			MainParser p1;
			p1.ReadList(filu, l);

			s.countArtists(s.root, l.start);
			cout << endl;


		}
			  break;

		case 4: {
			hashTable h;
			MainParser p;
			p.ReadHash(filu, h);
			cout << "Enter genre from the ones given below: " << endl;
			for (string i : h.genre) {
				cout << i << " ";
			}
			cout << endl;
			string genre;
			cin.ignore();
			getline(cin, genre);

			h.print(genre);
			cout << endl;

		}
			  break;

		case 5: {
			//max pop
			Heap h(1994);
			MainParser p;
			p.ReadMaxHeapForPop(filu, h);
			string song = h.returnMax();
			cout << song;
			cout << endl;
		}
			  break;

		case 6: {
			Heap h(1994);
			MainParser p;
			p.ReadMinHeapForPop(filu, h);
			string song = h.returnMax();
			cout << song;
			cout << endl;
		}
			  break;

		case 7: {
			//shortest duration
			Heap h(1994);
			MainParser p;
			p.ReadMinHeapForDur(filu, h);
			string song = h.returnMin();
			cout << song;
			cout << endl;

		}
			  break;

		case 8: {
			Heap h(1994);
			MainParser p;
			p.ReadMaxHeapForDur(filu, h);
			string song = h.returnMin();
			cout << song;
			cout << endl;
		}
			  break;

		case 0:
			break;
			break;
			return 0;

		default: {
			cout << "Invalid option";
		}
			   break;
		}
	}

}


//
//	int s = 1994;
//	SongAVLTree Songs;
//	Heap maxPop(s);
//	Heap minPop(s);
//	Heap maxDur(s);
//	Heap minDur(s);
//	MainParser MinHeapParser;
//	MainParser MaxHeapParser;
//	MainParser AVLTree;
//
//	MaxHeapParser.ReadMaxHeap(filu,maxPop);
//	cout << "Hello" << endl;
//	MaxHeapParser.ReadMaxHeap(filu, maxDur);
//	MinHeapParser.ReadMinHeap(filu, minPop);
//
//	cout << maxPop.returnMax() << " is the most popular song."<<endl;
//	cout << minPop.returnMin() << "is the least popular song." << endl;


	/*AVLTree.ReadAVL(filu,Songs);
	Songs.inOrder(Songs.root);*/




//




	//a.inOrder(a.root);
	//a.inOrder(a.root);
	//MainMenu m1;
	//m1.ShowMenu();
	//string artist = "";
	//string words[] = {"MAHAD"};

	//WordSearch w1;
	//w1.GenerateMatrix();

	//Tries t;
	//int n = sizeof(words) / sizeof(words[0]);
	//Tries* root = t.CreateNode();
	//for (int i = 0; i < n; i++) {
	//	t.InsertWord(root, words[i]);
	//	w1.InsertInMatrix(words[i]);
	//}
	//

	//w1.PrintMatrix();
	//cout << endl;

	//while (artist != "x") {
	//	cout << "Enter artist: ";
	//	cin >> artist;

	//	if (t.SearchWord(root, artist)) {
	//		cout << "found"<<endl;
	//		break;
	//	}
	//	else {
	//		cout << "not found" << endl;
	//	}
	//}









	







	







	





