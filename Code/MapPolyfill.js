const c = [1, 2, 3, 5]

const d = c.map(x => x * 2)

// const f = c.myMap(function(x) {
//     return x + 2;
// })

// console.log(f)

Array.prototype.myMap = function(callbackfn) {
    let obj = this
    let res = []
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