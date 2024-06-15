class MainParser {
public:
	string record, cell;
	fstream file;
	string temp[11];
	int i = 0;

	void ReadHash(string filename,hashTable& h) {
		file.open(filename, ios::in);
		if (file.is_open()) {
			while (getline(file, record)) {
				stringstream indiv(record);
				while (getline(indiv, cell, ';')) {
					temp[i] = cell;
					i++;
				}
				h.InsertSorted(temp[2],temp[1],temp[0]);
				i = 0;
			}
		}

		else {
			cout << "NO FILE!" << endl;
		}
	}

	void ReadAVL(string filename, SongAVLTree& a) {
		file.open(filename, ios::in);
		if (file.is_open()) {
			while (getline(file, record)) {
				stringstream indiv(record);
				while (getline(indiv, cell, ';')) {
					temp[i] = cell;
					i++;
				}
				a.Insert(a.root, temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], temp[9], temp[10]);
				i = 0;
			}
		}

		else {
			cout << "NO FILE!" << endl;
		}
	}

	void ReadList(string filename, ArtistsList& art) {
		file.open(filename, ios::in);
		if (file.is_open()) {
			while (getline(file, record)) {
				stringstream indiv(record);
				while (getline(indiv, cell, ';')) {
					temp[i] = cell;
					i++;
				}
				art.InsertWithDuplication(temp[1]);
				i = 0;
			}
		}

		else {
			cout << "NO FILE!" << endl;
		}
	}

	void ReadMaxHeapForPop(string filename, Heap& max) {
		file.open(filename, ios::in);
		if (file.is_open()) {
			while (getline(file, record)) {
				stringstream indiv(record);
				while (getline(indiv, cell, ';')) {
					temp[i] = cell;
					i++;
				}
				PopNode* p1 = new PopNode();
				p1->duration = stoi(temp[8]);
				p1->pop = stoi(temp[10]);
				p1->song = temp[0];
				max.InsertMaxPopularityHeap(p1);
				i = 0;
			}
		}

		else {
			cout << "NO FILE!" << endl;
		}
	}
	void ReadMinHeapForPop(string filename, Heap& max) {
		file.open(filename, ios::in);
		if (file.is_open()) {
			while (getline(file, record)) {
				stringstream indiv(record);
				while (getline(indiv, cell, ';')) {
					temp[i] = cell;
					i++;
				}
				PopNode* p1 = new PopNode();
				p1->duration = stoi(temp[8]);
				p1->pop = stoi(temp[10]);
				p1->song = temp[0];
				max.InsertMinPopularityHeap(p1);
				i = 0;
			}
		}

		else {
			cout << "NO FILE!" << endl;
		}
	}

	void ReadMinHeapForDur(string filename, Heap& min) {
		file.open(filename, ios::in);
		if (file.is_open()) {
			while (getline(file, record)) {
				stringstream indiv(record);
				while (getline(indiv, cell, ';')) {
					temp[i] = cell;
					i++;
				}
				PopNode* p1 = new PopNode();
				p1->duration = stoi(temp[8]);
				p1->pop = stoi(temp[10]);
				p1->song = temp[0];
				min.InsertMinDurationHeap(p1);
				i = 0;
			}
		}

		else {
			cout << "NO FILE!" << endl;
		}
	}
	void ReadMaxHeapForDur(string filename, Heap& min) {
		file.open(filename, ios::in);
		if (file.is_open()) {
			while (getline(file, record)) {
				stringstream indiv(record);
				while (getline(indiv, cell, ';')) {
					temp[i] = cell;
					i++;
				}
				PopNode* p1 = new PopNode();
				p1->duration = stoi(temp[8]);
				p1->pop = stoi(temp[10]);
				p1->song = temp[0];
				min.InsertMaxDurationHeap(p1);
				i = 0;
			}
		}

		else {
			cout << "NO FILE!" << endl;
		}
	}

};
