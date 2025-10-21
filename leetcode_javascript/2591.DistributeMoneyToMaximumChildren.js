/**
 * @param {number} money
 * @param {number} children
 * @return {number}
 */
var distMoney = function(money, children) {
    if (money < children) return -1;
    if (money > children * 8 ) return children - 1;
    if (money == children * 8 - 4) return children - 2;
    return Math.floor( (money - children) / 7 );
};
