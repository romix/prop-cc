//////////////////////////////////////////////////////////////////////////////
// NOTICE:
//
// ADLib, Prop and their related set of tools and documentation are in the
// public domain.   The author(s) of this software reserve no copyrights on
// the source code and any code generated using the tools.  You are encouraged
// to use ADLib and Prop to develop software, in both academic and commercial
// settings, and are free to incorporate any part of ADLib and Prop into
// your programs.
//
// Although you are under no obligation to do so, we strongly recommend that
// you give away all software developed using our tools.
//
// We also ask that credit be given to us when ADLib and/or Prop are used in
// your programs, and that this notice be preserved intact in all the source
// code.
//
// This software is still under development and we welcome any suggestions
// and help from the users.
//
// Allen Leung
// 1994
//////////////////////////////////////////////////////////////////////////////

#ifndef direct_chaining_hash_table_based_map_h
#define direct_chaining_hash_table_based_map_h

#include <AD/contain/hashmap.h>
#include <AD/hash/dchash.h>

/////////////////////////////////////////////////////////////////////////
//  Class DCHMap
/////////////////////////////////////////////////////////////////////////

template <class K, class V>
class DCHMap : public HashMap<K, V, DCHashTable<K,V> >
{
public:
  //////////////////////////////////////////////////////////////////
  // Constructors and destructor
  //////////////////////////////////////////////////////////////////

  DCHMap(int size = 64, double max_load = 1000.0)
      : HashMap<K,V,DCHashTable<K,V> >(size,max_load)
  {}
  DCHMap(const V& v, int size = 64, double max_load = 1000.0)
      : HashMap<K,V,DCHashTable<K,V> >(v,size,max_load)
  {}
  ~DCHMap()
  {}

  //////////////////////////////////////////////////////////////////
  // Everything else is inherited from HashMap
  //////////////////////////////////////////////////////////////////

  typedef HashMap<K, V, DCHashTable<K,V> > Super;
  /*
  typedef HashMap<K, V, DCHashTable<K,V> >::Key     Key;
  typedef HashMap<K, V, DCHashTable<K,V> >::Value   Value;
  typedef HashMap<K, V, DCHashTable<K,V> >::Element Element;
   */
};

#endif
