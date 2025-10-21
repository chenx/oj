// Version 3. 
// Cannot pass tail by reference, it's passed by value.
var tail = null;
var reverseList = function(head) {
    if (head === null || head.next === null) {
        tail = head;
        return head;
    }

    const h = head;
    head = head.next;
    h.next = null;
    head = reverseList(head);
    tail.next = h;
    tail = h;

    return head;
}

// Version 2. Use closure.
// Need to assign to null to avoid memory leak.
var reverseList2 = function(head) {
    let tail = null;

    var reverse = function(head) {
        if (head === null || head.next === null) {
            tail = head;
            return head;
        }

        const h = head;
        head = reverseList2(head.next);
        h.next = null;
        tail.next = h;
        tail = h;

        return head;
    }

    return reverse(head);
}

var reverseList = function(head) {
    let h = null;
    while (head !== null) {
        const tmp = head;
        head = head.next;
        tmp.next = h;
        h = tmp;
    }
    return h;
};
