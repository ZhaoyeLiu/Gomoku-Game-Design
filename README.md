# Gomoku-Game-Design
## Function Introduction:
This program uses a 15×15 standard Go game board with coordinates displayed along the edges, showing the row and column numbers. Players can drop their pieces by entering coordinates. The game supports two-player gameplay and keeps track of each player's wins.

## Logic and Algorithm Design:
This program is based on a combination of a two-dimensional array and the board coordinates, where the board coordinates correspond to console display coordinates. Two 15×15 two-dimensional arrays are created, all initialized to zero. These arrays correspond to the coordinates of the two players' pieces. An element of the array with a value of 1 indicates the presence of a player's piece at the corresponding board coordinates, while an element with a value of 0 indicates no piece at that location. The board coordinates are then mapped to console display coordinates. To enhance program aesthetics, the display coordinates are controlled within a specified range, with board coordinates ranging from 1 to 15. Two linear functions can map the board coordinates to the display coordinates. When a player achieves victory by connecting five pieces (horizontally, vertically, or diagonally), the corresponding array elements with a value of 1 are also connected, allowing the program to determine the winner via the two-dimensional array. The winning player is awarded one win. If a player inputs coordinates outside the board's range, a prompt will be displayed, and the player will be asked to redo their turn. If the input coordinates are already occupied by a piece, the corresponding array element will have a value of 1, and the move will be considered invalid. A prompt will be displayed, and the player will be asked to redo their turn.
