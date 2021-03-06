class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        
        long long hash = 0;
        for (int i = 0; i < key.length(); ++ i) {
            hash = hash * 33 + (key[i]);
            hash %= HASH_SIZE;
        }
        return hash;
    }
};


/**
Hash Function

In data structure Hash, hash function is used to convert a string(or any other type) 
into an integer smaller than hash size and bigger or equal to zero. The objective of 
designing a hash function is to "hash" the key as unreasonable as possible. A good 
hash function can avoid collision as less as possible. A widely used hash function 
algorithm is using a magic number 33, consider any string as a 33 based big integer 
like follow:

hashcode("abcd") = (ascii(a) * 333 + ascii(b) * 332 + ascii(c) *33 + ascii(d)) % HASH_SIZE 

                              = (97* 333 + 98 * 332 + 99 * 33 +100) % HASH_SIZE

                              = 3595978 % HASH_SIZE

here HASH_SIZE is the capacity of the hash table (you can assume a hash table is like 
an array with index 0 ~ HASH_SIZE-1).

Given a string as a key and the size of hash table, return the hash value of this key.


Have you met this question in a real interview?
Clarification

For this problem, you are not necessary to design your own hash algorithm or consider 
any collision issue, you just need to implement the algorithm as described.
Example

For key="abcd" and size=100, return 78

 */
