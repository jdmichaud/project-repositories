//  Boost string_algo library example file  ----------------------------------//

//  Copyright Jean-Daniel Michaud 2007. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#include <string>
#include <iostream>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/edit_distance.hpp>

using namespace std;
using namespace boost;
using namespace boost::algorithm;

int main()
{  
  cout << "* Edit Distance Example *" << endl << endl;

  string str1("kitten");
  string str2("sitting");

  cout << "edit distance between: " << endl 
    << "\t" << str1 << endl
    << "\t" << str2 << endl;
    
  cout << "Levenshtein -> " 
    << edit_distance(str1, str2) 
    << endl;
  cout << "Damerau-Levenshtein -> " 
    << damerau_levenshtein_distance(str1, str2) 
    << endl;
  cout << endl;

  str1 = "sunday";
  str2 = "saturday";

  cout << "edit distance between: " << endl 
    << "\t" << str1 << endl
    << "\t" << str2 << endl;
    
  cout << "Levenshtein -> " 
    << edit_distance(str1, str2) 
    << endl;
  cout << "Damerau-Levenshtein -> " 
    << damerau_levenshtein_distance(str1, str2) 
    << endl;
  cout << endl;

  str1 = "Re: [1.34] autolink doesn't work when not specifying toolset version";
  str2 = "Re: [1.34] [showstopper] autolink doesn't work when not specifyingtoolset version";

  cout << "edit distance between: " << endl 
    << "\t" << to_lower_copy(str1) << endl
    << "\t" << to_lower_copy(str2) << endl;
    
  cout << "Levenshtein -> " 
    << edit_distance(to_lower_copy(str1), to_lower_copy(str2)) 
    << endl;
  cout << "Damerau-Levenshtein -> " 
    << damerau_levenshtein_distance(to_lower_copy(str1), to_lower_copy(str2)) 
    << endl;

  return 0;
}
