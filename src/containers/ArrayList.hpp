#include <container.hpp>
#include <iostream>
#include <array>

const int DEFAULT_SIZE = 10;

template <typename T>
class ArrayList : public Container<T> {
	private:
		int count;
		std::array<T, DEFAULT_SIZE> values;
		void resize();
		void resize(int);
	public:
		auto get(int) -> T;
		void push_front(T);
		void push_back(T);
		void sort();
		auto find() -> T;
	public:
		auto size() -> int;
	public:
		template <typename U>
		friend auto operator<<(std::ostream os, const ArrayList<U>& self) -> std::ostream&;
	public:
		ArrayList<T>();
};

#include "ArrayList.tpp"
