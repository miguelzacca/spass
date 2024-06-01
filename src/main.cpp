#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <random>

static const std::string LETTERS = "qwertyuiopasdfghjklzxcvbnm";
static const std::string NUMBERS = "0123456789";

std::string process(const unsigned int &size, bool letters, bool numbers)
{
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<> letter_dist(0, LETTERS.size() - 1);
  std::uniform_int_distribution<> number_dist(0, NUMBERS.size() - 1);
  std::uniform_int_distribution<> letter_or_number_dist(0, 1);
  std::uniform_int_distribution<> case_dist(0, 1);

  std::string output;

  for (std::size_t i = 0; i < size; ++i)
  {
    bool use_letter = letters && (!numbers || !letter_or_number_dist(gen));

    if (use_letter)
    {
      char letter = LETTERS[letter_dist(gen)];
      if (case_dist(gen))
      {
        letter = std::toupper(letter);
      }
      output += letter;
      continue;
    }

    if (numbers)
    {
      output += NUMBERS[number_dist(gen)];
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
