// Ok, but times out for large input.
class Solution {
    public List<List<Integer>> findRLEArray(int[][] encoded1, int[][] encoded2) {
        List<Integer> arr1 = new ArrayList<Integer>();
        List<Integer> arr2 = new ArrayList<Integer>();

        for (int i = 0; i < encoded1.length; ++ i) {
            int[] arr = decode(encoded1[i]);
            for (int num : arr) arr1.add(num);
        }
        for (int i = 0; i < encoded2.length; ++ i) {
            int[] arr = decode(encoded2[i]);
            for (int num : arr) arr2.add(num);
        }

        int len = arr1.size();
        int[] result = new int[len];
        for (int i = 0; i < len; ++ i) {
            result[i] = arr1.get(i) * arr2.get(i);
        }

        return encode(result);
    }

    List<List<Integer>> encode(int[] arr) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if (arr.length == 0) return ret;

        int count = 1, val = arr[0];
        for (int i = 1; i < arr.length; ++ i) {
            if (val == arr[i]) { ++ count; }
            else {
                List<Integer> entry = new ArrayList();
                entry.add(val); entry.add(count);
                // ret.add(new ArrayList<>( Arrays.asList( new int[]{val, count} ) ));
                ret.add(entry);
                count = 1;
                val = arr[i];
            }
        }
        List<Integer> entry = new ArrayList();
        entry.add(val); entry.add(count);
        ret.add(entry);

        return ret;
    }

    int[] decode(int[] encoded) {
        int val = encoded[0], n = encoded[1];
        int[] arr = new int[n];
        for (int i = 0; i < n; ++ i) arr[i] = val;
        return arr;
    }
}

/**
1868. Product of Two Run-Length Encoded Arrays
Medium

Run-length encoding is a compression algorithm that allows for an integer array nums with many segments of consecutive 
repeated numbers to be represented by a (generally smaller) 2D array encoded. Each encoded[i] = [vali, freqi] describes 
the ith segment of repeated numbers in nums where vali is the value that is repeated freqi times.

    For example, nums = [1,1,1,2,2,2,2,2] is represented by the run-length encoded array encoded = [[1,3],[2,5]]. 
Another way to read this is "three 1's followed by five 2's".

The product of two run-length encoded arrays encoded1 and encoded2 can be calculated using the following steps:

    Expand both encoded1 and encoded2 into the full arrays nums1 and nums2 respectively.
    Create a new array prodNums of length nums1.length and set prodNums[i] = nums1[i] * nums2[i].
    Compress prodNums into a run-length encoded array and return it.

You are given two run-length encoded arrays encoded1 and encoded2 representing full arrays nums1 and nums2 respectively. 
Both nums1 and nums2 have the same length. Each encoded1[i] = [vali, freqi] describes the ith segment of nums1, and each 
encoded2[j] = [valj, freqj] describes the jth segment of nums2.

Return the product of encoded1 and encoded2.

Note: Compression should be done such that the run-length encoded array has the minimum possible length.
 */
