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

#ifndef LL1_parser_generator_h
#define LL1_parser_generator_h

//
// Class |LL1| represents a parser generated by a LL(1) grammar.
// The algorithm used is the one described in \cite{FL-1988}.
//

#include <iostream>               // Standard C++ I/O stream
#include <AD/automata/grammar.h>  // Canonical parser grammar
#include <AD/automata/sparsdfa.h> // Compressed sparse dfa


class LL1Gen : protected SparseDFA
{
  LL1Gen(const LL1Gen&);             // no copy constructor
  void operator = (const LL1Gen&);   // no assignment

protected:

  ///////////////////////////////////////////////////////////////////////////
  // Import and inherit some types
  ///////////////////////////////////////////////////////////////////////////
  typedef Grammar::NonTerminal NonTerminal;
  typedef Grammar::Terminal    Terminal;
  typedef Grammar::Action      Action;
  typedef Grammar::Production  Production;

  typedef SparseDFA            Super;
  typedef Super::State         State;
  typedef Super::Offset        Offset;
  typedef Super::Symbol        Symbol;
  typedef Super::Rule          Rule;

public:

  ///////////////////////////////////////////////////////////////////////////
  //  Constructor and destructor
  ///////////////////////////////////////////////////////////////////////////
  LL1Gen();
  ~LL1Gen();

  ///////////////////////////////////////////////////////////////////////////
  //  Compilation and code emission
  ///////////////////////////////////////////////////////////////////////////
  virtual void compile( const Grammar& G);
  virtual std::ostream& gen_code( std::ostream&, const char []) const;
};

#endif
