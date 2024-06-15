#include "Heap.h"

class TrackNode {
public:
	string song_name;
	string artist_name;
	string genre;
	string release_year;
	string bpm;
	string energy;
	string danceability;
	string loudness;
	string duration;
	string speechiness;
	string popularity;

	int height;
	TrackNode* right;
	TrackNode* left;

	int balancevector;

	TrackNode() {
		
		height = 1;
		balancevector = 0;
		right = NULL;
		left = NULL;
	}
	
	
}; 
class SongAVLTree {
public:
	TrackNode* root = NULL;
	TrackNode* loc = NULL;
	TrackNode* ploc = NULL;

	bool isEmpty() {
		return root == NULL;
	}

	int calculateHeight(TrackNode* TrackNode) {
		if (TrackNode == NULL) {
			return 0;
		}
		else {
			return 1 + max(calculateHeight(TrackNode->left), calculateHeight(TrackNode->right));
		}
	}

	int balanceVector(TrackNode* TrackNode) {
		return calculateHeight(TrackNode->left) - calculateHeight(TrackNode->right);

	}

	TrackNode* rightRotate(TrackNode* curr) {
		TrackNode* x = curr;
		TrackNode* y = curr->left;

		//Rotation
		x->left = y->right;
		y->right = x;

		//update heights
		x->height = calculateHeight(x);
		y->height = calculateHeight(y);

		x->balancevector = balanceVector(x);
		y->balancevector = balanceVector(y);
		return y;
	}

	TrackNode* leftRotate(TrackNode* curr) {
		TrackNode* x = curr;
		TrackNode* y = curr->right;

		//Rotation
		x->right = y->left;
		y->left = x;

		//update heights
		x->height = calculateHeight(x);
		y->height = calculateHeight(y);

		x->balancevector = balanceVector(x);
		y->balancevector = balanceVector(y);
		return y;
	}

	TrackNode* Insert(TrackNode* curr, string song, string artist, string gen, string year, string bpm, string energy, string dance, string loud, string duration, string speech, string pop) {
		//base case
		if (!isEmpty()) {
			if (curr == NULL) {
				TrackNode* nn = new TrackNode;
				nn->song_name = song;
				nn->artist_name = artist;
				nn->genre = gen;
				nn->release_year = year;
				nn->bpm = bpm;
				nn->energy = energy;
				nn->danceability = dance;
				nn->loudness = loud;
				nn->duration = duration;
				nn->speechiness = speech;
				nn->popularity = pop;
				return nn;
			}

			if (song > curr->song_name) {
				curr->right = Insert(curr->right, song, artist, gen, year, bpm, energy, dance, loud, duration, speech, pop);
			}
			else if (song < curr->song_name) {
				curr->left = Insert(curr->left, song,  artist,gen,  year,  bpm, energy, dance, loud, duration, speech, pop);
			}

			curr->height = calculateHeight(curr);
			curr->balancevector = balanceVector(curr);

			if (curr->balancevector > 1) {
				//Right Rotation
				if (curr->left->song_name > song) {
					return rightRotate(curr);

				}
				//Left Right Rotation
				else if (curr->left->song_name < song) {
					curr->left = leftRotate(curr->left);
					return rightRotate(curr);
				}
			}
			else if (curr->balancevector < -1) {
				//Left Rotation
				if (curr->right->song_name < song) {
					return leftRotate(curr);
				}
				//Right Left Rotation
				else if (curr->right->song_name > song) {
					curr->right = rightRotate(curr->right);
					return leftRotate(curr);
				}
			}
			return curr;
		}
		else {
			TrackNode* nn = new TrackNode();
			nn->song_name = song;
			nn->artist_name = artist;
			nn->genre = gen;
			nn->release_year = year;
			nn->bpm = bpm;
			nn->energy = energy;
			nn->danceability = dance;
			nn->loudness = loud;
			nn->duration = duration;
			nn->speechiness = speech;
			nn->popularity = pop;
			root = nn;
			return root;
		}

	}



	TrackNode* search(TrackNode* temp, string song) {
		if (temp == NULL) {
			return NULL;
		}
		else {
			if (song == temp->song_name) {
				return temp;
			}
			else if (song > temp->song_name) {
				return search(temp->right, song);
			}
			else {
				return search(temp->left, song);
			}
		}
	}

	void inOrder(TrackNode* TrackNode) {
		if (TrackNode != NULL) {
			inOrder(TrackNode->left);
			cout << TrackNode->song_name << endl;
			inOrder(TrackNode->right);
		}
	}

	void countArtists(TrackNode* root, ArtistNode* headnode) {
		int count = 0;
		if (root != NULL) {
			ArtistNode* loc = headnode;
			while (loc != NULL) {
				if (root->artist_name == loc->artist) {
					count++;
				}
				loc = loc->next;
			}
			loc = headnode;
			countArtists(root->left, loc);
			cout << root->artist_name << " " << count << endl;
			countArtists(root->right, loc);
		}

	}

};


