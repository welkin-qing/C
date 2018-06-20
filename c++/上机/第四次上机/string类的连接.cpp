// concatenating strings
#include <iostream>
#include <string>
 
main ()
{
  std::string firstlevel ("cn");
  std::string secondlevel ("edu");
  std::string thirdlevel("xupt");
  std::string scheme ("http://");
  std::string hostname;
  std::string url;
 
  hostname = "www." + thirdlevel+ '.'+secondlevel + '.' + firstlevel;
  url = scheme + hostname;
 
  std::cout << url << '\n';
 
  return 0;
}
