/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = new ListNode(-1,head);
        while(fast!=null && n > 0) //Move to node that is n steps away from start     
        {
        fast = fast.next;
            n--;
            }
    //If we already reached the end of the list, return head -> next
    if(fast == null)
            return head.next;
    
        //Start moving all pointers until we reach the end
    while(fast != null )
    {
        fast = fast.next;
        slow = slow.next;
        prev=prev.next;
        
    }
    
        prev.next = slow.next;
    
    return head;
    
    
    }
}
