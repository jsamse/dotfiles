#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  if (argc < 2) {
    cout << "USAGE" << endl;
    cout << "  prop [OPTIONS] <ACTION> [ARGUMENTS...]" << endl;
    cout << "ACTIONS" << endl;
    cout << "  print [DOCUMENT] [PROPERTY]" << endl;
    cout << "    no arguments: output the whole file" << endl;
    cout << "    only [DOCUMENT]: output all properties of that document" << endl;
    cout << "    both [DOCUMENT] and [PROPERTY]: output that property only" << endl;
    return 0;
  }

  string action = argv[1];

  if (action != "print") {
    cout << "unrecognized action" << endl;
    return 1;
  }

  bool success = false;
  string line;

  while (!cin.eof()) {
    getline(cin, line);

    if (argc < 3) {
      success = true;
      cout << line << endl;
      continue;
    }

    if (argv[2] == line)
    {
      if (argc < 4) success = true;

      getline(cin, line);

      while (!line.empty() && line.at(0) == ' ')
      {
        int startPos = line.find_first_not_of(' ');

        if (argc < 4) {
          cout << line.substr(startPos) << endl;
          getline(cin, line);
          continue;
        }

        int separatorPos = line.find(':');
        string name = line.substr(startPos, separatorPos - startPos);

        if (argv[3] != name)
        {
          getline(cin, line);
          continue;
        }
        
        int valueStartPos = line.find_first_not_of(' ', separatorPos + 1);
        string value = line.substr(valueStartPos);
        cout << value;
        return 0;
      }
    }
  }

  return success ? 0 : 1;
}

