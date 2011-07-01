///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "../../include/AD/automata/treegram.ph".
///////////////////////////////////////////////////////////////////////////////

#line 1 "../../include/AD/automata/treegram.ph"
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

#ifndef tree_grammar_h
#define tree_grammar_h

#include <iostream>
#include <new>
#include <AD/generic/generic.h>   // generic definitions
#include <AD/automata/treetab.h>  // tree grammar tables
#include <AD/memory/mem.h>        // memory managers
#include <AD/contain/bitset.h>    // bit sets

using namespace std;

////////////////////////////////////////////////////////////////////////////////
//  Definition of a tree term.
////////////////////////////////////////////////////////////////////////////////
   
#line 40 "../../include/AD/automata/treegram.ph"
#line 70 "../../include/AD/automata/treegram.ph"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for TreeTerm
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_TreeTerm_defined
#define datatype_TreeTerm_defined
   class a_TreeTerm;
   typedef a_TreeTerm * TreeTerm;
#endif

#  define wild_term 0

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype TreeTerm
//
///////////////////////////////////////////////////////////////////////////////
class a_TreeTerm {
public:
   enum Tag_TreeTerm {
      tag_tree_term = 0, tag_var_term = 1, tag_and_term = 2, 
      tag_or_term = 3, tag_not_term = 4, tag_set_term = 5
   };

public:
   const Tag_TreeTerm tag__; // variant tag
protected:
   inline a_TreeTerm(Tag_TreeTerm t__) : tag__(t__) {}
public:
#line 50 "../../include/AD/automata/treegram.ph"
   
   
         //////////////////////////////////////////////////////////////////////////
         //  The memory management routines of redefined to take advantage of
         //  placement.
         //////////////////////////////////////////////////////////////////////////
         inline void * operator new (size_t n) { return new char [n]; }
         inline void * operator new (size_t n, Mem& mem) { return mem.m_alloc(n); }
         inline void   operator delete (void *) {}
   
         //////////////////////////////////////////////////////////////////////////
         //  Function to allocate a new term.
         //////////////////////////////////////////////////////////////////////////
         friend TreeTerm new_term(Mem& mem, short int f, unsigned char n=0, TreeTerm * subterms=0);
   
         //////////////////////////////////////////////////////////////////////////
         // Equality and hashing of tree terms
         //////////////////////////////////////////////////////////////////////////
         friend Bool equal(const TreeTerm, const TreeTerm);
         friend unsigned int hash(const TreeTerm);
      
#line 70 "../../include/AD/automata/treegram.ph"
};
inline int boxed(const a_TreeTerm * x) { return x != 0; }
inline int untag(const a_TreeTerm * x) { return x ? (x->tag__+1) : 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TreeTerm::tree_term
//
///////////////////////////////////////////////////////////////////////////////
class TreeTerm_tree_term : public a_TreeTerm {
public:
#line 42 "../../include/AD/automata/treegram.ph"
   TreeTables::Functor _1; int _2; TreeTerm * _3; 
   inline TreeTerm_tree_term (TreeTables::Functor x_1, int x_2 = 0, TreeTerm * x_3 = 0)
    : a_TreeTerm(tag_tree_term), _1(x_1), _2(x_2), _3(x_3)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TreeTerm::var_term
//
///////////////////////////////////////////////////////////////////////////////
class TreeTerm_var_term : public a_TreeTerm {
public:
#line 45 "../../include/AD/automata/treegram.ph"
   TreeTables::Variable var_term; 
   inline TreeTerm_var_term (TreeTables::Variable x_var_term)
    : a_TreeTerm(tag_var_term), var_term(x_var_term)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TreeTerm::and_term
//
///////////////////////////////////////////////////////////////////////////////
class TreeTerm_and_term : public a_TreeTerm {
public:
#line 46 "../../include/AD/automata/treegram.ph"
   TreeTerm _1; TreeTerm _2; 
   inline TreeTerm_and_term (TreeTerm x_1, TreeTerm x_2)
    : a_TreeTerm(tag_and_term), _1(x_1), _2(x_2)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TreeTerm::or_term
//
///////////////////////////////////////////////////////////////////////////////
class TreeTerm_or_term : public a_TreeTerm {
public:
#line 47 "../../include/AD/automata/treegram.ph"
   TreeTerm _1; TreeTerm _2; 
   inline TreeTerm_or_term (TreeTerm x_1, TreeTerm x_2)
    : a_TreeTerm(tag_or_term), _1(x_1), _2(x_2)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TreeTerm::not_term
//
///////////////////////////////////////////////////////////////////////////////
class TreeTerm_not_term : public a_TreeTerm {
public:
#line 48 "../../include/AD/automata/treegram.ph"
   TreeTerm not_term; 
   inline TreeTerm_not_term (TreeTerm x_not_term)
    : a_TreeTerm(tag_not_term), not_term(x_not_term)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor TreeTerm::set_term
//
///////////////////////////////////////////////////////////////////////////////
class TreeTerm_set_term : public a_TreeTerm {
public:
#line 49 "../../include/AD/automata/treegram.ph"
   BitSet * set_term; 
   inline TreeTerm_set_term (BitSet * x_set_term)
    : a_TreeTerm(tag_set_term), set_term(x_set_term)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for TreeTerm
//
///////////////////////////////////////////////////////////////////////////////
inline a_TreeTerm * tree_term (TreeTables::Functor x_1, int x_2 = 0, TreeTerm * x_3 = 0)
{
   return new TreeTerm_tree_term (x_1, x_2, x_3);
}
inline a_TreeTerm * var_term (TreeTables::Variable x_var_term)
{
   return new TreeTerm_var_term (x_var_term);
}
inline a_TreeTerm * and_term (TreeTerm x_1, TreeTerm x_2)
{
   return new TreeTerm_and_term (x_1, x_2);
}
inline a_TreeTerm * or_term (TreeTerm x_1, TreeTerm x_2)
{
   return new TreeTerm_or_term (x_1, x_2);
}
inline a_TreeTerm * not_term (TreeTerm x_not_term)
{
   return new TreeTerm_not_term (x_not_term);
}
inline a_TreeTerm * set_term (BitSet * x_set_term)
{
   return new TreeTerm_set_term (x_set_term);
}
///////////////////////////////////////////////////////////////////////////////
//
// Downcasting functions for TreeTerm
//
///////////////////////////////////////////////////////////////////////////////
inline TreeTerm_tree_term * _tree_term(const a_TreeTerm * _x_) { return (TreeTerm_tree_term *)_x_; }
inline TreeTerm_var_term * _var_term(const a_TreeTerm * _x_) { return (TreeTerm_var_term *)_x_; }
inline TreeTerm_and_term * _and_term(const a_TreeTerm * _x_) { return (TreeTerm_and_term *)_x_; }
inline TreeTerm_or_term * _or_term(const a_TreeTerm * _x_) { return (TreeTerm_or_term *)_x_; }
inline TreeTerm_not_term * _not_term(const a_TreeTerm * _x_) { return (TreeTerm_not_term *)_x_; }
inline TreeTerm_set_term * _set_term(const a_TreeTerm * _x_) { return (TreeTerm_set_term *)_x_; }

#line 70 "../../include/AD/automata/treegram.ph"
#line 70 "../../include/AD/automata/treegram.ph"


//////////////////////////////////////////////////////////////////////////////
//  Tree grammar
//////////////////////////////////////////////////////////////////////////////
class TreeGrammar : public TreeTables {

   TreeGrammar(const TreeGrammar&);       // no copy constructor
   void operator = (const TreeGrammar&);  // no assignment

public:

   ///////////////////////////////////////////////////////////////////////////
   //  Inport inherited types
   ///////////////////////////////////////////////////////////////////////////
   typedef TreeTables         Super;
   typedef Super::Functor     Functor;
   typedef Super::Variable    Variable;
   typedef Super::NonTerminal NonTerminal;
   typedef Super::Arity       Arity;
   typedef Super::State       State;
   typedef Super::Cost        Cost;

   enum TreeGrammar_constants { Max_arity = 256 };

   ///////////////////////////////////////////////////////////////////////////
   //  Definition of a tree production
   ///////////////////////////////////////////////////////////////////////////
   struct TreeProduction {
      Variable var;
      TreeTerm term;
      Cost     cost;
      TreeProduction() {}
      TreeProduction(Variable v, TreeTerm t, Cost c = 0)
        : var(v), term(t), cost(c) {}
   };

protected:

   ///////////////////////////////////////////////////////////////////////////
   //  Internals
   ///////////////////////////////////////////////////////////////////////////
   Arity          * arities;                // mapping from functors to arity
   TreeProduction * productions;            // tree productions
   int              number_of_productions;  // production count
   int              number_of_functors;     // total number of functors
   int              number_of_variables;    // total number of non-terminals
   Functor          maximum_functor;        // range of functors
   Functor          minimum_functor;
   Variable         minimum_variable;       // range of non-terminals
   Variable         maximum_variable;
   int              maximum_arity;          // maximum arity of all functors
   const char **    functor_names;          // names of functors
   const char **    variable_names;         // names of non-terminals

private:

   void tabulate       (const TreeTerm);  // method to tabulate the ranges
   void tabulate_arity (const TreeTerm);  // method to tabulate the arities
   void init();                           // method to initialize the class

public:

   ///////////////////////////////////////////////////////////////////////////
   //  Constructors and destructor
   ///////////////////////////////////////////////////////////////////////////
            TreeGrammar();
            TreeGrammar(int n, TreeProduction [], const char *[], const char *[] = 0);
   virtual ~TreeGrammar();

   ///////////////////////////////////////////////////////////////////////////
   //  Compile a set of tree productions
   ///////////////////////////////////////////////////////////////////////////
   void compile (int n, TreeProduction [],
                 const char * functor_names[] = 0,
                 const char * variable_names[] = 0,
                 Functor min_f = 32767, Functor max_f = 0,
                 Variable min_v = 32767, Variable max_v = 0
                );

   ///////////////////////////////////////////////////////////////////////////
   //  Indexing
   ///////////////////////////////////////////////////////////////////////////
   inline const TreeProduction& operator [] (int i) const { return productions[i]; }
   inline       TreeProduction& operator [] (int i)       { return productions[i]; }

   ///////////////////////////////////////////////////////////////////////////
   //  Mutators
   ///////////////////////////////////////////////////////////////////////////
   inline void  update(int i, TreeTerm t) { productions[i].term = t; }
   void         normalise();

   ///////////////////////////////////////////////////////////////////////////
   //  Selectors
   ///////////////////////////////////////////////////////////////////////////
   inline int      size()           const { return number_of_productions; }
   inline Arity    arity(Functor f) const { return arities[f]; }
   inline Functor  min_functor()    const { return minimum_functor; }
   inline Functor  max_functor()    const { return maximum_functor; }
   inline Variable min_variable()   const { return minimum_variable; }
   inline Variable max_variable()   const { return maximum_variable; }
   inline int      max_arity()      const { return maximum_arity; }
   inline int      functors()       const { return number_of_functors; }
   inline int      variables()      const { return number_of_variables; }

   ///////////////////////////////////////////////////////////////////////////
   //  Printing methods
   ///////////////////////////////////////////////////////////////////////////
   const char * functor_name  (Functor)  const;
   const char * variable_name (Variable) const;
   ostream& print_functor  (ostream&, Functor)               const;
   ostream& print_variable (ostream&, Variable)              const;
   ostream& print          (ostream&, const TreeTerm)        const;
   ostream& print          (ostream&, const TreeProduction&) const;
   ostream& print          (ostream&, const TreeGrammar&)    const;
   friend ostream& operator << (ostream&, const TreeGrammar&);

   ///////////////////////////////////////////////////////////////////////////
   //  Iterator macros
   //  These can be used for to make code more readable.
   ///////////////////////////////////////////////////////////////////////////
#ifdef TreeGrammar_Iterators
#  define foreach_functor(f,G) \
      for(TreeGrammar::Functor f = (G).min_functor(); f <= (G).max_functor(); f++)
#  define foreach_unit_functor(f,G) \
      foreach_functor(f,G) if ((G).arity(f) == 0)
#  define foreach_non_unit_functor(f,G) \
      foreach_functor(f,G) if ((G).arity(f) > 0)
#  define foreach_arity(i,f,G) \
      for(int i = (G).arity(f); i >= 0; i--)
#  define foreach_variable(v,G) \
      for(TreeGrammar::Variable v = (G).min_variable(); v <= (G).max_variable(); v++)
#  define foreach_production(i,G) \
      for(int i = 0; i < (G).size(); i++)
#endif
};

#endif
#line 208 "../../include/AD/automata/treegram.ph"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 0
Number of ifs generated      = 0
Number of switches generated = 0
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = disabled
Fast string matching         = disabled
Inline downcasts             = disabled
--------------------------------------------------------------------------
*/
