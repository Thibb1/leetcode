/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var arr = new Array(nums).flat().sort((a, b) => {return a-b;});
    var x = 0;
    var y = arr.length;
    do {
        y--;
        var a = arr[x];
        var b = arr[y];
        if ((target >= 0 && a+b<target)
            || (y <= x)) {
            y = arr.length;
            x++;
        }
    } while (a+b!=target);
    return([nums.indexOf(a),nums.lastIndexOf(b)]);
};