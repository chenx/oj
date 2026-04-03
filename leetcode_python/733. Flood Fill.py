from collections import deque
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        m, n = len(image), len(image[0])
        options = [[-1, 0], [0, 1], [1, 0], [0, -1]]

        q = deque([(sr, sc)])
        used = set([(sr, sc)])

        startColor = image[sr][sc]
        image[sr][sc] = color

        while q:
            i, j = q.popleft()
            for option in options:
                x, y = i + option[0], j + option[1]
                if x >= 0 and x < m and y >= 0 and y < n:
                    if image[x][y] == startColor and (x, y) not in used:
                        image[x][y] = color
                        used.add((x, y))
                        q.append((x, y))
        
        return image


/**
733. Flood Fill
Solved
Easy
Topics
conpanies iconCompanies
Hint

You are given an image represented by an m x n grid of integers image, where image[i][j] represents the 
pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a 
flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

    Begin with the starting pixel and change its color to color.
    Perform the same process for each pixel that is directly adjacent (pixels that share a side with the 
      original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
    Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their 
      color if it matches the original color of the starting pixel.
    The process stops when there are no more adjacent pixels of the original color to update.

Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]
 */
