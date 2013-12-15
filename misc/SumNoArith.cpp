//
// Add 2 numbers w/o +-*/
// http://zhedahht.blog.163.com/blog/static/254111742011125100605/
// 
// @Created on: 3/9/2013
//

int AddWithoutArithmetic(int num1, int num2)
{
        if(num2 == 0)
                return num1;
 
        int sum = num1 ^ num2;
        int carry = (num1 & num2) << 1;
 
        return AddWithoutArithmetic(sum, carry);
}
