/*
   Determine if someone has won a game of tic-tac-toe on a board of any size?
   O(1) time needed. Space not specified.
   
   Ans:
   The algorithm's complexity is O(1) for determining if a given move will 
   win the game. It cannot be O(1) in general since you need to know the 
   state of the board to determine a winner. However, you can build that 
   state incrementally such that you can determine whether a move wins in O(1).

   To start, have an array of numbers for each row, column, and diagonal for 
   each player. On each move, increment the elements corresponding to the 
   player for the row, column, and diagonal (the move may not necessarily 
   be on a diagonal) influenced by that move. If the count for that player 
   is equal to the dimension of the board, that player wins.
 */
