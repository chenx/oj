//
// Get the number of times 1 appears in positive numbers 1 to n.
// http://zhedahht.blog.163.com/blog/static/25411174200732494452636/
// Also in Beauty of programming.
//
// @Created on: 3/9/2013
//

//
// By: yuxinwell
//
int numberof1(int n)
{
    int number = 0;
    int base = 1;
    while(1)
    {
        int lowbits = n % base;
        int curbits = n % (base*10) / base;
        int highbits = n / (base*10);
        
        if(curbits == 0) number += highbits * base;
        else if(curbits == 1) number += highbits * base + lowbits + 1;
        else number += (highbits + 1) * base;

        base *= 10;
        if(highbits == 0) break;
    }
    return number;
}
