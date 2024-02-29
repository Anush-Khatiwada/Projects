#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void encryptFile(string &inputFilePath,string &outputFilePath,int key)
{
    ifstream fin(inputFilePath);
    ofstream fout(outputFilePath);

  char ch;
  while (fin.get(ch))
  {
      if(isupper(ch))
      {
        fout<<char(((ch - 'A' + key) % 26 + 'A'));
      }
      else
      {
        fout<<char(((ch - 'a' + key) % 26 + 'a'));
      }
  }

  fin.close();
  fout.close();
}

void decryptFile(const std::string &inputFilePath, const std::string &outputFilePath, int key)
{
    ifstream fin(inputFilePath);
    ofstream fout(outputFilePath);

  char ch;
  while (fin.get(ch))
  {
      if(isupper(ch))
      {
        fout<<char(((ch - 'A' - key + 26) % 26 + 'A'));
      }
      else
      {
        fout<<char(((ch - 'a' - key + 26) % 26 + 'a'));
      }
  }

  fin.close();
  fout.close();
}

int main()
{
  string inputFilePath, outputFilePath;
  int choice, key;

    cout << "1. Encrypt File\n";
    cout << "2. Decrypt File\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter key (integer): ";
    cin >> key;

    cout << "Enter input file path: ";
    cin >> inputFilePath;
    cout << "Enter output file path: ";
    cin >> outputFilePath;

  if (choice == 1)
  {
      encryptFile(inputFilePath, outputFilePath, key);
  }
  else if (choice == 2)
  {
      decryptFile(inputFilePath, outputFilePath, key);
  }
  else
  {
      std::cout << "Invalid choice." <<endl;
  }

  return 0;
}