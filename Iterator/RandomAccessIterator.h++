//
// Created by Thomas Claudel on 10/14/20.
//

#ifndef FT_CONTAINERS_RANDOMACCESSITERATOR_H
#define FT_CONTAINERS_RANDOMACCESSITERATOR_H

namespace ft {
	template <typename T, bool is_const>
	class RandomAccessIterator {
	public:
		typedef T								value_type;
		typedef T								&reference;
		typedef T								*pointer;
		typedef size_t							size_type;
		typedef ptrdiff_t						difference_type;
		typedef random_access_iterator_tag		iterator_category;
		typedef random_access_iterator			self_type;

		RandomAccessIterator(pointer array)
		{
			this->array = array;
		}
		RandomAccessIterator(self_type const &other)
		{
			this->array = other.array
		}
	private:
		pointer		array
	};
}

#endif //FT_CONTAINERS_RANDOMACCESSITERATOR_H
