#include <vector>
#include <string>
#include <fstream>





int input_process(std::string _data);
void insert(std::string word);

void insert(std::string word)
{
  A.append(word);
};

int input_process(std::string _data)
{ std::string word;
  for (int i = 0; i < _data.size(); i++)
    {
      if ((_data[i] >= 'a' && _data[i]<='z') or (_data[i] >= 'A' && _data[i]<='Z'))
	{
	  word.append(_data[i]);
	}
      else
	{
	  if (!word.empty())
	    {
	      insert(word);
	      word.clear();
	    };
	};
    };
  return 0;
};
