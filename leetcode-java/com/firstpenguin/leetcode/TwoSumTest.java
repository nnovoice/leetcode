package com.firstpenguin.leetcode;

import static org.junit.Assert.*;

import org.junit.Test;

public class TwoSumTest {

	@Test
	public void testTwoSum0() {
		TwoSum solution = new TwoSum();
		int [] nums = {1,2,3,4,5};
		int [] res = solution.twoSum(nums, 8);
		System.out.println(res[0] + " " + res[1]);
		assert(res[0] == 2 && res[1] == 4);
	}
	@Test
	public void testTwoSum1() {
		TwoSum solution = new TwoSum();
		int [] nums = {1,2,3,4,5};
		int [] res = solution.twoSum(nums, 9);
		System.out.println(res[0] + " " + res[1]);
		assert(res[0] == 3 && res[1] == 4);
	}

}
