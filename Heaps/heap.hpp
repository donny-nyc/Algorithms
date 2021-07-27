class Heap {
	private:
		int *elements;
	public:
		Heap(int i);
		int parent(int i);
		int left(int i);
		int right(int i);
		int get(int i);
};
