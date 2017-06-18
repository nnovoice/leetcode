package com.firstpenguin.leetcode;

public class AddTwoNumbers {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode r = new ListNode(0);
        ListNode t = r;
        int x , y;
        int val, carry = 0;
        while (l1 != null || l2 != null) {
        	x = (l1 != null) ? l1.val : 0;
        	y = (l2 != null) ? l2.val : 0;
        	val = x + y + carry;
        	carry = val / 10;
        	t.next = new ListNode(val % 10);
        	t = t.next;
        	l1 = (l1 != null) ? l1.next : null;
        	l2 = (l2 != null) ? l2.next : null;
        }
        if (carry != 0)
        	t.next = new ListNode(carry);
        
        return r.next;
    }
}

