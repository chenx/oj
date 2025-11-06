// From: https://algo.monster/liteproblems/1868
class Solution2 {
    public List<List<Integer>> findRLEArray(int[][] encoded1, int[][] encoded2) {
        List<List<Integer>> result = new ArrayList<>();

        int index2 = 0; // Pointer for encoded2 array

        // Iterate through each run-length pair in encoded1
        for (int[] pair1 : encoded1) {
            int value1 = pair1[0];
            int frequency1 = pair1[1];

            // Process the current segment from encoded1
            while (frequency1 > 0) {
                // Take the minimum frequency between current segments of both arrays
                int minFrequency = Math.min(frequency1, encoded2[index2][1]);

                // Calculate the product of values from both arrays
                int productValue = value1 * encoded2[index2][0];

                // Check if we can merge with the last segment in result
                int lastIndex = result.size() - 1;
                if (lastIndex >= 0 && result.get(lastIndex).get(0) == productValue) {
                    // Merge with the last segment by updating its frequency
                    result.get(lastIndex).set(1, result.get(lastIndex).get(1) + minFrequency);
                } else { // Add a new segment to the result
                    result.add(new ArrayList<>(List.of(productValue, minFrequency)));
                }

                // Decrease the remaining frequencies
                frequency1 -= minFrequency;
                encoded2[index2][1] -= minFrequency;

                // Move to the next segment in encoded2 if current one is exhausted
                if (encoded2[index2][1] == 0) {
                    index2++;
                }
            }
        }

        return result;
    }
}

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
                // List<Integer> entry = new ArrayList();
                // entry.add(val); entry.add(count);
                // ret.add(entry);
                ret.add(new ArrayList<>( List.of( val, count ) ));
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
