
class ArtistNode {
public:
	ArtistNode* next;
	string artist;
	ArtistNode() {
		next = NULL;
		artist = "";
	}

};

class ArtistsList {
public:
	ArtistNode* start;
	ArtistNode* last;

	ArtistNode* loc;
	ArtistNode* ploc;
	int length;
	ArtistsList() {
		start = NULL;
		last = NULL;
		loc = NULL;
		ploc = NULL;

		length = 0;
	}

	bool isEmpty() {
		return start == NULL;
	}

	//void Search(string artist) {

	//	ploc = NULL;
	//	loc = start;

	//	while (loc != NULL and loc->artist < artist) {
	//		ploc = loc;
	//		loc = loc->next;
	//	}
	//	if (loc != NULL and loc->artist != artist) {
	//		loc = NULL;
	//	}
	//}

	//void InsertArtist(string artist) {
	//	ArtistNode* newnode = new ArtistNode();
	//	newnode->artist = artist;
	//	newnode->next = NULL;
	//	if (!isEmpty()) {
	//		Search(artist);
	//		if (loc == NULL) {
	//			if (ploc == NULL) {
	//				//insert at front
	//				newnode->next = start;;
	//				start = newnode;
	//			}
	//			else if (ploc->next == NULL) {
	//				//insert at end
	//				last->next = newnode;
	//				last = newnode;
	//			}
	//			else {
	//				//insert in middle
	//				newnode->next = ploc->next;
	//				ploc->next = newnode;
	//			}
	//			length++;
	//		}
	//		else {
	//			//already exists
	//		}
	//	}
	//	else {
	//		start = newnode;
	//		last = newnode;
	//		length++;
	//	}
	//}
	//count the number of occurences

	void InsertWithDuplication(string artist) {
		ArtistNode* newnode = new ArtistNode();
		newnode->artist = artist;
		newnode->next = NULL;
		if (!isEmpty()) {
			last->next = newnode;
			last = newnode;
		}
		else {
			start = newnode;
			last = newnode;
		}
	}

	void print() {
		if (!isEmpty()) {
			ArtistNode* temp = start;
			while (temp != NULL) {
				cout << temp->artist << endl;
				temp = temp->next;
			}
		}
	}
};
