#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

static const std::string LETTERS = "qwertyuiopasdfghjklzxcvbnm";

std::string process(const unsigned int &size, bool letters, bool numbers)
{
  srand(time(NULL));

  std::string output;

  for (std::size_t i = 0; i < size; ++i)
  {
    bool letterOrNumber = letters ? true : false;

    if (letters && numbers)
    {
      letterOrNumber = rand() % 2 == 0 ? true : false;
    }

    if (letters && letterOrNumber)
    {
      bool upperOrLower = rand() % 2 ? true : false;

      char letter = LETTERS[rand() % LETTERS.size()];
      if (upperOrLower)
      {
        letter = std::toupper(letter);
      }

      output += letter;
    }

    if (numbers && !letterOrNumber)
    {
      output += std::to_string(rand())[0];
    }
  }

  return output;
}

int main(int argc, char *argv[])
{
  try
  {
    if (argc != 3)
    {
      throw std::invalid_argument("Invalid number of arguments.");
    }

    const std::string option = argv[1];
    const unsigned int size = std::stoi(argv[2]);

    if (option == "-")
    {
      std::cout << process(size, true, true) << std::endl;
      return 0;
    }

    if (option == "-l")
    {
      std::cout << process(size, true, false) << std::endl;
      return 0;
    }

    if (option == "-n")
    {
      std::cout << process(size, false, true) << std::endl;
      return 0;
    }

    throw std::invalid_argument("Invalid argument.");
  }
  catch (const std::exception &e)
  {
    std::cerr << "ERROR: " << e.what() << std::endl;
    std::cerr << "USE: spass <-|-l|-n> <SIZE>" << std::endl;
    std::cerr << "EXAMPLE: spass - 16" << std::endl;
    return -1;
  }
}