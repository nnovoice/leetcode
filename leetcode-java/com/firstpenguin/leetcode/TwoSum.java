package com.firstpenguin.leetcode;

import java.util.HashMap;

public class TwoSum {
	public int[] twoSum(int[] nums, int target) {
		HashMap<Integer,Integer> hmap = new HashMap<Integer,Integer>();
    	int[] res = new int[2];
    	int diff;
		for (int i = 0; i < nums.length; i++) {
    		diff = target - nums[i];
    		if (hmap.containsKey(diff)) {
    			res[0] = hmap.get(diff);
    			res[1] = i;
    		}
    		else {
    			hmap.put(nums[i], i);
    		}
			//System.out.println(i);
		}
    	return res;
    }

	public static void main(String[] args) {
		TwoSum solution = new TwoSum();
		int [] nums = {1,2,3,4,5};
		int [] res = solution.twoSum(nums, 9);
		System.out.println(res[0] + " " + res[1]);

	}

}
