class Tries {
public:
	const static int size = 27;
	Tries* children[size];
	bool is_end;

	Tries* CreateNode() {
		Tries* root = new Tries;
		root->is_end = false;


		for (int i = 0; i < root->size; i++) {
			root->children[i] = NULL;
		}

		return root;
	}

	void InsertWord(Tries* root, string word) {
		Tries* loc = root;

		for (int i = 0; i < word.length(); i++) {
			int index = word[i] - 'A';
				if (loc->children[index] == NULL) {
					loc->children[index] = CreateNode();
				}
				loc = loc->children[index];


				
			}
		loc->is_end = true;
	}
		

	bool SearchWord(Tries* root, string word) {
		Tries* loc = root;
		for (int i = 0; i < word.length(); i++) {
			int index = word[i] - 'A';
			if (loc->children[index] == NULL) {
				return false;
			}
			loc = loc->children[index];
		}
		return (loc->is_end);
	}


};