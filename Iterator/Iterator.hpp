//
// Created by tclaudel on 10/13/20.
//

#ifndef FT_CONTAINERS_ITERATOR_HPP
#define FT_CONTAINERS_ITERATOR_HPP

# include <cstddef>
//# include <iostream>

namespace ft {
	struct		bidirectional_iterator_tag {};
	struct		random_access_iterator_tag {};

	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T				value_type;
		typedef Distance		difference_type;
		typedef Pointer			pointer;
		typedef Reference		reference;
		typedef Category		iterator_category;
	};
//	Advance
	void advance (InputIterator& it, Distance n);
}

#endif //FT_CONTAINERS_ITERATOR_HPP
