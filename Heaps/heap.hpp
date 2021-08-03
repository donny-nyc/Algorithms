class Heap {
	private:
		int *elements;
		int max;
		int size;
	public:
		Heap(int i);
		int getMax();
		int getSize();
		void decrementSize();
		int parent(int i);
		int left(int i);
		int right(int i);
		int get(int i);
		int set(int i, int value);
};

void max_heapify(Heap*, int);
void min_heapify(Heap*, int);
void build_max_heap(Heap*);
void build_min_heap(Heap*);
int* heapsort(Heap*);
