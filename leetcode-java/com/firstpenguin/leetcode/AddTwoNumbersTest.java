package com.firstpenguin.leetcode;

import static org.junit.Assert.*;

import java.util.ArrayList;

import org.junit.Test;

public class AddTwoNumbersTest {
	private ListNode getList(int[] nums) {
		if (nums == null) return null;
		ListNode head = new ListNode(0);
		ListNode t = head;
		for (int n : nums) {
			t.next = new ListNode(n);
			t = t.next;
		}
		return head.next;
	}
	/*private int[] getArray(ListNode l) {
		ArrayList<Integer> aList = new ArrayList<Integer>();
		Integer a;
		while (l != null) {
			aList.add(l.val);
			l = l.next;
		}
		return aList.toArray();
	}*/
	@Test
	public void testAddTwoNumbers0() {
		int [] nums = {1,2,3,4,5};
		int [] expectedArray = {2,4,6,8,0,1};
		ListNode l1 = getList(nums);
		ListNode l2 = getList(nums);
		AddTwoNumbers aAddTwoNumbers = new AddTwoNumbers();
		ListNode l3 = aAddTwoNumbers.addTwoNumbers(l1, l2);
		ListNode eList = getList(expectedArray);
		while (l3 != null && eList != null) {
			assert (l3.val == eList.val);
			System.out.println(l3.val + " " + eList.val);
			l3 = l3.next;
			eList = eList.next;
			
		}
		System.out.println(l3 + " " + eList);
		System.out.println(eList.val);
		assert (l3 == null && eList == null);
	}

}
