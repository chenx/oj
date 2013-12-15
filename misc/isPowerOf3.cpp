/*
http://stackoverflow.com/questions/1804311/how-to-check-if-an-integer-is-power-of-3

while (n % 3 == 0) {
    n /= 3;
}
return n == 1;

Note that 1 is the zeroth power of three.

Edit: You also need to check for zero before the loop, as the loop will not terminate for n = 0 (thanks to Bruno Rothgiesser).

--

Recursively divide by 3, check that the remainder is zero and re-apply to the quotient.

Note that 1 is a valid answer as 3 to the zero power is 1 is an edge case to beware.

--

Very interesting question, I like the answer from starblue, and this is a variation of his algorithm which will converge little bit faster to the solution:

private bool IsPow3(int n)
{
    if (n == 0) return false;
    while (n % 9 == 0)
    {
        n /= 9;
    }
    return (n == 1 || n == 3);
}




 */