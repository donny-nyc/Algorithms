namespace ds {

	template <typename T>
	class ListElement {
		private:
			ListElement *head, *prev, *next;
			T value;
		public:
			ListElement();
			~ListElement();
			void insertAfter(T);
			void insertBefore(T);
			ListElement(T t): value(t) {};
			T getValue() { return value; };
			bool hasPrev() { return prev != nullptr; }
			bool hasNext() { return next != nullptr; }
			ListElement* getNext() { return next; };
			ListElement* getPrevious() { return prev; };
	};

	template <typename U>
	class List {
		private:
			ListElement<U> *head, *tail;
			int count;
		public:
			List();
			~List();
			void push(U);
			U pop();
			void insertAt(int i, U);
			bool empty();
			bool full();
			int getCount();
			ListElement<U>* getHead() { return head; }
	};

  template <typename V>
	class SortStrategy {
		public:
			SortStrategy();
			virtual ~SortStrategy();
			virtual V* sort(V*);
	};

	template <typename W>
	W* sort_list(W&);
	}
