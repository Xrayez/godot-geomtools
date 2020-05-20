#ifndef POLY_TOOLS_H
#define POLY_TOOLS_H

namespace polytools {

template <typename T>
class Instantiable {
public:
	static T* create() {
		return memnew(T);
	}
};

template <typename T>
T* register_class() {
	return T::Instantiable<T>::create();
}

} // namespace polytools

#endif // POLY_TOOLS_H
