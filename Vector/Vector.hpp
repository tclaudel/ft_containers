//
// Created by tclaudel on 10/13/20.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
# define FT_CONTAINERS_VECTOR_HPP

# include "iterator.hpp"
# include <cstddef>

namespace ft {
	template<class T, class Alloc = std::allocator <T> >
	class Vector {
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ft::Iterator<T>								iterator;
		typedef ft::Iterator<const T>						const_iterator;
		typedef ft::RevIterator<T>							reverse_iterator;
		typedef ft::RevIterator<const T>					const_reverse_iterator;
		typedef typename ptrdiff_t							size_type;
		typedef typename size_t								difference_type;

		explicit Vector (const allocator_type& alloc = allocator_type()) {
			this->_array = 0;
			this->_size = 0;
			this->_capacity = 0;
		}

		explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
			this->_array = new value_type[n]();
			this->_size = n;
			for (size_type i = 0; i < n; i++;)
				this->_array[i] = val;
			this->_capacity = n;
		}

		template <class InputIterator>
		Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
			
		}
		Vector (const vector& x);
		~Vector(void);
		Vector& operator = (const Vector& other);

		// Iterators:
		iterator 				begin();
		const_iterator			begin() const;
		iterator 				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_iterator			rend() const;

		// Capacity:
		size_type				size() const;
		size_type				max_size() const;
		void					resize(size_type new_size, value_type value = value_type());
		size_type				capacity() const;
		bool					empty() const;
		void					reserve(size_type new_size);

		// Element access:
		reference				operator[](size_type index);
		const_reference			operator[](size_type index) const;
		reference				at(size_type index);
		const_reference			at(size_type index) const;
		reference				front();
		const_reference			front() const;
		reference				back();
		const_reference			back() const;

		// Modifiers:
		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last);
		template <class InputIterator>
		void					assign(size_type new_size, const value_type& value);
		void					push_back(const value_type& value);
		void					pop_back();
		void					insert(iterator position, const value_type& value);
		void					insert(iterator position, size_type count, const value_type& value);
		template <class InputIterator>
		void					insert(iterator position, InputIterator first);
		iterator				erase(iterator first, iterator last);
		iterator				erase(iterator fist, iterator last);
		void					swap(Vector& other);
		void					clear();

	private:
		pointer					_array;
		size_type				_size;
		size_type				_capacity;
		allocator_type			_alloc;
	};
	template <class T, class Alloc>
	bool	operator==(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs);
	template <class T, class Alloc>
	bool	operator!=(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs);
	template <class T, class Alloc>
	bool	operator<=(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs);
	template <class T, class Alloc>
	bool	operator>=(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs);
	template <class T, class Alloc>
	bool	operator<(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs);
	template <class T, class Alloc>
	bool	operator>(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs);

	template <class T, class Alloc>
	void 	swap(Vector<T, Alloc>& left, Vector<T, Alloc>& right);

} // namespace ft
#endif //FT_CONTAINERS_VECTOR_HPP
