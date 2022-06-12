document.querySelector('#level4').addEventListener('click', function(e) {
    console.log("level 4 clicked")
})

document.querySelector('#level3').addEventListener('click', function(e) {
    console.log("level 3 clicked")
})

document.querySelector('#level2').addEventListener('click', function(e) {
    console.log("level 2 clicked")
})

document.querySelector('#level1').addEventListener('click', function(e) {
    console.log("level 1 clicked")
    e.stopPropagation()
}, true)