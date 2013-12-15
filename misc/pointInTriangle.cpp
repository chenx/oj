/*
 * To decide if a point P is inside a triangle ABC:
 *
 * Method: area sum should equal: PAB + PBC + PCA = ABC.
 * 
 * Triangle area formula: http://mathworld.wolfram.com/TriangleArea.html
 * 
 * Given 3 edges a, b, c: 
 * - Heron's formula: Area = sqrt (S*(S-a)*(S-b)*(S-c)), where S = (a+b+c)/2.
 * 
 * Given 3 vertices (x1,y1), (x2,y2), (x3,y3), the (signed) area is:
 *            | x1 y1 1 |
 * Area = 1/2 | x2 y2 1 |
 *            | x3 y3 1 |
 * 
 * The same method can be used to decide if a point is in a CONVEX rectangle, or any CONVEX polygon.
 * Another method to tell if a point is in a rectangle is:
 *   use dot product to find the projected line from point P onto the rectangle sides, 
 *   and if its length is shorter than the sides, then the point must be inside the rectangle.
 */

//
// http://leetcode.com/2010/04/how-to-determine-if-point-is-inside.html
//
// Note this works for rectangles whose edges are not parallel/perpendicular to x/y axis.
// If parallel/perpendicular, it should be easier.
//
bool is_point_in_rectangle(const Rect& rect, const Point& p) {
  Vector2d P1(rect.p1.x, rect.p1.y);
  Vector2d P2(rect.p2.x, rect.p2.y);
  Vector2d P3(rect.p3.x, rect.p3.y);
  Vector2d P4(rect.p4.x, rect.p4.y);
  Vector2d P(p.x, p.y);
 
  Vector2d P1_P4 = P1 - P4;
  Vector2d P3_P4 = P3 - P4;
  Vector2d TWO_P_C = 2.0*P - P1 - P3;    // TWO_P_C=2P-C, C=Center of rectangle
 
  return (P3_P4.Dot(TWO_P_C - P3_P4) <= 0 && P3_P4.Dot(TWO_P_C + P3_P4) >= 0) &&
         (P1_P4.Dot(TWO_P_C - P1_P4) <= 0 && P1_P4.Dot(TWO_P_C + P1_P4) >= 0);
}

//
// Another method: http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html
//