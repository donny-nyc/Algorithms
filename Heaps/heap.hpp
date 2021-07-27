class Heap {
	private:
		int *elements;
		int max;
	public:
		Heap(int i);
		int getMax();
		int parent(int i);
		int left(int i);
		int right(int i);
		int get(int i);
		int set(int i, int value);
};

void max_heapify(Heap, int);
