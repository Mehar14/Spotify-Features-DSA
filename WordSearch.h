
using namespace std;

class invoke_srand {
public:
	invoke_srand()
	{
		srand(time(0));
	}
};
static invoke_srand do_invoke_srand;

class WordSearch {
public:
	const int static size = 25;
	char word[size][size];
	char occupy[size][size];

	string dirs[8] = { "north","south","east","west","ne","nw","se","sw" };

	void GenerateMatrix() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				int letter = rand() % (90 + 1 - 65) + 65;
				word[i][j] = letter;
				occupy[i][j] = 0;
			}
		}
	}

	string ChooseDir() {
		int choice = rand() % 8;
		return dirs[choice];
	}

	void InsertInMatrix(string sen) {

		int posx = rand() % size;
		int posy = rand() % size;
		string dir = ChooseDir();
		bool oke = false;

		//EAST
		if (dir == "east") {
			while (oke == false) {
				posx = rand() % size;
				posy = rand() % size;

				for (int i = 0; i < sen.length(); i++) {
					int checkx = posx + i;
					if (checkx <= (size - 1)) {
						if (occupy[posy][checkx] == sen[i]) {
							oke = true;
						}
						else {
							oke = false;
							break;
						}
					}
					else {
						oke = false;
						break;
					}
				}
			}
			if (oke) {
				for (int i = 0; i < sen.length(); i++) {
					word[posy][posx + i] = sen[i];
					occupy[posy][posx + i] = sen[i];
				}
			}
		}

		//NORTH
		else if (dir == "north") {
			while (oke == false) {
				posx = rand() % size;
				posy = rand() % size;

				for (int i = 0; i < sen.length(); i++) {
					int checky = posy - i;
					if (checky <= (size - 1) && checky >= 0) {
						if (occupy[checky][posx] == sen[i]) {
							oke = true;
						}
						else {
							oke = false;
							break;
						}
					}
					else {
						oke = false;
						break;
					}
				}
			}
			if (oke) {
				for (int i = 0; i < sen.length(); i++) {
					word[posy - i][posx] = sen[i];
					occupy[posy - i][posx] = sen[i];
				}
			}
		}

		//WEST
		else if (dir == "west") {
			while (oke == false) {
				posx = rand() % size;
				posy = rand() % size;

				for (int i = 0; i < sen.length(); i++) {
					int checkx = posx - i;
					if (checkx <= (size - 1) && checkx >= 0) {
						if (occupy[posy][checkx] == sen[i]) {
							oke = true;
						}
						else {
							oke = false;
							break;
						}
					}
					else {
						oke = false;
						break;
					}
				}
			}
			if (oke) {
				for (int i = 0; i < sen.length(); i++) {
					word[posy][posx - i] = sen[i];
					occupy[posy][posx - i] = sen[i];
				}
			}
		}

		//SOUTH
		else if (dir == "south") {
			while (oke == false) {
				posx = rand() % size;
				posy = rand() % size;

				for (int i = 0; i < sen.length(); i++) {
					int checky = posy + i;
					if (checky <= (size - 1) && checky >= 0) {
						if (occupy[checky][posx] == sen[i]) {
							oke = true;
						}
						else {
							oke = false;
							break;
						}
					}
					else {
						oke = false;
						break;
					}
				}
			}
			if (oke) {
				for (int i = 0; i < sen.length(); i++) {
					word[posy + i][posx] = sen[i];
					occupy[posy + i][posx] = sen[i];
				}
			}
		}

		//NORTHEAST
		else if (dir == "ne") {
			while (oke == false) {
				posx = rand() % size;
				posy = rand() % size;

				for (int i = 0; i < sen.length(); i++) {
					int checkx = posx + i;
					int checky = posy - i;
					if (checkx <= (size - 1) && checkx >= 0) {
						if (checky <= (size - 1) && checky >= 0) {
							if (occupy[checky][checkx] == sen[i]) {
								oke = true;
							}
							else {
								oke = false;
								break;
							}
						}
						else {
							oke = false;
							break;
						}
					}
					else {
						oke = false;
						break;
					}
				}
			}
			if (oke) {
				for (int i = 0; i < sen.length(); i++) {
					word[posy - i][posx + i] = sen[i];
					occupy[posy - i][posx + i] = sen[i];
				}
			}
		}

		//NORTHWEST
		else if (dir == "nw") {
			while (oke == false) {
				posx = rand() % size;
				posy = rand() % size;

				for (int i = 0; i < sen.length(); i++) {
					int checkx = posx - i;
					int checky = posy - i;
					if (checkx <= (size - 1) && checkx >= 0) {
						if (checky <= (size - 1) && checky >= 0) {
							if (occupy[checky][checkx] == sen[i]) {
								oke = true;
							}
							else {
								oke = false;
								break;
							}
						}
						else {
							oke = false;
							break;
						}
					}
					else {
						oke = false;
						break;
					}
				}
			}
			if (oke) {
				for (int i = 0; i < sen.length(); i++) {
					word[posy - i][posx - i] = sen[i];
					occupy[posy - i][posx - i] = sen[i];
				}
			}
		}

		//SOUTHEAST
		else if (dir == "se") {
			while (oke == false) {
				posx = rand() % size;
				posy = rand() % size;

				for (int i = 0; i < sen.length(); i++) {
					int checkx = posx + i;
					int checky = posy + i;
					if (checkx <= (size - 1) && checkx >= 0) {
						if (checky <= (size - 1) && checky >= 0) {
							if (occupy[checky][checkx] == sen[i]) {
								oke = true;
							}
							else {
								oke = false;
								break;
							}
						}
						else {
							oke = false;
							break;
						}
					}
					else {
						oke = false;
						break;
					}
				}
			}
			if (oke) {
				for (int i = 0; i < sen.length(); i++) {
					word[posy + i][posx + i] = sen[i];
					occupy[posy + i][posx + i] = sen[i];
				}
			}
		}

		//SOUTHWEST
		else if (dir == "sw") {
			while (oke == false) {
				posx = rand() % size;
				posy = rand() % size;

				for (int i = 0; i < sen.length(); i++) {
					int checkx = posx - i;
					int checky = posy + i;
					if (checkx <= (size - 1) && checkx >= 0) {
						if (checky <= (size - 1) && checky >= 0) {
							if (occupy[checky][checkx] == sen[i]) {
								oke = true;
							}
							else {
								oke = false;
								break;
							}
						}
						else {
							oke = false;
							break;
						}
					}
					else {
						oke = false;
						break;
					}
				}
			}
			if (oke) {
				for (int i = 0; i < sen.length(); i++) {
					word[posy + i][posx - i] = sen[i];
					occupy[posy + i][posx - i] = sen[i];
				}
			}

		}
	}


	void PrintMatrix() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << word[i][j] << " ";
			}
			cout << endl;
		}
	}

};


















