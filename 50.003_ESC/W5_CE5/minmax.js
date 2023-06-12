function numbers(l) {
    var o = [];
    for (let i in l) {
        var n = parseInt(l[i], 10);
        if (!isNaN(n)) {
            o.push(n);
        }
    }
    return o;
}

// input: an array of numbers

// output: an object containing 'min', with the minimum of the array 
//          and 'max' the maximum of the array.
function min_max(a) {
    var min = null; 
    var max = null;
    // TODO: fixme    
    for (let i in a) {
        if (min == null) {
            min = a[i];
        }
        if (max == null) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
        if (a[i] > max) {
            max = a[i];
        }
    }
    return { 'min': min, 'max': max }
}

function handleButton1Click() {
    var textbox1 = document.getElementById("textbox1"); 
    var min = document.getElementById("min"); 
    var max = document.getElementById("max"); 
    var items = textbox1.value.split(","); 
    var obj = min_max(numbers(items)); 
    min.innerHTML = obj['min']; 
    max.innerHTML = obj['max'];
}
function run() {
    var button1 = document.getElementById("button1");
    // TODO: fixme
    button1.addEventListener("click", handleButton1Click);

}

document.addEventListener("DOMContentLoaded", run);
