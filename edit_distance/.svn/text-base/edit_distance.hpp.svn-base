//  Boost string_algo library edit_distance.hpp header file  -----------------//

//  Copyright Jean-Daniel Michaud 2007. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  0.1. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#ifndef BOOST_EDIT_DISTANCE_HPP
#define BOOST_EDIT_DISTANCE_HPP

#include <vector>
#include <algorithm>
#include <boost/range/end.hpp>
#include <boost/range/begin.hpp>
#include <boost/range/size.hpp>
#include <boost/range/size_type.hpp>
#include <boost/range/iterator.hpp>
#include <boost/range/const_iterator.hpp>
#include <boost/algorithm/string/config.hpp>
#include <boost/algorithm/string/compare.hpp>

/*! \file boost/algorithm/string/edit_distance.hpp
    The edit distance is the number of deletion/insertion/substitution needed to 
    transform one string to another.
    
    The Damreau-Levenstein algorithm count a transposition as one operation 
    instead of two (deletion/insertion).
*/

namespace boost {
  namespace algorithm {
  
    //! edit_distance function
    /*! Compute the edit distance between string Arg1 and Arg2. 
        Damerau option specify the use of the Damreau-Levenstein algorithm.
        
        \param Arg1 The first string to compare
        \param Arg2 The second string to compare
        \param Comp The equality predicate
        \param Damerau Damreau-Levenstein algorithm used if true
        \return The edit distance between Arg1 and Arg2
    */
    template<typename Range1T, typename Range2T, typename PredicateT>
    inline unsigned int edit_distance(
      const Range1T& Arg1, 
      const Range2T& Arg2,
      PredicateT Comp,
      bool Damerau = false)
    {
      typedef BOOST_STRING_TYPENAME 
        range_const_iterator<Range1T>::type Iterator1T;
      typedef BOOST_STRING_TYPENAME 
        range_const_iterator<Range2T>::type Iterator2T;

      Iterator1T Arg1End = end(Arg1);
      Iterator2T Arg2End = end(Arg2);
    
      Iterator1T Arg1It = begin(Arg1);
      Iterator2T Arg2It = begin(Arg2);
      Iterator1T Arg1It2 = begin(Arg1);
      Iterator2T Arg2It2 = begin(Arg2);
      
      range_size<Range1T>::type Arg1Size = size(Arg1);
      range_size<Range2T>::type Arg2Size = size(Arg2);
      
      std::vector<unsigned int> d[3];
      d[0].resize(Arg2Size + 1);
      d[1].resize(Arg2Size + 1);
      d[2].resize(Arg2Size + 1);      
      d[0][0] = 0;
      d[1][0] = 0;
      
      unsigned int i;
      unsigned int j;
      for (j = 1; j < Arg2Size + 1; ++j)
      {
        d[0][j] = j;
        d[1][j] = j;
      }
      
      unsigned int is_equal = 0;
      for(i = 1; Arg1It != Arg1End; ++Arg1It, ++Arg1It2, ++i)
      {
        for(j = 1, Arg2It = begin(Arg2), Arg2It2 = begin(Arg2); 
            Arg2It != Arg2End; 
            ++Arg2It, ++j)
        {
          d[2][0] = i;
          if (Comp(*Arg1It, *Arg2It))
            is_equal = 0;
          else
            is_equal = 1;
            
          d[2][j] = (std::min)(
                                d[1][j] + 1, 
                                (std::min)(
                                            d[2][j - 1] + 1, 
                                            d[1][j - 1] + is_equal
                                          )
                              );
          if (Damerau)
          {
            if (i > 2 && j > 2
                && !Comp(*Arg1It, *Arg2It2) && !Comp(*Arg1It2, *Arg2It))
            {
              d[2][j] = (std::min)(
                                    d[2][j],
                                    d[0][j - 2] + is_equal
                                  );
              ++Arg2It2;
            }
          }          
        }
        std::copy(d[1].begin(), d[1].end(), d[0].begin());
        std::copy(d[2].begin(), d[2].end(), d[1].begin());
      }
                
      return d[2][Arg2Size];
    }

    //! edit_distance function
    /*! Compute the edit distance between string Arg1 and Arg2.
        
        \param Arg1 The first string to compare
        \param Arg2 The second string to compare
        \return The edit distance between Arg1 and Arg2
    */
    template<typename Range1T, typename Range2T>
    inline unsigned int edit_distance(
      const Range1T& Arg1, 
      const Range2T& Arg2)
    {
      return edit_distance(Arg1, Arg2, is_equal(), false);
    }

    //! edit_distance function
    /*! Compute the edit distance between string Arg1 and Arg2 using the 
        Damreau-Levenstein algorithm.
        
        \param Arg1 The first string to compare
        \param Arg2 The second string to compare
        \return The edit distance between Arg1 and Arg2
    */
    template<typename Range1T, typename Range2T>
    inline unsigned int damerau_levenshtein_distance(
      const Range1T& Arg1, 
      const Range2T& Arg2)
    {
      return edit_distance(Arg1, Arg2, is_equal(), true);
    }

  } // !algorithm
} // !boost

#endif // !BOOST_EDIT_DISTANCE_HPP
