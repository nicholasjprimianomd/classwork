/**
 *
 * CISC 2200: Data Structures<br/>
 * Project 2: Extending the Bag ADT<br/>
 * 
 * <p>This program tests the <code>VectorBag</code> class.  It is a
 * modification of the program given in Section&nbsp;3.2 of the text,
 * which tests the <code>ArrayBag</code> class.</p>
 *
 * <p>In addition to testing the operations that VectorBag implements
 * from the abstract BagInterface class, it tests the set-like
 * operations of union, intersection, and difference.</p>
 *
 * <p>(Based on Exercises&nbsp;1.6-1.8, along with Programming
 * Problem&nbsp;3.5.)</p>
 *
 * @author Nicholas Primiano
 * @date 12 February 2014
 * @file VectorBag.cpp
 *
 **********************************************************************/

#include "VectorBag.h"

/**
 * <p>Creates a new bag that combines the contents of this bag
 * and a second given bag without affecting the origin two bag.</p> 
 *
 * <p>Note that we can't call the operation "<code>union</code>",
 * since"<code>union</code>" is a reserve word.</p>
 *
 * @param first - A given bag
 * @param second - Another given bag
 * @return A bag that is the union of the two bags
 */
template <class ItemType>
VectorBag<ItemType> operator+(const VectorBag<ItemType>& first, 
			      const VectorBag<ItemType>& second)
{
    std::vector<ItemType> firstVector = first.toVector();
    std::vector<ItemType> secondVector = second.toVector();
    for (int i = 0; i < secondVector.size(); i++) {
	firstVector.push_back(secondVector[i]);
    } 
    return firstVector;
}  

/**
 * <p>Creates a new bag of objects that would be left in the bag 
 * after removing thoes that also occur in a second given bag 
 * without affecting the origional two bags.
 *
 * @param first - A given bag
 * @param second - Another given bag
 * @return A bag that is the difference of the two bags
 */
template <class ItemType>
VectorBag<ItemType> operator-(const VectorBag<ItemType>& first, 
			      const VectorBag<ItemType>& second)
{
    VectorBag<ItemType> firstVector = first.toVector();
    std::vector<ItemType> secondVector = second.toVector();
    VectorBag<ItemType> diff(first);
    for (int i = 0; i < secondVector.size(); i++){
	diff.remove(secondVector[i]);
    }
    return diff;
}

/**
 * Creates a new bag that contains thoes objects that occur in
 * this bag and a second given bag without affecting the origional 
 * two bags.
 *
 * @param first - A given bag
 * @param second - Another given bag
 * @return A bag that is the union of the two bags
 */
template <class ItemType>
VectorBag<ItemType> operator*(const VectorBag<ItemType>& first, 
			      const VectorBag<ItemType>& second)
{
    return first - (first - second);
}

/**
 * Sees whether this bag is empty.
 *
 * @return True if the bag is empty, or false if not.
 */
template <class ItemType>
bool VectorBag<ItemType>::isEmpty() const
{
    return data.size() == 0;
}

/**
 * Adds a new entry to this bag.
 *
 * @post If successful, item is stored in the bag and
 * the count of items in the bag has increased by 1.
 *
 * @param item The object to be added as a new entry.
 * @return True if addition was successful, or false if not.
 */
template <class ItemType>
bool VectorBag<ItemType>::add(ItemType const &item)
{
    data.push_back(item);
    return true;
}

/**
 * Gets the current number of entries in this bag.
 *
 * @return The integer number of entries currently in the bag.
 */
template<class ItemType>
int VectorBag<ItemType>::getCurrentSize() const {
    return data.size(); 
}

/**
 * Empties and then fills a given vector with all entries
 * that are in this bag.
 *
 * @return A vector containing all the entries in the bag.
 */
template<class ItemType>
std::vector<ItemType> VectorBag<ItemType>::toVector() const
{
    return data; 
}

/**
 * Counts the number of entries in this bag.
 *
 * @param item The entry to be counted.
 * @return The number of times item appears in the bag.
 */
template<class ItemType>
int VectorBag<ItemType>::getFrequencyOf(const ItemType &item) const
{
    int count = 0;
    for (int i = 0; i < data.size(); i ++) {
	if (data[i] == item)
	    count ++;
    }
    return count;
}

/**
 * Tests whether this bag contains a given entry.
 *
 * @param item The entry to locate.
 * @return True if bag contains item, or false otherwise.
 */
template<class ItemType>
bool VectorBag<ItemType>::contains(const ItemType &item) const
{
    for (int i = 0; i < data.size(); i ++){
	if (data[i] == item)
	    return true;
    }
    return false;
}

/**
 * Removes all entries from this bag.
 *
 * @post Bag contains no items, and the count of items
 * is 0.
 */
template<class ItemType>
void VectorBag<ItemType>::clear() {
    data.clear();
}

/**
 * Removes one occurrence of a given entry from this bag, if 
 * possible.
 *
 * @post If successful, item has been removed from the bag
 * and the count of items in the bag has decreased by 1.
 * @param item The entry to be removed.
 * @return True if removal was successful, or false if not.
 */
template<class ItemType>
bool VectorBag<ItemType>::remove(const ItemType &item)
{
    for (int i = 0; i < data.size(); i++) {
	if (data[i] == item){
	    data[i] = data[data.size() - 1]; 
	    data.pop_back();
	    return true;
	}
    }
    return false;
}

