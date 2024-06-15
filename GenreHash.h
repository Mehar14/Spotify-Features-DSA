
class hashNode {
public:
	hashNode* next;
	string song;
	string artist;
	string gen;

	hashNode() {
		next = NULL;
		artist = "";
		gen = "";
		song = "";
	}
};

class hashTable {
public:
	const int NumberofGenres = 14;
	hashNode** hashtable;

	hashNode* loc;
	hashNode* ploc;

	string genre[14] = { "rock","pop","adult standards","hip hop","metal","wave","mellow","british","disco","dutch","country","classic","electro","folk" };
	int count[14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	hashTable() {
		hashtable = new hashNode * [NumberofGenres];
		loc = NULL;
		ploc = NULL;

		for (int i = 0; i < NumberofGenres; i++) {
			hashtable[i] = NULL;
		}
	}

	int hashFunction(string gen) {
		int i;
		for (i= 0; i < NumberofGenres; i++) {
			if (gen == genre[i]) {
				break;
			}
		}
		return i;
	}

	void Search(string gen, string artist) {
		int pos = hashFunction(gen);

		ploc = NULL;
		loc = hashtable[pos];

		while (loc != NULL and loc->artist < artist) {
			ploc = loc;
			loc = loc->next;
		}
		if (loc != NULL and loc->artist != artist) {
			loc = NULL;
		}
	}

	void InsertSorted(string gen, string artist,string song) {
		Search(gen, artist);
		if (loc == NULL) {
			int pos = hashFunction(gen);
			count[pos] = count[pos] + 1;

			hashNode* newnode = new hashNode();
			newnode->artist = artist;
			newnode->next = NULL;
			newnode->song = song;

			if (hashtable[pos] == NULL) {
				hashtable[pos] = newnode;
			}
			else {
				if (ploc == NULL) {
					//insert at front
					newnode->next = hashtable[pos];
					hashtable[pos] = newnode;
				}
				else if (ploc->next == NULL) {
					ploc->next = newnode;
				}
				else {
					newnode->next = ploc->next;
					ploc->next = newnode;
				}
			}
		}
		else {
			//do nothing
			//node already exists
		}

	}

	void print(string gen) {
		int j = hashFunction(gen);
		hashNode* curr = hashtable[j];
		cout << genre[j] << " [" << count[j] << "] " << ": ";

			while (curr != NULL) {
				if (curr->next == NULL) {
					cout << curr->song;
					break;
				}
				cout << curr->song << "-->";
				curr = curr->next;
			}
			cout << endl;
			cout << endl;
	}

	int gibrandom(int num) {
		return rand() % (count[num] + 1 - 0) + 0;
	}

	string getstring(string gen) {
		int pos = hashFunction(gen);
		int ran = gibrandom(pos);
		loc = hashtable[pos];
		for (int i = 0; i < ran; i++) {
			loc = loc->next;
		}

		return loc->artist;
	}

};
