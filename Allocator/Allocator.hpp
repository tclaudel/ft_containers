//
// Created by tclaudel on 10/13/20.
//

#ifndef FT_CONTAINERS_ALLOCATOR_HPP
#define FT_CONTAINERS_ALLOCATOR_HPP

#include <limits>
#include <iostream>

namespace ft {
	template <class T>
	class Allocator {
	public:
		// type definitions
		typedef T					value_type;
		typedef T*					pointer;
		typedef const T*			const_pointer;
		typedef T&					reference;
		typedef const				T& const_reference;
		typedef std::size_t			size_type;
		typedef std::ptrdiff_t		difference_type;

		template <class U>
		struct 						rebind {
			typedef Allocator<U> 	other;
		};

		pointer address (reference value) const {
			return &value;
		}
		const_pointer address (const_reference value) const {
			return &value;
		}

		Allocator() throw() {}
		Allocator(const Allocator&) throw() {}
		template <class U>
		Allocator (const Allocator<U>&) throw() {}
		~Allocator() throw() {}

		size_type max_size () const throw() {
			return std::numeric_limits<std::size_t>::max() / sizeof(T);
		}

		pointer allocate (size_type num, const void* = 0) {
			pointer ret = (pointer)(::operator new(num*sizeof(T)));
			return ret;
		}

		void construct (pointer p, const T& value) {
			new((void*)p)T(value);
		}

		void destroy (pointer p) {
			p->~T();
		}

		void deallocate (pointer p, size_type num) {
			(void)num;
			::operator delete((void*)p);
		}
	};

	template <class T1, class T2>
	bool operator== (const Allocator<T1>&,
					 const Allocator<T2>&) throw() {
		return true;
	}
	template <class T1, class T2>
	bool operator!= (const Allocator<T1>&,
					 const Allocator<T2>&) throw() {
		return false;
	}
}
#endif //FT_CONTAINERS_ALLOCATOR_HPP
