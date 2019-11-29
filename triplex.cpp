#include <iostream>

void PrintIntroduction(int Difficulty)
{
  std::cout << "\n\n******\n";
  std::cout << "You are a secret agent breaking into a level " << Difficulty << " secure server room...\n";
  std::cout << "You have to guess the correct code to continue...\n";
  std::cout << "******\n\n";
}

bool PlayGame(int Difficulty)
{
  PrintIntroduction(Difficulty);

  const int CodeA = rand() % Difficulty + Difficulty;
  const int CodeB = rand() % Difficulty + Difficulty;
  const int CodeC = rand() % Difficulty + Difficulty;

  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;

  std::cout << std::endl;
  std::cout << "There are 3 numbers in the code" << std::endl;
  std::cout << "The codes add-up to: " << CodeSum << std::endl;
  std::cout << "The codes multiply to give: " << CodeProduct << std::endl;

  int GuessA, GuessB, GuessC;
  std::cout << std::endl;
  std::cout << "Enter 3 guess numbers (splitted by spaces): ";
  std::cin >> GuessA >> GuessB >> GuessC;
  std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl;

  const int GuessSum = GuessA + GuessB + GuessC;
  const int GuessProduct = GuessA * GuessB * GuessC;

  const bool bIsSameSum = CodeSum == GuessSum;
  const bool bIsSameProduct = CodeProduct == GuessProduct;

  if (bIsSameSum && bIsSameProduct)
  {
    std::cout << "You guess the code! The door is opened.\n" << std::endl;
    return true;
  }
  else
  {
    std::cout << "This is not the code, then the door stills locked. Try again.";
    return false;
  }
}

int main()
{
  int const MaxLevel = 5;
  int LevelDifficulty = 1;

  while(LevelDifficulty <= MaxLevel)
  {
    bool bLevelCompleted = PlayGame(LevelDifficulty);
    std::cin.clear();
    std::cin.ignore();

    if (bLevelCompleted)
    {
      ++LevelDifficulty;
      std::cout << "...\n";
      std::cout << "...\n";
      std::cout << "...\n";
    }
  }

  std::cout << "\nCongratulations! You have access to the main secure room, take all the files and get out of there!";

  return 0;
}
