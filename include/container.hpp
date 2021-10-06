template <typename T>
class Container {
	public:
		auto get(int) -> T; // should return element mapped to given index
		auto sort(); // order the container values based on the
								// underlying data structure and sort strategy
};
