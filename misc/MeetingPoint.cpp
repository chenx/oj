//
// On a 2-D grid, the positions (x,y) of 3 persons are given. Find the meeting 
// point such that sum of distances of each person from meeting point is minimized. 
// 
// See: http://www.careercup.com/question?id=14558941
//
// Ideas: 
// 2 points: any point on the line segment connecting these 2 persons.
// 3 points: 
//   if co-linear, use the center person's loc; 
//   otherwise, the point on the line segment connecting 2, draw a perpendicular 
//       line from the 3rd to intersect this. There are 3 such choices, choose
//       the shortest one.
// N points:
// 1) brute force 2) k-d tree 3) Euclidean distance, 4) Manhattan distance
// 
// Euclidean distance between (x,y) and (x1,y1) is sqrt( (x-x1)^2 + (y-y1)^2).
// Manhattan is |x-x1| + |y-y1|
// For Manhattan, you can pick the median of the x_i and the median of the y_i.
// For Euclidean this is a convex programming problem and hill climbing type algorithms can be used.
//
// @By: Xin Chen
// @Created on: 4/9/2013
// @Last modified: 4/9/2013
//

