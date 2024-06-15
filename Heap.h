#pragma once

class PopNode {
public:
    int duration;
    int pop;
    string song;
};

class Heap {
public:
    PopNode** arr;
    int max_size;
    int curr_size = 0;

    Heap(int size) {
        max_size = size;
        arr = new PopNode * [size];
    }

    bool isFull() {
        return curr_size == max_size;
    }

    int parent(int i) {
        return ((i - 1) / 2);
    }

    void swap(PopNode* a, PopNode* b) {
        PopNode temp = *a;
        *a = *b;
        *b = temp;
    }
    //Creating max heap based on Popularity
    void InsertMaxPopularityHeap(PopNode* node) {
        if (!isFull()) {
            //increase the curr size of heap
            curr_size++;
            int i = curr_size - 1;

            arr[i] = node;

            //check for the max heap
            while (i != 0 and arr[parent(i)]->pop < arr[i]->pop) {
                //swap function
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }
        else {
            //Heap is full
            return;
        }
    }
    //creating max Heap based on Duration
    void InsertMaxDurationHeap(PopNode* node) {
        if (!isFull()) {
            //increase the curr size of heap
            curr_size++;
            int i = curr_size - 1;

            arr[i] = node;

            //check for the max heap
            while (i != 0 and arr[parent(i)]->duration < arr[i]->duration) {
                //swap function
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }
        else {
            //Heap is full
            return;
        }
    }
    //Creating Min Heap based on Popularity
    void InsertMinPopularityHeap(PopNode* node) {
        if (!isFull()) {
            //increase the curr size of heap
            curr_size++;
            int i = curr_size - 1;

            arr[i] = node;

            //check for the max heap
            while (i != 0 and arr[parent(i)]->pop > arr[i]->pop) {
                //swap function
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }
        else {
            //Heap is full
            return;
        }
    }
    //Creating min heap based on duration
    void InsertMinDurationHeap(PopNode* node) {
        if (!isFull()) {
            //increase the curr size of heap
            curr_size++;
            int i = curr_size - 1;

            arr[i] = node;

            //check for the max heap
            while (i != 0 and arr[parent(i)]->duration > arr[i]->duration) {
                //swap function
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }
        else {
            //Heap is full
            return;
        }
    }

    void PrintHeap() {
        for (int t = 0; t < max_size; t++) {
            cout << arr[t]->song << " ";
        }
        cout << endl;
    }

    string returnMax() {
        return arr[0]->song;
  
    }
    string returnMin() {
        return arr[0]->song;
    }

};




