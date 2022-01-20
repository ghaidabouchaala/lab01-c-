#pragma once
#include <string>

using namespace std; 

namespace ssuds {
	/// @brief The ArrayList class is a collection that is used to store different types of data. 
	/// It is a flexible list that can be resized dynamically. 
	class ArrayList {
	protected:
		/// @brief the current size of the array
		unsigned int mSize;
		/// @brief an array of strings
		string* mData;
	public:
		/// @brief Default constructor -- calls the initialize method
		ArrayList();
		/// @brief  The destructor -- free up any memory the ArrayList has allocated
		~ArrayList();
		/// @brief append a new value to the end of the array
		/// @param new_value the value to be inserted
		void append(string new_value);
		/// @brief getter for mSize
		/// @return the array size
		int size();
		/// @brief list all array elements
		void list();
		/// @brief insert a new element in the array
		/// @param new_value the value to be inserted
		/// @param index position of where to insert the element
		void insert(string new_value, int index);
		/// @brief reset the ArrayList back to its default state
		void clear();
		/// @brief get the value of an element in the array
		/// @param index element position
		/// @return the string at the given index
		string get(int index);
		/// @brief find an element in the array
		/// @param value the searched for string 
		/// @param start_pos starting index to search from
		/// @return  the index of the first occurrence after the start_pos
		int find(string value, int start_pos=0);
		/// @brief remove one element from the array
		/// @param index the position of the element to remove
		void remove(int index);
		/// @brief remove all occurrences of an element
		/// @param value the value of the element to remove 
		/// @return the number of instances removed
		int remove_all(string value);

	};
}