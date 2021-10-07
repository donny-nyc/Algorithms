#ifndef CONTAINER_T
#define CONTAINER_T

#include <stdexcept>

template <typename T>
class Container {
	public:
		Container();
		Container(T*, int count);
		Container(const Container&&);
		Container(const Container&);
		auto operator=(Container&&) -> Container&;
		auto operator=(Container const&) -> Container&;
		virtual ~Container();
	public:
		auto find(T) -> T; // return the element, if the container has it
											 // Q: whether multiple copies can exist would
											 // depend on the data structure used
		auto get(int) -> T; // should return element mapped to given index
		auto sort(); // order the container values based on the
								// underlying data structure and sort strategy
};

template <typename T>
Container<T>::Container() {
	throw std::runtime_error("Container() not implemented");
}

template <typename T>
Container<T>::Container(T*, int) {
	throw std::runtime_error("Container(T*, int) not implemented");
}

template <typename T>
Container<T>::Container(const Container&&) {
	throw std::runtime_error("Container(const Container&&) move constructor not implemented");
}

template <typename T>
Container<T>::Container(const Container&) {
	throw std::runtime_error("Container(const Container&) - copy constructor not implemented");	
}

template <typename T>
Container<T>::~Container() = default; // easy way to declare 'default' destructor
/* {
	// don't throw in destructor
	// throw std::runtime_error("~Container - destructor not implemented");
}
*/ 
#endif
