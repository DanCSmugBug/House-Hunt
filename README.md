# House-Hunt
A C++ based text game where you must explore a randomly generated house to find gold and your lost object while avoiding the sleeping monster and the looming threat of midnight.

House Hunt is an attempt to make a "text-based adventure" with some mechanical meat on it's bones. I've always been a big fan of
exploration and time management elements in games, and wanted to create a game that incorporated those elements as well as could
provide a fresh experience every time I played it. As a result, House Hunt was born , and quickly it became perhaps the largest
project I've ever coded for. I'm fairly pleased with the end result.

The object of the game is to find a randomly generated item of yours that a monster took into it's manor. You must explore this mansion,
searching rooms for your precious object, searching furniture in rooms for gold, and keeping your ears open to try and figure out where
the monster is lurking so that you might avoid it. All of these activities take time, which should the clock hit 12:00 and you remain in
the house, the monster will awaken and kill you.

Start up of the game allows you to read some basic game rules, as well as create a character with a personalized name and a special
ability. These abilities effect the game experience in fairly significant ways, so pick carefully! You then choose how large the house is.
I recommend starting with the smallest option if you are new. The house is then generated, with a random number and placement of rooms
and hallways within, as well as potentially a second floor and cellar if the house is big enough. Within some of the rooms, the objective
item and monster are placed. The algorithm is such that it's not possible for the objective to be trapped behind the monster (or at least
in theory it shouldn't be, *nervous laughter*).

Upon entry of the house, in each room you have the option to search any furniture, move to a different room, listen for the monster,
or search for the objective item. Searching the furniture will only net you gold, which serves as a bit of a score system for the game,
and searching for the objective will never net you gold.

The game can end one of several ways: you leave the house without finding the objective item, which is a no-win scenario, you leave
the house with the objective scenario, which is a win (bolstered by however much gold you gather!), you stumble across the monster or
you run out of time, both of which results in a gruesome death at the hands of the monster.

This project was one started in late May of 2019, though I didn't start in ernest until the second week of June. It was a pretty good
learning experience, though I'm sure there are areas where the code could be improved. The process of removing memory leaks was a painful
one, but I'm glad it's free of them. After my brother-in-law immediately broke the game by typing words instead of numbers, I created
the inVerify class (or input verify) which I retroactively added to Penguin-Derby. In retrospect, I guess it doesn't make much since to
have it as a class. I should probably convert it to a library at some stage. Ah well. Perhaps in the future I may do that, or perhaps 
I'll come up with a practical reason for why I should keep it as a class. Now I'm rambling.
