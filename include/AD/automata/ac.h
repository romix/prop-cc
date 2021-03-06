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

#ifndef prop_Aho_Corasick_string_matcher_h
#define prop_Aho_Corasick_string_matcher_h

////////////////////////////////////////////////////////////////////////////
// The Aho-Corasick keyword matching algorithm\cite{AC}.  The resulting
// automaton is represented as a sparse DFA table.  This data structure
// makes it possible to use this algorithm for matching large sets
// of keys with large character sets while utilizing memory efficiently.
////////////////////////////////////////////////////////////////////////////

#include <AD/automata/dfatable.h>

class AC : public DFATables
{
  AC( const AC&);                // no copy constructor
  void operator = ( const AC&);  // no assignment

public:

  /////////////////////////////////////////////////////////////////////////
  // Make inherited types visible
  /////////////////////////////////////////////////////////////////////////
  typedef DFATables     Super;
  typedef Super::Rule   Rule;
  typedef Super::State  State;
  typedef Super::Symbol Symbol;
  typedef Super::Offset Offset;

protected:

  /////////////////////////////////////////////////////////////////////////
  // Compressed tables
  /////////////////////////////////////////////////////////////////////////
  const Offset * const base;         // base offset
  const State  * const check;        //
  const State  * const next;         // transition state
  const State  * const epsilon;      // the failure function computes epsilon transitions
  const Rule   * const matched_rule; // store the matched rule

public:

  /////////////////////////////////////////////////////////////////////////
  //  Constructor
  /////////////////////////////////////////////////////////////////////////
  AC( const Offset base_table  [],
      const State  check_table [],
      const State  failure     [],
      const State  next_table  [],
      const Rule   rule_table  []
    ) : base(base_table), check(check_table), next(next_table),
      epsilon(failure), matched_rule(rule_table)
  {}

  /////////////////////////////////////////////////////////////////////////
  //  Return the start state
  /////////////////////////////////////////////////////////////////////////
  inline State start_state() const
  {
    return 1;
  }

  ////////////////////////////////////////////////////////////////////
  // Advance one state within the Aho-Corasick automaton.
  ////////////////////////////////////////////////////////////////////
  inline State go (register State s, register Symbol c) const
  {
    register Offset offset;
    while (check[offset = base[s] + c] != s)
      s = epsilon[s];
    return next[offset];
  }
};

#endif
