/*
 * http://gurmeet.net/puzzles/tiling-a-chessboard-with-dominoes/
 
   (A) An 8x8 chessboard has had two of its diagonally opposite squares removed, 
   leaving it with sixty-two squares. Can we tile it with 31 non-overlapping 2x1 
   rectangles (dominoes) such that all squares are covered? (B) Under what 
   circumstances would removal of two squares from an 8x8 chessboard allow 
   such a tiling? For example, if we remove an arbitrary white square and an 
   arbitrary black square, can the remaining board be tiled?

   Source: Part (A) is the classic Mutilated Chessboard Problem posed by 
   Martin Gardner in one of his articles in Scientific American. 
   Part (B) has a surprising answer with an elegant mathematical proof.

   Solution:

   (A) Both removed squares have identical color! So their removal leaves us 
   with 30 squares of one color and 32 squares of the other color. Since a 
   domino always covers one black and one white squares, the 62 remaining 
   squares cannot be tiled.

   (B) Removal of any white and any black square allows tiling with dominoes. 
   Proof: Find a Hamiltonian cycle among the squares, with two squares deemed 
   adjacent iff they share an edge. In other words, cover all squares of a 
   chessboard using a rook without covering the same square twice, and returning 
   to the original square. Removal of one white and one black square breaks the 
   cycle into two paths with even lengths. A path of even length can be tiled 
   with 2x1 dominoes because successive squares in the path share an edge. 
   
   Followup:
   1) Use parity / coloring argument to show that a 10x10 board cannot be tiled 
      with 1x4 pieces.

   2) Show that if a 7x7 board is tiled with 1x3 pieces, then the untiled 
      square must occupy one of the following 9 positions: the center, one 
      of the four corners, or one of the central squares along the sides of 
      the board. 

   Solutions for Followup Problems listed above:

   1) Label rows as 0, 1, ..., 9. Label columns similarly. A square in 
   column c and row r is assigned the color (c + r) mod 4. The sum of 
   colors covered by any 1x4 tile is 2 modulo 4. The sum of colors of 
   25 such tiles shall also be 2. However, the sum of colors of all 
   100 squares is 0.

   2) Color the seven rows as 0, 1, 2, 0, 1, 2, 0. The sum of numbers 
   covered by a tile is always divisible by 3. So the uncovered square 
   must belong to a row labeled 0. Now repeat the same argument with 
   'rows' replaced by 'columns'. The intersection of these rows and 
   columns are the 9 squares listed in the problem statement. 
 */
