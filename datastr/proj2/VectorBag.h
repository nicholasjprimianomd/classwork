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
 * @file VectorBag.h
 *
 **********************************************************************/

#ifndef VECTORBAG_H
#define VECTORBAG_H

#include "BagInterface.h"

template <class ItemType> 
class VectorBag{

    std::vector<ItemType> data;

public:
    //0 parameter constructor
    VectorBag<ItemType>(){}
    //1 parameter constructor given a vector<ItemType> initilize data to myData
    VectorBag<ItemType> (const std::vector<ItemType>& myData) : data(myData){}
    //1 parameter constructor given a bag initilize data to myBag.data
    VectorBag<ItemType> (const VectorBag<ItemType>& myBag) : data(myBag.data){}
    std::vector<ItemType> toVector() const;
    bool add(ItemType const &item);
    bool remove(const ItemType &item);
    bool contains(const ItemType &item) const;
    bool isEmpty() const;
    int getFrequencyOf(const ItemType &item) const;
    int getCurrentSize() const;
    void clear();
};

#include "VectorBag.cpp"

#endif
