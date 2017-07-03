# Lem-in @42borntocode

• This project's purpose is to find the shortest way to get ants from the Start point of the ant nest to the end point.

• Obviously, their is some contraints : the ants have to take the shortest way, can't walk on the other ants and two or more ants can't be at the same place at the same time.

• At the beginning, the ants are in the room indicated by the ##start command. They have to reach the ##end room in the shortest way possible. 

• Only the moving ants are displayed

• Every turn, one ant is moved to a room linked to where she was at the previous turn.

• The results are displayed in this way : 
ant_number
rooms name and position
Links between the rooms
Lx-y Lz-w Lr-o ...
Where x, z, r are the ants number (from 1 to ant_number) and y, w, o rooms names.

## How to use it

• Clone the repository

```
git clone https://github.com/vkannema/lem-in
make
```
• Create a map
```
vim test_map
```

Exemple :

```
3
##start
0 1 0
##end
1 5 0
2 9 0
3 13 0
0-2
2-3
3-1
0-3
```

In this exemple, the map is considered like this :
```
    0
   / \
  2 - 3 
      |
      1
```
• Find the way 
```
./lem-in < test_map
```
