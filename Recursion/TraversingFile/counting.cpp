#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

//*****************************************************************************************************

int countTarget(char titles[], char target, int len);
void display(char titles[], char target, int count);

//*****************************************************************************************************

int main()
{
	char target;
	const int SIZE = 300;
	char titles[SIZE];
	ifstream file("movies.txt");
	int len;
	int count;

	len = (int)strlen(titles);

	if (file)
	{
		while (file.getline(titles, SIZE))
		{
			file >> target;
			file.ignore();
			count = countTarget(titles, target, len);
			display(titles, target, count);
		}
	}
	else
		cout << "File does not exist!" << endl;

	file.close();

	return 0;
}

//*****************************************************************************************************

int countTarget(char titles[], char target, int len)
{
	int result;

	if (len > 0)
	{
		if (tolower(target) == tolower(titles[len - 1]))
		{
			result = 1 + countTarget(titles, target, len - 1);
		}
		else
			result = countTarget(titles, target, len - 1);

	}
	else
		result = 0;

	return result;
}

//*****************************************************************************************************

void display(char titles[], char target, int count)
{
	cout << "The symbol " << target << " was found " << count << " times in movies: "
		<< endl << titles << endl << endl;
}

//*****************************************************************************************************
/*
The symbol r was found 21 times in movies:
Aquaman, Spider-Man: Into the Spider-Verse, Bumblebee, Avengers: Infinity War, Venom, Dragon Ball Super: Broly, Solo: A Star Wars Story, Black Panther, Beauty and the Beast, The Fate of the Furious, Despicable Me 3, Jumanji, Wolf Warrior, Guardians of the Galaxy, Thor: Ragnarok, Wonder Woman

The symbol R was found 31 times in movies:
Red Rock West, Harry Potter and the Order of the Phoenix, Transformers: Revenge of the Fallen, Frozen, Red Scorpion, 101 Dalmations, Red, The Angry Red Planet, Shrek, Red Dawn, Red Riding Hood, Toy Story 3, The Thin Red Line

The symbol e was found 32 times in movies:
Blue Velvet, The Big Blue, The Blue Lagoon, The Blues Brothers, The Hunger Games, Blue Streak, Blue Thunder, Blue Desert, Soldier Blue, Pirates of the Caribbean: Dead Man's Chest

The symbol b was found 20 times in movies:
The Black Cobra, Black Dog, Beauty and the Beast, Men in Black, Black Dynamite, Black Hawk Down, Black Book, Pitch Black, Black Sabbath, Black Sunday, Creature From the Black Lagoon, Black Death, Little Black Book, Black Sheep

The symbol g was found 17 times in movies:
Green Zone, The Green Mile, The Green Berets, The Hunger Games: Catching Fire, Soylent Green, The Green Lantern, Guardians of the Galaxy, Green Street Hooligans, Gravity

The symbol p was found 6 times in movies:
The Pink Panther, Pink Cadillac, The Secret Life of Pets, Despicable Me 2

The symbol y was found 8 times in movies:
Yellow Submarine, She Wore a Yellow Ribbon, Finding Dory, Gravity, Yellow brick road

The symbol O was found 28 times in movies:
The Color Purple, Deadpool, Zootopia, Home Alone, Wonder Woman, Iron Man, The Purple Rose of Cairo

The symbol I was found 25 times in movies:
National Lampoon's Men in White, Single White Female, White Fang, White Squall, Inception, The Twilight Saga: Breaking Dawn, The Chronicles of Narnia: The Lion, the Witch and the Wardrobe,  Lady in White, White Noise, Lair of the White Worm, White Men Can't Jump, White Chicks

Press any key to close this window . . .
*/
