#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  if (argc < 3) {
    cout << "usage: prop <document> <property>" << endl;
    return 0;
  }

  string documentName = argv[1];
  string propertyName = argv[2];
  string line;

  while (!cin.eof()) {
    getline(cin, line);
    if (documentName == line)
    {
      getline(cin, line);
      while (!line.empty() && line.at(0) == ' ')
      {
        int startPos = line.find_first_not_of(' ');
        int separatorPos = line.find(':');
        string name = line.substr(startPos, separatorPos - startPos);

        if (propertyName != name)
        {
          getline(cin, line);
          continue;
        }

        int valueStartPos = line.find_first_not_of(' ', separatorPos + 1);
        string value = line.substr(valueStartPos);
        cout << value << endl;
        return 0;
      }
    }
  }
  return 1;
}

