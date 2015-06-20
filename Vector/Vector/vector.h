#include <memory>
#include "base.h"

using namespace std;

template <typename T, class Alloc = allocator<T>>
class myVector : public Base {
public:
	typedef T value_type;
	typedef Alloc allocator_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef allocator_traits<allocator_type>::point point;
	typedef allocator_traits<allocator_type>::const_point const_point;
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef reverse_iterator<iterator> reverse_iterator;
	typedef reverse_iterator<const_iterator> const_reverse_iterator;
	typedef iterator_traits<iterator>::difference_type difference_type;
	typedef size_t size_type;

	myVector(const allocator_type& alloc = allocator_type()) {
		_allocator = alloc;
		_size = 0;
		_capacity = _allocator.max_size();
		_begin = NULL;
	}

	myVector(size_type n) {
		_begin = _allocator.allocate(n);
		_allocator.construct(_begin);
		_size = n;
		_capacity = _allocator.max_size();
	}
	myVector(size_type n, const value_type& val, const allocator_type& alloc = allocator_type()) {
		_begin = _allocator.allocate(n);
		_allocator.construct(_begin, val);
		_size = n;
		_capacity = _allocator.max_size();
	}

	template<typename InputIterator>
	myVector(InputIterator first, InputIterator last) {
		size_type s = last - first;
		_begin = _allocator.allocate(s);
		value_type *p = _begin;
		while (first != last)
			_allocator.construct(p++, *first++);
		_size = s;
		_capa = _allocator.max_size();
	}

	myVector(const myVector& v) {

	}
	myVector(const size_t &size, const T &value, const Alloc & = Alloc()) {}

	iterator begin() { return _begin; }
	iterator end() { return _begin + _size; }

	size_type size() { return _size; }
	size_type capacity() { return _capacity; }

	void resize(size_type &size) {
		if (size < _capacity)
			return;
		else {
			value_type *_new = _allocator.allocate(size);
			for (unsigned i = 0; i < _size; i++)
				_allocator.construct(_new, *(_begin + i));
			_allocator.destroy(_begin);
			_allocator.deallocate(_begin, _size);
			_begin = _new;
			_size = 
		}
	}
private:
	value_type *_begin;
	Alloc _allocator;
	size_type _capacity;
	size_type _size;
};