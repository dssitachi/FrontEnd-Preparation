const c = [1, 2, 3, 5]

Array.prototype.myMap = function(callbackfn) {
    const obj = this
    const res = []
    obj.forEach((x) => res.push(callbackfn(x)))
    return res;
}

let printName = function() {
    console.log(this.firstName)
}

const f = c.myMap(function(x) {
    return x + 2
})

console.log(f)